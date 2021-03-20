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
using System.Globalization;

namespace BD_Proiect
{
    public partial class Setare_program_menaj_camere : Form
    {
        public Setare_program_menaj_camere()
        {
            InitializeComponent();
        }

        private void Setare_program_menaj_camere_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'bD_ProiectDataSet5.Camere' table. You can move, or remove it, as needed.
            this.camereTableAdapter1.Fill(this.bD_ProiectDataSet5.Camere);
            // TODO: This line of code loads data into the 'bD_ProiectDataSet2.Camere' table. You can move, or remove it, as needed.
            //this.camereTableAdapter.Fill(this.bD_ProiectDataSet2.Camere);

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            if(e.ColumnIndex == 3)
            {
                int nr_camera = Convert.ToInt32(dataGridView1.Rows[e.RowIndex].Cells[0].Value);
                string ora_incepere = textBox1.Text;
                string ora_finalizare = textBox2.Text;
                string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True"; 

                SqlConnection conn = new SqlConnection(connstring);
                conn.Open();
                //se insereaza programul lucrat de menajere respectiv bucatari la o anumita camera 
                //pentru eventuala evidenta a orelor lucrate 
                string insert_menaj = "INSERT INTO Menaj_camere(ID_Camera,ID_Angajat,Ora_incepere,Ora_finalizare)" +
                    "VALUES('"+nr_camera+"','"+Form1.id+"','"+ora_incepere+"','"+ora_finalizare+"');";

                SqlCommand cmd_insert_menaj = new SqlCommand(insert_menaj, conn);
                cmd_insert_menaj.ExecuteNonQuery();
                conn.Close();
                dataGridView1.Rows.RemoveAt(e.RowIndex);
            }
        }
    }
}
