using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;

namespace BD_Proiect
{
    public class Users 
    {
        protected string name;
        protected string surname;
        protected string email;
        protected string password;
        private int manager;
        private int departament;
        void setManager(int id_manager)
        {
            manager = id_manager; ///cautarea id-ului va fi facuta in forma principala 
        }
        int getManager()
        {
            return manager;
        }
        void setDepartament(int Departament)
        {
            departament = Departament;
        }
        int getDepartament()
        {
            return departament;
        }
        void setName(string Name)
        {
            name = Name;
        }
        void setSurname(string Surname)
        {
            surname = Surname;
        }
        void setEmail(string Email)
        {
            email = Email;
        }
        void setPassword(string Password)
        {
            password = Password;
        }
        string getName()
        {
            return name;
        }
        string getSurname()
        {
            return surname;
        }
        string getEmail()
        {
            return email;
        }
        string getPassowrd()
        {
            return password;

        }
        public bool checkExistanceEmployeeLogin(string Email, string parola)
        {
            //se verifica daca exista cel putin un angajat cu Email-ul si Parola data
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
            string query = "SELECT COUNT(*) FROM Angajati WHERE Email = '" + Email + "' AND Password = '" + parola +
                "' AND (Nume_Job = 'Manager' OR Nume_Job = 'Receptioner' OR Nume_job = 'CEO' OR Nume_Job = 'Menajera' OR Nume_Job = 'Bucatar');";
            SqlConnection conn = new SqlConnection(connstring);
            conn.Open();
            SqlCommand cmd = new SqlCommand(query, conn);
            int referinta = 1;
            int count = (int)cmd.ExecuteScalar();
            return count == referinta ? true : false;
        }
        public bool checkServiciiMenaj(string Email,string parola)
        {
            //se verifica daca exista Menajera/ Bucatar cu datele de login date
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
            string query = "SELECT COUNT(*) FROM Angajati WHERE Email = '" + Email + "' AND Password = '" + parola + "' AND (Nume_Job = 'Menajera' OR Nume_Job = 'Bucatar') ;";
            SqlConnection conn = new SqlConnection(connstring);
            conn.Open();
            SqlCommand cmd = new SqlCommand(query, conn);
            int referinta = 1;
            int count = (int)cmd.ExecuteScalar();
            return count == referinta ? true : false;
        }
        public int getID_Clienti(string email, string password)
        {
            //se preia id-ul clientului curent
            int id;
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
            SqlConnection conn = new SqlConnection(connstring);
            conn.Open();
            string query= "SELECT ID_Client FROM Clienti WHERE Email = '"+email+"' AND Parola = '"+password+"';";
            SqlCommand cmd = new SqlCommand(query, conn);
            id = (int)cmd.ExecuteScalar();
            return id;

        }
        public int getID_Angajat(string email,string parola)
        {
            //se preia id-ul angajatului curent
            int id;
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
            SqlConnection conn = new SqlConnection(connstring);
            conn.Open();
            string query = "SELECT ID_Angajat FROM Angajati WHERE Email = '" + email + "' AND Password = '" + password + "';";
            SqlCommand cmd = new SqlCommand(query, conn);
            id = (int)cmd.ExecuteScalar();
            return id;
        }
        public bool checkClient(string Email,string parola)
        {
            //se verifica daca exista cel putin un client cu datele de login date
            string query = "SELECT COUNT(*) FROM Clienti WHERE Email = '" + Email + "' AND Parola = '" + parola + "';";
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
            SqlConnection conn = new SqlConnection(connstring);
            conn.Open();
            SqlCommand cmd = new SqlCommand(query, conn);
            int referinta = 1;
            int count = (int)cmd.ExecuteScalar();
            return count == referinta ? true : false;
        }
        public
        Users(string Email, string parola)
        {
            setEmail(Email);

            setPassword(parola);
        }
        Users(string nume_job, string nume, string prenume, string Email, string parola, int id_manager, int id_departament)
        {
            //se adauga un nou utilizator in sistem
            bool exista_angajat = checkExistanceEmployeeLogin(Email, parola);
            bool exista_departament = checkDepartment(id_departament);
            if (exista_departament == true)
            {
                if (exista_angajat == false)
                {
                    bool exista_intrus = checkIntrusi(Email, parola);
                    if (exista_intrus == false)
                    {
                        addNewUser(nume_job, nume, prenume, Email, parola, id_manager, id_departament);
                        //intra in sistemul de gestiune
                    }

                }
                else
                {
                    //intra in sistemul de gestiune, totul bine si frumos 
                }
            }

        }
        public bool checkIsCEO(string email,string password)
        {
            //se verifica daca utilizatorul curent este CEO
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True"; ;
            SqlConnection conn = new SqlConnection(connstring);
            conn.Open();
            string checkCEO = "SELECT COUNT(*) FROM Angajati WHERE Email = '" + email + "' AND Password = '" + password + "' AND Nume_job = 'CEO';";
            SqlCommand cmd = new SqlCommand(checkCEO, conn);
            int CEO = (int)cmd.ExecuteScalar();
            if(CEO == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        public bool checkIsReceptie(string email, string password)
        { 
            //se verifica daca utilizatorul curent este receptioner
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True"; ;
            SqlConnection conn = new SqlConnection(connstring);
            conn.Open();
            string checkCEO = "SELECT COUNT(*) FROM Angajati WHERE Email = '" + email + "' AND Password = '" + password + "' AND Nume_job = 'Receptioner';";
            SqlCommand cmd = new SqlCommand(checkCEO, conn);
            int CEO = (int)cmd.ExecuteScalar();
            if (CEO == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        public bool checkIsManager(string email, string password)
        {
            //se verifica daca utilizatorul curent este manager
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True"; ;
            SqlConnection conn = new SqlConnection(connstring);
            conn.Open();
            string checkCEO = "SELECT COUNT(*) FROM Angajati WHERE Email = '" + email + "' AND Password = '" + password + "' AND Nume_job = 'Manager';";
            SqlCommand cmd = new SqlCommand(checkCEO, conn);
            int CEO = (int)cmd.ExecuteScalar();
            if (CEO == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        void addNewUser(string nume_job, string nume, string prenume, string Email, string parola, int id_manager, int id_departament)
        {
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True"; ;
            SqlConnection conn = new SqlConnection(connstring);
            conn.Open();
            string query2 = "INSERT INTO Angajati(Nume_job, Nume, Prenume,ID_Manager, ID_Departament,Email,Password) VALUES('" + nume_job + "','" + nume + "','" + prenume + "','" + id_manager + "','" + id_departament + "','" + email + "','" + password + "');";
            SqlCommand cmd3 = new SqlCommand(query2, conn);
            cmd3.ExecuteNonQuery();
            conn.Close();
        }
        public bool checkDepartment(int id_departament)
        {
            //se verifica existenta unui departament cu un ID_dat
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True"; ;
            SqlConnection conn = new SqlConnection(connstring);
            conn.Open();
            string query3 = "SELECT COUNT(*) FROM Departamente WHERE ID_Departament = '" + id_departament + "'";
            SqlCommand cmd4 = new SqlCommand(query3, conn);
            int exista_departament = (int)cmd4.ExecuteScalar();
            conn.Close();
            if (exista_departament >= 1)
            {
                return true;
            }
            else
            {
                return false;
            }

        }
        public bool checkIntrusi(string Email, string parola)
        {
            //se verifica ca un utilizator neprivilegiat sa nu vrea sa se logheze cu drepturi mai mari
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
            SqlConnection conn = new SqlConnection(connstring);
            bool exista_intrus;//se face mai intai o verificare sa nu fie cumva menajere/femei de serviciu
            conn.Open();
            string query1 = "COUNT(*) FROM Angajati_hotel WHERE Email = '" + Email + "' AND Password = '" + parola + "' AND Nume_job = 'Menajera'";
            SqlCommand cmd1 = new SqlCommand(query1);
            int nr_menajera = (int)cmd1.ExecuteScalar();
            if (nr_menajera >= 1)
            {
                conn.Close();
                exista_intrus = true;
            }
            else
            {
                exista_intrus = false;
                conn.Close();
            }
            return exista_intrus;
        }
    }
}
