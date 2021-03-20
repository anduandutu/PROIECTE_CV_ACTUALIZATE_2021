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
    public partial class AddDepartament : Form
    {
        public AddDepartament()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {

            //La apăsarea butonului inserare se va insera un nou departament cu numele și descrierea specificată în cadrul formei 
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
            SqlConnection conn = new SqlConnection(connstring);
            //se realizează conexiunea la baza de date
            string add_dep = "INSERT INTO Departamente(Nume_Departament,Descriere_Departament) VALUES('"+textBox1.Text+"','"+richTextBox1.Text+"');";
            conn.Open();
            SqlCommand cmd = new SqlCommand(add_dep, conn);
            cmd.ExecuteNonQuery();
            //se realizează operația de INSERT pe tabela Departamente 
            //se închide conexiunea la baza de date și se ascunde forma curentă â
            //pentru a ne întoarce la forma principala Management_CEO
            conn.Close();
            this.Hide();
        }
    }
}
