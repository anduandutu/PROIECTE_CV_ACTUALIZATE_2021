#pragma once
#include "VizualizareCatalogStudenti.h"
namespace ProiectPOO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for VizualizareMateriiPredate
	/// </summary>
	public ref class VizualizareMateriiPredate : public System::Windows::Forms::Form
	{
	public:
		int id_prof;
	public:
		VizualizareMateriiPredate(void)
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
		~VizualizareMateriiPredate()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Label^  label1;
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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
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
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Sitka Text", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->Location = System::Drawing::Point(13, 49);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(634, 362);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellBorderStyleChanged += gcnew System::EventHandler(this, &VizualizareMateriiPredate::dataGridView1_CellBorderStyleChanged);
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &VizualizareMateriiPredate::dataGridView1_CellClick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Sitka Text", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(14, 11);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(305, 35);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Subjects you are teaching";
			// 
			// VizualizareMateriiPredate
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(662, 428);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->Name = L"VizualizareMateriiPredate";
			this->Text = L"VizualizareMateriiPredate";
			this->Load += gcnew System::EventHandler(this, &VizualizareMateriiPredate::VizualizareMateriiPredate_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void VizualizareMateriiPredate_Load(System::Object^  sender, System::EventArgs^  e) {
		SqlDataAdapter^ data;
		DataSet^ source = gcnew DataSet();

		SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
		//SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
		conn->Open();
		data = gcnew SqlDataAdapter("SELECT ID,Semester,Credits,Name FROM Subjects WHERE ID_Proffesor ='" + id_prof + "'; ", conn);
		data->Fill(source);
		DataTable ^dt = source->Tables[0];
		dataGridView1->DataSource = dt;
		//SqlCommand ^ cmd = gcnew SqlCommand("SELECT COUNT(*) FROM Subjects WHERE ID_Proffesor ='" + id_prof + "'; ", conn);
		int rows = dataGridView1->Rows->Count;
		dt->Columns->Add(gcnew DataColumn("Number of Students"));
		for (int i = 0; i < rows; i++){
			DataRow^ dr = dt->NewRow();
			String^ query = "SELECT COUNT(*) FROM Materii_intermediar WHERE Id_materie = '" + dataGridView1->Rows[i]->Cells[0]->Value + "'; ";
			SqlCommand^ cmd = gcnew SqlCommand(query, conn);
			int nr_studenti = (int)cmd->ExecuteScalar();
			dataGridView1->Rows[i]->Cells["Number of Students"]->Value = nr_studenti;
		}
		DataGridViewButtonColumn^ vizualizare_catalog = gcnew DataGridViewButtonColumn();
		vizualizare_catalog->Name = "Vizualizare catalog studenti";
		vizualizare_catalog->Text = "Vizualizare";
		vizualizare_catalog->UseColumnTextForButtonValue = true;
		int columnIndex = 5;
		dataGridView1->Columns->Insert(columnIndex, vizualizare_catalog);
	}
	private: System::Void dataGridView1_CellBorderStyleChanged(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void dataGridView1_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	if (e->ColumnIndex == dataGridView1->Columns["Vizualizare catalog studenti"]->Index)
	{
		int chestie = e->RowIndex;
		int id_materie = (int)dataGridView1->Rows[chestie]->Cells[0]->Value;
		VizualizareCatalogStudenti^ vizualizare = gcnew VizualizareCatalogStudenti;
		vizualizare->id_materie = id_materie;
		vizualizare->id_prof = id_prof;
		vizualizare->Show(this);
	}
}
};
}
