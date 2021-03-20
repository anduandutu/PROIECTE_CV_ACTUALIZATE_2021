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
    public partial class Bifurcatie : Form
    {
        static int id_user;
        public Bifurcatie()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Realizare_programare programare = new Realizare_programare();
            this.Hide();
            programare.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //JOIN 1
            id_user = Form1.id;
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
            DataTable dt = new DataTable();
            //preiau data curenta 
            string  data = DateTime.Today.ToString("yyyy-MM-dd hh:mm:ss");
            string query =
"SELECT C.Nume, C.Prenume, F.Suma_plata,P.Data_cazare,P.Data_decazare,P.Validata FROM Clienti C " +
"JOIN Facturi F ON C.ID_Client = F.ID_Client " +
"JOIN Programari_Clienti P ON F.Cod_Factura = P.ID_Factura " +
"WHERE(C.ID_Client = '" + id_user + "' AND F.Data_Facturare <= '" + data + "') " +
"GROUP BY C.Nume, C.Prenume,F.Suma_plata,P.Data_cazare,P.Data_decazare,P.Validata;";
            //aflu istoricul clientului de pana la data de astazi 

            SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
            adt.Fill(dt);
            dataGridView1.DataSource = dt;
            //umplu datagrid-ul cu datele obtinute in urma executarii cererii de tip JOIN
        }
    }
}
