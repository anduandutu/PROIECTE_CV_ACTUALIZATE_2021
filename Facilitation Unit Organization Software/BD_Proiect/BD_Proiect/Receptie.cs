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
using System.Net;
using System.Net.Mail;
using System.Net.Mime;
namespace BD_Proiect
{
    public partial class Receptie : Form
    {
        public Receptie()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //se populeaza datagrid-ul cu programarile ce urmeaza a fi validate de catre receptionist
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True"; 
            DataTable dt = new DataTable();
            string data = DateTime.Today.ToString("yyyy-MM-dd hh:mm:ss");
            string query =
"SELECT C.Nume, C.Prenume, F.Suma_plata,P.Data_cazare,P.Data_decazare FROM Clienti C " +
"JOIN Facturi F ON C.ID_Client = F.ID_Client " +
"JOIN Programari_Clienti P ON F.Cod_Factura = P.ID_Factura " +
"WHERE F.Data_Facturare <= '" + data + "'AND P.Validata = 0"+
"GROUP BY C.Nume, C.Prenume,F.Suma_plata,P.Data_cazare,P.Data_decazare;";
            SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
            adt.Fill(dt);
            dataGridView1.DataSource = dt;
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.ColumnIndex == 0)
            {
                DateTime d_cazare = (DateTime)dataGridView1.Rows[e.RowIndex].Cells["Data_cazare"].Value;
                DateTime d_decazare = (DateTime)dataGridView1.Rows[e.RowIndex].Cells["Data_decazare"].Value;
                string data_cazare = d_cazare.ToString("yyyy-MM-dd hh:mm:ss");
                string data_decazare = d_decazare.ToString("yyyy-MM-dd hh:mm:ss");

                //se valideaza programarile clientilor setandu-se campul Validata = 1
                string query = "UPDATE Programari_Clienti SET Validata = 1 WHERE ID_Programare =  ANY(SELECT ID_Programare FROM Programari_Clienti WHERE Data_cazare = '" + data_cazare + "' AND Data_decazare = '" + data_decazare + "');";
                string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
                SqlConnection conn = new SqlConnection(connstring);
                SqlCommand cmd = new SqlCommand(query, conn);
                conn.Open();
                cmd.ExecuteNonQuery();
                conn.Close();
                DataTable dt = new DataTable();
                string data = DateTime.Today.ToString("yyyy-MM-dd hh:mm:ss");
                //JOIN 1 -- si se da refresh automat la programarile ce se vor a fi validate 
                string query1 =
    "SELECT C.Nume, C.Prenume, F.Suma_plata,P.Data_cazare,P.Data_decazare FROM Clienti C " +
    "JOIN Facturi F ON C.ID_Client = F.ID_Client " +
    "JOIN Programari_Clienti P ON F.Cod_Factura = P.ID_Factura " +
    "WHERE F.Data_Facturare <= '" + data + "' AND P.Validata = 0" +
    "GROUP BY C.Nume, C.Prenume,F.Suma_plata,P.Data_cazare,P.Data_decazare;";
                SqlDataAdapter adt = new SqlDataAdapter(query1, connstring);
                adt.Fill(dt);
                dataGridView1.DataSource = dt;
                conn.Open();
                //se seteaza id-ul receptionist-ului care a validat la programarea validata in momentul de fata .
                string insert_id_receptionist = "UPDATE Programari_Clienti SET ID_Receptionist = '"+Form1.id+"' WHERE  ID_Programare =  ANY(SELECT ID_Programare FROM Programari_Clienti WHERE Data_cazare = '" + data_cazare+ "' AND Data_decazare = '" + data_decazare + "');";
                SqlCommand cmd1 = new SqlCommand(insert_id_receptionist, conn);
                cmd1.ExecuteNonQuery();
                conn.Close();
                //transmitere mail in legatura cu statusul comenzii ca a fost validata 
                //am nevoie de mail-ul angajatului si al clientului care a facut programarea 
                //mail care momentan nu functioneaza -- da o eroare


                string mail_sender = "SELECT Email FROM Angajati WHERE ID_Angajat ='" + Form1.id + "';";
                conn.Open();
                SqlCommand get_mail_sender = new SqlCommand(mail_sender, conn);
                string email_sender = get_mail_sender.ExecuteScalar().ToString();
                conn.Close();

                string mail_receiver = "SELECT Email FROM Clienti " +
                    "WHERE ID_Client = ANY(SELECT DISTINCT ID_Client FROM Programari_Clienti P" +
                    " WHERE P.Data_cazare ='" +data_cazare + "' " +
                    "AND P.Data_decazare = '" + data_decazare + "')";
                conn.Open();
                SqlCommand get_mail_receiver = new SqlCommand(mail_receiver, conn);
                string email_receiver = get_mail_receiver.ExecuteScalar().ToString();
                conn.Close();

                conn.Open();
                string password_sender = "SELECT Password FROM Angajati WHERE ID_Angajat ='" + Form1.id + "';";
                SqlCommand get_pass_sender = new SqlCommand(password_sender, conn);
                string password = get_pass_sender.ExecuteScalar().ToString();
                /*
                MailMessage mail = new MailMessage(email_sender, email_receiver);
                mail.Subject = "Subject";
                mail.IsBodyHtml = true;
                mail.Body = "this is email body";

                SmtpClient client = new SmtpClient("192.168.0.195"); // to do
                client.DeliveryMethod = SmtpDeliveryMethod.Network;
                client.UseDefaultCredentials = false;
                client.Credentials = new System.Net.NetworkCredential(email_sender, password);
                client.Port = 25;

                client.Send(mail);*/
                conn.Close();
            }
        }

        private void Receptie_Load(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
            DataTable dt2 = new DataTable();
            DateTime data = DateTime.Today;
            string data_cazare = dateTimePicker1.Value.ToString("yyyy-MM-dd hh:mm:ss");
            string data_decazare = dateTimePicker2.Value.ToString("yyyy-MM-dd hh:mm:ss");
            //JOIN 2
            string query =
"SELECT C.Nume, C.Prenume, F.Suma_plata,P.Data_cazare,P.Data_decazare,P.ID_Camera AS Nr_camera FROM Clienti C " +
"JOIN Facturi F ON C.ID_Client = F.ID_Client " +
"JOIN Programari_Clienti P ON F.Cod_Factura = P.ID_Factura " +
"WHERE P.Data_cazare = '"+data_cazare+"'AND data_decazare = '"+data_decazare+"'"+
"GROUP BY C.Nume, C.Prenume,F.Suma_plata,P.Data_cazare,P.Data_decazare,P.ID_Camera;";
            SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
            adt.Fill(dt2);
            dataGridView2.DataSource = dt2;
            //pentru preluarea programrilor cu un interval specificat cazare-decazare

        }

        private void dataGridView2_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.ColumnIndex == 0)
            {
                int cod_factura;
                string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
                SqlConnection conn = new SqlConnection(connstring);
                conn.Open();
                DateTime data_cazare = (DateTime)dataGridView2.Rows[e.RowIndex].Cells["Data_cazare"].Value;
                DateTime data_decazare = (DateTime)dataGridView2.Rows[e.RowIndex].Cells["Data_decazare"].Value;
                string dt_cazare = data_cazare.ToString("yyyy-MM-dd hh: mm:ss");
                string dt_decazare = data_decazare.ToString("yyyy-MM-dd hh: mm:ss");
                int camera = Convert.ToInt32(dataGridView2.Rows[e.RowIndex].Cells["Nr_camera"].Value); 

                //sterg factura asociata cu programarea stearsa de receptionist
               string query1 = "SELECT ID_Factura FROM Programari_clienti" +
                " WHERE Data_cazare = '" + dt_cazare + "' AND Data_decazare = '" + dt_decazare + "' AND ID_camera = '"+camera+"';";
                SqlCommand cmd1 = new SqlCommand(query1, conn);
                cod_factura = (int)cmd1.ExecuteScalar();

                //sterg programarea clientului
                string query2 = "DELETE FROM Programari_Clienti " +
                "WHERE ID_Programare = (SELECT DISTINCT ID_Programare FROM Programari_clienti" +
                " WHERE Data_cazare = '" + dt_cazare + "' AND Data_decazare = '" + dt_decazare + "'AND ID_Camera = '"+camera+"')" +
                "AND  Data_cazare = '" + dt_cazare + "' AND Data_decazare = '" + dt_decazare + "';";
                // setare Disponibilitatea camerei id_camera = 1
                string query3 = "UPDATE Camere SET Disponibilitate = 1 " +
                    "WHERE ID_Camera = '"+camera+"';";


                string query4 = "DELETE FROM Facturi "+
                " WHERE Cod_Factura = '"+cod_factura+"'";
               //stergere programare cu id_ul corespunzator

                SqlCommand cmd2 = new SqlCommand(query2, conn);
                SqlCommand cmd3 = new SqlCommand(query3, conn);
                SqlCommand cmd4 = new SqlCommand(query4, conn);


                cmd2.ExecuteNonQuery();
                cmd3.ExecuteNonQuery();
                cmd4.ExecuteNonQuery();
                conn.Close();

                //si realizez refresh automat al programarilor 
                DataTable dt3 = new DataTable();
                DateTime data = DateTime.Today;
                DateTime data_cazare1 = (DateTime)dateTimePicker1.Value;
                DateTime data_decazare1 = (DateTime)dateTimePicker2.Value;
                string data_cazare_1 = data_cazare1.ToString("yyyy - MM - dd hh: mm:ss");
                string data_decazare_1 = data_decazare1.ToString("yyyy - MM - dd hh: mm:ss");
                string query =
    "SELECT C.Nume, C.Prenume, F.Suma_plata,P.Data_cazare,P.Data_decazare,P.ID_Camera AS Nr_camera FROM Clienti C " +
    "JOIN Facturi F ON C.ID_Client = F.ID_Client " +
    "JOIN Programari_Clienti P ON F.Cod_Factura = P.ID_Factura " +
    "WHERE P.Data_cazare = '" + data_cazare_1 + "'AND data_decazare = '" + data_decazare_1 + "'" +
    "GROUP BY C.Nume, C.Prenume,F.Suma_plata,P.Data_cazare,P.Data_decazare,P.ID_Camera;";
                SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
                adt.Fill(dt3);
                dataGridView2.DataSource = dt3;
            }
        }
    }
}
