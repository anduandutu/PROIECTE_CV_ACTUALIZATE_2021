#include <Wire.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#define USE_ARDUINO_INTERRUPTS false
#include <PulseSensorPlayground.h>
//DE TESTAT PUTIN SI DE FACUT DOCUMENTATIA

//PENTRU PARTEA DE MASURARE PULS
const int OUTPUT_TYPE = SERIAL_PLOTTER;
const int PULSE_INPUT = A0;
const float THRESHOLD = 751;   // Adjust this number to avoid noise when idle
byte samplesUntilReport;
const byte SAMPLES_PER_SERIAL_SAMPLE = 10;
PulseSensorPlayground pulseSensor;


//Folosit pentru trimiterea unei notificari in momentul in care s-au realizat mai mult de x pasi pe zi 
//Folosit pentru trimiterea unui mail cu raportul pe zi:)
//Cu scop didactic se va opta pentru un interval de transmisie mai scurt -- 2 min)
String deviceId_Email= "vBA817A59D0E33C0";
String deviceId = "v4A962E06F959B36";
String deviceIdNotificationReport = "v0B1DF674904EF11";
const char* logServer = "api.pushingbox.com";

//variabile pentru transmisia de date catre platforma ThingSpeak
String apiKey = "PCHRV9E9M11ZLIBN";     // API KEY FROM THINGSPEAK

const char *ssid =  "andrei1999";     // replace with your wifi ssid and wpa2 key
const char *pass =  "andrei191";
const char* server = "api.thingspeak.com";

WiFiClient client;


// MPU6050 Slave Device Address
const uint8_t MPU6050SlaveAddress = 0x68;

// Select SDA and SCL pins for I2C communication 
const uint8_t scl = D6;
const uint8_t sda = D7;

// sensitivity scale factor respective to full scale setting provided in datasheet 
const uint16_t AccelScaleFactor = 16384;
const uint16_t GyroScaleFactor = 131;

// MPU6050 few configuration register addresses
const uint8_t MPU6050_REGISTER_SMPLRT_DIV   =  0x19;
const uint8_t MPU6050_REGISTER_USER_CTRL    =  0x6A;
const uint8_t MPU6050_REGISTER_PWR_MGMT_1   =  0x6B;
const uint8_t MPU6050_REGISTER_PWR_MGMT_2   =  0x6C;
const uint8_t MPU6050_REGISTER_CONFIG       =  0x1A;
const uint8_t MPU6050_REGISTER_GYRO_CONFIG  =  0x1B;
const uint8_t MPU6050_REGISTER_ACCEL_CONFIG =  0x1C;
const uint8_t MPU6050_REGISTER_FIFO_EN      =  0x23;
const uint8_t MPU6050_REGISTER_INT_ENABLE   =  0x38;
const uint8_t MPU6050_REGISTER_ACCEL_XOUT_H =  0x3B;
const uint8_t MPU6050_REGISTER_SIGNAL_PATH_RESET  = 0x68;

int16_t AccelX, AccelY, AccelZ, Temperature, GyroX, GyroY, GyroZ;

//variabile pentru monitorizarea numarului de pasi
int steps = 0;
int flag=0;


//indecsi de parcurgere
int ind; 


//pentru_temporizari evenimente
unsigned long lastMillis_steps = 0;
unsigned long lastMillis_pulse = 0;
unsigned long lastMillis_tractiuni = 0;


//PENTRU PARTEA DE MASURARE PULS
#define pulse_sensor A0
float threshold_pulse = 750.0;
float read_value;


//long previousMillis = 0;        // will store last time LED was updated
 
// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
const long interval_E1 = 3*60000; //actualizare nr Pasi
const long interval_E3 = 2*60000;//actualizare nr Tractiuni corecte
const long interval_E2 = 60000; //actualizare Puls
int BPM = 0;

//READING DATA FROM MPU6050

float threshold=0.7;
//Initializare vectori in functie de care se actualizeaza info 
//La fiecare 100 de masuratori se actualizeaza step counter-ul
float xval[100]={0};
float yval[100]={0};
float zval[100]={0};
float GyroXVal[100]={0};
float GyroYVal[100]={0};
float GyroZVal[100]={0};

//valori medii de calibrare
float xavg;
float yavg;
float zavg;
float GyroXAvg;
float GyroYAvg;
float GyroZAvg;

void setup() {
  Serial.begin(115200);
  //preluam datele prin intermediul comunicatiei I2C
  Wire.begin(sda, scl);
  MPU6050_Init();
  //Datele dorim sa fie calibrate la setup
  calibrate();
  //Ne conectam la reteaua WI-FI
  delay(10);
  Serial.println("Connecting to ");
  Serial.println(ssid);
 
 
  WiFi.begin(ssid, pass);
 
  while (WiFi.status() != WL_CONNECTED) 
  {
     delay(500);
     Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  //Iar la fiecare 24h se vor transmite datele despre nr pasi catre thingspeak 
  
  //CONFIGURARE PULSE MANAGER 
  // Configure the PulseSensor manager.
  pulseSensor.analogInput(PULSE_INPUT);

  pulseSensor.setSerial(Serial);
  pulseSensor.setOutputType(OUTPUT_TYPE);
  pulseSensor.setThreshold(THRESHOLD);

  // Skip the first SAMPLES_PER_SERIAL_SAMPLE in the loop().
  samplesUntilReport = SAMPLES_PER_SERIAL_SAMPLE;

  // Now that everything is ready, start reading the PulseSensor signal.
  if (!pulseSensor.begin()) {
    for(;;) {
      // Flash the led to show things didn't work.
      Serial.print(".");
    }
  }
}

//PENTRU PARTEA 5 a cerintei incerc recunoasterea unei miscari corecte de tractiune
//PRESUPUNE O MENTINERE CONSTANTA A DIRECTIEI DE MISCARE SI UNGHIUL DE ROTATIE CONSTANT PE TOATE AXELE 
int minVal=265;
int maxVal=402;
double x;
double y;
double z;
void calibrate(){
  
  double Ax, Ay, Az, T, Gx, Gy, Gz;
  float sum,sum1,sum2 = 0;
  float sumGx,sumGz,sumGy = 0;
  for(ind = 0;ind<100;ind++){
      
      Read_RawValue(MPU6050SlaveAddress, MPU6050_REGISTER_ACCEL_XOUT_H);
      
      //divide each with their sensitivity scale factor
      Ax = (double)AccelX/AccelScaleFactor;
      Ay = (double)AccelY/AccelScaleFactor;
      Az = (double)AccelZ/AccelScaleFactor;

      Gx = (double)GyroX/GyroScaleFactor;
      Gy = (double)GyroY/GyroScaleFactor;
      Gz = (double)GyroZ/GyroScaleFactor;
      
      xval[ind] = float(Ax);
      yval[ind] = float(Ay);
      zval[ind] = float(Az);
      
      sum = sum + Ax;
      sum1 = sum1+Ay;
      sum2 = sum2+Az;
  }
  delay(100);
  xavg = sum/100.0;
  yavg = sum1/100.0;
  zavg = sum2/100.0;
}
//FLAG-URI SEPARARE SITUATII DE URGENTA
int flag_steps = 1;
int flag_pulse = 1;
int flag_trimitere = 0;
int countTractiuni = 0;
void loop() {
    //PT ACCELEROMETRU
    int acc=0;
    //la fiecare 100 de masuratori se identifica abaterea patratica medie si se compara cu rezultatul anterior
    //Daca a existat o schimbare = incrementare step counter
    float totvect[100]={0};
    float totave[100]={0};
    //PENTRU MASURARE PASI + IDENTIFICARE MISCARE
    float xaccl[100] = {0};
    float yaccl[100] = {0};
    float zaccl[100] = {0};
    //PENTRU IDENTIFICAREA NIVELULUI DE ROTATIE
    float Xang[100] = {0};
    float Yang[100] = {0};
    float Zang[100] = {0};
    float totAng[100] = {0};
    double Ax, Ay, Az, T, Gx, Gy, Gz;
    int xAng,yAng,zAng;
    int countIncorrectTractiuniSamples = 0;
    
    //pentru partea de puls
    int c;
    int total_steps = 0;
    int last_pulse;
    int total_tractiuni = 0;
 
    
    
              unsigned long currentTime = millis();
              if (pulseSensor.sawNewSample()) {
                  if (--samplesUntilReport == (byte) 0) {
                    samplesUntilReport = SAMPLES_PER_SERIAL_SAMPLE;
              
                    pulseSensor.outputSample();
                    if (pulseSensor.sawStartOfBeat()) {
                      pulseSensor.outputBeat();
                      //SE MASOARA PULSUL
                      c = pulseSensor.getBeatsPerMinute();
                      Serial.println(c/3);   
                      delay(10000); 
                      Serial.println("CurrentBPM");
                      Serial.println(c/3);
                      if(c/3>=50 && c/3<=150){
                          last_pulse = c/3;
                          sendPulsesToThingspeak(c/3);
                      }         
                    //IN ACELASI TIMP CU GENERAREA IMPULSURILOR
                    //SE FAC SI MASURATORILE PENTRU STEP COUNTER
                    for (int a = 0; a < 100; a++)
                    {
                      //inregistrarea datelor masurate de la senzor  
                      Read_RawValue(MPU6050SlaveAddress, MPU6050_REGISTER_ACCEL_XOUT_H);
                        
                        //divide each with their sensitivity scale factor
                      Ax = (double)AccelX/AccelScaleFactor;
                      Ay = (double)AccelY/AccelScaleFactor;
                      Az = (double)AccelZ/AccelScaleFactor;
            
                      //GYRO
                      Gx = (double)GyroX/GyroScaleFactor;
                      Gy = (double)GyroY/GyroScaleFactor;
                      Gz = (double)GyroZ/GyroScaleFactor;
                      
                      xAng = map(Ax,minVal,maxVal,-90,90);
                      yAng = map(Ay,minVal,maxVal,-90,90);
                      zAng = map(Az,minVal,maxVal,-90,90);
                      
                      x= RAD_TO_DEG * (atan2(-yAng, -zAng)+PI);
                      y= RAD_TO_DEG * (atan2(-xAng, -zAng)+PI);
                      z= RAD_TO_DEG * (atan2(-yAng, -xAng)+PI);
            
                      Xang[a] = x;
                      delay(1);
                      Yang[a] = y;
                      delay(1);
                      Zang[a] = z;
                      delay(1);
                      totAng[a] = sqrt(pow(Xang[a],2)+pow(Yang[a],2)+pow(Zang[a],2));
                      
                      xaccl[a] = Ax;
                      delay(1);
                      yaccl[a] = Ay;
                      delay(1);
                      zaccl[a] = Az;
                      delay(1);
                      totvect[a] = sqrt(((xaccl[a] - xavg) * (xaccl[a] - xavg)) + ((yaccl[a] - yavg) * (yaccl[a] - yavg)) + ((zval[a] - zavg) * (zval[a] - zavg)));
                      totave[a] = (totvect[a] + totvect[a - 1]) / 2 ;
                      delay(100);
                      Serial.println(totave[a]);
                      //valoarea threshold functioneaza ca un FTS pentru valorile preluate de la accelerometru
                      if (totave[a] > threshold && flag == 0 && a>0)
                      {
                        steps = steps + 1;
                        flag = 1;
                      }
                      else if (totave[a] > threshold && flag == 1 && a>0)
                      {
                        // Don't Count
                      }
                      if (totave[a] < threshold   && flag == 1 && a>0)
                      {
                        flag = 0;
                      }
                      if (steps < 0) {
                        steps = 0;
                      }
                        //DACA NU NE MISCAM
                        //TRATAM CAZUL PENTRU NUMARAREA SAMPLE-urilor MISCARII  
                        //Serial.println(totave[a]);     
                        if((totAng[a] - totAng[a-1] == 0) && (totave[a] < 0.5 && totave[a]>0.31) && a>0 ){
                          countIncorrectTractiuniSamples++;
                        }
                    }
                    Serial.println("Procent incorectitudine tractiune: ");
                    Serial.print(countIncorrectTractiuniSamples);
                    if(countIncorrectTractiuniSamples<20 && countIncorrectTractiuniSamples>0){
                        countTractiuni++;
                        steps--;
                    }
                    delay(1000);
                    //PT TEMPORIZARE
                    unsigned long currentTime = millis();
                    if (currentTime - lastMillis_tractiuni >= interval_E3){ // La fiecare 2 min - 10s
                         total_tractiuni = total_tractiuni + countTractiuni;
                         sendTractiuniToThingspeak(countTractiuni);
                         countTractiuni = 0;
                         lastMillis_tractiuni = currentTime;  //get ready for the next iteration
                    }
                    if (currentTime - lastMillis_steps >= interval_E1) // LA FIECARE 3 min se va transmite --- (2*60000UL)
                    {
                        Serial.println('\n');
                        Serial.print("steps: ");
                        Serial.println(steps);
                        total_steps = total_steps + steps;
                        if(steps/3>=3){ //stepsnrMinute la care ne raportam
                            sendNotification(steps/3);//steps/nrMinute
                        }
                        if(steps>=0){
                            sendStepsToThingspeak(steps);
                        }
                        else{
                            steps = 0;
                        }
                        steps = 0;
                        lastMillis_steps = currentTime;  //get ready for the next iteration
                    }
                  }
                }
              }
}
void sendTractiuniToThingspeak(int tractiuniCorecte){
        if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field1=";
                             postStr += String(tractiuniCorecte);
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                             Serial.print("Numar tractiuni corecte: ");
                             Serial.print(tractiuniCorecte);
                        }
          client.stop();
 
          Serial.println("Waiting...");
  
  // thingspeak needs minimum 15 sec delay between updates, i've set it to 30 seconds
  delay(10000);
}

void sendNotificationReport(int noSteps,int noTractiuni,int puls){
  Serial.println("- connecting to pushing server: " + String(logServer));
  if (client.connect(logServer, 80)) {
    Serial.println("- succesfully connected");
    
    String postStr = "devid=";
    postStr += String(deviceIdNotificationReport);
    postStr += "&numberOfSteps=";
    postStr += String(noSteps);
    postStr += "\r\n\r\n";
    postStr += "&numberTractiuni=";
    postStr += String(noTractiuni);
    postStr += "\r\n\r\n";
    postStr += "&Pulse=";
    postStr += String(puls);
    postStr += "\r\n\r\n";
    Serial.println("- sending data...");
    
    client.print("POST /pushingbox HTTP/1.1\n");
    client.print("Host: api.pushingbox.com\n");
    client.print("Connection: close\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);
  }
  client.stop();
}
void sendNotification(int noSteps){

  Serial.println("- connecting to pushing server: " + String(logServer));
  if (client.connect(logServer, 80)) {
    Serial.println("- succesfully connected");
    
    String postStr = "devid=";
    postStr += String(deviceId);
    postStr += "&numberOfSteps=";
    postStr += String(noSteps);
    postStr += "\r\n\r\n";
    
    Serial.println("- sending data...");
    
    client.print("POST /pushingbox HTTP/1.1\n");
    client.print("Host: api.pushingbox.com\n");
    client.print("Connection: close\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);
  }
  client.stop();
  Serial.println("- stopping the client");
  if (client.connect(logServer, 80)) {
    client.print("GET /pushingbox?devid=");
    client.print(deviceId_Email);
    client.println(" HTTP/1.1");
    client.print("Host: ");
    client.println(logServer);
    client.println("User-Agent: Arduino");
    client.println();
  }
}


void sendPulsesToThingspeak(int puls){
  if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field2=";
                             postStr += String(puls);
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                             //Serial.print("Number of steps: ");
                             Serial.print(puls);
                        }
          client.stop();
 
          Serial.println("Waiting...");
  
  // thingspeak needs minimum 15 sec delay between updates, i've set it to 30 seconds
  delay(10000);
  
}
void sendStepsToThingspeak(int pasi){
        if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field3=";
                             postStr += String(pasi);
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                             Serial.print("Number of steps: ");
                             Serial.print(pasi);
                        }
          client.stop();
 
          Serial.println("Waiting...");
  
  // thingspeak needs minimum 15 sec delay between updates, i've set it to 30 seconds
  delay(10000);
}
//metodele de implementare ale protocolului I2C
void I2C_Write(uint8_t deviceAddress, uint8_t regAddress, uint8_t data){
  Wire.beginTransmission(deviceAddress);
  Wire.write(regAddress);
  Wire.write(data);
  Wire.endTransmission();
}

// read all 14 register
void Read_RawValue(uint8_t deviceAddress, uint8_t regAddress){
  Wire.beginTransmission(deviceAddress);
  Wire.write(regAddress);
  Wire.endTransmission();
  Wire.requestFrom(deviceAddress, (uint8_t)14);
  AccelX = (((int16_t)Wire.read()<<8) | Wire.read());
  AccelY = (((int16_t)Wire.read()<<8) | Wire.read());
  AccelZ = (((int16_t)Wire.read()<<8) | Wire.read());
  Temperature = (((int16_t)Wire.read()<<8) | Wire.read());
  GyroX = (((int16_t)Wire.read()<<8) | Wire.read());
  GyroY = (((int16_t)Wire.read()<<8) | Wire.read());
  GyroZ = (((int16_t)Wire.read()<<8) | Wire.read());
}

//configurare MPU6050
void MPU6050_Init(){
  delay(150);
  I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_SMPLRT_DIV, 0x07);
  I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_PWR_MGMT_1, 0x01);
  I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_PWR_MGMT_2, 0x00);
  I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_CONFIG, 0x00);
  I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_GYRO_CONFIG, 0x00);//set +/-250 degree/second full scale
  I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_ACCEL_CONFIG, 0x00);// set +/- 2g full scale
  I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_FIFO_EN, 0x00);
  I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_INT_ENABLE, 0x01);
  I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_SIGNAL_PATH_RESET, 0x00);
  I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_USER_CTRL, 0x00);
}
