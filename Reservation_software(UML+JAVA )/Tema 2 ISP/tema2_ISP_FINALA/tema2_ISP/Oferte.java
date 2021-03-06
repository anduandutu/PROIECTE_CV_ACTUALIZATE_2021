// --------------------------------------------------------
// Code generated by Papyrus Java
// --------------------------------------------------------

package tema2_ISP;

/************************************************************/
/**
 * 
 */
public class Oferte {
	/**
	 * 
	 */
	public float Pret;
	/**
	 * 
	 */
	private String Cod_oferta;
	/**
	 * 
	 */
	public tema2_ISP.Categorie_Oferta Categorie_Oferta;
	/**
	 * 
	 */
	public String Detalii; // va contine doar detalii despre stoc si discount
	/**
	 * 
	 */
	private String discount;
	/**
	 * 
	 */
	private int Stoc;

	/**
	 * 
	 */
	public static int nrOferta = 0;
	Oferte(Categorie_Oferta categorie, String detalii_oferta){
		this.Categorie_Oferta = categorie;
		//@cod_oferta - se va seta in functie de cateogoria de oferta primul caracter va fi M,H sau A(Masina,Hotel,Avion)
		nrOferta++;
		if(categorie == tema2_ISP.Categorie_Oferta.InchiriereMasina) {
			this.setCod_oferta("M",nrOferta);
		}
		else if(categorie == tema2_ISP.Categorie_Oferta.RezervareBiletAvion) {
			this.setCod_oferta("A",nrOferta);
		}
		else if(categorie == tema2_ISP.Categorie_Oferta.SejurHotel) {
			this.setCod_oferta("H",nrOferta);
		}	
		//@detalii oferta vor fi siruri de tipul "Atribut1: valoare, Atribut2: valoare" concatenate 
		this.Detalii = detalii_oferta;
		
		//Pentru obtinerea celorlalte detalii va trebui sa parsam input-ul pentru detalii
		String str = detalii_oferta;
		
        String split[] = str.split(":*,", 0);
        int nrDetalii = split.length;
        String [][] vec_detalii = new String[nrDetalii][nrDetalii-1];
        
        int i = 0;
        for (String s: split){
            String split_again[] = s.split(":",0);
            int j = 0;
            for (String s1: split_again){
                vec_detalii[i][j] = s1;
                j++;
            }
            i++;
        }
        //Generare si atribuire detalii obtinute
        float discount_for_calculation = 0.0f;
        for(int k = 0; k < nrDetalii; k++){
            if(vec_detalii[k][0].equals("stoc")) {
            	//@stoc_curent - valoarea stocului pentru oferta curenta
            	this.setStoc(Integer.parseInt(vec_detalii[k][1].trim()));	
            }
            else if(vec_detalii[k][0].equals("discount")){
            	//@discount_oferta = String cu formatul 'x%'
            	this.setDiscount(vec_detalii[k][1]);
            	discount_for_calculation = Float.parseFloat(vec_detalii[k][1].trim());
            }
            else if(vec_detalii[k][0].equals("pret")){
            	this.Pret = Float.parseFloat(vec_detalii[k][1].trim());
                
            }
        }
      //@pret_final = @pret_final - procentul din String-ul discount_oferta 
        this.Pret = this.Pret - (float)(((float)discount_for_calculation/100.0f)*this.Pret);
	}
	
	
	public void generareDetaliiIncluse() {
		System.out.println("Cod Oferta:"+this.getCod_oferta());
        System.out.println("Stoc oferta: "+this.getStoc());
        System.out.println("Discount: "+this.getDiscount());
        System.out.println("Pret:"+this.Pret);
		
	}

	public String getCod_oferta() {
		return Cod_oferta;
	}

	public void setCod_oferta(String cod_oferta,int nrOffer) {
		Cod_oferta = cod_oferta + String.valueOf(nrOffer);
	}

	public String getDiscount() {
		return discount;
	}

	public void setDiscount(String discount) {
		this.discount = discount + " %";
	}

	public int getStoc() {
		return Stoc;
	}

	public void setStoc(int stoc) {
		Stoc = stoc;
	}
};
