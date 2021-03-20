#pragma once
#include "Utilizatori_clasa.h"
#include <msclr\marshal_cppstd.h>
#include <cstdlib>
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Data::SqlClient;
#include <ctime>
public class  Studenti : public Utilizatori{
public:
	int ID;
	string englishLevel;
	int studyCycle;
	string Field;
	string Nationality;
	string Sex;
	string Subject;
	string date;
	Studenti(String^ nivel_engleza, String^ field, String^ nume, String^ prenume, int ciclu_studii, String^ nationalitate, String^ sex, String^ data_nasterii);
	void adaugareStudentInBaza();
	int get_ID_Student();
	void adaugareContacte(String^ a,String^ b);

};
void Studenti::adaugareContacte(String^ numar,String^ Email){
	string full_name = firstName+ " " + lastName;
	String^ name_stud= gcnew String(full_name.c_str());
	SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
	conn->Open();
	String^ query = "INSERT INTO Contacts(Name,Email,Telefon) VALUES('" + name_stud + "','" + Email + "','" + numar + "');";
	SqlCommand^ cmd = gcnew SqlCommand(query, conn);
	cmd->ExecuteNonQuery();
}
int Studenti::get_ID_Student(){
	String^ firstname = gcnew String(firstName.c_str());
	String^ lastname = gcnew String(lastName.c_str());
	SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
	conn->Open();
	SqlCommand^ getID = gcnew SqlCommand("SELECT ID FROM Studenti WHERE FirstName = '" + firstname + "'AND LastName = '" + lastname + "';",conn);
	int id = (int)getID->ExecuteScalar();
	return id;
}
Studenti::Studenti(String^ nivel_engleza, String^ field, String^ nume, String^ prenume, int ciclu_studii, String^ nationalitate, String^ sex, String^ data_nasterii){
	firstName = msclr::interop::marshal_as<std::string>(prenume);
	lastName = msclr::interop::marshal_as<std::string>(nume);
	studyCycle = ciclu_studii;
	Nationality = msclr::interop::marshal_as<std::string>(nationalitate);
	Sex = msclr::interop::marshal_as<std::string>(sex);
	Field = msclr::interop::marshal_as<std::string>(field);
	date = msclr::interop::marshal_as<std::string>(data_nasterii);
	englishLevel = msclr::interop::marshal_as<std::string>(nivel_engleza);
 //a + rand() % (b-a+1)
};
void Studenti::adaugareStudentInBaza(){
	String^ firstname = gcnew String(firstName.c_str());
	String^ lastname = gcnew String(lastName.c_str());
	String^ nationality = gcnew String(Nationality.c_str());
	String^ sex = gcnew String(Sex.c_str());
	String^ eng_lev = gcnew String(englishLevel.c_str());
	String^ birthDate = gcnew String(date.c_str());
	String^ field = gcnew String(Field.c_str());
	SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
	SqlCommand^ cmd = gcnew SqlCommand("INSERT INTO Studenti(StudyCycle, FirstName, LastName, Nationality, Sex, EnglishLevel, BirthDate,Field,Validat) VALUES( '" + studyCycle + "' ,'" + firstname + "','" + lastname+ "','" + nationality + "','" + sex + "','" + eng_lev + "','" + birthDate + "','" + field + "','"+0+"')", conn);
	SqlDataReader^ reader;
		conn->Open();
		reader = cmd->ExecuteReader();
		while (reader->Read()){

		}
		conn->Close();
}