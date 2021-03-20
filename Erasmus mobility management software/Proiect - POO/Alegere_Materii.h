#pragma once
using namespace std;
#include <cstdlib>
#include "Editare_materii.h"
namespace ProiectPOO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Alegere_Materii
	/// </summary>
	public ref class Alegere_Materii : public System::Windows::Forms::Form
	{
	public:
		int id_student;
	public:

		Alegere_Materii(void)
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
		~Alegere_Materii()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Label^  label2;
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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(125, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 30);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			this->label1->Click += gcnew System::EventHandler(this, &Alegere_Materii::label1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ActiveCaption;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Sitka Small", 9.75F));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Sitka Small", 9.75F));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->Location = System::Drawing::Point(12, 66);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(666, 273);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Alegere_Materii::dataGridView1_CellClick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->Location = System::Drawing::Point(7, 21);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(101, 28);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Student ID";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->button1->Font = (gcnew System::Drawing::Font(L"Sitka Subheading", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(480, 8);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(198, 52);
			this->button1->TabIndex = 3;
			this->button1->Text = L"NEXT";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Alegere_Materii::button1_Click);
			// 
			// Alegere_Materii
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(690, 351);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label1);
			this->MaximumSize = System::Drawing::Size(706, 390);
			this->MinimumSize = System::Drawing::Size(706, 390);
			this->Name = L"Alegere_Materii";
			this->Text = L"Choose Subjects";
			this->Load += gcnew System::EventHandler(this, &Alegere_Materii::Alegere_Materii_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
			DataTable^ dt = gcnew DataTable();
	private: System::Void Alegere_Materii_Load(System::Object^  sender, System::EventArgs^  e) {
		string s = to_string(id_student);
		label1->Text = gcnew String(s.c_str());
		SqlDataAdapter^ data;
		DataSet^ source = gcnew DataSet();
		SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
		//SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
		conn->Open();
		data = gcnew SqlDataAdapter("SELECT * FROM Subjects", conn);
		data->Fill(source);
		data->Fill(dt);
		dataGridView1->DataSource = source->Tables[0];
		DataGridViewButtonColumn^ alege_materie_ButtonColumn = gcnew DataGridViewButtonColumn();
		alege_materie_ButtonColumn->Name = "Choose Subject";
		alege_materie_ButtonColumn->Text = "Choose";
		alege_materie_ButtonColumn->UseColumnTextForButtonValue = true;
		int columnIndex = 5;
		dataGridView1->Columns->Insert(columnIndex, alege_materie_ButtonColumn);
	}
	private: System::Void dataGridView1_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		if (e->ColumnIndex == dataGridView1->Columns["Choose Subject"]->Index)
		{
			int chestie = e->RowIndex;
			int id_materie = Convert::ToInt32(dataGridView1->Rows[chestie]->Cells[0]->Value);
			SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
			//SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect - POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
			conn->Open();
			String^ query = "SELECT COUNT(*) FROM Materii_intermediar WHERE  Id_student= '" + id_student + "' AND Id_materie = '" + id_materie + "';";
			SqlCommand^ cmd = gcnew SqlCommand(query, conn);
			int count1 = (int)cmd->ExecuteScalar();
			if (count1 == 1){
				conn->Close();
			}
			else{
				SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
				//SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
				SqlCommand^ cmd = gcnew SqlCommand("INSERT INTO Materii_intermediar(Id_student,Id_materie) VALUES('" + id_student + "','" + id_materie + "');", conn);
				SqlDataReader^ reader;
				try{
					conn->Open();
					reader = cmd->ExecuteReader();
					while (reader->Read()){

					}
				}
				catch (Exception^ ex){
					MessageBox::Show(ex->Message);
				}
				finally{
					conn->Close();
				}
			}

		}
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Editare_materii^ forma_edit = gcnew Editare_materii;
		forma_edit->id_stud = id_student;
		forma_edit->ShowDialog(this);
	}
	private: System::Void printDocument1_PrintPage(System::Object^  sender, System::Drawing::Printing::PrintPageEventArgs^  e) {

	}

};
}
