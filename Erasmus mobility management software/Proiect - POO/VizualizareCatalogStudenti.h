#pragma once

namespace ProiectPOO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for VizualizareCatalogStudenti
	/// </summary>
	public ref class VizualizareCatalogStudenti : public System::Windows::Forms::Form
	{
	public:
		int id_materie;
		int id_prof;
	public:
		VizualizareCatalogStudenti(void)
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
		~VizualizareCatalogStudenti()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
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
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.25F));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.25F));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->Location = System::Drawing::Point(12, 62);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(728, 286);
			this->dataGridView1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->button1->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.25F));
			this->button1->Location = System::Drawing::Point(612, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(128, 44);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Exit";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &VizualizareCatalogStudenti::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(21, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 19);
			this->label1->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Sitka Text", 14.25F));
			this->label2->Location = System::Drawing::Point(25, 17);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(165, 28);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Virtual Catalogue";
			// 
			// VizualizareCatalogStudenti
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(752, 360);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"VizualizareCatalogStudenti";
			this->Text = L"VizualizareCatalogStudenti";
			this->Load += gcnew System::EventHandler(this, &VizualizareCatalogStudenti::VizualizareCatalogStudenti_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void VizualizareCatalogStudenti_Load(System::Object^  sender, System::EventArgs^  e) {
		SqlDataAdapter^ data;
		DataSet^ source = gcnew DataSet();
		SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=|DataDirectory|\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
		//SqlConnection^ conn = gcnew SqlConnection("Data Source=(LocalDB)\\v11.0;AttachDbFilename=C:\\Users\\Andrei\\Desktop\\PROIECT POO\\Proiect_ POO_v2\\Proiect POO\\BazaDeDateProiect.mdf;Integrated Security=True;Connect Timeout=30");
		conn->Open();
		data = gcnew SqlDataAdapter("SELECT Id_student FROM Materii_intermediar WHERE Id_materie ='" + id_materie + "'; ", conn);
		data->Fill(source);
		DataTable ^dt = source->Tables[0];
		dataGridView1->DataSource = dt;

		dt->Columns->Add(gcnew DataColumn("Nume_student"));
		String^ query = "SELECT COUNT(*) Id_student FROM Materii_intermediar WHERE Id_materie ='" + id_materie + "';";
		SqlCommand^ cmd = gcnew SqlCommand(query, conn);
		int nr_materii = (int)cmd->ExecuteScalar();
		for (int i = 0; i <= nr_materii; i++){
			DataRow^ dr = dt->NewRow();
			String^ query = "SELECT LastName FROM Studenti WHERE ID = '" + dataGridView1->Rows[i]->Cells[0]->Value + "'; ";
			SqlCommand^ cmd = gcnew SqlCommand(query, conn);
			String^ nume = (String^)cmd->ExecuteScalar();
			dataGridView1->Rows[i]->Cells["Nume_student"]->Value = nume;
		}
		dt->Columns->Add(gcnew DataColumn("Prenume_student"));
		for (int i = 0; i <= nr_materii; i++){
			DataRow^ dr1 = dt->NewRow();
			String^ query2 = "SELECT FirstName FROM Studenti WHERE ID = '" + dataGridView1->Rows[i]->Cells[0]->Value + "'; ";
			SqlCommand^ cmd2 = gcnew SqlCommand(query2, conn);
			String^ prenume = (String^)cmd2->ExecuteScalar();
			dataGridView1->Rows[i]->Cells["Prenume_student"]->Value = prenume;
		}
		for (int i = 0; i < nr_materii; i++){
			String^ query4 = "SELECT COUNT(*) FROM Classes WHERE ID_materie = '" + id_materie+ "'AND ID_student = '" + dataGridView1->Rows[i]->Cells[0]->Value + "';";
			SqlCommand^ cmd4 = gcnew SqlCommand(query4, conn);
			int nr_gasiri = (int)cmd->ExecuteScalar();
			if (nr_gasiri != 1){
				String^ query3 = "INSERT INTO Classes(ID_materie,ID_prof,ID_student) VALUES('" + id_materie + "','" + id_prof + "','" + dataGridView1->Rows[i]->Cells[0]->Value + "')";
				SqlCommand^ cmd3 = gcnew SqlCommand(query3, conn);
				cmd3->ExecuteNonQuery();
			}
			
		}
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
};
}
