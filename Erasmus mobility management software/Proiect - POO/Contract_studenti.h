#pragma once
using namespace std;
#include <msclr\marshal_cppstd.h>
#include <string.h>
namespace ProiectPOO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SqlClient;
	using namespace System::Drawing::Printing;
	using namespace System::Drawing;
	using namespace System::Configuration;

	/// <summary>
	/// Summary for Contract_studenti
	/// </summary>
	public ref class Contract_studenti : public System::Windows::Forms::Form
	{
	public:
		int id_stud;
	public:
		Contract_studenti(void)
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
		~Contract_studenti()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PrintDialog^  printDialog1;
	private: System::Drawing::Printing::PrintDocument^  printDocument1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;







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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->printDialog1 = (gcnew System::Windows::Forms::PrintDialog());
			this->printDocument1 = (gcnew System::Drawing::Printing::PrintDocument());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ActiveCaption;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 292);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(684, 267);
			this->dataGridView1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button1->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 15.75F));
			this->button1->Location = System::Drawing::Point(526, 14);
			this->button1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(195, 68);
			this->button1->TabIndex = 1;
			this->button1->Text = L"PRINT";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Contract_studenti::button1_Click);
			// 
			// printDialog1
			// 
			this->printDialog1->UseEXDialog = true;
			// 
			// printDocument1
			// 
			this->printDocument1->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &Contract_studenti::printDocument1_PrintPage);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(126, 11);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(117, 21);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(380, 11);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(117, 21);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Contract_studenti::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(124, 66);
			this->textBox3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(117, 21);
			this->textBox3->TabIndex = 4;
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(380, 66);
			this->textBox4->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(117, 21);
			this->textBox4->TabIndex = 5;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &Contract_studenti::textBox4_TextChanged);
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox5->Location = System::Drawing::Point(124, 136);
			this->textBox5->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(117, 21);
			this->textBox5->TabIndex = 6;
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox6->Location = System::Drawing::Point(380, 136);
			this->textBox6->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(117, 21);
			this->textBox6->TabIndex = 7;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &Contract_studenti::textBox6_TextChanged);
			// 
			// textBox7
			// 
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox7->Location = System::Drawing::Point(126, 204);
			this->textBox7->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(117, 21);
			this->textBox7->TabIndex = 8;
			// 
			// textBox8
			// 
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox8->Location = System::Drawing::Point(380, 192);
			this->textBox8->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(117, 21);
			this->textBox8->TabIndex = 9;
			this->textBox8->TextChanged += gcnew System::EventHandler(this, &Contract_studenti::textBox8_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 15.75F));
			this->label1->Location = System::Drawing::Point(9, 2);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(111, 30);
			this->label1->TabIndex = 10;
			this->label1->Text = L"ID Student";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 15.75F));
			this->label2->Location = System::Drawing::Point(7, 58);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(111, 30);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Last Name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 15.75F));
			this->label3->Location = System::Drawing::Point(5, 123);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(115, 30);
			this->label3->TabIndex = 12;
			this->label3->Text = L"First Name";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 15.75F));
			this->label4->Location = System::Drawing::Point(7, 192);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(116, 30);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Nationality";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 15.75F));
			this->label5->Location = System::Drawing::Point(239, 2);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(135, 30);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Date Of Birth";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 15.75F));
			this->label6->Location = System::Drawing::Point(236, 58);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(144, 30);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Field Of Study";
			this->label6->Click += gcnew System::EventHandler(this, &Contract_studenti::label6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 15.75F));
			this->label7->Location = System::Drawing::Point(239, 192);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(135, 30);
			this->label7->TabIndex = 16;
			this->label7->Text = L"English Level";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 15.75F));
			this->label8->Location = System::Drawing::Point(253, 123);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(121, 30);
			this->label8->TabIndex = 17;
			this->label8->Text = L"Study Cycle";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(12, 244);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(107, 30);
			this->label9->TabIndex = 18;
			this->label9->Text = L"SUBJECTS";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 15.75F));
			this->label10->ForeColor = System::Drawing::Color::Black;
			this->label10->Location = System::Drawing::Point(17, 571);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(102, 60);
			this->label10->TabIndex = 19;
			this->label10->Text = L"Admin\r\nSignature\r\n";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 15.75F));
			this->label11->Location = System::Drawing::Point(363, 571);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(102, 60);
			this->label11->TabIndex = 20;
			this->label11->Text = L"Student \r\nSignature";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(128, 578);
			this->richTextBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(225, 66);
			this->richTextBox1->TabIndex = 21;
			this->richTextBox1->Text = L"";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(471, 578);
			this->richTextBox2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->Size = System::Drawing::Size(225, 66);
			this->richTextBox2->TabIndex = 22;
			this->richTextBox2->Text = L"";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button2->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 15.75F));
			this->button2->Location = System::Drawing::Point(526, 177);
			this->button2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(195, 68);
			this->button2->TabIndex = 23;
			this->button2->Text = L"EXIT";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Contract_studenti::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button3->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 15.75F));
			this->button3->Location = System::Drawing::Point(526, 89);
			this->button3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(195, 68);
			this->button3->TabIndex = 24;
			this->button3->Text = L"BACK";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Contract_studenti::button3_Click_1);
			// 
			// Contract_studenti
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(725, 662);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->MaximumSize = System::Drawing::Size(741, 701);
			this->MinimumSize = System::Drawing::Size(741, 701);
			this->Name = L"Contract_studenti";
			this->Text = L"Student Contract";
			this->Load += gcnew System::EventHandler(this, &Contract_studenti::Contract_studenti_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Contract_studenti_Load(System::Object^  sender, System::EventArgs^  e) {
		SqlConnection^ conn = gcnew SqlConnection("Data Source = (LocalDB)\\v11.0; AttachDbFilename =|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security = True; Connect Timeout = 30");
		//SqlConnection^ conn = gcnew SqlConnection("Data Source = |Proiect - POO|\BazaDeDateProiect.mdf");
		conn->Open();
		//Am afisat ID-ul studentului curent
		string id = to_string(id_stud);
		textBox1->Text = gcnew String(id.c_str());
		//Preiau prenumele studentului din baza de date
		SqlCommand ^ cmd1 = gcnew SqlCommand("SELECT FirstName FROM Studenti WHERE ID = '" + id_stud + "';", conn);
		if (cmd1->ExecuteScalar() != NULL){
			String^ firstName = (String^)cmd1->ExecuteScalar();
			textBox5->Text = firstName;
		}
		//Preiau numele studentului din baza de date
		SqlCommand ^ cmd2 = gcnew SqlCommand("SELECT LastName FROM Studenti WHERE ID = '" + id_stud + "';", conn);
		if (cmd2->ExecuteScalar() != NULL){
			String^ lastName = (String^)cmd2->ExecuteScalar();
			textBox3->Text = lastName;
		}

		//Preiau nationalitatea studentului
		SqlCommand ^ cmd3 = gcnew SqlCommand("SELECT Nationality FROM Studenti WHERE ID = '" + id_stud + "';", conn);
		if (cmd3->ExecuteScalar() != NULL){
			String^ lastName = (String^)cmd3->ExecuteScalar();
			textBox7->Text = lastName;
		}
		//Preiau data nasterii
		int ciclu_studii; 
		SqlCommand ^ cmd5 = gcnew SqlCommand("SELECT StudyCycle FROM Studenti WHERE ID = '" + id_stud + "';", conn);
		if (cmd5->ExecuteScalar() != NULL){
			int studyCycle = (int)cmd5->ExecuteScalar();
			ciclu_studii = studyCycle;
			string sCycle = to_string(studyCycle);
			textBox6->Text = gcnew String(sCycle.c_str());
		}
		SqlCommand ^ cmd6 = gcnew SqlCommand("SELECT BirthDate FROM Studenti WHERE ID = '" + id_stud + "';", conn);
		if (cmd6->ExecuteScalar() != NULL){
		String^ birth = (String^)cmd6->ExecuteScalar();
		textBox2->Text = birth;
		}
		//field
		SqlCommand ^ cmd7 = gcnew SqlCommand("SELECT Field FROM Studenti WHERE ID = '" + id_stud + "';", conn);
		if (cmd7->ExecuteScalar() != NULL){
		String^ field = (String^)cmd7->ExecuteScalar();
		textBox4->Text = field;
		}
		SqlCommand ^ cmd4 = gcnew SqlCommand("SELECT EnglishLevel FROM Studenti WHERE ID = '" + id_stud + "';", conn);
		if (cmd4->ExecuteScalar() != NULL){
		String^ e_level = (String^)cmd4->ExecuteScalar();
		textBox8->Text = e_level;
		}


		SqlDataAdapter^ data;
		DataSet^ source = gcnew DataSet();



		//string = C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf
		
		//aici iau id-urile  materiilor alese
		
		data = gcnew SqlDataAdapter("SELECT Id_materie FROM Materii_intermediar WHERE Id_student ='" + id_stud + "'; ", conn);
		data->Fill(source);
		DataTable ^dt = source->Tables[0];
		dataGridView1->DataSource = dt;
		String^ query = "SELECT COUNT(*) Id_materie FROM Materii_intermediar WHERE Id_student ='" + id_stud + "';";
		SqlCommand^ cmd = gcnew SqlCommand(query, conn);
		int nr_materii = (int)cmd->ExecuteScalar();
		DataGridViewTextBoxColumn^ sem = gcnew DataGridViewTextBoxColumn();
		sem->Name = "Semester";
		dataGridView1->Columns->Insert(1,sem);

		int c1_1, c1_2, c2_1, c2_2, c3_1, c3_2, c4_1, c4_2, c5_1, c5_2, c6_1, c6_2;
		//aici e o bucata de cod ce ajuta mult pentru situatie de studenti
		
		for (int i = 0; i < nr_materii; i++){
			String^ query = "SELECT Semester FROM Subjects WHERE ID ='" + dataGridView1->Rows[i]->Cells[0]->Value + "';";
			SqlCommand^ cmd = gcnew SqlCommand(query, conn);
			int semestru = (int)cmd->ExecuteScalar();
			if (semestru == 1 &&(ciclu_studii == 1)){
				c1_1++;
			}
			else if (semestru == 2 && (ciclu_studii == 1)){
				c1_2++;
			}
			else if (semestru == 1 && (ciclu_studii == 2)){
				c2_1++;
			}
			else if (semestru == 2 && (ciclu_studii == 2)){
				c2_2++;
			}
			else if (semestru == 1 && (ciclu_studii == 3)){
				c3_1++;
			}
			else if (semestru == 2 && (ciclu_studii == 3)){
				c3_2++;
			}
			else if (semestru == 1 && (ciclu_studii == 4)){
				c4_1++;
			}
			else if (semestru == 2 && (ciclu_studii == 4)){
				c4_2++;
			}
			else if (semestru == 1 && (ciclu_studii == 5)){
				c5_1++;
			}
			else if (semestru == 2 && (ciclu_studii == 5)){
				c5_2++;
			}
			else if (semestru == 1 && (ciclu_studii == 6)){
				c6_1++;
			}
			else if (semestru == 2 && (ciclu_studii == 6)){
				c6_2++;
			}
			
			dataGridView1->Rows[i]->Cells[1]->Value = semestru;
		}
		String^ creare_situatie =
			"UPDATE Studenti SET materii_1_1 = '" + c1_1 + "', materii_1_2 = '" + c1_2 + "',materii_2_1 = '" + c2_1 + "',materii_2_2 = '"
			+ c2_2 + "', materii_3_1 = '" + c3_1 + "',materii_3_2 = '" + c3_2 + "',materii_4_1 ='" + c4_1 + "',materii_4_2='"
			+ c4_2 + "',materii_5_1 = '" + c5_1 + "',materii_5_2 = '"+c5_2+"',materii_6_1 = '"+c6_1+"',materii_6_2 = '"+c6_2+"' WHERE Id = '" + id_stud + "';"
			;
		SqlCommand ^ cmd_situatie = gcnew SqlCommand(creare_situatie, conn);
		cmd_situatie->ExecuteNonQuery();
		DataGridViewTextBoxColumn^ credite = gcnew DataGridViewTextBoxColumn();
		credite->Name = "Credits";
		dataGridView1->Columns->Insert(2, credite);
		for (int i = 0; i < nr_materii; i++){
			String^ query = "SELECT Credits FROM Subjects WHERE ID ='" + dataGridView1->Rows[i]->Cells[0]->Value + "';";
			SqlCommand^ cmd = gcnew SqlCommand(query, conn);
			int credit= (int)cmd->ExecuteScalar();
			dataGridView1->Rows[i]->Cells[2]->Value = credit;
		}

		DataGridViewTextBoxColumn^ prof = gcnew DataGridViewTextBoxColumn();
		prof->Name = "Teacher";
		dataGridView1->Columns->Insert(3, prof);
		for (int i = 0; i < nr_materii; i++){
			//if (dataGridView1->Rows[i]->Cells[0]->Value != 0){
				String^ query = "SELECT ID_Proffesor FROM Subjects WHERE ID ='" + dataGridView1->Rows[i]->Cells[0]->Value + "';";
				SqlCommand^ cmd = gcnew SqlCommand(query, conn);
				int id_prof = (int)cmd->ExecuteScalar();
				if (id_prof !=0){
					String^ query1 = "SELECT First_Name FROM Proffessors WHERE Id='" + id_prof + "';";
					String^ query2 = "SELECT Last_Name FROM Proffessors WHERE Id='" + id_prof + "';";
					SqlCommand^ cmd1 = gcnew SqlCommand(query1, conn);
					String^ prenume_prof = (String^)cmd1->ExecuteScalar();
					SqlCommand^ cmd2 = gcnew SqlCommand(query2, conn);
					String^ nume_prof = (String^)cmd2->ExecuteScalar();
					string prenumele_prof = msclr::interop::marshal_as<std::string>(prenume_prof);
					string numele_prof = msclr::interop::marshal_as<std::string>(nume_prof);
					string full_name = numele_prof + " " + prenumele_prof;
					String^ name_prof = gcnew String(full_name.c_str());
					dataGridView1->Rows[i]->Cells[3]->Value = name_prof;
				}
			//}
		}
		DataGridViewTextBoxColumn^ materie = gcnew DataGridViewTextBoxColumn();
		materie->Name = "Subject";
		dataGridView1->Columns->Insert(4, materie);
		for (int i = 0; i < nr_materii; i++){
			String^ query = "SELECT Name FROM Subjects WHERE ID ='" + dataGridView1->Rows[i]->Cells[0]->Value + "';";
			SqlCommand^ cmd = gcnew SqlCommand(query, conn);
			String^ nume_mat = (String^)cmd->ExecuteScalar();
			dataGridView1->Rows[i]->Cells[4]->Value = nume_mat;
		}
		

	}
	private: System::Void printDocument1_PrintPage(System::Object^  sender, System::Drawing::Printing::PrintPageEventArgs^  e) {
		//Bitmap^ bm = gcnew Bitmap(this->Width, this->Height);
		int poz_sus_jos = 100;
		int poz_stanga_dreapta = 300;
		e->Graphics->DrawString("Politehnica University of Bucharest", this->Font, System::Drawing::Brushes::Black, 0 , 0);

		e->Graphics->DrawString("STUDY CONTRACT", this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta, poz_sus_jos);
		e->Graphics->DrawString(label1->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta - 100, poz_sus_jos+20 + 100);
		e->Graphics->DrawString(label2->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta - 100, poz_sus_jos+40 + 100);
		e->Graphics->DrawString(label3->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta - 100, poz_sus_jos + 60 + 100);
		e->Graphics->DrawString(label4->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta - 100, poz_sus_jos + 80 + 100);

		e->Graphics->DrawString(label5->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta + 100, poz_sus_jos + 20 + 100);
		e->Graphics->DrawString(label6->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta + 100, poz_sus_jos + 40 + 100);
		e->Graphics->DrawString(label7->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta + 100, poz_sus_jos + 60 + 100);
		e->Graphics->DrawString(label8->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta + 100, poz_sus_jos + 80 + 100);

		e->Graphics->DrawString(textBox1->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta - 30, poz_sus_jos + 20 + 100);
		e->Graphics->DrawString(textBox3->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta - 30, poz_sus_jos + 40 + 100);
		e->Graphics->DrawString(textBox5->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta - 30, poz_sus_jos + 60 + 100);
		e->Graphics->DrawString(textBox7->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta - 30, poz_sus_jos + 80 + 100);

		e->Graphics->DrawString(textBox2->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta + 200, poz_sus_jos + 20 + 100);
		e->Graphics->DrawString(textBox4->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta + 200, poz_sus_jos + 40 + 100);
		e->Graphics->DrawString(textBox6->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta + 200, poz_sus_jos + 60 + 100);
		e->Graphics->DrawString(textBox8->Text, this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta + 200, poz_sus_jos + 80 + 100);

		//tabela cu materii

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

		e->Graphics->DrawString(label10->Text, this->Font, System::Drawing::Brushes::Black, 100, poz_i_sus_jos+100);
		e->Graphics->DrawString(label11->Text, this->Font, System::Drawing::Brushes::Black, 500, poz_i_sus_jos + 100);
		e->Graphics->DrawString(richTextBox1->Text, this->Font, System::Drawing::Brushes::Black, 200, poz_i_sus_jos + 100);
		e->Graphics->DrawString(richTextBox2->Text, this->Font, System::Drawing::Brushes::Black, 550, poz_i_sus_jos + 100);
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	SqlConnection^ conn = gcnew SqlConnection("Data Source = (LocalDB)\\v11.0; AttachDbFilename =|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security = True; Connect Timeout = 30");
	//SqlConnection^ conn = gcnew SqlConnection("Data Source = |Proiect - POO|\BazaDeDateProiect.mdf");
	conn->Open();
	String^ query = "UPDATE Studenti SET  BirthDate = '" + textBox2->Text + "' WHERE ID = '"+id_stud+"';";
	SqlCommand ^ cmd = gcnew SqlCommand(query, conn);
	cmd->ExecuteNonQuery();
	String^ query1 = "UPDATE Studenti SET Field  = '" + textBox4->Text + "' WHERE ID = '" + id_stud + "';";
	SqlCommand ^ cmd1 = gcnew SqlCommand(query1, conn);
	cmd1->ExecuteNonQuery();
	String^ query2 = "UPDATE Studenti SET  EnglishLevel = '" + textBox8->Text + "' WHERE ID = '" + id_stud + "';";
	SqlCommand ^ cmd2 = gcnew SqlCommand(query2, conn);
	cmd2->ExecuteNonQuery();
	printDialog1->Document = printDocument1;
	PrintController^ printcontroller = gcnew StandardPrintController();
	printDocument1->PrintController = printcontroller;
	PaperSize^ ps = gcnew PaperSize();
	ps->RawKind = (int)PaperKind::A4;
	printDocument1->DefaultPageSettings->PaperSize = ps;
	//printDocument1->DefaultPageSettings->Landscape = true;
	printDocument1->Print();
}
private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	/*SqlConnection^ conn = gcnew SqlConnection("Data Source = (LocalDB)\\v11.0; AttachDbFilename =|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security = True; Connect Timeout = 30");
	//SqlConnection^ conn = gcnew SqlConnection("Data Source = |Proiect - POO|\BazaDeDateProiect.mdf");
	conn->Open();
	String^ query = "INSERT INTO Studenti(BirthDate) VALUES('" + textBox2->Text + "');";
	SqlCommand ^ cmd = gcnew SqlCommand(query, conn);*/


}
private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	//field
	/*SqlConnection^ conn = gcnew SqlConnection("Data Source = (LocalDB)\\v11.0; AttachDbFilename =|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security = True; Connect Timeout = 30");
	//SqlConnection^ conn = gcnew SqlConnection("Data Source = |Proiect - POO|\BazaDeDateProiect.mdf");
	conn->Open();
	String^ query = "INSERT INTO Studenti(Field) VALUES('" + textBox4->Text + "');";
	SqlCommand ^ cmd = gcnew SqlCommand(query, conn);
	SqlDataReader^ reader;
	reader = cmd->ExecuteReader();*/

}
private: System::Void textBox6_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox8_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	//e_level
	/*SqlConnection^ conn = gcnew SqlConnection("Data Source = (LocalDB)\\v11.0; AttachDbFilename =|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security = True; Connect Timeout = 30");
	//SqlConnection^ conn = gcnew SqlConnection("Data Source = |Proiect - POO|\BazaDeDateProiect.mdf");
	conn->Open();
	String^ query = "INSERT INTO Studenti(EnglishLevel) VALUES('" + textBox8->Text + "');";
	SqlCommand ^ cmd = gcnew SqlCommand(query, conn);
	SqlDataReader^ reader;
	reader = cmd->ExecuteReader();*/
}
private: System::Void button3_Click_1(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
}
};
}
