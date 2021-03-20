package testeGenerareComanda;

import static org.junit.Assert.*;

import java.io.ByteArrayInputStream;
import java.io.InputStream;

import org.junit.Rule;
import org.junit.Test;
import org.junit.rules.ExpectedException;

import tema2_ISP.Administrator;
import tema2_ISP.AgentTurism;
import tema2_ISP.Aplicatie;
import tema2_ISP.Client;
import tema2_ISP.Rezervari;

public class Test2 {
	@Rule
    ExpectedException exitCall = ExpectedException.none();
	@Test
	public void testMain() {
				//TESTE DE VALIDARE FLOW COMANDA
				//SE TESTEAZA MOMENTAN DOAR PARTEA DE VALIDARE A COMENZII IN DIVERSE CONTEXTE
				String sep = System.getProperty("line.separator");
								
								
				//TEST 1 -- exista oferte in sistem adaugate de administrator in sistem
				//		 -- utilizatorul incearca sa acceseze aceasta oferta pentru vizualizare detalii inainte de comanda
				//       -- utilizatorul nu doreste sa realizeze comanda 
				//       -- programul se inchide cu succes in momentul in care utilizatorul alege o alta optiune decat cele posibile.
				String simulatedUserInput1 = "admin" + sep + "admin" + sep + "ADMIN"+ sep + 
								"8" + sep + "M"+sep + "10"+sep + "2" + sep + "19.8" + sep + "BMW" + sep + "5"+sep +"3"+
								"c1@gmail.com"+sep+"passC1"+sep+"CLIENT"+sep+
								"4"+sep+"M"+sep + "Cairo" + sep + "n" + sep + "1" + sep + "M1" + sep + "6";
				java.io.InputStream savedStandardInputStream1 = System.in;
				System.setIn(new ByteArrayInputStream(simulatedUserInput1.getBytes()));
				System.setIn(savedStandardInputStream1);
				exitCall.expectMessage("");//PASSED
				
				
				//TEST 3 -- se realizeaza o comanda care este apoi invalidata de Agent Turism 
				//creare obiect admin
				Administrator admin = new Administrator("admin","admin","Administrator");
				//adaugare oferta
				
				InputStream sysInBackup = System.in;
				ByteArrayInputStream in = new ByteArrayInputStream(("BMW" + sep + "10").getBytes());
				System.setIn(in);
				
				admin.adaugareOferta(tema2_ISP.Categorie_Oferta.InchiriereMasina, "stoc:3,discount:5,pret:20");
				
				System.setIn(sysInBackup);
				
				//aici tre sa pun cumva 2 input-uri gen automat si nush cum
				tema2_ISP.Oferte offer = Administrator.oferte.get(Administrator.oferte.size()-1);
				assertNotNull(offer);
				//verificare ca oferta a fost adaugata
				//logare client
				Client c = new Client("c1@gmail.com","passC1","CLIENT");
				//creare rezervare client
				Rezervari rezervare_client = new Rezervari(c, offer, "M1B10", tema2_ISP.Categorie_Oferta.InchiriereMasina ,10);
				AgentTurism agent_nou = new AgentTurism("a1@gmail.com","a1","Agent Turism");
		    	Aplicatie.agenti_turism.add(agent_nou);
		    	assertNotNull(agent_nou);
				//adaugare rezervare in view pwntru agenti
				AgentTurism.rezervari.add(rezervare_client);
				//agentul valideaza rezervarea
				agent_nou.validareRezervare("c1@gmail.com", "M1B10", AgentTurism.rezervari);
		    	
				assertFalse(agent_nou.isValidat()); //PASSED
				
				//TEST 4 -- VALIDARE REZERVARE VALIDA CREATA DE UTILIZATOR
				//creare obiect admin
				Administrator admin1 = new Administrator("admin","admin","Administrator");
				//adaugare oferta
				InputStream sysInBackup2 = System.in;
				ByteArrayInputStream in2 = new ByteArrayInputStream(("BMW" + sep + "30").getBytes());
				System.setIn(in2);
				admin1.adaugareOferta(tema2_ISP.Categorie_Oferta.InchiriereMasina, "stoc:14,discount:5,pret:20");
				
				System.setIn(sysInBackup2);
				//aici tre sa pun cumva 2 input-uri gen automat si nush cum
				tema2_ISP.Oferte offer1 = Administrator.oferte.get(Administrator.oferte.size()-1);
				assertNotNull(offer1);
						
				//verificare ca oferta a fost adaugata
				//logare client
				Client c1 = new Client("c1@gmail.com","passC1","CLIENT");
				//Create rezervare client
				Rezervari rezervare_client1 = new Rezervari(c1, offer1, "M1B10", tema2_ISP.Categorie_Oferta.InchiriereMasina ,10);
				AgentTurism agent_nou1 = new AgentTurism("a1@gmail.com","a1","Agent Turism");
				Aplicatie.agenti_turism.add(agent_nou);
				assertNotNull(agent_nou);
				//adaugare rezervare in view pwntru agenti
				AgentTurism.rezervari.add(rezervare_client1);
				//agentul valideaza rezervarea
				agent_nou.validareRezervare("c1@gmail.com", "M1B10", AgentTurism.rezervari);
				    	
				assertTrue(agent_nou.isValidat()); //PASSED
				
				//TEST 5 -- utilizatorul incearca sa realizeze o comanda care este apoi abandonata fix inainte de filtrare
				String simulatedUserInput5 = "admin" + sep + "admin" + sep + "ADMIN"+ sep + 
				"8" + sep + "A"+sep + "10"+sep + "2" + sep + "19.8" + sep + "5" + sep + "Business"+sep +"6:45"+ sep + "Hawaii" + sep + "3" +
				"c1@gmail.com"+sep+"passC1"+sep+"CLIENT"+sep+
				"4"+sep+"A"+sep + "n" + sep + "2" + sep + "A1" + sep + "12" + sep + "n" + sep + "6";
				java.io.InputStream savedStandardInputStream5 = System.in;
				System.setIn(new ByteArrayInputStream(simulatedUserInput5.getBytes()));
				System.setIn(savedStandardInputStream5);
				exitCall.expectMessage(""); //PASSED
	}

}
