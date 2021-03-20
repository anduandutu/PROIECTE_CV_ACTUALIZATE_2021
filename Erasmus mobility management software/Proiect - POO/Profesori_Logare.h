#pragma once
using namespace std;
#include "VizualizareMateriiPredate.h"
namespace ProiectPOO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for Profesori_Logare
	/// </summary>
	public ref class Profesori_Logare : public System::Windows::Forms::Form
	{
	public:
		Profesori_Logare(void)
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
		~Profesori_Logare()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.25F));
			this->label1->Location = System::Drawing::Point(11, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(223, 28);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Proffessor\'s First Name";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Sitka Small", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(240, 25);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(287, 24);
			this->textBox1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.25F));
			this->label2->Location = System::Drawing::Point(13, 69);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(218, 28);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Proffessor\'s Last Name";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Sitka Small", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(240, 72);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(287, 24);
			this->textBox2->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(309, 113);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(218, 63);
			this->button1->TabIndex = 4;
			this->button1->Text = L"LOGIN";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Profesori_Logare::button1_Click);
			// 
			// Profesori_Logare
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(579, 188);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->MaximumSize = System::Drawing::Size(595, 227);
			this->MinimumSize = System::Drawing::Size(595, 227);
			this->Name = L"Profesori_Logare";
			this->Text = L"Profesori_Logare";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		//SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
		SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
		conn->Open();
		VizualizareMateriiPredate ^materii = gcnew VizualizareMateriiPredate;
		String^ query1 = "SELECT Id FROM Proffessors  WHERE First_Name  = '" + textBox1->Text + "' AND Last_Name = '" + textBox2->Text + "';";
		SqlCommand^ cmd1 = gcnew SqlCommand(query1, conn);
		int id = (int)cmd1->ExecuteScalar();
		materii->id_prof = id;
		this->Hide();
		materii->Show(this);
	}
};
}
