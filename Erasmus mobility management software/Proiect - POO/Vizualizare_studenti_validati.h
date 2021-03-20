#pragma once
using namespace std;
#include <msclr\marshal_cppstd.h>
#include <cstdlib>
#include <string.h>
namespace ProiectPOO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace System::Drawing::Printing;
	using namespace System::Configuration;


	/// <summary>
	/// Summary for Vizualizare_studenti_validati
	/// </summary>
	public ref class Vizualizare_studenti_validati : public System::Windows::Forms::Form
	{
	public:
		Vizualizare_studenti_validati(void)
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
		~Vizualizare_studenti_validati()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::CheckBox^  checkBox4;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::CheckBox^  checkBox5;
	private: System::Windows::Forms::CheckBox^  checkBox6;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::PrintDialog^  printDialog1;
	private: System::Drawing::Printing::PrintDocument^  printDocument1;
	private: System::Windows::Forms::Button^  button4;


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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->printDialog1 = (gcnew System::Windows::Forms::PrintDialog());
			this->printDocument1 = (gcnew System::Drawing::Printing::PrintDocument());
			this->button4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ActiveCaption;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Sitka Text", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Sitka Text", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->Location = System::Drawing::Point(13, 113);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(854, 185);
			this->dataGridView1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.25F));
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(158, 28);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Studenti validati";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button1->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.25F));
			this->button1->Location = System::Drawing::Point(732, 7);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(135, 41);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Exit";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Vizualizare_studenti_validati::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"Study Cycle" });
			this->comboBox1->Location = System::Drawing::Point(289, 19);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 3;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Vizualizare_studenti_validati::comboBox1_SelectedIndexChanged);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Sitka Text", 8.25F));
			this->checkBox1->Location = System::Drawing::Point(426, 12);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(80, 20);
			this->checkBox1->TabIndex = 4;
			this->checkBox1->Text = L"checkBox1";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->Visible = false;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Sitka Text", 8.25F));
			this->checkBox2->Location = System::Drawing::Point(617, 12);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(81, 20);
			this->checkBox2->TabIndex = 5;
			this->checkBox2->Text = L"checkBox2";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->Visible = false;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Font = (gcnew System::Drawing::Font(L"Sitka Text", 8.25F));
			this->checkBox3->Location = System::Drawing::Point(426, 46);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(81, 20);
			this->checkBox3->TabIndex = 6;
			this->checkBox3->Text = L"checkBox3";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->Visible = false;
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Font = (gcnew System::Drawing::Font(L"Sitka Text", 8.25F));
			this->checkBox4->Location = System::Drawing::Point(617, 46);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(82, 20);
			this->checkBox4->TabIndex = 7;
			this->checkBox4->Text = L"checkBox4";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.25F));
			this->label2->Location = System::Drawing::Point(177, 11);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(90, 28);
			this->label2->TabIndex = 8;
			this->label2->Text = L"SORT BY";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.25F));
			this->button2->Location = System::Drawing::Point(162, 46);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(121, 38);
			this->button2->TabIndex = 9;
			this->button2->Text = L"SORT";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Vizualizare_studenti_validati::button2_Click);
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Font = (gcnew System::Drawing::Font(L"Sitka Text", 8.25F));
			this->checkBox5->Location = System::Drawing::Point(426, 79);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(81, 20);
			this->checkBox5->TabIndex = 10;
			this->checkBox5->Text = L"checkBox5";
			this->checkBox5->UseVisualStyleBackColor = true;
			this->checkBox5->Visible = false;
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Font = (gcnew System::Drawing::Font(L"Sitka Text", 8.25F));
			this->checkBox6->Location = System::Drawing::Point(617, 79);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(82, 20);
			this->checkBox6->TabIndex = 11;
			this->checkBox6->Text = L"checkBox6";
			this->checkBox6->UseVisualStyleBackColor = true;
			this->checkBox6->Visible = false;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Semester 1", L"Semester 2" });
			this->comboBox2->Location = System::Drawing::Point(289, 59);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 12;
			this->comboBox2->Visible = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button3->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.25F));
			this->button3->Location = System::Drawing::Point(3, 45);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(135, 41);
			this->button3->TabIndex = 13;
			this->button3->Text = L"Back";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Vizualizare_studenti_validati::button3_Click);
			// 
			// printDialog1
			// 
			this->printDialog1->UseEXDialog = true;
			// 
			// printDocument1
			// 
			this->printDocument1->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &Vizualizare_studenti_validati::printDocument1_PrintPage);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button4->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.25F));
			this->button4->Location = System::Drawing::Point(732, 59);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(135, 41);
			this->button4->TabIndex = 14;
			this->button4->Text = L"Print";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Vizualizare_studenti_validati::button4_Click);
			// 
			// Vizualizare_studenti_validati
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(896, 323);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->checkBox6);
			this->Controls->Add(this->checkBox5);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->MaximumSize = System::Drawing::Size(912, 362);
			this->MinimumSize = System::Drawing::Size(912, 362);
			this->Name = L"Vizualizare_studenti_validati";
			this->Text = L"Vizualizare_studenti_validati";
			this->Load += gcnew System::EventHandler(this, &Vizualizare_studenti_validati::Vizualizare_studenti_validati_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Vizualizare_studenti_validati_Load(System::Object^  sender, System::EventArgs^  e) {


	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (comboBox1->SelectedItem == "Study Cycle"){
			checkBox1->Visible = true;
			checkBox2->Visible = true;
			checkBox3->Visible = true;
			checkBox4->Visible = true;
			checkBox5->Visible = true;
			checkBox6->Visible = true;
			comboBox2->Visible = true;
			checkBox1->Text = "1-st Year";
			checkBox2->Text = "2-nd Year";
			checkBox3->Text = "3-rd Year";
			checkBox4->Text = "4-th Year";
			checkBox5->Text = "1-st Year Master";
			checkBox6->Text = "2-nd Year Master";
		}
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		//anul 1
		if (checkBox1->Checked == true){
			if (comboBox2->SelectedItem == "Semester 1"){
				SqlDataAdapter^ data;
				DataSet^ source = gcnew DataSet();
				SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
				//SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
				conn->Open();
				data = gcnew SqlDataAdapter("SELECT ID,StudyCycle,FirstName,LastName,Nationality,Sex,EnglishLevel,Birthdate,Field,Email,Id_university  FROM Studenti WHERE Validat = '" + 1 + "'AND StudyCycle = 1 AND materii_1_1 >=1; ", conn);
				data->Fill(source);
				DataTable ^dt = source->Tables[0];
				dataGridView1->DataSource = dt;

			}
			else if (comboBox2->SelectedItem == "Semester 2"){
				//VEZI OAMENI CU MATERII DE PE SEMESTRUL 2
				SqlDataAdapter^ data;
				DataSet^ source = gcnew DataSet();
				SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
				//SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
				conn->Open();
				data = gcnew SqlDataAdapter("SELECT ID,StudyCycle,FirstName,LastName,Nationality,Sex,EnglishLevel,Birthdate,Field,Email,Id_university  FROM Studenti WHERE Validat = '" + 1 + "'AND StudyCycle = 1 AND materii_1_2 >=1; ", conn);
				data->Fill(source);
				DataTable ^dt = source->Tables[0];
				dataGridView1->DataSource = dt;

			}
		}
		//anul 2
		if (checkBox2->Checked == true){
			if (comboBox2->SelectedItem == "Semester 1"){

				//VEZI OAMENI CU MATERII DE PE SEM 1
				SqlDataAdapter^ data;
				DataSet^ source = gcnew DataSet();
				SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
				//SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
				conn->Open();
				data = gcnew SqlDataAdapter("SELECT ID,StudyCycle,FirstName,LastName,Nationality,Sex,EnglishLevel,Birthdate,Field,Email,Id_university FROM Studenti WHERE Validat = '" + 1 + "'AND StudyCycle = 2 AND materii_2_1 >=1; ", conn);
				data->Fill(source);
				DataTable ^dt = source->Tables[0];
				dataGridView1->DataSource = dt;
			}
			else if (comboBox2->SelectedItem == "Semester 2"){
				SqlDataAdapter^ data;
				DataSet^ source = gcnew DataSet();
				SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
				//SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
				conn->Open();
				data = gcnew SqlDataAdapter("SELECT ID,StudyCycle,FirstName,LastName,Nationality,Sex,EnglishLevel,Birthdate,Field,Email,Id_university,Email,Id_university   FROM Studenti WHERE Validat = '" + 1 + "'AND StudyCycle = 2 AND materii_2_2 >=1; ", conn);
				data->Fill(source);
				DataTable ^dt = source->Tables[0];
				dataGridView1->DataSource = dt;
			}
		}
		//anul 3
		if (checkBox3->Checked == true){
			if (comboBox2->SelectedItem == "Semester 1"){
				//VEZI OAMENI CU MATERII DE PE SEM 1
				SqlDataAdapter^ data;
				DataSet^ source = gcnew DataSet();
				SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
				//SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
				conn->Open();
				data = gcnew SqlDataAdapter("SELECT ID,StudyCycle,FirstName,LastName,Nationality,Sex,EnglishLevel,Birthdate,Field,Email,Id_university,Email,Id_university   FROM Studenti WHERE Validat = '" + 1 + "'AND StudyCycle = 3 AND materii_3_1 >=1; ", conn);
				data->Fill(source);
				DataTable ^dt = source->Tables[0];
				dataGridView1->DataSource = dt;

			}
			else if (comboBox2->SelectedItem == "Semester 2"){
				//VEZI OAMENI CU MATERII DE PE SEMESTRUL 2
				SqlDataAdapter^ data;
				DataSet^ source = gcnew DataSet();
				SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
				//SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
				conn->Open();
				data = gcnew SqlDataAdapter("SELECT ID,StudyCycle,FirstName,LastName,Nationality,Sex,EnglishLevel,Birthdate,Field,Email,Id_university  FROM Studenti WHERE Validat = '" + 1 + "'AND StudyCycle = 3 AND materii_3_2 >=1; ", conn);
				data->Fill(source);
				DataTable ^dt = source->Tables[0];
				dataGridView1->DataSource = dt;
			}
		}
		//anul 4
		if (checkBox4->Checked == true){
			if (comboBox2->SelectedItem == "Semester 1"){
				SqlDataAdapter^ data;
				DataSet^ source = gcnew DataSet();
				SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
				//SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
				conn->Open();
				data = gcnew SqlDataAdapter("SELECT ID,StudyCycle,FirstName,LastName,Nationality,Sex,EnglishLevel,Birthdate,Field,Email,Id_university  FROM Studenti WHERE Validat = '" + 1 + "'AND StudyCycle = 4 AND materii_4_1 >=1; ", conn);
				data->Fill(source);
				DataTable ^dt = source->Tables[0];
				dataGridView1->DataSource = dt;
			}
			else if (comboBox2->SelectedItem == "Semester 2"){
				SqlDataAdapter^ data;
				DataSet^ source = gcnew DataSet();
				SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
				//SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
				conn->Open();
				data = gcnew SqlDataAdapter("SELECT ID,StudyCycle,FirstName,LastName,Nationality,Sex,EnglishLevel,Birthdate,Field,Email,Id_university  FROM Studenti WHERE Validat = '" + 1 + "'AND StudyCycle = 4 AND materii_4_2 >=1; ", conn);
				data->Fill(source);
				DataTable ^dt = source->Tables[0];
				dataGridView1->DataSource = dt;

			}
		}
		//master an 1
		if (checkBox5->Checked == true){
			if (comboBox2->SelectedItem == "Semester 1"){
				//VEZI OAMENI CU MATERII DE PE SEM 1
				SqlDataAdapter^ data;
				DataSet^ source = gcnew DataSet();
				SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
				//SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
				conn->Open();
				data = gcnew SqlDataAdapter("SELECT ID,StudyCycle,FirstName,LastName,Nationality,Sex,EnglishLevel,Birthdate,Field,Email,Id_university  FROM Studenti WHERE Validat = '" + 1 + "'AND StudyCycle = 5 AND materii_5_1 >=1; ", conn);
				data->Fill(source);
				DataTable ^dt = source->Tables[0];
				dataGridView1->DataSource = dt;

			}
			else if (comboBox2->SelectedItem == "Semester 2"){
				// PE SEMESTRUL 2
				SqlDataAdapter^ data;
				DataSet^ source = gcnew DataSet();
				SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
				//SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
				conn->Open();
				data = gcnew SqlDataAdapter("SELECT ID,StudyCycle,FirstName,LastName,Nationality,Sex,EnglishLevel,Birthdate,Field ,Email,Id_university FROM Studenti WHERE Validat = '" + 1 + "'AND StudyCycle = 5 AND materii_5_2 >=1; ", conn);
				data->Fill(source);
				DataTable ^dt = source->Tables[0];
				dataGridView1->DataSource = dt;
			}
		}
		//master an 2
		if (checkBox6->Checked == true){
			if (comboBox2->SelectedItem == "Semester 1"){
				SqlDataAdapter^ data;
				DataSet^ source = gcnew DataSet();
				SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
				//SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
				conn->Open();
				data = gcnew SqlDataAdapter("SELECT ID,StudyCycle,FirstName,LastName,Nationality,Sex,EnglishLevel,Birthdate,Field,Email,Id_university  FROM Studenti WHERE Validat = '" + 1 + "'AND StudyCycle = 6 AND materii_6_1 >=1; ", conn);
				data->Fill(source);
				DataTable ^dt = source->Tables[0];
				dataGridView1->DataSource = dt;

				//VEZI OAMENI CU MATERII DE PE SEM 1
			}
			else if (comboBox2->SelectedItem == "Semester 2"){
				//VEZI OAMENI CU MATERII DE PE SEMESTRUL 2
				SqlDataAdapter^ data;
				DataSet^ source = gcnew DataSet();
				SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
				//SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
				conn->Open();
				data = gcnew SqlDataAdapter("SELECT ID,StudyCycle,FirstName,LastName,Nationality,Sex,EnglishLevel,Birthdate,Field,Email,Id_university  FROM Studenti WHERE Validat = '" + 1 + "'AND StudyCycle = 6 AND materii_6_2 >=1; ", conn);
				data->Fill(source);
				DataTable ^dt = source->Tables[0];
				dataGridView1->DataSource = dt;
			}
		}
	};
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
	}
private: System::Void printDocument1_PrintPage(System::Object^  sender, System::Drawing::Printing::PrintPageEventArgs^  e) {
	e->Graphics->DrawString("Politehnica University of Bucharest", this->Font, System::Drawing::Brushes::Black, 0, 0);
	e->Graphics->DrawString("ERASMUS STUDENT LIST", this->Font, System::Drawing::Brushes::Black, 100, 300);



	e->Graphics->DrawString("StudyCycle", this->Font, System::Drawing::Brushes::Brown, 100, 400);
	e->Graphics->DrawString("FirstName", this->Font, System::Drawing::Brushes::Brown, 200, 400);
	e->Graphics->DrawString("LastName", this->Font, System::Drawing::Brushes::Brown, 300, 400);
	e->Graphics->DrawString("Nationality", this->Font, System::Drawing::Brushes::Brown, 400, 400);
	e->Graphics->DrawString("Sex", this->Font, System::Drawing::Brushes::Brown, 500, 400);
	int poz_i_sus_jos = 450;
	for (int i = 0; i < dataGridView1->Rows->Count; i++){
		int poz_i_s_d = 100;
		for (int j = 1; j <= 5; j++){
			e->Graphics->DrawString(Convert::ToString(dataGridView1->Rows[i]->Cells[j]->Value), this->Font, System::Drawing::Brushes::Black, poz_i_s_d, poz_i_sus_jos);
			poz_i_s_d = poz_i_s_d + 100;
		}

		poz_i_sus_jos = poz_i_sus_jos + 50;
	}

	//e->Graphics->DrawString("EnglishLevel", this->Font, System::Drawing::Brushes::Brown, 100, poz_sus_jos);
	//e->Graphics->DrawString("Birthdate", this->Font, System::Drawing::Brushes::Brown, 200, poz_sus_jos);
	e->Graphics->DrawString("Field", this->Font, System::Drawing::Brushes::Brown, 100, poz_i_sus_jos + 50);
	e->Graphics->DrawString("Email", this->Font, System::Drawing::Brushes::Brown, 400, poz_i_sus_jos + 50);
	//e->Graphics->DrawString("Id_university", this->Font, System::Drawing::Brushes::Brown, 400, poz_i_sus_jos + 100);
	poz_i_sus_jos = poz_i_sus_jos + 100;
	for (int i = 0; i < dataGridView1->Rows->Count; i++){
		int poz_i_s_d = 100;
		for (int j = 8; j < 10; j++){
			e->Graphics->DrawString(Convert::ToString(dataGridView1->Rows[i]->Cells[j]->Value), this->Font, System::Drawing::Brushes::Black, poz_i_s_d, poz_i_sus_jos);
			poz_i_s_d = poz_i_s_d + 300;
		}

		poz_i_sus_jos = poz_i_sus_jos + 50;
	}
		

}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	printDialog1->Document = printDocument1;
	PrintController^ printcontroller = gcnew StandardPrintController();
	printDocument1->PrintController = printcontroller;
	PaperSize^ ps = gcnew PaperSize();
	ps->RawKind = (int)PaperKind::A4;
	printDocument1->DefaultPageSettings->PaperSize = ps;
	//printDocument1->DefaultPageSettings->Landscape = true;
	printDocument1->Print();
}
};
}