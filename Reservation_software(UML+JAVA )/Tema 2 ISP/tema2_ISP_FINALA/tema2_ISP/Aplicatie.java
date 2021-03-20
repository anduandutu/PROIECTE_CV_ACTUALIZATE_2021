package tema2_ISP;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Enumeration;
import java.util.Vector;

public class Aplicatie {
	public static Vector<tema2_ISP.Client> clienti_inregistrati = new Vector<tema2_ISP.Client>();
	public static Vector<tema2_ISP.Client> clienti_vizitatori = new Vector<tema2_ISP.Client>();//DONE
	public static Vector<tema2_ISP.AgentTurism> agenti_turism = new Vector<tema2_ISP.AgentTurism>(); //DONE
	
	//PLECAM DE LA PRESUPUNEREA CA EXISTA UN SINGUR ADMIN
	public static void main(String[] args) {
		//AGENTI
		tema2_ISP.AgentTurism agent1 = new tema2_ISP.AgentTurism("a1@gmail.com","a1","Agent Turism");
		tema2_ISP.AgentTurism agent2 = new tema2_ISP.AgentTurism("a2@gmail.com","a2","Agent Turism");
		agenti_turism.add(agent1);
		agenti_turism.add(agent2);
		BufferedReader in = new BufferedReader(new InputStreamReader (System.in));
		try {
			//LOGIN MENU
			System.out.println("Va rugam sa va introduceti mail-ul dvs: ");
			String email = new String(in.readLine());
			System.out.println("Va rugam sa introduceti parola dvs: ");
			String parola = new String(in.readLine());
			System.out.println("OPTIUNI USER:\n");
			System.out.println("ADMIN: Administrator Login\n");
			System.out.println("AGENT: Agent Turism Login\n");
			System.out.println("CLIENT: Client login ");
			System.out.println("GUEST: Client fara privilegii de comanda");
			
			//OPTIUNI CREARE CONT/LOGARE
			BufferedReader in_user_creation = new BufferedReader(new InputStreamReader (System.in));
			try {
				System.out.println("Optiunea dvs este:");
				String tip_utilizator = new String(in_user_creation.readLine());
				handleUsers(email,parola,tip_utilizator);
				
			}
			catch(IOException e) {
				e.printStackTrace();
			}
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
	public static void handleUsers(String email,String parola,String tip_user) {
		
		//Creare tip user respectiv
		switch(tip_user) {
			case "ADMIN":{
					//CREARE ADMIN
					Administrator administrator = new Administrator(email,parola,"Administrator");
					administrator.afisareUser();
					while(true) {
						administrator.loadPossibilities();
					}
			}
			case "AGENT":{
					//CREARE AGENT TURISM
					 Enumeration<tema2_ISP.AgentTurism> enumobject = agenti_turism.elements();  
		             int index = 0;
		             boolean exista = false;
		             tema2_ISP.AgentTurism agent_existent= null;
		             while (enumobject.hasMoreElements())   
		             {             
		            	if(enumobject.nextElement().Email.equals(email)) {
		            		agent_existent = agenti_turism.get(index);
		            		exista = true;
		            		
		            	}
		        		index++;
		             }   
				     
				    if(exista == false) {
				    	System.out.println("Contul dvs de agent va fi adaugat in sistem si retrimis pentru logare!...");
				    	AgentTurism agent_nou = new AgentTurism(email,parola,"Agent Turism");
				    	agenti_turism.add(agent_nou);
						handleUsers(email,parola,tip_user);
				    }
				    else {
				    	System.out.println("Va vom loga imediat!...");
				    	agent_existent.afisareUser();
						while(true) {
							agent_existent.loadPossibilities();
						}
				    }
				    break;
			}
			case "CLIENT":{
					//LOGARE CLIENT
					 Enumeration<tema2_ISP.Client> enumobject = clienti_inregistrati.elements();  
		             int index = 0;
		             boolean exista = false;
		             tema2_ISP.Client client_existent = null;
		             while (enumobject.hasMoreElements())   
		             {             
		            	if(enumobject.nextElement().Email.equals(email)) {
		            		client_existent = clienti_inregistrati.get(index);
		            		exista = true;
		            	}
		        		index++;
		             }   
				     
				    if(exista == false) {
				    	System.out.println("Va vom crea un cont nou!");
				    	Client c_nou = new Client(email,parola,"CLIENT_C");
				    	clienti_inregistrati.add(c_nou);
				    	handleUsers(email,parola,"CLIENT");
				    }
				    else {
				    	System.out.println("Nu sunteti logat deja!Va vom redirectiona catre login...");
				    	System.out.println("Va vom loga imediat!...");
				    	client_existent.logat = client_existent.login(email, parola);
				    	client_existent.afisareUser();
						while(true) {
							client_existent.loadPossibilities();
						}
				    }
				    break;
			}
			case "GUEST":{
					//CREARE CLIENT INVITAT
					Client vizitator =  new Client(email,parola,"GUEST");
					clienti_vizitatori.add(vizitator);
					break;
			}
			default:{
					 //DACA NU ESTE NICIUNA DIN OPTIUNI TREBUIE SA RERULAM MAIN-UL DE LA INCEPUT
					 System.out.println("ATI INTRODUS O OPTIUNE INCORECTA");
					 main(new String[] {});
					 break;
			}
		}
		
	}

}
