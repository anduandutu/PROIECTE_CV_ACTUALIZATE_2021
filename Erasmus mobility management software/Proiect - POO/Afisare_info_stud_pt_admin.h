#pragma once
using namespace std;
#include "Vizualizare_info_student.h"
namespace ProiectPOO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Afisare_info_stud_pt_admin
	/// </summary>
	public ref class Afisare_info_stud_pt_admin : public System::Windows::Forms::Form
	{
	public:
		Afisare_info_stud_pt_admin(void)
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
		~Afisare_info_stud_pt_admin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected:
	private: System::Windows::Forms::Label^  label1;

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ActiveCaption;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Sitka Small", 10));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->Location = System::Drawing::Point(25, 62);
			this->dataGridView1->Name = L"dataGridView1";
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Sitka Small", 10));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->Size = System::Drawing::Size(617, 364);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Afisare_info_stud_pt_admin::dataGridView1_CellClick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 22));
			this->label1->Location = System::Drawing::Point(265, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(132, 43);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Students";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// Afisare_info_stud_pt_admin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(674, 466);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->MaximumSize = System::Drawing::Size(690, 505);
			this->MinimumSize = System::Drawing::Size(690, 505);
			this->Name = L"Afisare_info_stud_pt_admin";
			this->Text = L"Afisare_info_stud_pt_admin";
			this->Load += gcnew System::EventHandler(this, &Afisare_info_stud_pt_admin::Afisare_info_stud_pt_admin_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Afisare_info_stud_pt_admin_Load(System::Object^  sender, System::EventArgs^  e) {
		SqlDataAdapter^ data;
		DataSet^ source = gcnew DataSet();
		SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
		conn->Open();
		data = gcnew SqlDataAdapter("SELECT ID,FirstName,LastName,Field FROM Studenti WHERE Validat ='" + 0 + "';", conn);
		data->Fill(source);
		dataGridView1->DataSource = source->Tables[0];
		DataGridViewButtonColumn^ validare_Student = gcnew DataGridViewButtonColumn();
		validare_Student->Name = "Validare_student";
		validare_Student->Text = "Valideaza";
		validare_Student->UseColumnTextForButtonValue = true;
		int columnIndex = 4;
		dataGridView1->Columns->Insert(columnIndex, validare_Student);
		DataGridViewButtonColumn^ vizualizare_Student = gcnew DataGridViewButtonColumn();
		vizualizare_Student->Name = "Vizualizare_contract_student";
		vizualizare_Student->Text = "Vizualizeaza";
		vizualizare_Student->UseColumnTextForButtonValue = true;
		int columnIndex1 = 5;
		dataGridView1->Columns->Insert(columnIndex1, vizualizare_Student);
	}
	private: System::Void dataGridView1_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		Vizualizare_info_student^ info_stud = gcnew Vizualizare_info_student;
		if (e->ColumnIndex == dataGridView1->Columns["Validare_student"]->Index){
			int chestie = e->RowIndex;
			SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
			SqlCommand^ cmd = gcnew SqlCommand("UPDATE Studenti SET Validat ='" + 1 + "'WHERE ID = '" + dataGridView1->Rows[chestie]->Cells[0]->Value+"'; ", conn);
			SqlDataReader^ reader;
			conn->Open();
			reader = cmd->ExecuteReader();
			while (reader->Read()){

			}
			conn->Close();
			dataGridView1->Rows->RemoveAt(chestie);
		}
		
		if (e->ColumnIndex == dataGridView1->Columns["Vizualizare_contract_student"]->Index){
			int chestie = e->RowIndex;
			info_stud->id_stud = (int)dataGridView1->Rows[chestie]->Cells[0]->Value;
			info_stud->Show(this);
		}
	}
};
}
