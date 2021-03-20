#pragma once
#include "Proffessors.h"
#include <msclr\marshal_cppstd.h>
#include "VizualizareMateriiPredate.h"
namespace ProiectPOO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Profesori
	/// </summary>
	public ref class Profesori : public System::Windows::Forms::Form
	{
	public:
		Profesori(void)
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
		~Profesori()
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
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button1;

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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.25F));
			this->label1->Location = System::Drawing::Point(16, 16);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(111, 28);
			this->label1->TabIndex = 0;
			this->label1->Text = L"First Name";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Sitka Heading", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(135, 16);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(196, 28);
			this->textBox1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.25F));
			this->label2->Location = System::Drawing::Point(361, 12);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(106, 28);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Last Name";
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Sitka Heading", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(475, 16);
			this->textBox2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(268, 28);
			this->textBox2->TabIndex = 3;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ActiveCaption;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::ActiveCaption;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Sitka Heading", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(16, 145);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(747, 464);
			this->dataGridView1->TabIndex = 4;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Profesori::dataGridView1_CellClick);
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Profesori::dataGridView1_CellContentClick);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.25F));
			this->label3->Location = System::Drawing::Point(16, 87);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(368, 28);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Choose the subject that you are teaching";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->button1->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(195, 648);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(367, 69);
			this->button1->TabIndex = 6;
			this->button1->Text = L"CREATE ACCOUNT";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Profesori::button1_Click);
			// 
			// Profesori
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 23);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(787, 749);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Sitka Heading", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"Profesori";
			this->Text = L"Teachers";
			this->Load += gcnew System::EventHandler(this, &Profesori::Profesori_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
{
	this->Hide();
	VizualizareMateriiPredate^ vizualizare_materii = gcnew VizualizareMateriiPredate;
	SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
	//SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
	conn->Open();
	String^ query1 = "SELECT Id FROM Proffessors  WHERE First_Name  = '" + textBox1->Text + "' AND Last_Name = '" + textBox2->Text + "';";
	SqlCommand^ cmd1 = gcnew SqlCommand(query1, conn);
	int id = (int)cmd1->ExecuteScalar();
	vizualizare_materii->id_prof = id;
	vizualizare_materii->Show(this);
	
}
private: System::Void dataGridView1_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	if (e->ColumnIndex == dataGridView1->Columns["Choose Subject"]->Index){
		String ^prenume = textBox1->Text;
		String ^nume = textBox2->Text;
		string firstName = msclr::interop::marshal_as<std::string>(prenume);
		string lastName = msclr::interop::marshal_as<std::string>(nume);
		int chestie = e->RowIndex;
		int id_materie = (int)dataGridView1->Rows[chestie]->Cells[0]->Value;
		Proffessors nou_prof(firstName,lastName,id_materie);
		nou_prof.adaugareProfesor();
		dataGridView1->Rows[chestie]->Cells["ID_Proffesor"]->Value= nou_prof.getIDProffessor();
		nou_prof.adaugareUtilizator();
		nou_prof.legareProfesorDeMaterie(id_materie);


	}
}
private: System::Void Profesori_Load(System::Object^  sender, System::EventArgs^  e) {
	SqlDataAdapter^ data;
	DataSet^ source = gcnew DataSet();
	SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
	//SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
	conn->Open();
	data = gcnew SqlDataAdapter("SELECT * FROM Subjects", conn);
	data->Fill(source);
	dataGridView1->DataSource = source->Tables[0];
	DataGridViewButtonColumn^ alege_materie_ButtonColumn = gcnew DataGridViewButtonColumn();
	alege_materie_ButtonColumn->Name = "Choose Subject";
	alege_materie_ButtonColumn->Text = "Teach";
	alege_materie_ButtonColumn->UseColumnTextForButtonValue = true;
	int columnIndex = 5;
	dataGridView1->Columns->Insert(columnIndex, alege_materie_ButtonColumn);
}
};
}
