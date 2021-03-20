#pragma once
#include <iostream>
#include <string>
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Data::SqlClient;
public class Utilizatori{
public:
	int ID;
	string firstName;
	string lastName;
	void adaugareUtilizator();
	void setID(int id){
		ID = id;
	};
	void setfirstName(string first){
		firstName = first;
	};
	void setlastName(string last){
		lastName = last;
	};
	bool cautare_Utilizator_Student();
	bool cautare_Utilizator_Profesor();
};

void Utilizatori::adaugareUtilizator(){
	String^ firstname = gcnew String(firstName.c_str());
	String^ lastname = gcnew String(lastName.c_str());
	SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
	//SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
	String^ query = "INSERT INTO Users(FirstName,LastName) VALUES('"+firstname+"','"+lastname+"')";
	SqlCommand^ cmd = gcnew SqlCommand(query, conn);
	SqlDataReader^ reader;
	conn->Open();
	cmd->ExecuteReader();
	MessageBox::Show("User has been saved!");
}
bool Utilizatori::cautare_Utilizator_Student(){
	String^ firstname = gcnew String(firstName.c_str());
	String^ lastname = gcnew String(lastName.c_str());
	SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
	//SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
	conn->Open();
	String^ query = "SELECT COUNT(*) FROM Studenti WHERE FirstName  = '" + firstname + "' AND LastName = '" + lastname + "';";
	SqlCommand^ cmd = gcnew SqlCommand(query, conn);
	int count1 = (int) cmd->ExecuteScalar();
	conn->Close();
	return count1 == 1;
}
bool Utilizatori::cautare_Utilizator_Profesor(){
	String^ firstname = gcnew String(firstName.c_str());
	String^ lastname = gcnew String(lastName.c_str());
	SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
	//SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
	conn->Open();
	String^ query = "SELECT COUNT(*) FROM Proffessors  WHERE First_Name  = '" + firstname + "' AND Last_Name = '" + lastname+"';";
	SqlCommand^ cmd = gcnew SqlCommand(query, conn);
	int count =(int) cmd->ExecuteScalar();
	conn->Close();
	return count == 1;
}