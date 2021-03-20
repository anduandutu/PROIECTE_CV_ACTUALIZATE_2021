#pragma once
#include <msclr\marshal_cppstd.h>
#include <cstdlib>
#include <string.h>
using namespace std;
namespace ProiectPOO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace System::Drawing::Printing;

	/// <summary>
	/// Summary for Administrare_situatie_studenti
	/// </summary>
	public ref class Administrare_situatie_studenti : public System::Windows::Forms::Form
	{
	public:
		int index;
	public:
		Administrare_situatie_studenti(void)
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
		~Administrare_situatie_studenti()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Drawing::Printing::PrintDocument^  printDocument1;
	private: System::Windows::Forms::PrintDialog^  printDialog1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;


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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->printDocument1 = (gcnew System::Drawing::Printing::PrintDocument());
			this->printDialog1 = (gcnew System::Windows::Forms::PrintDialog());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 16));
			this->label1->Location = System::Drawing::Point(12, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(303, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Incoming number of students";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SunkenVertical;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 8));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 8));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::MediumAquamarine;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->Location = System::Drawing::Point(12, 82);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(826, 274);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Administrare_situatie_studenti::dataGridView1_CellClick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 16));
			this->label2->Location = System::Drawing::Point(6, 42);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(322, 32);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Number of students per subject";
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView2->BackgroundColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 8));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView2->DefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView2->Location = System::Drawing::Point(12, 443);
			this->dataGridView2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->Size = System::Drawing::Size(826, 274);
			this->dataGridView2->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 378);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(256, 35);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Student info per class";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 16));
			this->label4->Location = System::Drawing::Point(321, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(73, 32);
			this->label4->TabIndex = 5;
			this->label4->Text = L"label4";
			// 
			// printDocument1
			// 
			this->printDocument1->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &Administrare_situatie_studenti::printDocument1_PrintPage);
			// 
			// printDialog1
			// 
			this->printDialog1->UseEXDialog = true;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 18));
			this->label5->Location = System::Drawing::Point(389, 372);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(90, 35);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Sort by";
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 8));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"StudyCycle", L"FirstName", L"LastName" });
			this->comboBox1->Location = System::Drawing::Point(485, 378);
			this->comboBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 24);
			this->comboBox1->TabIndex = 7;
			// 
			// comboBox2
			// 
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 8));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Ascending", L"Descending" });
			this->comboBox2->Location = System::Drawing::Point(612, 378);
			this->comboBox2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 24);
			this->comboBox2->TabIndex = 8;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 12));
			this->button1->Location = System::Drawing::Point(741, 377);
			this->button1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(97, 32);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Sort";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button2->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 16));
			this->button2->Location = System::Drawing::Point(674, 10);
			this->button2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(164, 65);
			this->button2->TabIndex = 10;
			this->button2->Text = L"EXIT";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Administrare_situatie_studenti::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button3->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 16));
			this->button3->Location = System::Drawing::Point(485, 9);
			this->button3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(164, 65);
			this->button3->TabIndex = 11;
			this->button3->Text = L"BACK";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Administrare_situatie_studenti::button3_Click);
			// 
			// Administrare_situatie_studenti
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(848, 732);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 8));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->MaximumSize = System::Drawing::Size(864, 771);
			this->MinimumSize = System::Drawing::Size(864, 726);
			this->Name = L"Administrare_situatie_studenti";
			this->Text = L"Administrare_situatie_studenti";
			this->Load += gcnew System::EventHandler(this, &Administrare_situatie_studenti::Administrare_situatie_studenti_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Administrare_situatie_studenti_Load(System::Object^  sender, System::EventArgs^  e) {
		SqlDataAdapter^ data;
		DataSet^ source = gcnew DataSet();
		SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
		conn->Open();
		data = gcnew SqlDataAdapter("SELECT Id,Name from Subjects", conn);
		data->Fill(source);
		DataTable ^dt = source->Tables[0];

		dt->Columns->Add(gcnew DataColumn("No. Students"));
		dataGridView1->DataSource = dt;
		int nr_materii = dataGridView1->Rows->Count;
		int nr_total_studenti;
		for (int i = 0; i < nr_materii; i++){
			DataRow^ dr = dt->NewRow();
			String^ query = "SELECT COUNT(*) FROM Materii_intermediar WHERE Id_materie = '" + dataGridView1->Rows[i]->Cells[0]->Value + "'; ";
			SqlCommand^ cmd = gcnew SqlCommand(query, conn);
			int nr_stud = (int)cmd->ExecuteScalar();
			dataGridView1->Rows[i]->Cells["No. Students"]->Value = nr_stud;
		}
		String^ query_stud = "SELECT COUNT(*) FROM Studenti";
		SqlCommand^ cmd_stud = gcnew SqlCommand(query_stud, conn);
		nr_total_studenti = (int)cmd_stud->ExecuteScalar();
		string nr_total = to_string(nr_total_studenti);
		label4->Text = gcnew String(nr_total.c_str());
		DataGridViewButtonColumn^ vizualizare_clasa = gcnew DataGridViewButtonColumn();
		vizualizare_clasa->Name = "Classes";
		vizualizare_clasa->Text = "Class";
		vizualizare_clasa->UseColumnTextForButtonValue = true;
		int columnIndex = 3;
		dataGridView1->Columns->Insert(columnIndex, vizualizare_clasa);
		DataGridViewButtonColumn^ print_situatie_materie = gcnew DataGridViewButtonColumn();
		print_situatie_materie->Name = "Print situation";
		print_situatie_materie->Text = "Print";
		print_situatie_materie->UseColumnTextForButtonValue = true;
		columnIndex = 4;
		dataGridView1->Columns->Insert(columnIndex, print_situatie_materie);
	}
	private: System::Void dataGridView1_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		if (e->ColumnIndex == dataGridView1->Columns["Print situation"]->Index){
			printDialog1->Document = printDocument1;
			PrintController^ printcontroller = gcnew StandardPrintController();
			printDocument1->PrintController = printcontroller;
			PaperSize^ ps = gcnew PaperSize();
			ps->RawKind = (int)PaperKind::A4;
			printDocument1->DefaultPageSettings->PaperSize = ps;
			//printDocument1->DefaultPageSettings->Landscape = true;
			printDocument1->Print();
			index = e->RowIndex;
		}
		if (e->ColumnIndex == dataGridView1->Columns["Classes"]->Index)
		{
			SqlDataAdapter^ data1;
			DataSet^ source1 = gcnew DataSet();
			SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
			conn->Open();
			data1 = gcnew SqlDataAdapter("SELECT Id_student from Materii_intermediar WHERE Id_materie  = '" + dataGridView1->Rows[e->RowIndex]->Cells[0]->Value+ "';", conn);
			data1->Fill(source1);
			DataTable ^dt1 = source1->Tables[0];
			dt1->Columns->Add(gcnew DataColumn("Last Name"));
			dt1->Columns->Add(gcnew DataColumn("First Name"));
			dt1->Columns->Add(gcnew DataColumn("Study Cycle"));
			dataGridView2->DataSource = dt1;
			int nr_studenti = dataGridView2->Rows->Count;
			for (int i = 0; i < nr_studenti; i++){
				DataRow^ dr = dt1->NewRow();
				String^ query = "SELECT LastName FROM Studenti WHERE ID = '" + dataGridView2->Rows[i]->Cells[0]->Value + "'; ";
				SqlCommand^ cmd = gcnew SqlCommand(query, conn);
				String^ nume_stud = (String^)cmd->ExecuteScalar();
				dataGridView2->Rows[i]->Cells["Last Name"]->Value = nume_stud;

				DataRow^ dr1 = dt1->NewRow();
				String^ query1 = "SELECT FirstName FROM Studenti WHERE ID = '" + dataGridView2->Rows[i]->Cells[0]->Value + "'; ";
				SqlCommand^ cmd1 = gcnew SqlCommand(query1, conn);
				String^ nume_stud1 = (String^)cmd1->ExecuteScalar();
				dataGridView2->Rows[i]->Cells["First Name"]->Value = nume_stud1;

				DataRow^ dr2 = dt1->NewRow();
				String^ query2 = "SELECT StudyCycle FROM Studenti WHERE ID = '" + dataGridView2->Rows[i]->Cells[0]->Value + "'; ";
				SqlCommand^ cmd2 = gcnew SqlCommand(query2, conn);
				int study_cycle = (int)cmd2->ExecuteScalar();
				dataGridView2->Rows[i]->Cells["Study Cycle"]->Value = study_cycle;
			}
		}
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	if ((comboBox1->SelectedItem == "StudyCycle") && (comboBox2->SelectedItem == "Ascending")){
		dataGridView2->Sort(this->dataGridView2->Columns["Study Cycle"], ListSortDirection::Ascending);
	}
	else if ((comboBox1->SelectedItem == "StudyCycle") && (comboBox2->SelectedItem == "Descending")){
		dataGridView2->Sort(this->dataGridView2->Columns["Study Cycle"], ListSortDirection::Descending);
	}
	if ((comboBox1->SelectedItem == "FirstName") && (comboBox2->SelectedItem == "Ascending")){
		dataGridView2->Sort(this->dataGridView2->Columns["First Name"], ListSortDirection::Ascending);
	}
	else if((comboBox1->SelectedItem == "FirstName") && (comboBox2->SelectedItem == "Descending")){
		dataGridView2->Sort(this->dataGridView2->Columns["First Name"], ListSortDirection::Descending);
	}
	if ((comboBox1->SelectedItem == "LastName") && (comboBox2->SelectedItem == "Ascending")){
		dataGridView2->Sort(this->dataGridView2->Columns["Last Name"], ListSortDirection::Ascending);
	}
	else if ((comboBox1->SelectedItem == "LastName") && (comboBox2->SelectedItem == "Descending")){
		dataGridView2->Sort(this->dataGridView2->Columns["Last Name"], ListSortDirection::Descending);
	}
}
private: System::Void printDocument1_PrintPage(System::Object^  sender, System::Drawing::Printing::PrintPageEventArgs^  e) {
	int poz_sus_jos = 100;
	int poz_stanga_dreapta = 300;
	e->Graphics->DrawString("Politehnica University of Bucharest", this->Font, System::Drawing::Brushes::Black, 0, 0);
	e->Graphics->DrawString("Erasmus students incoming situation", this->Font, System::Drawing::Brushes::Black, poz_stanga_dreapta, poz_sus_jos);
	String^ nume = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	e->Graphics->DrawString(nume, this->Font, System::Drawing::Brushes::Black, 50,150);
	string nr_studenti = to_string(dataGridView2->Rows->Count);
	String^ nr = gcnew String(nr_studenti.c_str());
	e->Graphics->DrawString(nr, this->Font, System::Drawing::Brushes::Black, 250, 150);
	e->Graphics->DrawString("ID_Student", this->Font, System::Drawing::Brushes::Brown, 150, 200);
	e->Graphics->DrawString("First Name", this->Font, System::Drawing::Brushes::Brown, 150+100, 200);
	e->Graphics->DrawString("Last Name", this->Font, System::Drawing::Brushes::Brown, 150+200, 200);
	e->Graphics->DrawString("Study Cycle", this->Font, System::Drawing::Brushes::Brown, 150+300, 200);
	int poz_jos_sus = 250;
	for (int i = 0; i < dataGridView2->Rows->Count;i++){
		int poz_dreapta_stanga = 150;
		for (int j = 0; j < 4; j++){
			e->Graphics->DrawString(Convert::ToString(dataGridView2->Rows[i]->Cells[j]->Value), this->Font, System::Drawing::Brushes::Black, poz_dreapta_stanga, poz_jos_sus);
			poz_dreapta_stanga = poz_dreapta_stanga + 100;
		}
		poz_jos_sus = poz_jos_sus + 20;
		
	}
	
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
}
};
}
