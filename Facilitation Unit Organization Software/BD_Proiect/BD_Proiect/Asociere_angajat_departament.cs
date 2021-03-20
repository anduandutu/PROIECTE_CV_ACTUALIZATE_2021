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
    public partial class Asociere_angajat_departament : Form
    {
        public Asociere_angajat_departament()
        {
            InitializeComponent();
        }

        private void Asociere_angajat_departament_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'bD_ProiectDataSet7.Angajati' table. You can move, or remove it, as needed.
            this.angajatiTableAdapter1.Fill(this.bD_ProiectDataSet7.Angajati);
            // TODO: This line of code loads data into the 'bD_ProiectDataSet6.Departamente' table. You can move, or remove it, as needed.
            this.departamenteTableAdapter1.Fill(this.bD_ProiectDataSet6.Departamente);
            // TODO: This line of code loads data into the 'bD_ProiectDataSet4.Angajati' table. You can move, or remove it, as needed.
           // this.angajatiTableAdapter.Fill(this.bD_ProiectDataSet4.Angajati);
            // TODO: This line of code loads data into the 'bD_ProiectDataSet3.Departamente' table. You can move, or remove it, as needed.
            //this.departamenteTableAdapter.Fill(this.bD_ProiectDataSet3.Departamente);

        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Hide();
            ManagementCEO ceo = new ManagementCEO();
            ceo.Show();
        }
        //public string nume_dep ;
        private void dataGridView2_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            //setam un label cu departamentul pe care il selectam pentru asociere 
            if(e.ColumnIndex == 2)
            {
                label5.Text = dataGridView2.Rows[e.RowIndex].Cells[0].Value.ToString();
            }
        }

        private void dataGridView1_CellContentClick(object sender1, DataGridViewCellEventArgs e1)
        {
         }

        private void button2_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < dataGridView1.Rows.Count; i++)
            {
                //pentru fiecare angajat selectat pentru asociere cu departamentul deja selectat 
                DataGridViewCheckBoxCell cell = dataGridView1.Rows[i].Cells[0] as DataGridViewCheckBoxCell;
                if (cell.Value == cell.TrueValue)
                {
                  string connString = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
                    SqlConnection conn = new SqlConnection(connString);
                    //identificam id_ul managerului identificat cu email-ul si parola introduse 
                  string query1 = "SELECT ID_Angajat FROM Angajati WHERE Nume = '" + textBox1.Text + "' AND Prenume = '" + textBox2.Text + "' AND Email = '" + textBox3.Text + "';";
                  conn.Open();
                  SqlCommand cmd1 = new SqlCommand(query1, conn);
                  int id_manager = (int)cmd1.ExecuteScalar();


                  string query2 = "SELECT ID_Departament FROM Departamente WHERE Nume_Departament = '" + label5.Text + "';";
                  SqlCommand cmd2 = new SqlCommand(query2, conn);
                  int id_departament= (int)cmd2.ExecuteScalar();
                  //identific si id_ul departamentului selectat
                  string nume_ang = dataGridView1.Rows[i].Cells[2].Value.ToString();
                  string prenume_ang = dataGridView1.Rows[i].Cells[3].Value.ToString();
                  string email_ang = dataGridView1.Rows[i].Cells[4].Value.ToString();
                  string query3 = "UPDATE Angajati SET ID_Manager = '" + id_manager + "' ,ID_Departament = '" + id_departament + "' " +
                      "WHERE Nume = '"+nume_ang+"' AND Prenume = '" + prenume_ang + "' AND Email = '" + email_ang + "';";
                  SqlCommand cmd = new SqlCommand(query3, conn);
                  cmd.ExecuteNonQuery();
                 //si apoi avand toate informatiile necesare 
                 //realizam operatia de UPDATE pe tabela Angajati
                 //actualizand informatiile despre departamentul si managerul cu care acesti angajati sunt asociati 
                  conn.Close();
                }
            }
        }
    }
}

