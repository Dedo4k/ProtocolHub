#pragma once
#include <msclr/marshal_cppstd.h>
#include "Form2.h"

namespace curseProject1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			this->systemFilePaths = (gcnew System::Collections::ArrayList());
			InitializeComponent();
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Collections::ArrayList^ systemFilePaths;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������ToolStripMenuItem;
	private: System::Windows::Forms::Label^ infoLabel;
	private: System::Windows::Forms::Panel^ outPanel;
	private: System::Windows::Forms::Label^ outLabel;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������ToolStripMenuItem;
	private: System::Windows::Forms::Label^ numberLabel;

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^ �����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����������������ToolStripMenuItem;

	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->infoLabel = (gcnew System::Windows::Forms::Label());
			this->outPanel = (gcnew System::Windows::Forms::Panel());
			this->outLabel = (gcnew System::Windows::Forms::Label());
			this->numberLabel = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1->SuspendLayout();
			this->outPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->����ToolStripMenuItem,
					this->��������ToolStripMenuItem, this->����������ToolStripMenuItem, this->�����ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(287, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->�������ToolStripMenuItem,
					this->�����������������ToolStripMenuItem
			});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->�������ToolStripMenuItem->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(193, 22);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�������ToolStripMenuItem_Click);
			// 
			// �����������������ToolStripMenuItem
			// 
			this->�����������������ToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->�����������������ToolStripMenuItem->Name = L"�����������������ToolStripMenuItem";
			this->�����������������ToolStripMenuItem->Size = System::Drawing::Size(193, 22);
			this->�����������������ToolStripMenuItem->Text = L"������� ����������";
			this->�����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�����������������ToolStripMenuItem_Click);
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(71, 20);
			this->��������ToolStripMenuItem->Text = L"��������";
			this->��������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::��������ToolStripMenuItem_Click);
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->����������ToolStripMenuItem->Text = L"� ���������";
			this->����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::����������ToolStripMenuItem_Click);
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"�����ToolStripMenuItem.Image")));
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(28, 20);
			this->�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�����ToolStripMenuItem_Click);
			// 
			// infoLabel
			// 
			this->infoLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->infoLabel->AutoSize = true;
			this->infoLabel->Location = System::Drawing::Point(13, 236);
			this->infoLabel->Name = L"infoLabel";
			this->infoLabel->Size = System::Drawing::Size(161, 13);
			this->infoLabel->TabIndex = 1;
			this->infoLabel->Text = L"���������� ����� �� �����.";
			// 
			// outPanel
			// 
			this->outPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->outPanel->AutoScroll = true;
			this->outPanel->Controls->Add(this->outLabel);
			this->outPanel->Location = System::Drawing::Point(16, 28);
			this->outPanel->Name = L"outPanel";
			this->outPanel->Size = System::Drawing::Size(256, 205);
			this->outPanel->TabIndex = 2;
			// 
			// outLabel
			// 
			this->outLabel->AutoSize = true;
			this->outLabel->Location = System::Drawing::Point(0, 0);
			this->outLabel->Name = L"outLabel";
			this->outLabel->Size = System::Drawing::Size(0, 13);
			this->outLabel->TabIndex = 0;
			// 
			// numberLabel
			// 
			this->numberLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->numberLabel->AutoEllipsis = true;
			this->numberLabel->AutoSize = true;
			this->numberLabel->Location = System::Drawing::Point(208, 236);
			this->numberLabel->Name = L"numberLabel";
			this->numberLabel->Size = System::Drawing::Size(67, 13);
			this->numberLabel->TabIndex = 3;
			this->numberLabel->Text = L"��������: 0";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// Form1
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(287, 261);
			this->Controls->Add(this->numberLabel);
			this->Controls->Add(this->outPanel);
			this->Controls->Add(this->infoLabel);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ProtocolHub";
			this->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::Drag_Drop);
			this->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::Drag_Enter);
			this->DragLeave += gcnew System::EventHandler(this, &Form1::Drag_Leave);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->outPanel->ResumeLayout(false);
			this->outPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void Drag_Drop(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e);

	private: System::Void Drag_Enter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e);

	private: System::Void Drag_Leave(System::Object^ sender, System::EventArgs^ e);

	private: System::Void �������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	
	private: System::Void ��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void ����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void �����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void �����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
