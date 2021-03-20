package testeGenerareComanda;

import static org.junit.Assert.*;

import java.util.Vector;

import org.junit.Test;

import tema2_ISP.Client;
import tema2_ISP.OferteBiletAvion;
import tema2_ISP.OferteMasini;
import tema2_ISP.OferteSejurHotel;

public class Test1 {
	//teste legate de realizarea unei rezervari fara posibilitatea selectarii unei oferte.
	//TESTE REALIZATE PENTRU FIECARE TIP POSIBIL DE REZERVARE
	@Test
	public void testRezervareMasina() {
		//CAZ TEST 1
		String sep = System.getProperty("line.separator");
		Client c1 = new Client("client3","c3","CLIENT_C");
		c1.login("client3", "c3");	
		Vector<OferteMasini> oferte_masini = c1.oferteVizualizateMasini;
		assertEquals(oferte_masini.size(),0);
	}

	@Test
	public void testRezervareHotel() {
		// CAZ TEST 1 HOTEL	
		Client c1 = new Client("client1","c1","CLIENT_C");
		c1.login("client1", "c1");
		Vector<OferteSejurHotel> oferte_hotel = c1.oferteVizualizateSejurHotel;
		assertEquals(oferte_hotel.size(),0);
	}

	@Test
	public void testRezervareAvion() {
		
		// CAZ TEST 1 AVION
		
		//Un client nu poate vizualiza oferte in primul rand si nici genera comenzi daca nu exista 
		//cumva oferte
		//Intrucat vizualizarea ofertelor si generarea de comenzi porneste de la afisarea listei de oferte 
		//vom verifica lungimea listei de oferte, iar daca este 0 cand admin-ul nu 
		// a adauagat oferte, automat testul trebuie sa treaca
		
		Client c1 = new Client("client","c","CLIENT_C");
		c1.login("client", "c");
		Vector<OferteBiletAvion> oferte_avion = c1.oferteVizualizateBiletAvion;
		assertEquals(oferte_avion.size(),0);	
		
	}

}
