#pragma once
#include <msclr\marshal_cppstd.h>
#include "Admin.h"
#include "Afisare_info_stud_pt_admin.h"
#include "Autentificare_Login.h"
#include "Administrare_situatie_studenti.h"
#include "Vizualizare_studenti_validati.h"
using namespace std;
namespace ProiectPOO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Logare_Admin
	/// </summary>
	public ref class Logare_Admin : public System::Windows::Forms::Form
	{
	public:
		int optiune;
	public:
		Logare_Admin(void)
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
		~Logare_Admin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox3;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Sitka Small", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(195, 17);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(229, 22);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Sitka Small", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(195, 89);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(229, 22);
			this->textBox2->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(28, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(165, 28);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Admin First Name";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 14.25F));
			this->label2->Location = System::Drawing::Point(28, 84);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(161, 28);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Admin Last Name";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::Control;
			this->button1->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 14.25F));
			this->button1->Location = System::Drawing::Point(275, 136);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(149, 50);
			this->button1->TabIndex = 4;
			this->button1->Text = L"LOGIN";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Logare_Admin::button1_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 14.25F));
			this->checkBox1->Location = System::Drawing::Point(456, 17);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(269, 32);
			this->checkBox1->TabIndex = 5;
			this->checkBox1->Text = L"Vizualizare studenti validati";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Logare_Admin::checkBox1_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 14.25F));
			this->checkBox2->Location = System::Drawing::Point(456, 84);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(248, 32);
			this->checkBox2->TabIndex = 6;
			this->checkBox2->Text = L"Validare contract studenti";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &Logare_Admin::checkBox2_CheckedChanged);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 14.25F));
			this->checkBox3->Location = System::Drawing::Point(456, 149);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(274, 60);
			this->checkBox3->TabIndex = 7;
			this->checkBox3->Text = L"Vizualizare situatie studenti \r\nincoming";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &Logare_Admin::checkBox3_CheckedChanged);
			// 
			// Logare_Admin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->ClientSize = System::Drawing::Size(722, 237);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->MaximumSize = System::Drawing::Size(738, 276);
			this->MinimumSize = System::Drawing::Size(738, 276);
			this->Name = L"Logare_Admin";
			this->Text = L"Sign in Administrator";
			this->Load += gcnew System::EventHandler(this, &Logare_Admin::Logare_Admin_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ prenume = textBox1->Text;
		String^ nume = textBox2->Text;
		string firstName = msclr::interop::marshal_as<std::string>(prenume);
		string lastName = msclr::interop::marshal_as<std::string>(nume);
		Admin a(firstName, lastName);
			if (a.cautare_Utilizator_Student() == false){
				if (a.verificareAdmin() == true){
					a.adaugareUtilizator();
					if (optiune == 1){
						//this->Hide();
						Vizualizare_studenti_validati^ vizualizare = gcnew Vizualizare_studenti_validati;
						vizualizare->Show(this);
					}
					else if (optiune == 2){
						//this->Hide();
						Afisare_info_stud_pt_admin^ forma_validare_contracte = gcnew Afisare_info_stud_pt_admin;
						forma_validare_contracte->Show(this);
					}
					else if (optiune == 3){
						//this->Hide();
						Administrare_situatie_studenti^ situatie = gcnew Administrare_situatie_studenti;
						situatie->Show(this);
					}
					
				}
				else{
					MessageBox::Show("You are not the admin! You are an intruder!Bye!");
					this->Close();
					Application::Exit();
				}
			}
			else{
				MessageBox::Show("You are not the admin! You are a student! Please log in as a student! ");
				this->Close();
				Application::Exit();
			}

	}
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	optiune = 1;
}
private: System::Void Logare_Admin_Load(System::Object^  sender, System::EventArgs^  e) {
	optiune = 2;
}
private: System::Void checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	optiune = 3;
}
private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	optiune = 2;
}
};
}
