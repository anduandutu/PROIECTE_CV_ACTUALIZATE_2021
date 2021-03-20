#pragma once
using namespace std;
#include "Contract_studenti.h"
//#include "Alegere_Materii.h"
namespace ProiectPOO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	/// <summary>
	/// Summary for Editare_materii
	/// </summary>
	public ref class Editare_materii : public System::Windows::Forms::Form
	{
	public:
		int id_stud;
	public:
		Editare_materii(void)
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
		~Editare_materii()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ActiveCaption;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Sitka Small", 9.75F));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Sitka Small", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView1->Location = System::Drawing::Point(12, 72);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(495, 214);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Editare_materii::dataGridView1_CellClick);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button1->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 15.75F));
			this->button1->Location = System::Drawing::Point(334, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(172, 41);
			this->button1->TabIndex = 1;
			this->button1->Text = L"GENERATE CONTRACT";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Editare_materii::button1_Click);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button2->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button2->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 15.75F));
			this->button2->Location = System::Drawing::Point(12, 13);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(172, 41);
			this->button2->TabIndex = 2;
			this->button2->Text = L"GO BACK";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Editare_materii::button2_Click);
			// 
			// Editare_materii
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(530, 305);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->MaximumSize = System::Drawing::Size(546, 344);
			this->MinimumSize = System::Drawing::Size(546, 344);
			this->Name = L"Editare_materii";
			this->Text = L"Update student contract";
			this->Load += gcnew System::EventHandler(this, &Editare_materii::Editare_materii_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Editare_materii_Load(System::Object^  sender, System::EventArgs^  e) {

		SqlDataAdapter^ data;
		DataSet^ source = gcnew DataSet();
		SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
		//SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
		conn->Open();
		data = gcnew SqlDataAdapter("SELECT Id_materie FROM Materii_intermediar WHERE Id_student ='" + id_stud + "'; ", conn);
		data->Fill(source);
		DataTable ^dt = source->Tables[0];
		dataGridView1->DataSource = dt;
		dt->Columns->Add(gcnew DataColumn("Materie"));
		String^ query = "SELECT COUNT(*) Id_materie FROM Materii_intermediar WHERE Id_student ='" + id_stud + "';";
		SqlCommand^ cmd = gcnew SqlCommand(query, conn);
		int nr_materii = (int)cmd->ExecuteScalar();
		for (int i = 0; i <= nr_materii; i++){
			DataRow^ dr = dt->NewRow();
			String^ query = "SELECT Name FROM Subjects WHERE ID = '" + dataGridView1->Rows[i]->Cells[0]->Value +"'; ";
			SqlCommand^ cmd = gcnew SqlCommand(query, conn);
			String^ materie = (String^) cmd->ExecuteScalar();
			dataGridView1->Rows[i]->Cells["Materie"]->Value = materie; 
		}
		DataGridViewButtonColumn^ alege_materie_ButtonColumn = gcnew DataGridViewButtonColumn();
		alege_materie_ButtonColumn->Name = "Delete Subject";
		alege_materie_ButtonColumn->Text = "Delete";
		alege_materie_ButtonColumn->UseColumnTextForButtonValue = true;
		int columnIndex = 2;
		dataGridView1->Columns->Insert(columnIndex, alege_materie_ButtonColumn);
	}
	private: System::Void dataGridView1_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		if (e->ColumnIndex == dataGridView1->Columns["Delete Subject"]->Index)
		{
			int chestie = e->RowIndex;
			int id_materie = (int)dataGridView1->Rows[chestie]->Cells[0]->Value;
			SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
			//SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
			conn->Open();
			String^ query = "SELECT COUNT(*) FROM Materii_intermediar WHERE  Id_student= '" + id_stud + "' AND Id_materie = '" + id_materie + "';";
			SqlCommand^ cmd = gcnew SqlCommand(query, conn);
			int count1 = (int)cmd->ExecuteScalar();
			if (count1 == 1){
				SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
				//SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
				conn->Open();
				SqlCommand^ cmd = gcnew SqlCommand("DELETE FROM Materii_intermediar WHERE Id_student = '"+id_stud+"'AND Id_materie = '"+dataGridView1->Rows[chestie]->Cells[0]->Value+"';", conn);
				cmd->ExecuteNonQuery();
				dataGridView1->Rows->RemoveAt(chestie);
			}
			else{
				conn->Close();
			}

		}
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		//this->Hide();
		Contract_studenti^ contract = gcnew Contract_studenti;
		contract->id_stud = id_stud;
		contract->Show(this);
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
}
};
}
