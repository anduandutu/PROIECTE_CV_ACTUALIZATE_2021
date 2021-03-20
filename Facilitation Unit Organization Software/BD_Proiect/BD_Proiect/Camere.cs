using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;

namespace BD_Proiect
{
    class Camere
    {
        public int disponibilitate;
        public Camere()
        {
            disponibilitate = 1;
        }
        public void setDisponibilitate(int disp,int id_camera)
        {
            //metoda de setare a disponibilitatii camerei pentru o camera specificata 
            //disp poate lua valoare doar 0 si 1 
            string query = "UPDATE Camere SET Disponibilitate ='" + disp + "'WHERE ID_Camera='" + id_camera + "';";
            string connstring = "Data Source=(localDb)\\Databases;Initial Catalog=BD_Proiect;Integrated Security=True";
            SqlConnection conn = new SqlConnection(connstring);
            conn.Open();
            SqlCommand cmd = new SqlCommand(query, conn);
            cmd.ExecuteNonQuery();
        }

    }
}
