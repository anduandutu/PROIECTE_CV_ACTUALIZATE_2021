// --------------------------------------------------------
// Code generated by Papyrus Java
// --------------------------------------------------------

package tema2_ISP;

/************************************************************/
/**
 * 
 */
public class OferteBiletAvion extends tema2_ISP.Oferte {
	OferteBiletAvion(tema2_ISP.Categorie_Oferta categorie, String detalii_oferta) {
		super(categorie, detalii_oferta);
		// TODO Auto-generated constructor stub
	}

	/**
	 * 
	 */
	private String clasa_zbor;
	private int nrEscale;
	private String unitate_pret = "None";
	private String ora_decolare;
	private String destinatie;

	
	public String getDestinatie() {
		return destinatie;
	}
	public void setDestinatie(String dest) {
		this.destinatie = dest;
	}
	public String getUnitate_pret() {
		return unitate_pret;
	}

	public void setUnitate_pret(String unitate_pret) {
		this.unitate_pret = unitate_pret;
	}

	public float getPret_unitar() {
		return super.Pret;
	}

	public int getNrEscale() {
		return nrEscale;
	}

	public void setNrEscale(int nrEscale) {
		this.nrEscale = nrEscale;
	}

	public String getClasa_zbor() {
		return clasa_zbor;
	}

	public void setClasa_zbor(String clasa_zbor) {
		this.clasa_zbor = clasa_zbor;
	}

	public String getOra_decolare() {
		return ora_decolare;
	}

	public void setOra_decolare(String ora_decolare) {
		this.ora_decolare = ora_decolare;
	}
};