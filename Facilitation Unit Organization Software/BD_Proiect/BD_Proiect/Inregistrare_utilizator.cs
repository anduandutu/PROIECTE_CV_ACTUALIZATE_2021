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
    public partial class Inregistrare_utilizator : Form
    {
        public Inregistrare_utilizator()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string Email = textBox3.Text;
            string parola = textBox4.Text;
            string cnp = textBox5.Text;
            //se verifica daca utilizatorul este client sau angajat deja existent  al unitatii de cazare 
            Users a = new Users(Email, parola);
            bool isClient = a.checkClient(Email, parola);
            bool isAngajat = a.checkExistanceEmployeeLogin(Email, parola);
            //se identifica tipul de status pe care il are utilizatorul in raport cu unitatea de cazare 
            //are forma separata
            bool isReceptionist = checkedListBox1.GetItemCheckState(0) == CheckState.Checked ? true : false;
            //are forma separata
            bool isCEO = checkedListBox1.GetItemCheckState(1) == CheckState.Checked ? true : false;
            //are forma separata
            bool is_Client= checkedListBox1.GetItemCheckState(2) == CheckState.Checked ? true : false;
            //are forma separata
            bool isManager = checkedListBox1.GetItemCheckState(3) == CheckState.Checked ? true : false;
            //Useri din categoria cu cel mai mic acces -- Menajere si Bucatari -- vor merge doar sa poata sa isi seteze 
            //camera la care vor lucra(curatenie etc etc ) intre intervalul oral x : y
            //au forma comuna
            bool isMenajera = checkedListBox1.GetItemCheckState(4) == CheckState.Checked ? true : false;
            bool isBucatar = checkedListBox1.GetItemCheckState(5) == CheckState.Checked ? true : false;
            string nume_job = ""; 
            if(isBucatar == true)
            {
                nume_job = "Bucatar";
            }
            if(isCEO == true)
            {
                nume_job = "CEO";
            }
            if(isMenajera == true)
            {
                nume_job = "Menajera";
            }
            if(isManager== true)
            {
                nume_job = "Manager";
            }
            if(isReceptionist == true)
            {
                nume_job = "Receptioner";
            }
            //Se vor face verificări privind adresele de email folosite , dorindu-se să fie utilizată 
            // o adresă email validă 
            //Apoi se va face o verificare a relatiei dintre CNP si Nationalitate : 
            // 1. Pentru utilizatori Romani - avem CNP de lungime 13 
            // 2. Pentru utilizatori straini - avem CNP de lungime 0 
            if (Email.Contains("@yahoo.com") || (Email.Contains("@gmail.com")))
            {
                if (cnp.Length == 13)
                {
                    if (textBox6.Text.Equals("Romana") == true)
                    {
                        //daca am selectat ca vreau saa fiu client si nu exist in sistem ca client 
                        //ma bag in sistem drept client
                        //altfel daca vreau sa fiu angajat si nu exist ca angajat ma bag in sistem ca angajat
                        if (is_Client == true)
                        {
                            if (isClient == false)
                            {
                                Clienti client = new Clienti(Email, parola);
                                client.insertClient(textBox1.Text, textBox2.Text, textBox6.Text, textBox5.Text, Email, parola);

                            }
                            Form1 login_client = new Form1();
                            this.Hide();
                            login_client.Show();
                        }
                        else if (isManager == true || isCEO == true || isBucatar == true || isMenajera == true || isReceptionist == true)
                        {
                            if (isAngajat == false)
                            {
                                Angajat ang = new Angajat(Email, parola);
                                ang.insertAngajat(textBox1.Text, textBox2.Text, textBox5.Text, Email, parola, nume_job);

                            }
                            Form1 login_angajat = new Form1();
                            this.Hide();
                            login_angajat.Show();
                        }
                    }
                    else
                    {
                        MessageBox.Show("Please enter a valid nationality or a valid CNP for your nationality!");
                    }
                }
                else if(cnp.Length == 0)
                {
                    if(textBox6.Text.Equals("Romana") == false)
                    {

                        //aceeaasi logica se pastreaza si pentru clientii sau angajatii straini
                        if (is_Client == true)
                        {
                            if (isClient == false)
                            {
                                Clienti client_strain = new Clienti(Email, parola);
                                client_strain.insertClient(textBox1.Text, textBox2.Text, textBox6.Text, textBox5.Text, Email, parola);

                            }
                            Form1 login_client_strain = new Form1();
                            this.Hide();
                            login_client_strain.Show();
                        }
                        else if (isManager == true || isCEO == true || isBucatar == true || isMenajera == true || isReceptionist == true)
                        {
                            if (isAngajat == false)
                            {
                                Angajat ang_strain = new Angajat(Email, parola);
                                ang_strain.insertAngajat(textBox1.Text, textBox2.Text, textBox5.Text, Email, parola, nume_job);

                            }
                            Form1 login_angajat_strain = new Form1();
                            this.Hide();
                            login_angajat_strain.Show();
                        }
                    }
                    else
                    {
                        MessageBox.Show("Please enter a valid nationality or a valid CNP for your nationality!");
                    }

                }
            }
            else
            {
                MessageBox.Show("Please enter an appropriate email address!");
            }
            //se afiseaza mesaje corespunzatoare in cazul in care nu sunt indeplinite conditiile de inserare client/angajat
        }
    }
}
