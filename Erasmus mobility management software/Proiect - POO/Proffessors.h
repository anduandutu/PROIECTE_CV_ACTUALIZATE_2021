#pragma once
#include "Utilizatori_clasa.h"
#include <cstdlib>
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Data::SqlClient;
public class Proffessors : public Utilizatori{
	public:
		int id_subject;
		void adaugareProfesor();
		Proffessors(string first_name, string last_name, int subject){
			firstName = first_name;
			lastName = last_name;
			id_subject = subject;
		};
		int getIDProffessor();
		void legareProfesorDeMaterie(int id_materie);
};
void Proffessors::legareProfesorDeMaterie(int id_materie){
	SqlConnection^ conexiune = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
	//SqlConnection^ conexiune = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
	conexiune->Open();
	SqlCommand^ cmd_profi = gcnew SqlCommand("UPDATE Subjects SET ID_Proffesor = '" + getIDProffessor() + "'WHERE ID = '" + id_materie + "';", conexiune);
	SqlDataReader^ reader;
	reader = cmd_profi->ExecuteReader();
}
int Proffessors::getIDProffessor(){
	String^ firstname = gcnew String(firstName.c_str());
	String^ lastname = gcnew String(lastName.c_str());
	SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
	//SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
	conn->Open();
	SqlCommand^ getID = gcnew SqlCommand("SELECT Id FROM Proffessors WHERE First_Name = '" + firstname + "'AND Last_Name = '" + lastname + "';", conn);
	int id = (int)getID->ExecuteScalar();
	return id;
}
void Proffessors::adaugareProfesor(){
	String^ firstname = gcnew String(firstName.c_str());
	String^ lastname = gcnew String(lastName.c_str());
	SqlConnection^ conn_profi = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
	//SqlConnection^ conn_profi = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
	SqlCommand^ cmd_profi = gcnew SqlCommand("INSERT INTO Proffessors(First_Name,Last_Name,ID_Subject) VALUES('" + firstname + "','" + lastname + "','" + id_subject + "');", conn_profi);
	SqlDataReader^ reader;
	try{
		conn_profi->Open();
		reader = cmd_profi->ExecuteReader();
		MessageBox::Show("Saved");
	}
	catch (Exception^ ex){
		MessageBox::Show(ex->Message);
	}
	finally{
		conn_profi->Close();
	}
}