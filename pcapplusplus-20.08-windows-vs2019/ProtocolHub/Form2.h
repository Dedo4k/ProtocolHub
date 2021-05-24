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
	
	protected:
	private: System::Collections::ArrayList^ systemFilePaths;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ôàéëToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ íàçàäToolStripMenuItem;
	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::ToolStripMenuItem^ ñåññèèToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^ dataGridView2;






	private: System::Windows::Forms::ToolStripMenuItem^ çàêğûòüÏğèëîæåíèåToolStripMenuItem;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Number;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Source;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SrcPort;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Destination;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DstPort;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Protocol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Time;
	private: System::Windows::Forms::ToolStripComboBox^ toolStripComboBox1;
	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form2::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ôàéëToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->çàêğûòüÏğèëîæåíèåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->íàçàäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ñåññèèToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripComboBox1 = (gcnew System::Windows::Forms::ToolStripComboBox());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Source = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SrcPort = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Destination = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DstPort = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Protocol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Time = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->ôàéëToolStripMenuItem,
					this->íàçàäToolStripMenuItem, this->ñåññèèToolStripMenuItem, this->toolStripComboBox1
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(5, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(1901, 27);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ôàéëToolStripMenuItem
			// 
			this->ôàéëToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->çàêğûòüÏğèëîæåíèåToolStripMenuItem });
			this->ôàéëToolStripMenuItem->Name = L"ôàéëToolStripMenuItem";
			this->ôàéëToolStripMenuItem->Size = System::Drawing::Size(48, 23);
			this->ôàéëToolStripMenuItem->Text = L"Ôàéë";
			// 
			// çàêğûòüÏğèëîæåíèåToolStripMenuItem
			// 
			this->çàêğûòüÏğèëîæåíèåToolStripMenuItem->BackColor = System::Drawing::Color::White;
			this->çàêğûòüÏğèëîæåíèåToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"çàêğûòüÏğèëîæåíèåToolStripMenuItem.Image")));
			this->çàêğûòüÏğèëîæåíèåToolStripMenuItem->Name = L"çàêğûòüÏğèëîæåíèåToolStripMenuItem";
			this->çàêğûòüÏğèëîæåíèåToolStripMenuItem->Size = System::Drawing::Size(193, 22);
			this->çàêğûòüÏğèëîæåíèåToolStripMenuItem->Text = L"Çàêğûòü ïğèëîæåíèå";
			this->çàêğûòüÏğèëîæåíèåToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form2::çàêğûòüÏğèëîæåíèåToolStripMenuItem_Click);
			// 
			// íàçàäToolStripMenuItem
			// 
			this->íàçàäToolStripMenuItem->Name = L"íàçàäToolStripMenuItem";
			this->íàçàäToolStripMenuItem->Size = System::Drawing::Size(51, 23);
			this->íàçàäToolStripMenuItem->Text = L"Íàçàä";
			this->íàçàäToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form2::íàçàäToolStripMenuItem_Click);
			// 
			// ñåññèèToolStripMenuItem
			// 
			this->ñåññèèToolStripMenuItem->Name = L"ñåññèèToolStripMenuItem";
			this->ñåññèèToolStripMenuItem->Size = System::Drawing::Size(59, 23);
			this->ñåññèèToolStripMenuItem->Text = L"Ñåññèè";
			this->ñåññèèToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form2::ñåññèèToolStripMenuItem_Click);
			// 
			// toolStripComboBox1
			// 
			this->toolStripComboBox1->Name = L"toolStripComboBox1";
			this->toolStripComboBox1->Size = System::Drawing::Size(121, 23);
			this->toolStripComboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form2::toolStripComboBox1_SelectedIndexChanged);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Number,
					this->Source, this->SrcPort, this->Destination, this->DstPort, this->Protocol, this->Time
			});
			this->dataGridView1->Location = System::Drawing::Point(21, 41);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(1868, 690);
			this->dataGridView1->TabIndex = 6;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form2::dataGridView1_CellClick);
			// 
			// Number
			// 
			this->Number->FillWeight = 5;
			this->Number->HeaderText = L"¹";
			this->Number->Name = L"Number";
			this->Number->ReadOnly = true;
			// 
			// Source
			// 
			this->Source->FillWeight = 21.3198F;
			this->Source->HeaderText = L"Source";
			this->Source->MinimumWidth = 6;
			this->Source->Name = L"Source";
			this->Source->ReadOnly = true;
			// 
			// SrcPort
			// 
			this->SrcPort->FillWeight = 21.3198F;
			this->SrcPort->HeaderText = L"SrcPort";
			this->SrcPort->MinimumWidth = 6;
			this->SrcPort->Name = L"SrcPort";
			this->SrcPort->ReadOnly = true;
			// 
			// Destination
			// 
			this->Destination->FillWeight = 21.3198F;
			this->Destination->HeaderText = L"Destination";
			this->Destination->MinimumWidth = 6;
			this->Destination->Name = L"Destination";
			this->Destination->ReadOnly = true;
			// 
			// DstPort
			// 
			this->DstPort->FillWeight = 21.3198F;
			this->DstPort->HeaderText = L"DstPort";
			this->DstPort->MinimumWidth = 6;
			this->DstPort->Name = L"DstPort";
			this->DstPort->ReadOnly = true;
			// 
			// Protocol
			// 
			this->Protocol->FillWeight = 21.3198F;
			this->Protocol->HeaderText = L"Protocol";
			this->Protocol->MinimumWidth = 6;
			this->Protocol->Name = L"Protocol";
			this->Protocol->ReadOnly = true;
			// 
			// Time
			// 
			this->Time->FillWeight = 21.3198F;
			this->Time->HeaderText = L"Time";
			this->Time->MinimumWidth = 6;
			this->Time->Name = L"Time";
			this->Time->ReadOnly = true;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView2->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->EnableHeadersVisualStyles = false;
			this->dataGridView2->GridColor = System::Drawing::SystemColors::WindowText;
			this->dataGridView2->Location = System::Drawing::Point(21, 738);
			this->dataGridView2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(1868, 283);
			this->dataGridView2->TabIndex = 7;
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1901, 1033);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Form2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ProtocolHub";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
		public: void StartParsingFiles(System::Collections::ArrayList^ systemFilePaths);

		private: System::Void íàçàäToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void ñåññèèToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void çàêğûòüÏğèëîæåíèåToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		private: System::Void toolStripComboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
};
}
