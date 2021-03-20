package tema2_ISP;

public class RezervariMasini {
	//clasa de asociatie intre OferteMasini si Client
	private String cod_comanda;
	private OferteMasini oferta_masina;
	private Client client;
	
	
	public RezervariMasini(OferteMasini o_masina, Client client, String cod_comanda) {
		// TODO Auto-generated constructor stub
		this.setClient(client);
		this.setCod_comanda(cod_comanda);
		this.setOferta_masina(o_masina);
		System.out.println("Rezervare Masina Realizata. Veti fi notificat in momentul care se va valida/invalida rezervarea!");
		//new Rezervari(this,this.getCod_comanda(),tema2_ISP.Categorie_Oferta.InchiriereMasina);
	}

	public String getCod_comanda() {
		return cod_comanda;
	}

	public void setCod_comanda(String cod_comanda) {
		this.cod_comanda = cod_comanda;
	}

	public OferteMasini getOferta_masina() {
		return oferta_masina;
	}

	public void setOferta_masina(OferteMasini oferta_masina) {
		this.oferta_masina = oferta_masina;
	}

	public Client getClient() {
		return client;
	}

	public void setClient(Client client) {
		this.client = client;
	}
}
