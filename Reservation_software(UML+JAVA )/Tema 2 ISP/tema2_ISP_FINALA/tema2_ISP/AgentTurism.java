// --------------------------------------------------------
// Code generated by Papyrus Java
// --------------------------------------------------------

package tema2_ISP;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Enumeration;
import java.util.Vector;

/************************************************************/
/**
 * 
 */
public class AgentTurism extends tema2_ISP.User {
	public AgentTurism(String email_user, String parola, String tip_utilizator) {
		super(email_user, parola, tip_utilizator);
		// TODO Auto-generated constructor stub
	}
	
	void loadPossibilities() {
		System.out.println("Aveti posibilitatea urmatoarelor operatii:");
		System.out.println("1.Schimbare username");
		System.out.println("2.Schimbare parola");
		System.out.println("3.Logout");
		System.out.println("4.Validare comanda client");
		BufferedReader input_client = new BufferedReader(new InputStreamReader (System.in));
		String optiune_client;
		this.validat = false;
		try {
			optiune_client = new String(input_client.readLine());
				switch(optiune_client) {
				case "1":{
					BufferedReader input_new_username= new BufferedReader(new InputStreamReader (System.in));
					System.out.println("Introduceti noul username: ");
					try {
						String new_username = new String(input_new_username.readLine());
						super.change_username(new_username);
					}
					catch(IOException e1) {
						e1.printStackTrace();
					}	
					break;
					
				}
				case "2":{
					System.out.println("Introduceti noua parola:");
					BufferedReader input_new_parola= new BufferedReader(new InputStreamReader (System.in));
					try {
						String new_pass = new String(input_new_parola.readLine());
						super.setPass(new_pass);
					}
					catch(IOException e1) {
						e1.printStackTrace();
					}	
					break;
				}
				case "3":{
					super.logout();
				}
				case "4":{
					 this.vizualizareRezervari(rezervari);
					 
					 String filtrare = " ";
					 System.out.println("Doriti sa filtrati comenzile?[y/n]");
					 BufferedReader getfiltrare= new BufferedReader(new InputStreamReader (System.in));
					 try {
						 filtrare = new String(getfiltrare.readLine());
					 }
					 catch(IOException e1) {
							e1.printStackTrace();
					 }
					 if(filtrare.contentEquals("y")) {
						 //PRELUAM OPTIUNEA PENTRU FILTRARE
						 System.out.println("Posibilitatile de filtrare sunt urmatoarele: ");
						 System.out.println("1. Data comanda");
						 System.out.println("2. Categorie serviciu cerut[M/A/H]");
						 String filtru = " ";
						 System.out.println("Intruduceti optiunea de filtrare:");
						 BufferedReader getfiltru= new BufferedReader(new InputStreamReader (System.in));
						 try {
							 filtru = new String(getfiltru.readLine());
						 }
						 catch(IOException e1) {
								e1.printStackTrace();
						 }
						 
						 //AFISAREA COMENZILOR FILTRATE
						 switch(filtru) { 
							 case "1":{
								 Vector<tema2_ISP.Rezervari> vec_comenzi_filtrate = this.filtrare(tema2_ISP.Filtre_agent.DataComanda);
								 this.vizualizareRezervari(vec_comenzi_filtrate);
								 break;
							 }
							 case "2":{
								 Vector<tema2_ISP.Rezervari> vec_comenzi_filtrate = this.filtrare(tema2_ISP.Filtre_agent.CategorieServiciu);
								 this.vizualizareRezervari(vec_comenzi_filtrate);
								 break;
							 }
						 }
						 //DUPA CE SE FILTREAZA COMENZILE PT VIZUALIZARE SE VALIDEAZA COMANDA SPECIFICA
						 String client_email = " ";
						 System.out.println("Intruduceti va rog email-ul clientului care a realizat comanda de validat:");
						 BufferedReader get_email= new BufferedReader(new InputStreamReader (System.in));
						 try {
								client_email = new String(get_email.readLine());
						 }
						 catch(IOException e1) {
								e1.printStackTrace();
						 }
	
						 String cod_comanda = "";
						 System.out.println("Introduceti va rog codul comenzii petru validare:");
						 BufferedReader get_cod1= new BufferedReader(new InputStreamReader (System.in));
						 try {
								cod_comanda = new String(get_cod1.readLine());
						 }
						 catch(IOException e1) {
								e1.printStackTrace();
						 }
						 this.validareRezervare(client_email, cod_comanda, rezervari);
						 
					 }
					 else {
							 String client_email = " ";
							 System.out.println("Intruduceti va rog email-ul clientului care a realizat comanda de validat:");
							 BufferedReader get_email= new BufferedReader(new InputStreamReader (System.in));
							 try {
									client_email = new String(get_email.readLine());
							 }
							 catch(IOException e1) {
									e1.printStackTrace();
							 }
		
							 String cod_comanda = "";
							 System.out.println("Introduceti va rog codul comenzii petru validare:");
							 BufferedReader get_cod1= new BufferedReader(new InputStreamReader (System.in));
							 try {
									cod_comanda = new String(get_cod1.readLine());
							 }
							 catch(IOException e1) {
									e1.printStackTrace();
							 }
							 this.validareRezervare(client_email, cod_comanda, rezervari);
					 }
		             
					break;
				}
				default:{
					super.exit();
					break;
				}
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	/**
	 * 
	 */
	private boolean validat = false;
	/**
	 * 
	 */
	public static Vector<tema2_ISP.Rezervari> rezervari = new Vector<tema2_ISP.Rezervari>();

	/**
	 * 
	 * @param client_email 
	 * @param cod_comanda 
	 * @return 
	 */
	public void vizualizareRezervari(Vector<tema2_ISP.Rezervari> lista_rezervari) {
		
		Enumeration<tema2_ISP.Rezervari> enumobject = lista_rezervari.elements();
		while (enumobject.hasMoreElements())   
        {   
			tema2_ISP.Rezervari rezervare_curenta = enumobject.nextElement();
			System.out.println("Comanda nr: "+rezervare_curenta.getNrRezervare());
			System.out.println("Cod comanda: "+rezervare_curenta.getCod_comanda());
			System.out.println("Data comanda: "+rezervare_curenta.data_comanda.toString());
			System.out.println("Date de contact: " + rezervare_curenta.get_comanda_client().Email);
			System.out.println("Stoc curent pentru oferta solicitata: " + rezervare_curenta.getOferta_solicitata().getStoc());
			System.out.println("Cantitate dorita: "+rezervare_curenta.getCantitate_solicitata());
			System.out.println("Pret total: "+(float)rezervare_curenta.getCantitate_solicitata()*rezervare_curenta.getOferta_solicitata().Pret);
			System.out.println("------------------------------------------------DELIMITATOR--------------------------------------------------");
			
        }
	}
	
	
	
	public void validareRezervare(String client_email, String cod_comanda,Vector<tema2_ISP.Rezervari> lista_rezervari) {
		Enumeration<tema2_ISP.Rezervari> enumobject = lista_rezervari.elements();
		while (enumobject.hasMoreElements())   
        {             
	       	tema2_ISP.Rezervari rezervare_curenta = enumobject.nextElement();
	       	if(rezervare_curenta.get_comanda_client().Email.equals(client_email) && rezervare_curenta.getCod_comanda().equals(cod_comanda)) {
	       		if(rezervare_curenta.getOferta_solicitata().getStoc() - rezervare_curenta.getCantitate_solicitata() >=0) {
	       			rezervare_curenta.getOferta_solicitata().setStoc(rezervare_curenta.getOferta_solicitata().getStoc() - rezervare_curenta.getCantitate_solicitata());
		       		rezervare_curenta.setValidata(true);
		       		this.setValidat(rezervare_curenta.isValidata());
	       		}
	       		else {
	       			rezervare_curenta.setValidata(false);
		       		this.setValidat(rezervare_curenta.isValidata());
	       		}
	       		if(this.isValidat() == true) {
	       			System.out.println("Comanda a fost validata! Se trimite clientului Email de confirmare...");
	       		}
	       		else {
	       			System.out.println("Comanda a fost respinsa! Se trimite clientului Email de infirmare ...");
	       		}
	       		
	       	}
        }   
	}

	/**
	 * 
	 * @param criteriu_filtrare_comenzi 
	 */
	public Vector<tema2_ISP.Rezervari> filtrare(tema2_ISP.Filtre_agent criteriu_filtrare_comenzi) {
		 Vector<tema2_ISP.Rezervari> vec_rezervari = new Vector<tema2_ISP.Rezervari>();
		 if(criteriu_filtrare_comenzi == tema2_ISP.Filtre_agent.DataComanda){
			 String filtruData = " ";
			 System.out.println("Introduceti data comenzii pe care doriti sa o vizualizati in format [yyyy-mm-dd] :");
			 BufferedReader getFiltruData= new BufferedReader(new InputStreamReader (System.in));
			 try {
				 filtruData = new String(getFiltruData.readLine());
			 }
			 catch(IOException e1) {
					e1.printStackTrace();
			 }
			 
			 //Conversie string in data
			 
			 DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");
		     LocalDate data_filtrare = LocalDate.parse(filtruData, formatter);
		     
		     //Filtrare data
			 Enumeration<tema2_ISP.Rezervari> enumobject = rezervari.elements();  
             int index = 0;
             
             while (enumobject.hasMoreElements())   
             {             
            	if(enumobject.nextElement().data_comanda.equals(data_filtrare)) {
            		vec_rezervari.add(rezervari.get(index));
            	}
        		index++;
             }
             return vec_rezervari;
			 
		 }
		 else if(criteriu_filtrare_comenzi == tema2_ISP.Filtre_agent.CategorieServiciu){
			 String filtruCategorie = " ";
			 System.out.println("Introduceti tipul categoriei de serviciu in functie de care filtrati[M/A/H] :");
			 BufferedReader getFiltruCategorie= new BufferedReader(new InputStreamReader (System.in));
			 try {
				 filtruCategorie = new String(getFiltruCategorie.readLine());
			 }
			 catch(IOException e1) {
					e1.printStackTrace();
			 }
		     //Filtrare in fct de categorie
			 Enumeration<tema2_ISP.Rezervari> enumobject = rezervari.elements();  
             int index = 0;
		     while (enumobject.hasMoreElements())   
		     {             
		         if(enumobject.nextElement().getCod_comanda().contains(filtruCategorie)) {
		            vec_rezervari.add(rezervari.get(index));
		         }
		         index++;
		     }
		     return vec_rezervari;
            	 
		 }
		 return vec_rezervari;
	}

	public boolean isValidat() {
		return validat;
	}

	public void setValidat(boolean validat) {
		this.validat = validat;
	}
};
