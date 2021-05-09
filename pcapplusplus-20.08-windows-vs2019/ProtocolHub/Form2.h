#pragma once

namespace curseProject1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		Form2(System::Collections::ArrayList^ systemFilePaths)
		{
			this->systemFilePaths = (gcnew System::Collections::ArrayList(systemFilePaths));
			InitializeComponent();			
			StartParsingFiles(systemFilePaths);
		}

	protected:
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Collections::ArrayList^ systemFilePaths;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ Ù‡ÈÎToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ Ì‡Á‡‰ToolStripMenuItem;








	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton1;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton2;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton3;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton4;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton5;
	private: System::Windows::Forms::ToolStripComboBox^ toolStripComboBox1;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator2;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator3;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator4;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator5;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator6;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton6;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator7;
	private: System::Windows::Forms::ToolStripLabel^ toolStripLabel1;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator8;
	private: System::Windows::Forms::ToolStripDropDownButton^ toolStripDropDownButton1;






	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Time;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Source;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Destination;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Protocol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Info;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ moreInfo;













	private: System::ComponentModel::IContainer^ components;

	protected:



#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form2::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->Ù‡ÈÎToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Ì‡Á‡‰ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton5 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator5 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripComboBox1 = (gcnew System::Windows::Forms::ToolStripComboBox());
			this->toolStripSeparator6 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton6 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator7 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripLabel1 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->toolStripSeparator8 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripDropDownButton1 = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Time = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Source = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Destination = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Protocol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Info = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->moreInfo = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->Ù‡ÈÎToolStripMenuItem,
					this->Ì‡Á‡‰ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1685, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// Ù‡ÈÎToolStripMenuItem
			// 
			this->Ù‡ÈÎToolStripMenuItem->Name = L"Ù‡ÈÎToolStripMenuItem";
			this->Ù‡ÈÎToolStripMenuItem->Size = System::Drawing::Size(59, 24);
			this->Ù‡ÈÎToolStripMenuItem->Text = L"‘‡ÈÎ";
			// 
			// Ì‡Á‡‰ToolStripMenuItem
			// 
			this->Ì‡Á‡‰ToolStripMenuItem->Name = L"Ì‡Á‡‰ToolStripMenuItem";
			this->Ì‡Á‡‰ToolStripMenuItem->Size = System::Drawing::Size(65, 24);
			this->Ì‡Á‡‰ToolStripMenuItem->Text = L"Õ‡Á‡‰";
			this->Ì‡Á‡‰ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form2::Ì‡Á‡‰ToolStripMenuItem_Click);
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(17) {
				this->toolStripButton1,
					this->toolStripSeparator1, this->toolStripButton2, this->toolStripSeparator2, this->toolStripButton3, this->toolStripSeparator3,
					this->toolStripButton4, this->toolStripSeparator4, this->toolStripButton5, this->toolStripSeparator5, this->toolStripComboBox1,
					this->toolStripSeparator6, this->toolStripButton6, this->toolStripSeparator7, this->toolStripLabel1, this->toolStripSeparator8,
					this->toolStripDropDownButton1
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 28);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(1685, 28);
			this->toolStrip1->TabIndex = 5;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(29, 25);
			this->toolStripButton1->Text = L"toolStripButton1";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 28);
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(29, 25);
			this->toolStripButton2->Text = L"toolStripButton2";
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(6, 28);
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(29, 25);
			this->toolStripButton3->Text = L"toolStripButton3";
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(6, 28);
			// 
			// toolStripButton4
			// 
			this->toolStripButton4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton4.Image")));
			this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton4->Name = L"toolStripButton4";
			this->toolStripButton4->Size = System::Drawing::Size(29, 25);
			this->toolStripButton4->Text = L"toolStripButton4";
			// 
			// toolStripSeparator4
			// 
			this->toolStripSeparator4->Name = L"toolStripSeparator4";
			this->toolStripSeparator4->Size = System::Drawing::Size(6, 28);
			// 
			// toolStripButton5
			// 
			this->toolStripButton5->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton5.Image")));
			this->toolStripButton5->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton5->Name = L"toolStripButton5";
			this->toolStripButton5->Size = System::Drawing::Size(29, 25);
			this->toolStripButton5->Text = L"toolStripButton5";
			// 
			// toolStripSeparator5
			// 
			this->toolStripSeparator5->Name = L"toolStripSeparator5";
			this->toolStripSeparator5->Size = System::Drawing::Size(6, 28);
			// 
			// toolStripComboBox1
			// 
			this->toolStripComboBox1->Name = L"toolStripComboBox1";
			this->toolStripComboBox1->Size = System::Drawing::Size(160, 28);
			this->toolStripComboBox1->Text = L"dfdf";
			// 
			// toolStripSeparator6
			// 
			this->toolStripSeparator6->Name = L"toolStripSeparator6";
			this->toolStripSeparator6->Size = System::Drawing::Size(6, 28);
			// 
			// toolStripButton6
			// 
			this->toolStripButton6->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton6.Image")));
			this->toolStripButton6->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton6->Name = L"toolStripButton6";
			this->toolStripButton6->Size = System::Drawing::Size(29, 25);
			this->toolStripButton6->Text = L"toolStripButton6";
			// 
			// toolStripSeparator7
			// 
			this->toolStripSeparator7->Name = L"toolStripSeparator7";
			this->toolStripSeparator7->Size = System::Drawing::Size(6, 28);
			// 
			// toolStripLabel1
			// 
			this->toolStripLabel1->Name = L"toolStripLabel1";
			this->toolStripLabel1->Size = System::Drawing::Size(111, 25);
			this->toolStripLabel1->Text = L"toolStripLabel1";
			// 
			// toolStripSeparator8
			// 
			this->toolStripSeparator8->Name = L"toolStripSeparator8";
			this->toolStripSeparator8->Size = System::Drawing::Size(6, 28);
			// 
			// toolStripDropDownButton1
			// 
			this->toolStripDropDownButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripDropDownButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripDropDownButton1.Image")));
			this->toolStripDropDownButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripDropDownButton1->Name = L"toolStripDropDownButton1";
			this->toolStripDropDownButton1->Size = System::Drawing::Size(34, 25);
			this->toolStripDropDownButton1->Text = L"toolStripDropDownButton1";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Time, this->Source,
					this->Destination, this->Protocol, this->Info
			});
			this->dataGridView1->Location = System::Drawing::Point(22, 60);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(1651, 442);
			this->dataGridView1->TabIndex = 6;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form2::dataGridView1_CellClick);
			// 
			// Time
			// 
			this->Time->HeaderText = L"Time";
			this->Time->MinimumWidth = 6;
			this->Time->Name = L"Time";
			this->Time->ReadOnly = true;
			this->Time->Width = 125;
			// 
			// Source
			// 
			this->Source->HeaderText = L"Source";
			this->Source->MinimumWidth = 6;
			this->Source->Name = L"Source";
			this->Source->ReadOnly = true;
			this->Source->Width = 125;
			// 
			// Destination
			// 
			this->Destination->HeaderText = L"Destination";
			this->Destination->MinimumWidth = 6;
			this->Destination->Name = L"Destination";
			this->Destination->ReadOnly = true;
			this->Destination->Width = 125;
			// 
			// Protocol
			// 
			this->Protocol->HeaderText = L"Protocol";
			this->Protocol->MinimumWidth = 6;
			this->Protocol->Name = L"Protocol";
			this->Protocol->ReadOnly = true;
			this->Protocol->Width = 125;
			// 
			// Info
			// 
			this->Info->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Info->HeaderText = L"Info";
			this->Info->MinimumWidth = 6;
			this->Info->Name = L"Info";
			this->Info->ReadOnly = true;
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->moreInfo);
			this->panel1->Location = System::Drawing::Point(22, 508);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1651, 318);
			this->panel1->TabIndex = 7;
			// 
			// moreInfo
			// 
			this->moreInfo->AutoSize = true;
			this->moreInfo->Location = System::Drawing::Point(0, 0);
			this->moreInfo->Name = L"moreInfo";
			this->moreInfo->Size = System::Drawing::Size(0, 17);
			this->moreInfo->TabIndex = 0;
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1685, 838);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Form2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ProtocolHub";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}


#pragma endregion
		private: System::Void Ì‡Á‡‰ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	
		public: void StartParsingFiles(System::Collections::ArrayList^ systemFilePaths);
		private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
};
}
