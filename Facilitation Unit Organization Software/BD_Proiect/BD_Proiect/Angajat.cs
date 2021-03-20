using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;

namespace BD_Proiect
{
    class Angajat : Users
    {
        public string Nationalitate;

        public Angajat(string Email, string parola) : base(Email, parola)
        {
            email = Email;
            password = parola;
            Nationalitate = "";
        }
        public void insertAngajat(string nume, string prenume, string nationalitate, string email, string parola, string nume_job)
        {
            //setam salariul angajatului ce urmeaza a fi inserat in sistem
            double salariu = 0.0;
            if(nume_job == "Manager")
            {
                salariu = 3500.00;
            }
            if(nume_job == "CEO")
            {
                salariu = 4500.00;
            }
            if(nume_job == "Menajera")
            {
                salariu = 2000.00;
            }
            if(nume_job == "Bucatar")
            {
                salariu = 3000.00;
            }
            if(nume_job == "Receptioner")
            {
                salariu = 3500.00;
            }
            //realizam operatie de INSERT pe tabela Angajati cu valorile preluate din formade inregistrare in sistem
            string connString = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True"; ;
            SqlConnection conn = new SqlConnection(connString);
            string queryInsertAngajat = "INSERT INTO Angajati(Nume,Prenume,Email,Password,Nationalitate,Nume_Job,Salariu) VALUES('" + nume + "','" + prenume + "','" + email + "','" + parola + "','" + nationalitate + "','"+nume_job+"','"+salariu+"');";
            conn.Open();
            SqlCommand cmd = new SqlCommand(queryInsertAngajat, conn);
            cmd.ExecuteNonQuery();
            conn.Close();

        }

    }
}
