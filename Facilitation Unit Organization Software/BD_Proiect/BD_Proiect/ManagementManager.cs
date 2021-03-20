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
    public partial class ManagementManager : Form
    {
        public ManagementManager()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //SUBCERERE 1
            //zona de raportari a managerului
            int id_manager = Form1.id;
            string query = "SELECT TOP 10 A.Nume,A.Prenume " +
                "FROM Angajati A " +
                "WHERE A.ID_Manager = (SELECT A1.ID_Angajat FROM Angajati A1 WHERE A1.ID_Angajat = '"+id_manager+"')" +
                "ORDER BY A.Salariu,A.Nume,A.Prenume DESC";
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
            DataTable dt = new DataTable();
            SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
            adt.Fill(dt);
            dataGridView1.DataSource = dt;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //JOIN 4
            string query = "SELECT  DISTINCT D.Nume_Departament FROM Departamente D JOIN Angajati A ON D.ID_Departament = A.ID_Departament WHERE A.ID_Manager = '" + Form1.id +"';";
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
            DataTable dt = new DataTable();
            SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
            adt.Fill(dt);
            dataGridView1.DataSource = dt;
        }

        private void button3_Click(object sender, EventArgs e)
        { 
            //JOIN 3
            string query = "SELECT DISTINCT A.Nume,A.Prenume,M.ID_Camera AS Nr_Camera FROM  Angajati A JOIN Menaj_camere M ON A.ID_Angajat = M.ID_Angajat UNION SELECT DISTINCT A.Nume,A.Prenume,P.ID_Camera AS Nr_Camera FROM  Angajati A JOIN Programari_clienti P ON A.ID_Angajat = P.ID_Receptionist";
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
            DataTable dt = new DataTable();
            SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
            adt.Fill(dt);
            dataGridView1.DataSource = dt;
        }
    }
}
