using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace BD_Proiect
{
    public partial class Realizare_programare : Form
    {
        public static int id;
        public Realizare_programare()
        {
            InitializeComponent();
        }

        private void Realizare_programare_Load(object sender, EventArgs e)
        {

            //initializez un data-grid cu camerele disponibile la momentul curent
            label3.Text = Form1.id.ToString();
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
            DataTable dt = new DataTable();
            string query = "SELECT ID_Camera AS Nr_Camera,Tip_camera,Descriere_Facilitati,Nr_Locuri,Disponibilitate,Pret_camera FROM Camere WHERE Disponibilitate = 1;";
            SqlDataAdapter adt = new SqlDataAdapter(query,connstring);
            adt.Fill(dt);
            dataGridView1.DataSource = dt;
            
        }
       // public int index;
        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            
            //creez o tabela intermediara pentru memorare date solicitate
            Camere camera = new Camere();//ne va ajuta pentru update-ul disponibilitatii camerei in timp real
            DataTable intermediar = new DataTable();
            intermediar.Columns.Add("Nr_Camera");
            intermediar.Columns.Add("Tip_Camera");
            intermediar.Columns.Add("Descriere_Facilitati");
            intermediar.Columns.Add("Nr_locuri");
            intermediar.Columns.Add("Pret/noapte");
            for (int i = 0; i < dataGridView1.Rows.Count; i++)
            { 
                DataGridViewCheckBoxCell cell =dataGridView1.Rows[i].Cells[0] as DataGridViewCheckBoxCell;
                if (cell.Value == cell.TrueValue)
                {
                    //si se face camera indisponibila daca aceasta a fost programata
                    camera.setDisponibilitate(0,(int) dataGridView1.Rows[i].Cells[1].Value);
                    DataRow row = intermediar.NewRow();
                    row["Nr_camera"] = (int)dataGridView1.Rows[i].Cells[1].Value;
                    row["Tip_Camera"] = dataGridView1.Rows[i].Cells[2].Value;
                    row["Descriere_Facilitati"] = dataGridView1.Rows[i].Cells[3].Value;
                    row["Nr_locuri"] = dataGridView1.Rows[i].Cells[4].Value;
                    row["Pret/noapte"] = dataGridView1.Rows[i].Cells[6].Value;
                    intermediar.Rows.Add(row);

                }
            }
            //memorez intr-un datatable camerele selectate pentru programari de catre client 
            //urmeaza posinbilitatea stergerii unei comenzi in cazul in care a aparut o greseala
            dataGridView2.DataSource = intermediar;
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
            DataTable dt = new DataTable();
            string query = "SELECT ID_Camera,Tip_camera,Descriere_Facilitati,Nr_Locuri,Disponibilitate,Pret_camera FROM Camere WHERE Disponibilitate = 1;";
            SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
            adt.Fill(dt);
            dataGridView1.DataSource = dt;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Camere camera1 = new Camere();
            for (int i = 0; i < dataGridView2.Rows.Count; i++)
            {
                DataGridViewCheckBoxCell cell = dataGridView2.Rows[i].Cells[0] as DataGridViewCheckBoxCell;
                if (cell.Value == cell.TrueValue)
                {
                    camera1.setDisponibilitate(1,Convert.ToInt32(dataGridView2.Rows[i].Cells[1].Value));
                    dataGridView2.Rows.RemoveAt(i);
                    //DELETE DIN Facturi
                }
            }
            //preiau din baza de date
            
            string query = "SELECT ID_Camera,Tip_camera,Descriere_Facilitati,Nr_Locuri,Disponibilitate,Pret_camera FROM Camere WHERE Disponibilitate = 1;";
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
            DataTable dt = new DataTable();
            SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
            adt.Fill(dt);
            dataGridView1.DataSource = dt;
        }

        private void dataGridView2_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void checkedListBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            //facem operatii de tip SELECT pentru filtrarea informatiilor prezentate 
            //in functie de criteriul de filtrare selectat pret/ nr_locuri_camera
            bool criteriu_pret700 = false;
            bool criteriu700_1000 = false;
            bool criteriu1000_1200 = false;
            bool criteriu_peste1200 = false;

            bool criteriu2pers = false;
            bool criteriu3pers = false;
            bool criteriu4pers = false;
            bool criteriu_mai_mult_4pers = false;
            if (checkedListBox1.GetItemCheckState(0) == CheckState.Checked)
            {
                criteriu_pret700 = true;
            }
            if (checkedListBox1.GetItemCheckState(1) == CheckState.Checked)
            {
                criteriu700_1000 = true;
            }
            if (checkedListBox1.GetItemCheckState(2) == CheckState.Checked)
            {
                criteriu1000_1200 = true;
            }
            if (checkedListBox1.GetItemCheckState(3) == CheckState.Checked)
            {
                criteriu_peste1200 = true;
            }
            if (checkedListBox2.GetItemCheckState(0) == CheckState.Checked)
            {
                criteriu2pers = true;

            }
            if (checkedListBox2.GetItemCheckState(1) == CheckState.Checked)
            {
                criteriu3pers = true;
            }
            if (checkedListBox2.GetItemCheckState(2) == CheckState.Checked)
            {
                criteriu4pers = true;
            }
            if (checkedListBox2.GetItemCheckState(3) == CheckState.Checked)
            {
                criteriu_mai_mult_4pers = true;
            }
            string query;
            if(criteriu2pers == true)
            {
                if(criteriu_pret700 == true)
                {
                    query = "SELECT ID_Camera,Tip_camera,Descriere_Facilitati,Nr_Locuri,Disponibilitate,Pret_camera FROM Camere WHERE Disponibilitate = 1 AND Nr_locuri = 2 AND Pret_camera<700;";
                    string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
                    DataTable dt = new DataTable();
                    SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
                    adt.Fill(dt);
                    dataGridView1.DataSource = dt;
                }
                else if(criteriu700_1000 == true)
                {
                    query = "SELECT ID_Camera,Tip_camera,Descriere_Facilitati,Nr_Locuri,Disponibilitate,Pret_camera FROM Camere WHERE Disponibilitate = 1 AND Nr_locuri = 2 AND Pret_camera BETWEEN 700 AND 1000; ";
                    string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
                    DataTable dt = new DataTable();
                    SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
                    adt.Fill(dt);
                    dataGridView1.DataSource = dt;
                }
                else if(criteriu1000_1200 == true)
                {
                    query = "SELECT ID_Camera, Tip_camera, Descriere_Facilitati, Nr_Locuri, Disponibilitate, Pret_camera FROM Camere WHERE Disponibilitate = 1 AND Nr_locuri = 2 AND Pret_camera BETWEEN 1000 AND 1200;";
                    string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
                    DataTable dt = new DataTable();
                    SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
                    adt.Fill(dt);
                    dataGridView1.DataSource = dt;
                }
                else if(criteriu_peste1200 == true)
                {
                    query = "SELECT ID_Camera, Tip_camera, Descriere_Facilitati, Nr_Locuri, Disponibilitate, Pret_camera FROM Camere WHERE Disponibilitate = 1 AND Nr_locuri = 2 AND Pret_camera > 1200;";
                    string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
                    DataTable dt = new DataTable();
                    SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
                    adt.Fill(dt);
                    dataGridView1.DataSource = dt;
                }
                else
                {
                    query = "SELECT ID_Camera, Tip_camera, Descriere_Facilitati, Nr_Locuri, Disponibilitate, Pret_camera FROM Camere WHERE Disponibilitate = 1 AND Nr_locuri = 2 ;";
                    string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
                    DataTable dt = new DataTable();
                    SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
                    adt.Fill(dt);
                    dataGridView1.DataSource = dt;

                }
            }
            else if(criteriu3pers == true)
            {
                if (criteriu_pret700 == true)
                {
                    query = "SELECT ID_Camera,Tip_camera,Descriere_Facilitati,Nr_Locuri,Disponibilitate,Pret_camera FROM Camere WHERE Disponibilitate = 1 AND Nr_locuri = 3 AND Pret_camera<700;";
                    string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
                    DataTable dt = new DataTable();
                    SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
                    adt.Fill(dt);
                    dataGridView1.DataSource = dt;
                }
                else if (criteriu700_1000 == true)
                {
                    query = "SELECT ID_Camera,Tip_camera,Descriere_Facilitati,Nr_Locuri,Disponibilitate,Pret_camera FROM Camere WHERE Disponibilitate = 1 AND Nr_locuri = 3 AND Pret_camera BETWEEN 700 AND 1000; ";
                    string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
                    DataTable dt = new DataTable();
                    SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
                    adt.Fill(dt);
                    dataGridView1.DataSource = dt;
                }
                else if (criteriu1000_1200 == true)
                {
                    query = "SELECT ID_Camera, Tip_camera, Descriere_Facilitati, Nr_Locuri, Disponibilitate, Pret_camera FROM Camere WHERE Disponibilitate = 1 AND Nr_locuri = 3 AND Pret_camera BETWEEN 1000 AND 1200;";
                    string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
                    DataTable dt = new DataTable();
                    SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
                    adt.Fill(dt);
                    dataGridView1.DataSource = dt;
                }
                else if (criteriu_peste1200 == true)
                {
                    query = "SELECT ID_Camera, Tip_camera, Descriere_Facilitati, Nr_Locuri, Disponibilitate, Pret_camera FROM Camere WHERE Disponibilitate = 1 AND Nr_locuri = 3 AND Pret_camera > 1200;";
                    string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
                    DataTable dt = new DataTable();
                    SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
                    adt.Fill(dt);
                    dataGridView1.DataSource = dt;
                }
                else
                {
                    query = "SELECT ID_Camera, Tip_camera, Descriere_Facilitati, Nr_Locuri, Disponibilitate, Pret_camera FROM Camere WHERE Disponibilitate = 1 AND Nr_locuri = 3;";
                    string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
                    DataTable dt = new DataTable();
                    SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
                    adt.Fill(dt);
                    dataGridView1.DataSource = dt;

                }
            }
            else if(criteriu4pers == true)
            {
                if (criteriu_pret700 == true)
                {
                    query = "SELECT ID_Camera,Tip_camera,Descriere_Facilitati,Nr_Locuri,Disponibilitate,Pret_camera FROM Camere WHERE Disponibilitate = 1 AND Nr_locuri = 4 AND Pret_camera<700;";
                    string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
                    DataTable dt = new DataTable();
                    SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
                    adt.Fill(dt);
                    dataGridView1.DataSource = dt;
                }
                else if (criteriu700_1000 == true)
                {
                    query = "SELECT ID_Camera,Tip_camera,Descriere_Facilitati,Nr_Locuri,Disponibilitate,Pret_camera FROM Camere WHERE Disponibilitate = 1 AND Nr_locuri = 4 AND Pret_camera BETWEEN 700 AND 1000; ";
                    string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
                    DataTable dt = new DataTable();
                    SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
                    adt.Fill(dt);
                    dataGridView1.DataSource = dt;
                }
                else if (criteriu1000_1200 == true)
                {
                    query = "SELECT ID_Camera, Tip_camera, Descriere_Facilitati, Nr_Locuri, Disponibilitate, Pret_camera FROM Camere WHERE Disponibilitate = 1 AND Nr_locuri = 4 AND Pret_camera BETWEEN 1000 AND 1200;";
                    string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
                    DataTable dt = new DataTable();
                    SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
                    adt.Fill(dt);
                    dataGridView1.DataSource = dt;
                }
                else if (criteriu_peste1200 == true)
                {
                    query = "SELECT ID_Camera, Tip_camera, Descriere_Facilitati, Nr_Locuri, Disponibilitate, Pret_camera FROM Camere WHERE Disponibilitate = 1 AND Nr_locuri = 4 AND Pret_camera > 1200;";
                    string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
                    DataTable dt = new DataTable();
                    SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
                    adt.Fill(dt);
                    dataGridView1.DataSource = dt;
                }
                else
                {
                    query = "SELECT ID_Camera, Tip_camera, Descriere_Facilitati, Nr_Locuri, Disponibilitate, Pret_camera FROM Camere WHERE Disponibilitate = 1 AND Nr_locuri = 4;";
                    string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
                    DataTable dt = new DataTable();
                    SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
                    adt.Fill(dt);
                    dataGridView1.DataSource = dt;

                }
               
            }
            else if(criteriu_mai_mult_4pers == true)
            {
                if (criteriu_pret700 == true)
                {
                    query = "SELECT ID_Camera,Tip_camera,Descriere_Facilitati,Nr_Locuri,Disponibilitate,Pret_camera FROM Camere WHERE Disponibilitate = 1 AND Nr_locuri >4 AND Pret_camera<700;";
                    string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
                    DataTable dt = new DataTable();
                    SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
                    adt.Fill(dt);
                    dataGridView1.DataSource = dt;
                }
                else if (criteriu700_1000 == true)
                {
                    query = "SELECT ID_Camera,Tip_camera,Descriere_Facilitati,Nr_Locuri,Disponibilitate,Pret_camera FROM Camere WHERE Disponibilitate = 1 AND Nr_locuri >4 AND Pret_camera BETWEEN 700 AND 1000; ";
                    string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
                    DataTable dt = new DataTable();
                    SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
                    adt.Fill(dt);
                    dataGridView1.DataSource = dt;
                }
                else if (criteriu1000_1200 == true)
                {
                    query = "SELECT ID_Camera, Tip_camera, Descriere_Facilitati, Nr_Locuri, Disponibilitate, Pret_camera FROM Camere WHERE Disponibilitate = 1 AND Nr_locuri >4 AND Pret_camera BETWEEN 1000 AND 1200;";
                    string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True"; ;
                    DataTable dt = new DataTable();
                    SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
                    adt.Fill(dt);
                    dataGridView1.DataSource = dt;
                }
                else if (criteriu_peste1200 == true)
                {
                    query = "SELECT ID_Camera, Tip_camera, Descriere_Facilitati, Nr_Locuri, Disponibilitate, Pret_camera FROM Camere WHERE Disponibilitate = 1 AND Nr_locuri >4 AND Pret_camera > 1200;";
                    string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
                    DataTable dt = new DataTable();
                    SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
                    adt.Fill(dt);
                    dataGridView1.DataSource = dt;
                }
                else
                {
                    query = "SELECT ID_Camera, Tip_camera, Descriere_Facilitati, Nr_Locuri, Disponibilitate, Pret_camera FROM Camere WHERE Disponibilitate = 1 AND Nr_locuri > 4;";
                    string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
                    DataTable dt = new DataTable();
                    SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
                    adt.Fill(dt);
                    dataGridView1.DataSource = dt;

                }
            }
            else
            {
                query = "SELECT ID_Camera,Tip_camera,Descriere_Facilitati,Nr_Locuri,Disponibilitate,Pret_camera FROM Camere WHERE Disponibilitate = 1; ";
                string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
                DataTable dt = new DataTable();
                SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
                adt.Fill(dt);
                dataGridView1.DataSource = dt;
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            SqlConnection con = new SqlConnection("Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True");
            
            for(int i = 0; i < dataGridView2.Rows.Count; i++)
            {
                con.Open();
                string plata_camera = dataGridView2.Rows[i].Cells[5].Value.ToString();
                int id_camera = Convert.ToInt32(dataGridView2.Rows[i].Cells[1].Value);
                //se realizeaza cate o factura pentru fiecare camera pentru care exista programari 
                id = Convert.ToInt32(label3.Text);
                string  today = DateTime.Today.ToString("yyyy-MM-dd hh:mm:ss") ;
                string query = "INSERT INTO Facturi(Suma_plata,ID_Client,Data_Facturare,ID_Camera) VALUES('"+plata_camera+"','" + id + "','"+today+"','"+id_camera+"');";
                SqlCommand cmd = new SqlCommand(query, con);
                cmd.ExecuteNonQuery();
                con.Close();
                //Si se actualizeaza tabela programri_clienti in acelasi timp cu inserarea noilor facturi
                con.Open();
                string query_select_id_factura_creata = "SELECT Cod_Factura FROM Facturi WHERE ID_Client='" + id + "' AND Data_Facturare = '" + today + "' AND ID_Camera = '"+id_camera+"'; ";
                SqlCommand cmd_factura = new SqlCommand(query_select_id_factura_creata, con);
                int id_factura = (int)cmd_factura.ExecuteScalar();
                //realizam programarea ce urmeaza a fi confirmata de RECEPTIONIST
                string zi_incepere_sejur = this.dateTimePicker1.Value.Date.ToString("yyyy-MM-dd hh:mm:ss");
                string zi_finalizare_sejur = this.dateTimePicker2.Value.Date.ToString("yyyy-MM-dd hh:mm:ss");
                string query_programari = "INSERT INTO Programari_Clienti(ID_Camera,ID_Client,ID_Factura,Data_cazare,Data_decazare,ID_Receptionist) VALUES('"+id_camera+"','"+id+"','"+id_factura+"','"+zi_incepere_sejur+"','"+zi_finalizare_sejur+"',NULL);";
                SqlCommand cmd_programare = new SqlCommand(query_programari, con);
                cmd_programare.ExecuteNonQuery();
                //inchid conexiunea la BD
                con.Close();
            }
            //se redirectioneaza client-ul catre etapa de facturare
            Factura_Client factura = new Factura_Client();
            this.Hide();
            factura.Show();
        }
    }
}
