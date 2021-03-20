package tema2_ISP;

public class RezervariHotel {
	//clasa de asociatie intre OferteSejurHotel si Clienti
	
	private String cod_comanda;
	private String destinatie;
	private OferteSejurHotel oferta_hotel;
	private Client client;
	public RezervariHotel(OferteSejurHotel o_hotel, Client client, String cod_comanda2) {
		// TODO Auto-generated constructor stub
		this.setClient(client);
		this.setOferta_hotel(o_hotel);
		this.setCod_comanda(cod_comanda2);
		this.setDestinatie(client.getDestinatie_curenta());
		System.out.println("Rezervare Sejut Hotel Realizata. Veti fi notificat in momentul care se va valida/invalida rezervarea!");
		//new Rezervari(this,this.getCod_comanda(),tema2_ISP.Categorie_Oferta.SejurHotel);
	}
	public String getCod_comanda() {
		return cod_comanda;
	}
	public void setCod_comanda(String cod_comanda) {
		this.cod_comanda = cod_comanda;
	}
	public String getDestinatie() {
		return destinatie;
	}
	public void setDestinatie(String destinatie) {
		this.destinatie = destinatie;
	}
	public Client getClient() {
		return client;
	}
	public void setClient(Client client) {
		this.client = client;
	}
	public OferteSejurHotel getOferta_hotel() {
		return oferta_hotel;
	}
	public void setOferta_hotel(OferteSejurHotel oferta_hotel) {
		this.oferta_hotel = oferta_hotel;
	}
}
