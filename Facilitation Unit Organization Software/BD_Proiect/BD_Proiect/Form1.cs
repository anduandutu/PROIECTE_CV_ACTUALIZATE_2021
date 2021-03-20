using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BD_Proiect
{
    public partial class Form1 : Form
    {
        public static int id;
        public Form1()
        {
            InitializeComponent();
        }

        private void splitContainer1_Panel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void splitContainer1_Panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string email = textBox1.Text;
            string password = textBox2.Text;
            //clientul va fi redirectionat catre forma de inregistrare daca nu exista
            //daca exista insa, el va fi trimis catre o lista cu posibilele camere , respectiv detalii despre ele
            Users a = new Users(email, password);
            //se verifica existenta utilizatorului ca angajat
            //sau ca si client in sistem 
            bool angajat = a.checkExistanceEmployeeLogin(email,password);
            bool client = a.checkClient(email, password);
            if(client == true)
            {
                //Daca este client este redirectionat catre forma Bifurcatie.cs
                id = a.getID_Clienti(email, password);
                //Realizare_programare programare = new Realizare_programare();
                Bifurcatie alegere_optiune = new Bifurcatie();
                this.Hide();
                alegere_optiune.Show();
                //programare.Show();
            }
            else
            {
                //daca este angajat se face diferentierea in functie de tipul de utilizator 
                //utilizator privilegiat -- Manager si CEO
                //utilizator semi-privilegiat -- Receptioner
                //utilizator neprivilegiat -- Bicatar si Menajera
                if (angajat == true)
                {
                    //se vor crea forme pentru diferentiere date CEO/Manager/Administrator/Menaj/Bucatar
                    bool suntCEO = a.checkIsCEO(email, password);
                    bool suntManagerDepartament = a.checkIsManager(email, password);
                    bool suntReceptia = a.checkIsReceptie(email, password);
                    bool suntServiciiMenaj = a.checkServiciiMenaj(email, password);
                    if (suntCEO == true)
                    {
                        id = a.getID_Angajat(email, password);
                        MessageBox.Show("Buna ziua! Sunteti CEO hotel ! Va dorim o zi frumoasa!");
                        ManagementCEO ceo = new ManagementCEO();
                        this.Hide();
                        ceo.Show();
                    }
                    else
                    {
                        MessageBox.Show("Nu sunteti CEO");
                        if(suntManagerDepartament == true)
                        {
                            id = a.getID_Angajat(email, password);
                            MessageBox.Show("Buna ziua, sa aveti o zi frumoasa , dle Manager!");
                            ManagementManager manager = new ManagementManager();
                            this.Hide();
                            manager.Show();
                        }
                        else
                        {
                            MessageBox.Show("Nu sunteti nici manager");
                            if(suntReceptia == true)
                            {
                                id = a.getID_Angajat(email, password);
                                MessageBox.Show("Buna ziua! Aici receptia hotelului!");
                                Receptie receptie = new Receptie();
                                this.Hide();
                                receptie.Show();
                            }
                            else
                            {
                                if(suntServiciiMenaj == true)
                                {
                                    id = a.getID_Angajat(email, password);
                                    Setare_program_menaj_camere menaj = new Setare_program_menaj_camere();
                                    this.Hide();
                                    menaj.Show();
                                }
                                else
                                {
                                    MessageBox.Show("Nu existati in sistem!");
                                    this.Hide();
                                    Inregistrare_utilizator inregistrarePersoana = new Inregistrare_utilizator();
                                    MessageBox.Show("Se pare ca nu exista o inregistrare cu email-ul si parola furnizate . Veti fi redirectionat catre forma de inregistrare.");
                                    inregistrarePersoana.Show();
                                }
                            }
                        }
                    }
                }
                else
                {
                    //daca nu exista utilizatorul sub nicio forma in sistem, el este pus sa se inregistreze 
                    //fiind redirectionat catre Inregistrare_Utilizator.cs
                    this.Hide();
                    Inregistrare_utilizator inregistrareClient = new Inregistrare_utilizator();
                    MessageBox.Show("Se pare ca nu exista o inregistrare cu email-ul si parola furnizate . Veti fi redirectionat catre forma de inregistrare.");
                    inregistrareClient.Show();
                }
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
