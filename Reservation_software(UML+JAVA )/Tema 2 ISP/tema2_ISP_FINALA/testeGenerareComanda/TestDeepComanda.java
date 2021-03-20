package testeGenerareComanda;

import static org.junit.Assert.*;

import java.io.ByteArrayInputStream;
import java.io.InputStream;
import java.util.Vector;

import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import tema2_ISP.*;

public class TestDeepComanda {
	//TESTARE UNITARA A METODELOR CE IMPLICA GENERAREA UNEI REZERVARI
	//ADICA REZERVARE MASINA ,PLATA MASINA , isValidat din agent turism
	Client client_test;
	OferteBiletAvion oferta_avion_test;
	tema2_ISP.OferteMasini oferta_masina_test;
	@BeforeClass
	public static void setup() {
		String sep = System.getProperty("line.separator");
		Administrator admin1 = new Administrator("admin","admin","Administrator");
		//INPUT-uri automate
		InputStream sysInBackup = System.in;
		ByteArrayInputStream in = new ByteArrayInputStream(("BMW" + sep + "3").getBytes());
		System.setIn(in);
		
		admin1.adaugareOferta(tema2_ISP.Categorie_Oferta.InchiriereMasina, "stoc:14,discount:5,pret:20");
		
		System.setIn(sysInBackup);
		
		InputStream sysInBackup1 = System.in;
		ByteArrayInputStream in1 = new ByteArrayInputStream(("Logan" + sep + "10").getBytes());
		System.setIn(in1);
		admin1.adaugareOferta(tema2_ISP.Categorie_Oferta.InchiriereMasina, "stoc:16,discount:5,pret:20");
		System.setIn(sysInBackup1);
		
		InputStream sysInBackup2 = System.in;
		ByteArrayInputStream in2 = new ByteArrayInputStream(("Matrimonial" + sep + "Jacuzzi" + sep + "Constanta").getBytes());
		System.setIn(in2);
		admin1.adaugareOferta(tema2_ISP.Categorie_Oferta.SejurHotel, "stoc:30,discount:1,pret:60");
		System.setIn(sysInBackup2);
		
		InputStream sysInBackup3 = System.in;
		ByteArrayInputStream in3 = new ByteArrayInputStream(("Matrimonial" + sep + "Jacuzzi" + sep + "Neptun").getBytes());
		System.setIn(in3);
		admin1.adaugareOferta(tema2_ISP.Categorie_Oferta.SejurHotel, "stoc:32,discount:1,pret:60");		
		System.setIn(sysInBackup3);
		
		InputStream sysInBackup4 = System.in;
		ByteArrayInputStream in4 = new ByteArrayInputStream(("1" + sep + "I" + sep + "3:45" + sep + "Neptun").getBytes());
		System.setIn(in4);
		admin1.adaugareOferta(tema2_ISP.Categorie_Oferta.RezervareBiletAvion, "stoc:21,discount:10,pret:40");
		System.setIn(sysInBackup4);
		
		InputStream sysInBackup5 = System.in;
		ByteArrayInputStream in5 = new ByteArrayInputStream(("3" + sep + "Econom" + sep + "6:45" + sep + "Madrid").getBytes());
		System.setIn(in5);
		admin1.adaugareOferta(tema2_ISP.Categorie_Oferta.RezervareBiletAvion, "stoc:32,discount:10,pret:40");
		System.setIn(sysInBackup5);
	}
	
	
	@Test
	public void testRezervareMasina() {
		//CAZ TEST 2 si 3
		//se logheaza un client 
		Client c2 = new Client("client3","c3","CLIENT_C");
		c2.login("client3", "c3");
		//si vede exact 2 oferte de tip avion
		Vector<OferteMasini> oferte_m= c2.oferteVizualizateMasini;
				
		//incearca sa realizeze o rezervare de tip sejur hotel
		c2.rezervareMasina(oferte_m.get(oferte_m.size()-1), "M205");
				
		//rezervarea a fost adaugata in vectorul de rezervari cu succes
		assertNotNull(c2.rezervariMasini.get(c2.rezervariMasini.size()-1));
				
		//rezervarea creata este realizata cu codul de comanda corect
		assertEquals("M205",c2.rezervariMasini.get(c2.rezervariMasini.size()-1).getCod_comanda());
		
		
	}

	@Test
	public void testRezervareHotel() {
		//CAZ TEST 2 si 3
		//se logheaza un client 
		Client c2 = new Client("client1","c1","CLIENT_C");
		c2.login("client1", "c1");
				
		//si vede exact 2 oferte de tip avion
		Vector<OferteSejurHotel> oferte_h= c2.oferteVizualizateSejurHotel;
		//assertEquals(oferte_h.size(),1);
				
		//incearca sa realizeze o rezervare de tip sejur hotel
		c2.rezervareHotel(oferte_h.get(oferte_h.size()-1), "H215");
				
		//rezervarea a fost adauhgata in vectorul de rezervari cu succes
		assertNotNull(c2.rezervariHotel.get(c2.rezervariHotel.size()-1));
				
		//rezervarea creata este realizata cu codul de comanda corect
		assertEquals("H215",c2.rezervariHotel.get(c2.rezervariHotel.size()-1).getCod_comanda());
	}

	@Test
	public void testRezervareAvion() {
		//CAZ TEST 2 SI 3 --- realizare rezervare fara validare 
		//		 		  --- se va actualiza vectorul de rezervari al clientului pe categoria de rezervare realizata
		//                --- nu se va actualiza vectorul de rezervari al clientului pe AgentTurism intrucat nu s-a efectuat inca etapa de plata 
		//                --- a comenzii
		//se logheaza un client 
		Client c2 = new Client("client","c","CLIENT_C");
		c2.login("client", "c");
		//si vede exact 2 oferte de tip avion
		Vector<OferteBiletAvion> oferte_a= c2.oferteVizualizateBiletAvion;
		//incearca sa realizeze o rezervare de tip bilet avion
		c2.rezervareAvion(oferte_a.get(oferte_a.size()-1), "A210");
		//rezervarea a fost adauhgata in vectorul de rezervari cu succes
		assertNotNull(c2.rezervariAvion.get(c2.rezervariAvion.size()-1));
		//rezervarea creata este realizata cu codul de comanda corect
		assertEquals("A210",c2.rezervariAvion.get(c2.rezervariAvion.size()-1).getCod_comanda());
	}

	@Test
	public void testPlata_comandaAvion() {
		//CAZ TEST 2 SI 3 --- realizare rezervare fara validare 
		//		 		  --- se va actualiza vectorul de rezervari al clientului pe categoria de rezervare realizata
		//                --- nu se va actualiza vectorul de rezervari al clientului pe AgentTurism intrucat nu s-a efectuat inca etapa de plata 
		//                --- a comenzii
		//se logheaza un client 
		
		String sep = System.getProperty("line.separator");
		
		Client c2 = new Client("client6","c6","CLIENT_C");
		c2.login("client6", "c6");
		//si vede exact 2 oferte de tip avion
		Vector<OferteBiletAvion> oferte_a= c2.oferteVizualizateBiletAvion;
		//incearca sa realizeze o rezervare de tip bilet avion
		c2.rezervareAvion(oferte_a.get(oferte_a.size()-1), "A220");
		//rezervarea a fost adauhgata in vectorul de rezervari cu succes
		assertNotNull(c2.rezervariAvion.get(c2.rezervariAvion.size()-1));
		//rezervarea creata este realizata cu codul de comanda corect
		assertEquals("A220",c2.rezervariAvion.get(c2.rezervariAvion.size()-1).getCod_comanda());
						
		//se creeaza un agent de turism
		AgentTurism agent_nou = new AgentTurism("a1@gmail.com","a1","Agent Turism");
		Aplicatie.agenti_turism.add(agent_nou);
		assertNotNull(agent_nou);
				    	
		//verificam ca agentul de turism vede rezervarea realizata de client
		Vector<Rezervari> rezervariCurente = AgentTurism.rezervari;
						
		//daca nu exista , se continua cu plata
		InputStream sysInBackup_a = System.in;
		ByteArrayInputStream in_a = new ByteArrayInputStream(("23" + sep + "y").getBytes());
		System.setIn(in_a);
		
		c2.plata_comandaAvion(oferte_a.get(oferte_a.size()-1));
		System.setIn(sysInBackup_a);
		
		//cream un agent de turism 
		assertTrue(rezervariCurente.size()>0);
				    	
		//verificam ca exista o rezervare la agentul de turism
		assertNotNull(rezervariCurente.get(rezervariCurente.size()-1));
				    	
		//verificam ca corespund datele (adica rezervarea adaugata este cea de la clientul care a comandat)
		assertEquals("client6",rezervariCurente.get(rezervariCurente.size()-1).get_comanda_client().Email);
		
		//Detalii comanda
		int stoc = rezervariCurente.get(rezervariCurente.size()-1).getOferta_solicitata().getStoc() - rezervariCurente.get(rezervariCurente.size()-1).getCantitate_solicitata();
	    //agentul valideaza rezervarea
		agent_nou.validareRezervare(rezervariCurente.get(rezervariCurente.size()-1).get_comanda_client().Email, rezervariCurente.get(rezervariCurente.size()-1).getCod_comanda(), AgentTurism.rezervari);
		
		boolean chestie = agent_nou.isValidat();
	    //validarea se face in functie de stocul curent al ofertei cerute
		if(chestie) {
			assertTrue(agent_nou.isValidat()); //PASSED
		}
		else {
			assertFalse(agent_nou.isValidat()); //PASSED
		}
	}

	@Test
	public void testPlata_comandaMasina() {
		String sep = System.getProperty("line.separator");
		Client c2 = new Client("client3","c3","CLIENT_C");
		c2.login("client3", "c3");
		//si vede exact 2 oferte de tip avion
		Vector<OferteMasini> oferte_m= c2.oferteVizualizateMasini;
		
		//incearca sa realizeze o rezervare de tip sejur hotel
		c2.rezervareMasina(oferte_m.get(oferte_m.size()-1), "M205");
		
		//rezervarea a fost adaugata in vectorul de rezervari cu succes
		assertNotNull(c2.rezervariMasini.get(c2.rezervariMasini.size()-1));
		
		//rezervarea creata este realizata cu codul de comanda corect
		assertEquals("M205",c2.rezervariMasini.get(c2.rezervariMasini.size()-1).getCod_comanda());
		
		//se creeaza un agent de turism
		AgentTurism agent_nou = new AgentTurism("a3@gmail.com","a3","Agent Turism");
    	Aplicatie.agenti_turism.add(agent_nou);
    	assertNotNull(agent_nou);
    	//momentan nu avem rezervare pentru ca rezervarea nu a fost finalizata(adica mai are plata clientul)
    	
    	//verificam ca agentul de turism vede rezervarea realizata de client
    	Vector<Rezervari> rezervariCurente = agent_nou.rezervari;
		
    	InputStream sysInBackup_m = System.in;
		ByteArrayInputStream in_m = new ByteArrayInputStream(("23" + sep + "y").getBytes());
		System.setIn(in_m);
    	//daca nu exista , se continua cu plata
		c2.plata_comandaMasina(oferte_m.get(oferte_m.size()-1));
		System.setIn(sysInBackup_m);
		//cream un agent de turism 
    	assertTrue(rezervariCurente.size()>0);
    	
    	//verificam ca exista o rezervare la agentul de turism
    	assertNotNull(rezervariCurente.get(rezervariCurente.size()-1));
    	
    	//verificam ca corespund datele (adica rezervarea adaugata este cea de la clientul care a comandat)
    	assertEquals("client3",rezervariCurente.get(rezervariCurente.size()-1).get_comanda_client().Email);
		//agentul valideaza rezervarea
		agent_nou.validareRezervare(rezervariCurente.get(rezervariCurente.size()-1).get_comanda_client().Email, rezervariCurente.get(rezervariCurente.size()-1).getCod_comanda(), AgentTurism.rezervari);
		
    	//validarea se face in functie de stocul curent al ofertei cerute
		if(rezervariCurente.get(rezervariCurente.size()-1).getOferta_solicitata().getStoc() - rezervariCurente.get(rezervariCurente.size()-1).getCantitate_solicitata() >=0 ) {
			assertTrue(agent_nou.isValidat()); //PASSED
		}
		else {
			assertFalse(agent_nou.isValidat()); //PASSED
		}
	}

	@Test
	public void testPlata_comandaSejurHotel() {
		//CAZ TEST 2 si 3
		//se logheaza un client 
		String sep = System.getProperty("line.separator");
		Client c2 = new Client("client1","c1","CLIENT_C");
		c2.login("client1", "c1");
		
		//si vede exact 2 oferte de tip avion
		Vector<OferteSejurHotel> oferte_h= c2.oferteVizualizateSejurHotel;
		
		//incearca sa realizeze o rezervare de tip sejur hotel
		c2.rezervareHotel(oferte_h.get(oferte_h.size()-1), "H215");
		
		//rezervarea a fost adauhgata in vectorul de rezervari cu succes
		assertNotNull(c2.rezervariHotel.get(c2.rezervariHotel.size()-1));
		
		//rezervarea creata este realizata cu codul de comanda corect
		assertEquals("H215",c2.rezervariHotel.get(c2.rezervariHotel.size()-1).getCod_comanda());
		
		//se creeaza un agent de turism
		AgentTurism agent_nou = new AgentTurism("a2@gmail.com","a2","Agent Turism");
    	Aplicatie.agenti_turism.add(agent_nou);
    	assertNotNull(agent_nou);
    	//momentan nu avem rezervare pentru ca rezervarea nu a fost finalizata(adica mai are plata clientul)
    	
    	
    	//verificam ca agentul de turism vede rezervarea realizata de client
    	Vector<Rezervari> rezervariCurente = agent_nou.rezervari;
    	//assertFalse(rezervariCurente.size() == 0);
		
    	//daca nu exista , se continua cu plata
    	InputStream sysInBackup_h = System.in;
		ByteArrayInputStream in_h = new ByteArrayInputStream(("23" + sep + "y").getBytes());
		System.setIn(in_h);
		c2.plata_comandaSejurHotel(oferte_h.get(oferte_h.size()-1));
		System.setIn(sysInBackup_h);
		//cream un agent de turism 
    	assertTrue(rezervariCurente.size()>0);
    	
    	//verificam ca exista o rezervare la agentul de turism
    	assertNotNull(rezervariCurente.get(rezervariCurente.size()-1));
    	
    	//verificam ca corespund datele (adica rezervarea adaugata este cea de la clientul care a comandat)
    	assertEquals("client1",rezervariCurente.get(rezervariCurente.size()-1).get_comanda_client().Email);
		//agentul valideaza rezervarea
		agent_nou.validareRezervare(rezervariCurente.get(rezervariCurente.size()-1).get_comanda_client().Email, rezervariCurente.get(rezervariCurente.size()-1).getCod_comanda(), AgentTurism.rezervari);
		
    	//validarea se face in functie de stocul curent al ofertei cerute
		if(rezervariCurente.get(rezervariCurente.size()-1).getOferta_solicitata().getStoc() - rezervariCurente.get(rezervariCurente.size()-1).getCantitate_solicitata() >=0 ) {
			assertTrue(agent_nou.isValidat()); //PASSED
		}
		else {
			assertFalse(agent_nou.isValidat()); //PASSED
		}
	}

}
