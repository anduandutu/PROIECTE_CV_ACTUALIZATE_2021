package tema2_ISP;

public class RezervariBiletAvion {
	//Intre OferteBiletAvion si Client - clasa de asociatie
	
	private String cod_comanda;
	private String destinatie;
	private OferteBiletAvion oferta;
	private Client client;
	public RezervariBiletAvion(OferteBiletAvion o_avion, Client client, String cod_comanda2) {
		// TODO Auto-generated constructor stub
		this.setOferta(o_avion);
		this.setClient(client);
		this.setCod_comanda(cod_comanda2);
		this.setDestinatie(client.getDestinatie_curenta());
		System.out.println("Rezervare Bilet Avion realizata. Veti fi notificat in momentul care se va valida/invalida rezervarea!");
		//new Rezervari(this,this.getCod_comanda(),tema2_ISP.Categorie_Oferta.RezervareBiletAvion);
	}
	public OferteBiletAvion getOferta() {
		return oferta;
	}
	public void setOferta(OferteBiletAvion oferta) {
		this.oferta = oferta;
	}
	public Client getClient() {
		return client;
	}
	public void setClient(Client client) {
		this.client = client;
	}
	public String getDestinatie() {
		return destinatie;
	}
	public void setDestinatie(String destinatie) {
		this.destinatie = destinatie;
	}
	public String getCod_comanda() {
		return cod_comanda;
	}
	public void setCod_comanda(String cod_comanda) {
		this.cod_comanda = cod_comanda;
	}
}
