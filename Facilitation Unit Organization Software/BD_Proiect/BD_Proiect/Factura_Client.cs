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
    public partial class Factura_Client : Form
    {
        static int id_user;
        public Factura_Client()
        {
            InitializeComponent();
        }
        private void Factura_Client_Load(object sender, EventArgs e)
        {
            //JOIN 2
            id_user = Form1.id;
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
            DataTable dt = new DataTable();
            string data = DateTime.Today.ToString("yyyy-MM-dd hh:mm:ss");
            string query =
"SELECT C.Nume, C.Prenume, F.Suma_plata,P.Data_cazare,P.Data_decazare,P.Validata FROM Clienti C " +
"JOIN Facturi F ON C.ID_Client = F.ID_Client " +
"JOIN Programari_Clienti P ON F.Cod_Factura = P.ID_Factura " +
"WHERE(C.ID_Client = '"+id_user+"' AND F.Data_Facturare = '"+data+"') " +
"GROUP BY C.Nume, C.Prenume,F.Suma_plata,P.Data_cazare,P.Data_decazare,P.Validata;";
            //la load se populeaza datagrid-ul cu informatii despre programarile realizate de utilizatorul curent 
            //in data de astazi cand a fost accesat de fapt soft-ul
            SqlDataAdapter adt = new SqlDataAdapter(query, connstring);
            adt.Fill(dt);
            dataGridView1.DataSource = dt;


            //calculam numarul de zile de pe comenzile de astazi 
            double suma = 0;
            double nr_zile_total;
            // se calculeaza suma totala de plata de pana acum 
            //conform numaruli de zile al sejurului pe fiecare camera selectata 

            for (int i = 0; i < dataGridView1.Rows.Count; i++)
            {
                string cazare = dataGridView1.Rows[i].Cells[3].Value.ToString();
                DateTime data_cazare = Convert.ToDateTime(cazare);
                string data_cazaree = data_cazare.ToString("yyyy-MM-dd hh:mm:ss");
                DateTime data1 = Convert.ToDateTime(data_cazaree);


                string decazare = dataGridView1.Rows[i].Cells[4].Value.ToString();
                DateTime data_decazare = Convert.ToDateTime(decazare);
                string data_decazaree = data_decazare.ToString("yyyy-MM-dd hh:mm:ss");
                DateTime data2 = Convert.ToDateTime(data_decazaree);
                if(data1 == data2)
                {
                    nr_zile_total = 1;
                }
                else
                {
                    TimeSpan t = data2.Subtract(data1);
                    nr_zile_total = Convert.ToDouble(t.TotalDays);
                }
                suma = suma + Convert.ToDouble(dataGridView1.Rows[i].Cells[2].Value)*nr_zile_total;
            }
            textBox1.Text = suma.ToString();
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Realizare_programare realiz = new Realizare_programare();
            realiz.Show();
            this.Hide();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //TO_DO -- de realizat pdf-ul asa cum trebuie 
            //momentan face un screenshot al formei si il memoreaza in pdf
            //folosind metoda Capture Screen
            CaptureScreen();
            printDocument1.Print();
            Application.Exit();
        }
        Bitmap memoryImage;

        private void CaptureScreen()
        {
            Graphics myGraphics = this.CreateGraphics();
            Size s = this.Size;
            memoryImage = new Bitmap(s.Width, s.Height, myGraphics);
            Graphics memoryGraphics = Graphics.FromImage(memoryImage);
            memoryGraphics.CopyFromScreen(this.Location.X, this.Location.Y, 0, 0, s);
        }

        private void printDocument1_PrintPage(object sender, System.Drawing.Printing.PrintPageEventArgs e)
        {
            e.Graphics.DrawImage(memoryImage, 0, 0);
        }
    }
}
