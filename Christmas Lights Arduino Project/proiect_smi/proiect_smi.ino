/*

This software is licensed under a Creative Commons Attribution-ShareAlike 3.0 Unported License
Attribution-ShareAlike
CC BY-SA 

Lucrare 11 - Elemente practice de bază în dezvoltarea sistemelor cu microprocesoare integrate utilizând Arduino Uno

Proiect comanda la distanta

http://smi.aii.pub.ro
 
*/

#include <IRremote.h>


//pini circuit
const int receiver = 5; 
IRrecv irrecv(receiver);
decode_results results;

const int releuPin = 6;
const int buzzerPin = 4;
//variabile globale 
int track ; // numarul piesei
volatile int n;

//variabile utilizate pentru definirea cantecelor
const int length[6] = {69,73,71,29,51,77}; // numarul de note din fiecare piesa
const char * notes[6] = {"ggagsed deggsgg ggagsed deggsgg DCbCDbCbabCabagabgagsgasgsesgeseddeggsgg ", \
                     "ddaagfedcdefga ddaagfedcdefga avgavCDagfdefgfgavaagfedfedgfgavCDagfed" , \
                     "cfffgagavCavafggfcfffgagavCavafggffaCDCvagfgavCcfagfccfffgagavCavafggf " , \
                     "faagfvvagaCCbCaDCvagfeagffef ", \
                     "aavCagfgagdgavCaggfgagff vavCDDaaCagfecavCagfgagff ", \
                     "cffefaagCCCvagacffefaagCffeedcCCCfvaagCCCfvaagDDDCvavgavCffgaDDDCvavgavCffgf " };
const byte beats[6][77] = { 
                 { 2,2,2,2,2,2,2,2,2,2,2,2,2,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,2,2,4,2,2,2,2,2,2,4,1,1,2,4,2,2,2,2,2,2,2,2,2,2,8 } , \
                 { 2,2,1,1,1,1,4,2,2,2,2,2,2,4,2,2,2,2,1,1,1,1,4,2,2,2,2,2,2,4,2,2,3,1,1,1,1,1,3,1,1,1,1,1,3,1,1,1,1,1,3,1,1,1,1,1,3,1,1,1,1,1,3,1,2,2,2,2,2,2,4,2,2 }, \
                 { 2,2,2,2,2,1,1,1,1,2,2,2,1,1,2,2,6,2,2,2,2,2,1,1,1,1,2,2,2,1,1,2,2,6,1,1,3,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,4,4,2,2,2,2,1,1,1,1,2,2,2,1,1,2,2,6,2 } , \
                 { 2,3,1,2,2,2,2,2,2,2,2,2,2,6,2,3,1,2,2,2,2,2,2,2,2,2,2,6,2 }, \
                 { 2,3,1,2,2,4,4,3,1,2,2,8,3,1,2,2,3,1,4,2,2,3,1,6,2,3,1,2,2,2,2,2,2,2,2,2,2,6,2,2,2,2,2,4,4,2,2,3,1,8,8}, \
                 { 2,2,3,1,2,2,2,2,2,2,3,1,2,2,4,2,2,3,1,2,2,2,2,2,2,3,1,2,2,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,2,1,1,3,1,2,2,4,3,1,2,2,2,2,4,2,1,1,3,1,2,2,4,8} };
const int tempo[6] = {150,150,150,150,150,150}; 
const char * piesa[6] = {"God Rest Ye Merry Gentlemen   ", \
                    "Ding Dong Merrily on High     ", \
                   "O Little Town of Bethlehem    ", \
                   "While Shephards Watched       ", \
                   "In The Bleak Midwinter        ", \
                   "Hark the Herald               " };

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(buzzerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(buzzerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
    
const char names[] = { 'c', 'd', 'e', 'f', 's', 'g', 'a', 'v', 'b', 'C', 'D', 'E' }; // note
const int tones[] = { 1915, 1700, 1519, 1432, 1352, 1275, 1136, 1073, 1014, 956, 852, 758 }; // frecvente

  for (int i = 0; i < 12; i++) {
    if (names[i] == note) {
      //schimb instalatia in functie de fiecare nota din fundal
       digitalWrite(releuPin,LOW);
       delay(10);
       playTone(tones[i], duration);
       digitalWrite(releuPin,HIGH);
       delay(50);
    }
  }
}

void setup()

{
  irrecv.enableIRIn();
  pinMode(releuPin, OUTPUT);  
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}
void playSong(int nr_piesa){
        irrecv.enableIRIn();
        Serial.print("Play Piesa ");
        Serial.print(track+1);
        for (n = 0; n < length[nr_piesa]; n++) 
        {
            for (int j=n; j<(n+30); j++);// Serial.print(piesa[track][j % 30]);
            if (notes[nr_piesa][n] == ' ') delay(beats[nr_piesa][n] * tempo[nr_piesa]); // pauză
            else {
              
              playNote(notes[nr_piesa][n], beats[nr_piesa][n] * tempo[nr_piesa]);
            }
            if (irrecv.decode(&results)) 
            {
              irrecv.resume(); // receive the next value
            }
            //daca apasam butonul 4 oprim
            if (results.value==0xFF22DD) {
                      break;
            }
        }
        // pauza intre note
        delay(tempo[nr_piesa] / 2);
}
void loop() {
         //bucata asta trebuie mutata efectiv altundeva
          if (irrecv.decode(&results)) 
          {
            //Buton 1
            if(results.value == 0xFFA25D){
                track = 1;
            }
            //Buton 5
            if(results.value == 0xFF02FD){
                track = 2;
            }
            //Buton 7
            if (results.value==0xFFE01F) {
                track = 3;
            }
            //Buton ok
            if(results.value == 0xFF38C7){
               Serial.print("Pornim instalatia...");
               playSong(track);
            }
            irrecv.resume(); // receive the next value
          }
}
