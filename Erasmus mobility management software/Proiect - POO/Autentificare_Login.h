#pragma once
#include "Forma_principala.h";
#include "Login.h"
#include "Profesori.h"
#include "Profesori_Logare.h"
#include "Logare_Admin.h"
#include "Afisare_info_stud_pt_admin.h"
#include "Administrare_situatie_studenti.h"
#include "Vizualizare_studenti_validati.h"

namespace ProiectPOO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Autentificare_Login
	/// </summary>
	public ref class Autentificare_Login : public System::Windows::Forms::Form
	{
	public:
		Autentificare_Login(void)
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
		~Autentificare_Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  autentificareToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  studentToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  profesorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  adminToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  inregistrareToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  studentToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  profesorToolStripMenuItem1;

	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;





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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Autentificare_Login::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->autentificareToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->studentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->profesorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->adminToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->inregistrareToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->studentToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->profesorToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->autentificareToolStripMenuItem,
					this->inregistrareToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(540, 29);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// autentificareToolStripMenuItem
			// 
			this->autentificareToolStripMenuItem->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->autentificareToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->studentToolStripMenuItem,
					this->profesorToolStripMenuItem, this->adminToolStripMenuItem
			});
			this->autentificareToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 11.25F, System::Drawing::FontStyle::Italic,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->autentificareToolStripMenuItem->Name = L"autentificareToolStripMenuItem";
			this->autentificareToolStripMenuItem->Size = System::Drawing::Size(66, 25);
			this->autentificareToolStripMenuItem->Text = L"Sign in";
			// 
			// studentToolStripMenuItem
			// 
			this->studentToolStripMenuItem->BackColor = System::Drawing::SystemColors::HighlightText;
			this->studentToolStripMenuItem->Name = L"studentToolStripMenuItem";
			this->studentToolStripMenuItem->Size = System::Drawing::Size(152, 26);
			this->studentToolStripMenuItem->Text = L"Student";
			this->studentToolStripMenuItem->Click += gcnew System::EventHandler(this, &Autentificare_Login::studentToolStripMenuItem_Click);
			// 
			// profesorToolStripMenuItem
			// 
			this->profesorToolStripMenuItem->Name = L"profesorToolStripMenuItem";
			this->profesorToolStripMenuItem->Size = System::Drawing::Size(152, 26);
			this->profesorToolStripMenuItem->Text = L"Profesor";
			this->profesorToolStripMenuItem->Click += gcnew System::EventHandler(this, &Autentificare_Login::profesorToolStripMenuItem_Click);
			// 
			// adminToolStripMenuItem
			// 
			this->adminToolStripMenuItem->Name = L"adminToolStripMenuItem";
			this->adminToolStripMenuItem->Size = System::Drawing::Size(152, 26);
			this->adminToolStripMenuItem->Text = L"Admin";
			this->adminToolStripMenuItem->Click += gcnew System::EventHandler(this, &Autentificare_Login::adminToolStripMenuItem_Click);
			// 
			// inregistrareToolStripMenuItem
			// 
			this->inregistrareToolStripMenuItem->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->inregistrareToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->studentToolStripMenuItem1,
					this->profesorToolStripMenuItem1
			});
			this->inregistrareToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 11.25F, System::Drawing::FontStyle::Italic));
			this->inregistrareToolStripMenuItem->Name = L"inregistrareToolStripMenuItem";
			this->inregistrareToolStripMenuItem->Size = System::Drawing::Size(70, 25);
			this->inregistrareToolStripMenuItem->Text = L"Sign up";
			// 
			// studentToolStripMenuItem1
			// 
			this->studentToolStripMenuItem1->Name = L"studentToolStripMenuItem1";
			this->studentToolStripMenuItem1->Size = System::Drawing::Size(152, 26);
			this->studentToolStripMenuItem1->Text = L"Student";
			this->studentToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Autentificare_Login::studentToolStripMenuItem1_Click);
			// 
			// profesorToolStripMenuItem1
			// 
			this->profesorToolStripMenuItem1->Name = L"profesorToolStripMenuItem1";
			this->profesorToolStripMenuItem1->Size = System::Drawing::Size(152, 26);
			this->profesorToolStripMenuItem1->Text = L"Profesor";
			this->profesorToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Autentificare_Login::profesorToolStripMenuItem1_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->exitToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 11.25F, System::Drawing::FontStyle::Italic));
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(48, 25);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Autentificare_Login::exitToolStripMenuItem_Click);
			// 
			// Autentificare_Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDark;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(540, 377);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximumSize = System::Drawing::Size(556, 416);
			this->MinimumSize = System::Drawing::Size(556, 416);
			this->Name = L"Autentificare_Login";
			this->Text = L"Autentificare_Login";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
	public: System::Void studentToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
		Forma_principala ^ autentificare_stud = gcnew Forma_principala;
		autentificare_stud->Show(this);
	}
	private: System::Void studentToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
		Login ^ login_form_stud = gcnew Login;
		login_form_stud->Show(this);

	}
private: System::Void profesorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	Profesori_Logare^ profi_log = gcnew Profesori_Logare;
	profi_log->Show(this);
}
private: System::Void profesorToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	Profesori^ profi = gcnew Profesori;
	profi->Show(this);
}
private: System::Void adminToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	Logare_Admin^ admin = gcnew Logare_Admin;
	admin->Show(this);
}
};
};
