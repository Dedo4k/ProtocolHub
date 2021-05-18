#pragma once

namespace curseProject1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Sessions : public System::Windows::Forms::Form
	{
	public:
		Sessions(System::Collections::ArrayList^ systemFilePaths)
		{
			this->filters = gcnew System::Collections::ArrayList;
			this->systemFilePaths = gcnew System::Collections::ArrayList(systemFilePaths);
			InitializeComponent();
			startDrawingSessions(systemFilePaths);
			drawHandshake();
		}

	protected:
		~Sessions()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Collections::ArrayList^ filters;
	private: System::Collections::ArrayList^ systemFilePaths;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ Ù‡ÈÎToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ Ì‡Á‡‰ToolStripMenuItem;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TrackBar^ trackBar2;
	private: System::Windows::Forms::ToolStripMenuItem^ ÙËÎ¸Ú˚ToolStripMenuItem;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::BindingSource^ bindingSource1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Protocols;
	private: System::Windows::Forms::ToolStripMenuItem^ ·‡ÈÚÓ‚Í‡ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ Á‡Í˚Ú¸œËÎÓÊÂÌËÂToolStripMenuItem;
	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Sessions::typeid));
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->Ù‡ÈÎToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Á‡Í˚Ú¸œËÎÓÊÂÌËÂToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Ì‡Á‡‰ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ÙËÎ¸Ú˚ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->·‡ÈÚÓ‚Í‡ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Protocols = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->Ù‡ÈÎToolStripMenuItem,
					this->Ì‡Á‡‰ToolStripMenuItem, this->ÙËÎ¸Ú˚ToolStripMenuItem, this->·‡ÈÚÓ‚Í‡ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(1426, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// Ù‡ÈÎToolStripMenuItem
			// 
			this->Ù‡ÈÎToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->Á‡Í˚Ú¸œËÎÓÊÂÌËÂToolStripMenuItem });
			this->Ù‡ÈÎToolStripMenuItem->Name = L"Ù‡ÈÎToolStripMenuItem";
			this->Ù‡ÈÎToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->Ù‡ÈÎToolStripMenuItem->Text = L"‘‡ÈÎ";
			// 
			// Á‡Í˚Ú¸œËÎÓÊÂÌËÂToolStripMenuItem
			// 
			this->Á‡Í˚Ú¸œËÎÓÊÂÌËÂToolStripMenuItem->BackColor = System::Drawing::Color::White;
			this->Á‡Í˚Ú¸œËÎÓÊÂÌËÂToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Á‡Í˚Ú¸œËÎÓÊÂÌËÂToolStripMenuItem.Image")));
			this->Á‡Í˚Ú¸œËÎÓÊÂÌËÂToolStripMenuItem->Name = L"Á‡Í˚Ú¸œËÎÓÊÂÌËÂToolStripMenuItem";
			this->Á‡Í˚Ú¸œËÎÓÊÂÌËÂToolStripMenuItem->Size = System::Drawing::Size(197, 26);
			this->Á‡Í˚Ú¸œËÎÓÊÂÌËÂToolStripMenuItem->Text = L"«‡Í˚Ú¸ ÔËÎÓÊÂÌËÂ";
			this->Á‡Í˚Ú¸œËÎÓÊÂÌËÂToolStripMenuItem->Click += gcnew System::EventHandler(this, &Sessions::Á‡Í˚Ú¸œËÎÓÊÂÌËÂToolStripMenuItem_Click);
			// 
			// Ì‡Á‡‰ToolStripMenuItem
			// 
			this->Ì‡Á‡‰ToolStripMenuItem->Name = L"Ì‡Á‡‰ToolStripMenuItem";
			this->Ì‡Á‡‰ToolStripMenuItem->Size = System::Drawing::Size(51, 20);
			this->Ì‡Á‡‰ToolStripMenuItem->Text = L"Õ‡Á‡‰";
			this->Ì‡Á‡‰ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Sessions::Ì‡Á‡‰ToolStripMenuItem_Click);
			// 
			// ÙËÎ¸Ú˚ToolStripMenuItem
			// 
			this->ÙËÎ¸Ú˚ToolStripMenuItem->Name = L"ÙËÎ¸Ú˚ToolStripMenuItem";
			this->ÙËÎ¸Ú˚ToolStripMenuItem->Size = System::Drawing::Size(69, 20);
			this->ÙËÎ¸Ú˚ToolStripMenuItem->Text = L"‘ËÎ¸Ú˚";
			this->ÙËÎ¸Ú˚ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Sessions::ÙËÎ¸Ú˚ToolStripMenuItem_Click);
			// 
			// ·‡ÈÚÓ‚Í‡ToolStripMenuItem
			// 
			this->·‡ÈÚÓ‚Í‡ToolStripMenuItem->Name = L"·‡ÈÚÓ‚Í‡ToolStripMenuItem";
			this->·‡ÈÚÓ‚Í‡ToolStripMenuItem->Size = System::Drawing::Size(69, 20);
			this->·‡ÈÚÓ‚Í‡ToolStripMenuItem->Text = L"¡‡ÈÚÓ‚Í‡";
			this->·‡ÈÚÓ‚Í‡ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Sessions::·‡ÈÚÓ‚Í‡ToolStripMenuItem_Click);
			// 
			// chart1
			// 
			this->chart1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->chart1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->chart1->BorderlineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
			chartArea1->BackColor = System::Drawing::Color::DimGray;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Location = System::Drawing::Point(172, 74);
			this->chart1->Margin = System::Windows::Forms::Padding(2);
			this->chart1->Name = L"chart1";
			this->chart1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Light;
			this->chart1->Size = System::Drawing::Size(1246, 756);
			this->chart1->TabIndex = 1;
			this->chart1->Text = L"chart1";
			this->chart1->AxisViewChanged += gcnew System::EventHandler<System::Windows::Forms::DataVisualization::Charting::ViewEventArgs^ >(this, &Sessions::chart1_AxisViewChanged);
			// 
			// trackBar1
			// 
			this->trackBar1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->trackBar1->Cursor = System::Windows::Forms::Cursors::Default;
			this->trackBar1->Location = System::Drawing::Point(1340, 25);
			this->trackBar1->Margin = System::Windows::Forms::Padding(2);
			this->trackBar1->Maximum = 50;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(78, 45);
			this->trackBar1->TabIndex = 2;
			this->trackBar1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Sessions::trackBar1_MouseUp);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(1353, 50);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 17);
			this->label1->TabIndex = 3;
			this->label1->Text = L"—ÂÒÒËË";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(1270, 50);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 17);
			this->label2->TabIndex = 5;
			this->label2->Text = L"¬ÂÏˇ";
			// 
			// trackBar2
			// 
			this->trackBar2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->trackBar2->Cursor = System::Windows::Forms::Cursors::Default;
			this->trackBar2->Location = System::Drawing::Point(1257, 25);
			this->trackBar2->Margin = System::Windows::Forms::Padding(2);
			this->trackBar2->Maximum = 100;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(78, 45);
			this->trackBar2->TabIndex = 1;
			this->trackBar2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Sessions::trackBar2_MouseUp);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(1196, 25);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(56, 41);
			this->button1->TabIndex = 6;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Sessions::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Protocols });
			this->dataGridView1->Location = System::Drawing::Point(10, 74);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(158, 756);
			this->dataGridView1->TabIndex = 7;
			// 
			// Protocols
			// 
			this->Protocols->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Protocols->HeaderText = L"Protocols";
			this->Protocols->MinimumWidth = 6;
			this->Protocols->Name = L"Protocols";
			this->Protocols->ReadOnly = true;
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button2->Location = System::Drawing::Point(1136, 25);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(56, 41);
			this->button2->TabIndex = 8;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Sessions::button2_Click);
			// 
			// Sessions
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1426, 839);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->trackBar2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Sessions";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ProtocolHub";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

		public: void drawHandshake();
		public: void startDrawingSessions(System::Collections::ArrayList^ systemFilePaths);
		public: void startFinding();
		public: void setFilters(System::Collections::ArrayList^ filters);
		public: System::Collections::ArrayList^ getSystemFilePaths();

		private: System::Void Ì‡Á‡‰ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void ÙËÎ¸Ú˚ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void ·‡ÈÚÓ‚Í‡ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void Á‡Í˚Ú¸œËÎÓÊÂÌËÂToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e);
		private: System::Void trackBar2_Scroll(System::Object^ sender, System::EventArgs^ e);
		private: System::Void trackBar1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		private: System::Void trackBar2_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void chart1_AxisViewChanged(System::Object^ sender, System::Windows::Forms::DataVisualization::Charting::ViewEventArgs^ e);
};
}
