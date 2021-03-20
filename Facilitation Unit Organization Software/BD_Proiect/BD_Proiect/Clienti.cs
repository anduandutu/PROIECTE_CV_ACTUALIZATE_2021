using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;

namespace BD_Proiect
{
    class Clienti : Users
    {
        public string Nationalitate;

        public Clienti(string Email, string parola) : base(Email, parola)
        {
            email = Email;
            password = parola;
            Nationalitate = "";
        }
        public void insertClient(string nume, string prenume,string nationalitate, string CNP,string email,string parola)
        {
            //adaugarea unui client in sistem cu datele preluate din forma de inregistrare
            string connString = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
            SqlConnection conn = new SqlConnection(connString);
            string queryInsertClient = "INSERT INTO Clienti(Nume,Prenume,Email,Parola,Nationalitate,CNP) VALUES('"+nume+"','"+prenume+"','"+email+"','"+parola+"','"+nationalitate+"','"+CNP+"');";
            conn.Open();
            SqlCommand cmd = new SqlCommand( queryInsertClient,conn);
            cmd.ExecuteNonQuery();
            conn.Close();

        }
    }
}
