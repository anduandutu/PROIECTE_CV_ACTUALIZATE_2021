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
    public partial class ManagementCEO : Form
    {
        public ManagementCEO()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //SUBCERERE 2
            string query = "SELECT A.Nume,A.Prenume,A.Salariu FROM Angajati A " +
                "WHERE EXISTS" +
                "(SELECT MAX(C.Salariu), D.ID_Departament From Angajati C " +
                "JOIN Departamente D ON C.ID_Departament = D.ID_Departament GROUP BY D.ID_Departament HAVING MAX(C.Salariu) = A.Salariu)";
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
            DataTable dt = new DataTable();
            SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
            adt.Fill(dt);
            dataGridView1.DataSource = dt;
        }

        private void button8_Click(object sender, EventArgs e)
        {
            //se deschide o noua forma pentru inserarea unui nou departament 
            AddDepartament dep = new AddDepartament();
            dep.Show();
        }

        private void button9_Click(object sender, EventArgs e)
        {
            //se deschide o noua forma pentru asocierea angajat-departament-manager
            Asociere_angajat_departament asociere = new Asociere_angajat_departament();
            this.Hide();
            asociere.Show();
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.ColumnIndex == 0)
            {
                string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
                SqlConnection conn = new SqlConnection(connstring);
                //in momentul in care doresc concedierea unui angajat fac UPDATE pe tabelele ce au legatura cu angajatul respectiv 
                //si setez cu NULL campurile ce sunt asociate cu id-ul angajatului 
                if (dataGridView1.Rows[e.RowIndex].Cells["Nume_Job"].Value.ToString() == "Receptioner")
                {
                    //spre exemplu cand concediez un receptioner
                    //voi sterge id-ul sau din tabela Programari_Clienti pentru 
                    //a nu exista coliziuni cu constrangerea de tip FK din tabela Programari_Clienti
                    string query_on_delete_set_null = "UPDATE Programari_Clienti SET ID_Receptionist = NULL WHERE ID_Receptionist = " +
                        "(SELECT ID_Angajat FROM ANGAJATI WHERE Nume = '" + dataGridView1.Rows[e.RowIndex].Cells["Nume"].Value + "' " +
                        "AND Prenume = '" + dataGridView1.Rows[e.RowIndex].Cells["Prenume"].Value + "' " +
                        "AND Email = '" + dataGridView1.Rows[e.RowIndex].Cells["Email"].Value + "');";
                    conn.Open();
                    SqlCommand set_null_facturi = new SqlCommand(query_on_delete_set_null, conn);
                    set_null_facturi.ExecuteNonQuery();
                    conn.Close();
                }
                else if (dataGridView1.Rows[e.RowIndex].Cells["Nume_Job"].Value.ToString() == "Bucatar" || (dataGridView1.Rows[e.RowIndex].Cells["Nume_Job"].Value.ToString() == "Menajera"))
                {
                    string query_on_delete_set_null = "UPDATE Menaj_Camere SET ID_Angajat = NULL WHERE ID_Angajat = " +
                         "(SELECT ID_Angajat FROM ANGAJATI WHERE Nume = '" + dataGridView1.Rows[e.RowIndex].Cells["Nume"].Value + "' " +
                         "AND Prenume = '" + dataGridView1.Rows[e.RowIndex].Cells["Prenume"].Value + "' " +
                         "AND Email = '" + dataGridView1.Rows[e.RowIndex].Cells["Email"].Value + "');";
                    conn.Open();
                    SqlCommand set_null_facturi = new SqlCommand(query_on_delete_set_null, conn);
                    set_null_facturi.ExecuteNonQuery();
                    conn.Close();
                }
                else if (dataGridView1.Rows[e.RowIndex].Cells["Nume_Job"].Value.ToString() == "Manager" || dataGridView1.Rows[e.RowIndex].Cells["Nume_Job"].Value.ToString() == "manager")
                {
                    string query_on_delete_set_null = "UPDATE Angajati SET ID_Manager = NULL WHERE EXISTS (SELECT ID_Angajat FROM Angajati WHERE ID_Manager = (SELECT ID_Angajat FROM Angajati WHERE Nume = '" + dataGridView1.Rows[e.RowIndex].Cells["Nume"].Value.ToString() +"' AND Prenume = '" + dataGridView1.Rows[e.RowIndex].Cells["Prenume"].Value.ToString() + "' AND Email = '" + dataGridView1.Rows[e.RowIndex].Cells["Email"].Value.ToString() + "'));";
                    conn.Open();
                    SqlCommand set_null_facturi = new SqlCommand(query_on_delete_set_null, conn);
                    set_null_facturi.ExecuteNonQuery();
                    conn.Close();
                }
                //si abia apoi realizez stergerea anhajatului din sistem
                string query_delete = "DELETE FROM ANGAJATI WHERE Nume = '" + dataGridView1.Rows[e.RowIndex].Cells["Nume"].Value+ "' " +
                    "AND Prenume = '"+dataGridView1.Rows[e.RowIndex].Cells["Prenume"].Value+"' " +
                    "AND Email = '"+dataGridView1.Rows[e.RowIndex].Cells["Email"].Value+"';";

                conn.Open();
                SqlCommand delete = new SqlCommand(query_delete, conn);
                delete.ExecuteNonQuery();
                conn.Close();
                //si updatez datagrid-ul utilizat
                string query_update = "SELECT Nume,Prenume,Email,Nume_Job FROM Angajati";
                conn.Open();
                DataTable data = new DataTable();
                SqlDataAdapter adt = new SqlDataAdapter(query_update, connstring);
                adt.Fill(data);
                dataGridView1.DataSource = data;
                conn.Close();

            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            //populez data_grid-ul cu angajatii curenti ai unitatii de cazare
            string query_initializare = "SELECT Nume,Prenume,Email,Nume_Job FROM Angajati ";
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
            SqlConnection conn = new SqlConnection(connstring);
            conn.Open();
            DataTable data = new DataTable();
            SqlDataAdapter adt = new SqlDataAdapter(query_initializare, connstring);
            adt.Fill(data);
            dataGridView1.DataSource = data;
            conn.Close();
        }

        private void ManagementCEO_Load(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            //JOIN 6
            string query = "SELECT A.Nume,A.Prenume,1.2*A.Salariu AS Salariu_Nou,COUNT(MC.ID_Camera) AS Nr_camere_lucrate FROM Angajati A JOIN Menaj_camere MC ON A.ID_Angajat = MC.ID_Angajat WHERE Nume_Job = 'Menajera' GROUP BY A.Nume,A.Prenume,A.Salariu HAVING COUNT(MC.ID_Camera) > 5";
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
            DataTable dt = new DataTable();
            SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
            adt.Fill(dt);
            dataGridView1.DataSource = dt;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            //SUBCERERE 3
            string query = "SELECT A.Nume,A.Prenume FROM Angajati A WHERE ID_Angajat = (SELECT PC1.ID_Receptionist FROM Programari_clienti PC1 GROUP BY PC1.ID_Receptionist HAVING COUNT(PC1.ID_Programare) = (SELECT TOP 1 COUNT(PC.ID_Programare) AS Nr_Programari FROM Programari_clienti PC GROUP BY PC.ID_Receptionist ORDER BY COUNT(PC.ID_Programare) DESC))";
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
            DataTable dt = new DataTable();
            SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
            adt.Fill(dt);
            dataGridView1.DataSource = dt;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            //SUBCERERE 4
            string query = "SELECT C.Nume,C.Prenume FROM Clienti C WHERE C.ID_Client = ANY( SELECT TOP 10 PC.ID_Client AS Nr_Programari FROM Programari_clienti PC GROUP BY PC.ID_Client ORDER BY COUNT(PC.ID_Programare) DESC)";
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
            DataTable dt = new DataTable();
            SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
            adt.Fill(dt);
            dataGridView1.DataSource = dt;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            //SUBCERERE 5
            string query = "SELECT Ang.Nume,Ang.Prenume,Ang.Salariu,D1.Nume_Departament FROM Angajati Ang JOIN Departamente D1 ON D1.ID_Departament = Ang.ID_Departament WHERE EXISTS( SELECT D.ID_Departament, AVG(A.Salariu) FROM Angajati A JOIN Departamente D ON A.ID_Departament = D.ID_Departament GROUP BY D.ID_Departament HAVING Ang.Salariu < AVG(A.Salariu))";
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
            DataTable dt = new DataTable();
            SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
            adt.Fill(dt);
            dataGridView1.DataSource = dt;
        }

        private void button7_Click(object sender, EventArgs e)
        {
            //JOIN 5
            string query = "SELECT A.Nume,A.Prenume FROM Angajati A JOIN Clienti C ON A.Email = C.Email";
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
            DataTable dt = new DataTable();
            SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
            adt.Fill(dt);
            dataGridView1.DataSource = dt;
        }
        //restul cererilor intra in zona de raportari a CEO-ului
    }
}
