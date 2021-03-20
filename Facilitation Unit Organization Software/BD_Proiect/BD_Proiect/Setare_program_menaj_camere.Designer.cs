namespace BD_Proiect
{
    partial class Setare_program_menaj_camere
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.camereBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.bD_ProiectDataSet2 = new BD_Proiect.BD_ProiectDataSet2();
            this.camereTableAdapter = new BD_Proiect.BD_ProiectDataSet2TableAdapters.CamereTableAdapter();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.bD_ProiectDataSet5 = new BD_Proiect.BD_ProiectDataSet5();
            this.camereBindingSource1 = new System.Windows.Forms.BindingSource(this.components);
            this.camereTableAdapter1 = new BD_Proiect.BD_ProiectDataSet5TableAdapters.CamereTableAdapter();
            this.iDCameraDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.tipCameraDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.descrierefacilitatiDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column1 = new System.Windows.Forms.DataGridViewButtonColumn();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.camereBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.bD_ProiectDataSet2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.bD_ProiectDataSet5)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.camereBindingSource1)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.AutoGenerateColumns = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.iDCameraDataGridViewTextBoxColumn,
            this.tipCameraDataGridViewTextBoxColumn,
            this.descrierefacilitatiDataGridViewTextBoxColumn,
            this.Column1});
            this.dataGridView1.DataSource = this.camereBindingSource1;
            this.dataGridView1.Location = new System.Drawing.Point(16, 15);
            this.dataGridView1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidth = 51;
            this.dataGridView1.Size = new System.Drawing.Size(599, 393);
            this.dataGridView1.TabIndex = 2;
            this.dataGridView1.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellContentClick);
            // 
            // camereBindingSource
            // 
            this.camereBindingSource.DataMember = "Camere";
            this.camereBindingSource.DataSource = this.bD_ProiectDataSet2;
            // 
            // bD_ProiectDataSet2
            // 
            this.bD_ProiectDataSet2.DataSetName = "BD_ProiectDataSet2";
            this.bD_ProiectDataSet2.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // camereTableAdapter
            // 
            this.camereTableAdapter.ClearBeforeFill = true;
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(624, 46);
            this.textBox1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(264, 22);
            this.textBox1.TabIndex = 3;
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(624, 113);
            this.textBox2.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(264, 22);
            this.textBox2.TabIndex = 4;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(624, 15);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(91, 17);
            this.label1.TabIndex = 5;
            this.label1.Text = "Ora incepere";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(623, 94);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(97, 17);
            this.label2.TabIndex = 6;
            this.label2.Text = "Ora Finalizare";
            // 
            // bD_ProiectDataSet5
            // 
            this.bD_ProiectDataSet5.DataSetName = "BD_ProiectDataSet5";
            this.bD_ProiectDataSet5.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // camereBindingSource1
            // 
            this.camereBindingSource1.DataMember = "Camere";
            this.camereBindingSource1.DataSource = this.bD_ProiectDataSet5;
            // 
            // camereTableAdapter1
            // 
            this.camereTableAdapter1.ClearBeforeFill = true;
            // 
            // iDCameraDataGridViewTextBoxColumn
            // 
            this.iDCameraDataGridViewTextBoxColumn.DataPropertyName = "ID_Camera";
            this.iDCameraDataGridViewTextBoxColumn.HeaderText = "ID_Camera";
            this.iDCameraDataGridViewTextBoxColumn.MinimumWidth = 6;
            this.iDCameraDataGridViewTextBoxColumn.Name = "iDCameraDataGridViewTextBoxColumn";
            this.iDCameraDataGridViewTextBoxColumn.ReadOnly = true;
            this.iDCameraDataGridViewTextBoxColumn.Width = 125;
            // 
            // tipCameraDataGridViewTextBoxColumn
            // 
            this.tipCameraDataGridViewTextBoxColumn.DataPropertyName = "Tip_Camera";
            this.tipCameraDataGridViewTextBoxColumn.HeaderText = "Tip_Camera";
            this.tipCameraDataGridViewTextBoxColumn.MinimumWidth = 6;
            this.tipCameraDataGridViewTextBoxColumn.Name = "tipCameraDataGridViewTextBoxColumn";
            this.tipCameraDataGridViewTextBoxColumn.Width = 125;
            // 
            // descrierefacilitatiDataGridViewTextBoxColumn
            // 
            this.descrierefacilitatiDataGridViewTextBoxColumn.DataPropertyName = "Descriere_facilitati";
            this.descrierefacilitatiDataGridViewTextBoxColumn.HeaderText = "Descriere_facilitati";
            this.descrierefacilitatiDataGridViewTextBoxColumn.MinimumWidth = 6;
            this.descrierefacilitatiDataGridViewTextBoxColumn.Name = "descrierefacilitatiDataGridViewTextBoxColumn";
            this.descrierefacilitatiDataGridViewTextBoxColumn.Width = 125;
            // 
            // Column1
            // 
            this.Column1.HeaderText = "Adaugare_menaj";
            this.Column1.MinimumWidth = 6;
            this.Column1.Name = "Column1";
            this.Column1.Width = 125;
            // 
            // Setare_program_menaj_camere
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(905, 422);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.dataGridView1);
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "Setare_program_menaj_camere";
            this.Text = "Setare_program_menaj_camere";
            this.Load += new System.EventHandler(this.Setare_program_menaj_camere_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.camereBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.bD_ProiectDataSet2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.bD_ProiectDataSet5)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.camereBindingSource1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.DataGridView dataGridView1;
        private BD_ProiectDataSet2 bD_ProiectDataSet2;
        private System.Windows.Forms.BindingSource camereBindingSource;
        private BD_ProiectDataSet2TableAdapters.CamereTableAdapter camereTableAdapter;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private BD_ProiectDataSet5 bD_ProiectDataSet5;
        private System.Windows.Forms.BindingSource camereBindingSource1;
        private BD_ProiectDataSet5TableAdapters.CamereTableAdapter camereTableAdapter1;
        private System.Windows.Forms.DataGridViewTextBoxColumn iDCameraDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn tipCameraDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn descrierefacilitatiDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewButtonColumn Column1;
    }
}