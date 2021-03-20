#pragma once
using namespace std;
#include <string.h>
#include <cstdlib>
namespace ProiectPOO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for Vizualizare_info_student
	/// </summary>
	public ref class Vizualizare_info_student : public System::Windows::Forms::Form
	{
	public:
		int id_stud;
		bool validabil;
	private: System::Windows::Forms::PrintDialog^  printDialog1;
	public:
	private: System::Drawing::Printing::PrintDocument^  printDocument1;
			 bool validat;
	public:
		Vizualizare_info_student(void)
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
		~Vizualizare_info_student()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox9;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->printDialog1 = (gcnew System::Windows::Forms::PrintDialog());
			this->printDocument1 = (gcnew System::Drawing::Printing::PrintDocument());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 14.25F));
			this->label1->Location = System::Drawing::Point(50, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(101, 28);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ID Student";
			this->label1->Click += gcnew System::EventHandler(this, &Vizualizare_info_student::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(170, 19);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(167, 24);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Vizualizare_info_student::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 14.25F));
			this->label2->Location = System::Drawing::Point(42, 63);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(109, 28);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Study Cycle";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 14.25F));
			this->label3->Location = System::Drawing::Point(42, 118);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(105, 28);
			this->label3->TabIndex = 3;
			this->label3->Text = L"First Name";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 14.25F));
			this->label4->Location = System::Drawing::Point(46, 171);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(101, 28);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Last Name";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 14.25F));
			this->label5->Location = System::Drawing::Point(367, 13);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(122, 28);
			this->label5->TabIndex = 5;
			this->label5->Text = L"English Level";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 14.25F));
			this->label6->Location = System::Drawing::Point(439, 63);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(41, 28);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Sex";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 14.25F));
			this->label7->Location = System::Drawing::Point(386, 118);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(94, 28);
			this->label7->TabIndex = 7;
			this->label7->Text = L"BirthDate";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 14.25F));
			this->label8->Location = System::Drawing::Point(428, 175);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(52, 28);
			this->label8->TabIndex = 8;
			this->label8->Text = L"Field";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 14.25F));
			this->label9->Location = System::Drawing::Point(39, 228);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(108, 28);
			this->label9->TabIndex = 9;
			this->label9->Text = L"Nationality";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.25F));
			this->label10->Location = System::Drawing::Point(12, 275);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(158, 28);
			this->label10->TabIndex = 10;
			this->label10->Text = L"Subjects student";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ActiveCaption;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::WindowFrame;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 9.749999F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->Location = System::Drawing::Point(16, 317);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 9.749999F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->Size = System::Drawing::Size(701, 313);
			this->dataGridView1->TabIndex = 11;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Vizualizare_info_student::dataGridView1_CellContentClick);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button1->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.25F));
			this->button1->Location = System::Drawing::Point(170, 657);
			this->button1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(381, 79);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Print valid contract";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Vizualizare_info_student::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(170, 67);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(167, 24);
			this->textBox2->TabIndex = 13;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Vizualizare_info_student::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(170, 122);
			this->textBox3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(167, 24);
			this->textBox3->TabIndex = 14;
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(170, 175);
			this->textBox4->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(167, 24);
			this->textBox4->TabIndex = 15;
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox5->Location = System::Drawing::Point(170, 228);
			this->textBox5->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(167, 24);
			this->textBox5->TabIndex = 16;
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox6->Location = System::Drawing::Point(517, 20);
			this->textBox6->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(167, 24);
			this->textBox6->TabIndex = 17;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &Vizualizare_info_student::textBox6_TextChanged);
			// 
			// textBox7
			// 
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox7->Location = System::Drawing::Point(517, 67);
			this->textBox7->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(167, 24);
			this->textBox7->TabIndex = 18;
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &Vizualizare_info_student::textBox7_TextChanged);
			// 
			// textBox8
			// 
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox8->Location = System::Drawing::Point(517, 122);
			this->textBox8->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(167, 24);
			this->textBox8->TabIndex = 19;
			this->textBox8->TextChanged += gcnew System::EventHandler(this, &Vizualizare_info_student::textBox8_TextChanged);
			// 
			// textBox9
			// 
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox9->Location = System::Drawing::Point(517, 175);
			this->textBox9->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(167, 24);
			this->textBox9->TabIndex = 20;
			this->textBox9->TextChanged += gcnew System::EventHandler(this, &Vizualizare_info_student::textBox9_TextChanged);
			// 
			// printDialog1
			// 
			this->printDialog1->UseEXDialog = true;
			// 
			// printDocument1
			// 
			this->printDocument1->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &Vizualizare_info_student::printDocument1_PrintPage);
			// 
			// Vizualizare_info_student
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(746, 749);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 9.749999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"Vizualizare_info_student";
			this->Text = L"Vizualizare_info_student";
			this->Load += gcnew System::EventHandler(this, &Vizualizare_info_student::Vizualizare_info_student_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		//iau first-name-ul
		
	}
	private: System::Void Vizualizare_info_student_Load(System::Object^  sender, System::EventArgs^  e) {
		//conversie
		string id = to_string(id_stud);//si aici
		textBox1->Text = gcnew String(id.c_str());//aici
		SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
		//SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
		conn->Open();
		SqlCommand ^ cmd = gcnew SqlCommand("SELECT FirstName FROM Studenti WHERE ID = '" + id_stud + "';", conn);
		String^ firstName = (String^)cmd->ExecuteScalar();
		textBox3->Text = firstName;
		//iau study cycle 
		SqlCommand ^ cmd1 = gcnew SqlCommand("SELECT StudyCycle FROM Studenti WHERE ID = '" + id_stud + "';", conn);
		int studyCycle = (int)cmd1->ExecuteScalar();
		string sCycle = to_string(studyCycle);
		textBox2->Text = gcnew String(sCycle.c_str());
		//iau lastName
		SqlCommand ^ cmd2 = gcnew SqlCommand("SELECT LastName FROM Studenti WHERE ID = '" + id_stud + "';", conn);
		String^ lastName = (String^)cmd2->ExecuteScalar();
		textBox4->Text = lastName;
		//iau nationality
		SqlCommand ^ cmd3 = gcnew SqlCommand("SELECT Nationality FROM Studenti WHERE ID = '" + id_stud + "';", conn);
		String^ nationality = (String^)cmd3->ExecuteScalar();
		textBox5->Text = nationality;
		//englishLevel
		SqlCommand ^ cmd4 = gcnew SqlCommand("SELECT EnglishLevel FROM Studenti WHERE ID = '" + id_stud + "';", conn);
		String^ e_level = (String^)cmd4->ExecuteScalar();
		textBox6->Text = e_level;
		//sex
		SqlCommand ^ cmd5 = gcnew SqlCommand("SELECT Sex FROM Studenti WHERE ID = '" + id_stud + "';", conn);
		String^ sex = (String^)cmd5->ExecuteScalar();
		textBox7->Text = sex;
		//birthdate
		SqlCommand ^ cmd6 = gcnew SqlCommand("SELECT BirthDate FROM Studenti WHERE ID = '" + id_stud + "';", conn);
		String^ birth = (String^)cmd6->ExecuteScalar();
		textBox8->Text = birth;
		//field
		SqlCommand ^ cmd7 = gcnew SqlCommand("SELECT Field FROM Studenti WHERE ID = '" + id_stud + "';", conn);
		String^ field = (String^)cmd7->ExecuteScalar();
		textBox9->Text = field;
		//datagrid - materii
		SqlDataAdapter^ data;
		DataSet^ source = gcnew DataSet();
		//aici iau id-urile  materiilor alese
		data = gcnew SqlDataAdapter("SELECT Id_materie FROM Materii_intermediar WHERE Id_student ='" + id_stud + "'; ", conn);
		data->Fill(source);
		DataTable ^dt = source->Tables[0];
		dataGridView1->DataSource = dt;
		String^ query = "SELECT COUNT(*) Id_materie FROM Materii_intermediar WHERE Id_student ='" + id_stud + "';";
		SqlCommand^ cmd14 = gcnew SqlCommand(query, conn);
		int nr_materii = (int)cmd14->ExecuteScalar();
		DataGridViewTextBoxColumn^ sem = gcnew DataGridViewTextBoxColumn();
		sem->Name = "Semester";
		dataGridView1->Columns->Insert(1, sem);
		for (int i = 0; i < nr_materii; i++){
			String^ query = "SELECT Semester FROM Subjects WHERE ID ='" + dataGridView1->Rows[i]->Cells[0]->Value + "';";
			SqlCommand^ cmd9 = gcnew SqlCommand(query, conn);
			int semestru = (int)cmd9->ExecuteScalar();
			dataGridView1->Rows[i]->Cells[1]->Value = semestru;
		}
		DataGridViewTextBoxColumn^ credite = gcnew DataGridViewTextBoxColumn();
		credite->Name = "Credits";
		dataGridView1->Columns->Insert(2, credite);
		for (int i = 0; i < nr_materii; i++){
			String^ query = "SELECT Credits FROM Subjects WHERE ID ='" + dataGridView1->Rows[i]->Cells[0]->Value + "';";
			SqlCommand^ cmd = gcnew SqlCommand(query, conn);
			int credit = (int)cmd->ExecuteScalar();
			dataGridView1->Rows[i]->Cells[2]->Value = credit;
		}
		
		DataGridViewTextBoxColumn^ prof = gcnew DataGridViewTextBoxColumn();
		prof->Name = "Profesor";
		dataGridView1->Columns->Insert(3, prof);
		for (int i = 0; i < nr_materii; i++){

			String^ query = "SELECT ID_Proffesor FROM Subjects WHERE ID ='" + dataGridView1->Rows[i]->Cells[0]->Value + "';";
			SqlCommand^ cmd10 = gcnew SqlCommand(query, conn);
			int id_prof = (int)cmd10->ExecuteScalar();
			if (id_prof != 0){
				String^ query1 = "SELECT First_Name FROM Proffessors WHERE Id='" + id_prof + "';";
				String^ query2 = "SELECT Last_Name FROM Proffessors WHERE Id='" + id_prof + "';";
				SqlCommand^ cmd11 = gcnew SqlCommand(query1, conn);
				String^ prenume_prof = (String^)cmd11->ExecuteScalar();
				SqlCommand^ cmd12 = gcnew SqlCommand(query2, conn);
				String^ nume_prof = (String^)cmd12->ExecuteScalar();
				string prenumele_prof = msclr::interop::marshal_as<std::string>(prenume_prof);
				string numele_prof = msclr::interop::marshal_as<std::string>(nume_prof);
				string full_name = numele_prof + prenumele_prof;
				String^ name_prof = gcnew String(full_name.c_str());
				dataGridView1->Rows[i]->Cells[3]->Value = name_prof;
			}
		}
		DataGridViewTextBoxColumn^ materie = gcnew DataGridViewTextBoxColumn();
		materie->Name = "Subject";
		dataGridView1->Columns->Insert(4, materie);
		for (int i = 0; i < nr_materii; i++){
			String^ query = "SELECT Name FROM Subjects WHERE ID ='" + dataGridView1->Rows[i]->Cells[0]->Value + "';";
			SqlCommand^ cmd13 = gcnew SqlCommand(query, conn);
			String^ nume_mat = (String^)cmd13->ExecuteScalar();
			dataGridView1->Rows[i]->Cells[4]->Value = nume_mat;
		}

	}
private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	if (String::IsNullOrEmpty(textBox3->Text) && String::IsNullOrEmpty(textBox4->Text) && String::IsNullOrEmpty(textBox5->Text) && String::IsNullOrEmpty(textBox6->Text) && String::IsNullOrEmpty(textBox7->Text) && String::IsNullOrEmpty(textBox8->Text) && String::IsNullOrEmpty(textBox9->Text)){
		validabil = false;
	}
	else{
		validabil = true;
	}
	if (validabil == true){
		printDialog1->Document = printDocument1;
		PrintController^ printcontroller = gcnew StandardPrintController();
		printDocument1->PrintController = printcontroller;
		PaperSize^ ps = gcnew PaperSize();
		ps->RawKind = (int)PaperKind::A4;
		printDocument1->DefaultPageSettings->PaperSize = ps;
		//printDocument1->DefaultPageSettings->Landscape = true;
		printDocument1->Print();

	}
	else{
		MessageBox::Show("Contractul inca nu este validabil pentru ca nu sunt completate toate campurile!");
	}
}
		 Bitmap^ memoryImage;
private: System::Void printDocument1_PrintPage(System::Object^  sender, System::Drawing::Printing::PrintPageEventArgs^  e) {
	int poz_sus_jos = 100;
	int poz_stanga_dreapta = 300;
	e->Graphics->DrawString("Politehnica University of Bucharest", this->Font, System::Drawing::Brushes::Black, 0, 0);
	e->Graphics->DrawString("STUDY CONTRACT", this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta, poz_sus_jos);
	e->Graphics->DrawString(label1->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta - 100, poz_sus_jos + 20 + 100);
	e->Graphics->DrawString(label2->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta - 100, poz_sus_jos + 40 + 100);
	e->Graphics->DrawString(label3->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta - 100, poz_sus_jos + 60 + 100);
	e->Graphics->DrawString(label4->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta - 100, poz_sus_jos + 80 + 100);
	e->Graphics->DrawString(label9->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta - 100, poz_sus_jos + 100 + 100);
	e->Graphics->DrawString(label5->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta + 100, poz_sus_jos + 20 + 100);
	e->Graphics->DrawString(label6->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta + 100, poz_sus_jos + 40 + 100);
	e->Graphics->DrawString(label7->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta + 100, poz_sus_jos + 60 + 100);
	e->Graphics->DrawString(label8->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta + 100, poz_sus_jos + 80 + 100);

	e->Graphics->DrawString(textBox1->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta - 30, poz_sus_jos + 20 + 100);
	e->Graphics->DrawString(textBox2->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta - 30, poz_sus_jos + 40 + 100);
	e->Graphics->DrawString(textBox3->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta - 30, poz_sus_jos + 60 + 100);
	e->Graphics->DrawString(textBox4->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta - 30, poz_sus_jos + 80 + 100);
	e->Graphics->DrawString(textBox5->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta - 30, poz_sus_jos + 100 + 100);
	e->Graphics->DrawString(textBox6->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta + 200, poz_sus_jos + 20 + 100);
	e->Graphics->DrawString(textBox7->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta + 200, poz_sus_jos + 40 + 100);
	e->Graphics->DrawString(textBox8->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta + 200, poz_sus_jos + 60 + 100);
	e->Graphics->DrawString(textBox9->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta + 200, poz_sus_jos + 80 + 100);

	//tabela cu materii
	e->Graphics->DrawString(label10->Text, this->Font, System::Drawing::Brushes::Black, 100, 350);

	e->Graphics->DrawString("Id-Materie", this->Font, System::Drawing::Brushes::Brown, 100, 400);
	e->Graphics->DrawString("Semester", this->Font, System::Drawing::Brushes::Brown, 200, 400);
	e->Graphics->DrawString("Credits", this->Font, System::Drawing::Brushes::Brown, 300, 400);
	e->Graphics->DrawString("Teacher`s name", this->Font, System::Drawing::Brushes::Brown, 400, 400);
	e->Graphics->DrawString("Subject`s name", this->Font, System::Drawing::Brushes::Brown, 500, 400);

	int poz_i_sus_jos = 450;
	for (int i = 0; i < dataGridView1->Rows->Count; i++){
		int poz_i_s_d = 100;
		for (int j = 0; j < 5; j++){
			e->Graphics->DrawString(Convert::ToString(dataGridView1->Rows[i]->Cells[j]->Value), this->Font, System::Drawing::Brushes::Black, poz_i_s_d, poz_i_sus_jos);
			poz_i_s_d = poz_i_s_d + 100;
		}

		poz_i_sus_jos = poz_i_sus_jos + 50;
	}
	e->Graphics->DrawString("Admin signature", this->Font, System::Drawing::Brushes::Black, 100, poz_i_sus_jos + 100);
	e->Graphics->DrawString("Student signature", this->Font, System::Drawing::Brushes::Black, 500, poz_i_sus_jos + 100);

}
private: System::Void textBox6_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox7_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox8_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox9_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
