#pragma once
#include <sstream>
#include <chrono>
#include <ctime>
#include <msclr\marshal_cppstd.h>
#include "Studenti.h"
#include "Login.h"
#include "Alegere_Materii.h"
#include "Profesori_Logare.h"
using namespace std;
namespace ProiectPOO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for Forma_principala
	/// </summary>
	public ref class Forma_principala : public System::Windows::Forms::Form
	{
	public:
		int id_stud_curent;
	public:
		Forma_principala()
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Forma_principala()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	public: System::Windows::Forms::TextBox^  textBox1;
	private:
	public: System::Windows::Forms::TextBox^  textBox2;
	public: System::Windows::Forms::TextBox^  textBox3;
	public: System::Windows::Forms::TextBox^  textBox4;




	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox7;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::DateTimePicker^  dateOfBirth;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::Label^  label10;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Forma_principala::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->dateOfBirth = (gcnew System::Windows::Forms::DateTimePicker());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 14.25F));
			this->button1->Location = System::Drawing::Point(526, 15);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(119, 47);
			this->button1->TabIndex = 0;
			this->button1->Text = L"SAVE";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Forma_principala::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 8));
			this->textBox1->Location = System::Drawing::Point(152, 16);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 21);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Forma_principala::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 8));
			this->textBox2->Location = System::Drawing::Point(152, 40);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 21);
			this->textBox2->TabIndex = 2;
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 8));
			this->textBox3->Location = System::Drawing::Point(152, 92);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 21);
			this->textBox3->TabIndex = 3;
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 8));
			this->textBox4->Location = System::Drawing::Point(152, 66);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 21);
			this->textBox4->TabIndex = 4;
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 9));
			this->textBox5->Location = System::Drawing::Point(417, 92);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(225, 23);
			this->textBox5->TabIndex = 5;
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 8));
			this->textBox6->Location = System::Drawing::Point(420, 42);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 21);
			this->textBox6->TabIndex = 6;
			// 
			// textBox7
			// 
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 8));
			this->textBox7->Location = System::Drawing::Point(420, 16);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(100, 21);
			this->textBox7->TabIndex = 7;
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &Forma_principala::textBox7_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::Window;
			this->label1->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(46, 8);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 28);
			this->label1->TabIndex = 9;
			this->label1->Text = L"FirstName";
			this->label1->Click += gcnew System::EventHandler(this, &Forma_principala::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::HighlightText;
			this->label2->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 14.25F));
			this->label2->Location = System::Drawing::Point(47, 32);
			this->label2->MaximumSize = System::Drawing::Size(101, 30);
			this->label2->MinimumSize = System::Drawing::Size(101, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(101, 30);
			this->label2->TabIndex = 10;
			this->label2->Text = L"LastName";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 14.25F));
			this->label3->Location = System::Drawing::Point(26, 86);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(122, 28);
			this->label3->TabIndex = 11;
			this->label3->Text = L"English Level";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label4->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 14.25F));
			this->label4->Location = System::Drawing::Point(37, 58);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(109, 28);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Study Cycle";
			this->label4->Click += gcnew System::EventHandler(this, &Forma_principala::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label5->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 14.25F));
			this->label5->Location = System::Drawing::Point(290, 88);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(126, 28);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Field of Study";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label6->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 14.25F));
			this->label6->Location = System::Drawing::Point(306, 36);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(108, 28);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Nationality";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label7->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 14.25F));
			this->label7->Location = System::Drawing::Point(297, 64);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(119, 28);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Date of birth";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label8->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 14.25F));
			this->label8->Location = System::Drawing::Point(373, 8);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(41, 28);
			this->label8->TabIndex = 16;
			this->label8->Text = L"Sex";
			// 
			// dateOfBirth
			// 
			this->dateOfBirth->Location = System::Drawing::Point(420, 68);
			this->dateOfBirth->Name = L"dateOfBirth";
			this->dateOfBirth->Size = System::Drawing::Size(225, 20);
			this->dateOfBirth->TabIndex = 17;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label9->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 14.25F));
			this->label9->Location = System::Drawing::Point(12, 114);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(136, 28);
			this->label9->TabIndex = 18;
			this->label9->Text = L"Phone Number";
			// 
			// textBox8
			// 
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 8));
			this->textBox8->Location = System::Drawing::Point(152, 118);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(148, 21);
			this->textBox8->TabIndex = 19;
			this->textBox8->TextChanged += gcnew System::EventHandler(this, &Forma_principala::textBox8_TextChanged);
			// 
			// textBox9
			// 
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox9->Location = System::Drawing::Point(420, 118);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(225, 23);
			this->textBox9->TabIndex = 20;
			this->textBox9->TextChanged += gcnew System::EventHandler(this, &Forma_principala::textBox9_TextChanged);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label10->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 14.25F));
			this->label10->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label10->Location = System::Drawing::Point(354, 114);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(60, 28);
			this->label10->TabIndex = 21;
			this->label10->Text = L"Email";
			// 
			// Forma_principala
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(654, 361);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->dateOfBirth);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Forma_principala";
			this->Text = L"Student Sign up";
			this->Load += gcnew System::EventHandler(this, &Forma_principala::Forma_principala_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ firstName = textBox1->Text;
		String^ lastName = textBox2->Text;
		String^ eng_lev = textBox3->Text;
		string studycycle = msclr::interop::marshal_as<std::string>(textBox4->Text);
		int studyCycle = stoi(studycycle);
		String^ field = textBox5->Text;
		String^ nationality = textBox6->Text;
		String^ sex = textBox7->Text;
		String^ date = dateOfBirth->Text;
		Studenti student(eng_lev, field, lastName, firstName, studyCycle, nationality, sex, date);
		if (student.cautare_Utilizator_Profesor() == false){
			if (student.cautare_Utilizator_Student() == true){
				MessageBox::Show("A user with your firstname and lastname already exists");
				this->Hide();
				Login^ form = gcnew Login;
				form->Show(this);
			}
			else{
				string firstname = msclr::interop::marshal_as<std::string>(firstName);
				student.setfirstName(firstname);
				string lastname = msclr::interop::marshal_as<std::string>(lastName);
				student.setlastName(lastname);
				student.adaugareUtilizator();
				student.adaugareStudentInBaza();
				student.adaugareContacte(textBox8->Text, textBox9->Text);
				this->Hide();
				MessageBox::Show("Redirecting you to the page where you choose the subjects");
				Alegere_Materii^ materii = gcnew Alegere_Materii;
				id_stud_curent = student.get_ID_Student();
				materii->id_student = id_stud_curent;
				materii->Show(this);
			}
		}
		else{
			MessageBox::Show("There is already a proffesor with the same data as you!");
			this->Hide();
			Profesori_Logare^ profi = gcnew Profesori_Logare;
			profi->Show(this);
		}

	}
	private: System::Void Forma_principala_Load(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox8_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox9_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox7_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
};