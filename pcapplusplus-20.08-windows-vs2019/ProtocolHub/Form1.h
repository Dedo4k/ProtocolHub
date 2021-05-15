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
	private: System::Windows::Forms::ToolStripMenuItem^ ôàéëToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ îòêğûòüToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ îÏğîãğàììåToolStripMenuItem;
	private: System::Windows::Forms::Label^ infoLabel;
	private: System::Windows::Forms::Panel^ outPanel;
	private: System::Windows::Forms::Label^ outLabel;
	private: System::Windows::Forms::ToolStripMenuItem^ î÷èñòèòüToolStripMenuItem;
	private: System::Windows::Forms::Label^ numberLabel;

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^ äàëååToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ çàêğûòüÏğèëîæåíèåToolStripMenuItem;

	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ôàéëToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îòêğûòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->çàêğûòüÏğèëîæåíèåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->î÷èñòèòüToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îÏğîãğàììåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->äàëååToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
				this->ôàéëToolStripMenuItem,
					this->î÷èñòèòüToolStripMenuItem, this->îÏğîãğàììåToolStripMenuItem, this->äàëååToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(287, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ôàéëToolStripMenuItem
			// 
			this->ôàéëToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->îòêğûòüToolStripMenuItem,
					this->çàêğûòüÏğèëîæåíèåToolStripMenuItem
			});
			this->ôàéëToolStripMenuItem->Name = L"ôàéëToolStripMenuItem";
			this->ôàéëToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->ôàéëToolStripMenuItem->Text = L"Ôàéë";
			// 
			// îòêğûòüToolStripMenuItem
			// 
			this->îòêğûòüToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->îòêğûòüToolStripMenuItem->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->îòêğûòüToolStripMenuItem->Name = L"îòêğûòüToolStripMenuItem";
			this->îòêğûòüToolStripMenuItem->Size = System::Drawing::Size(193, 22);
			this->îòêğûòüToolStripMenuItem->Text = L"Îòêğûòü";
			this->îòêğûòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::îòêğûòüToolStripMenuItem_Click);
			// 
			// çàêğûòüÏğèëîæåíèåToolStripMenuItem
			// 
			this->çàêğûòüÏğèëîæåíèåToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->çàêğûòüÏğèëîæåíèåToolStripMenuItem->Name = L"çàêğûòüÏğèëîæåíèåToolStripMenuItem";
			this->çàêğûòüÏğèëîæåíèåToolStripMenuItem->Size = System::Drawing::Size(193, 22);
			this->çàêğûòüÏğèëîæåíèåToolStripMenuItem->Text = L"Çàêğûòü ïğèëîæåíèå";
			this->çàêğûòüÏğèëîæåíèåToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::çàêğûòüÏğèëîæåíèåToolStripMenuItem_Click);
			// 
			// î÷èñòèòüToolStripMenuItem
			// 
			this->î÷èñòèòüToolStripMenuItem->Name = L"î÷èñòèòüToolStripMenuItem";
			this->î÷èñòèòüToolStripMenuItem->Size = System::Drawing::Size(71, 20);
			this->î÷èñòèòüToolStripMenuItem->Text = L"Î÷èñòèòü";
			this->î÷èñòèòüToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::î÷èñòèòüToolStripMenuItem_Click);
			// 
			// îÏğîãğàììåToolStripMenuItem
			// 
			this->îÏğîãğàììåToolStripMenuItem->Name = L"îÏğîãğàììåToolStripMenuItem";
			this->îÏğîãğàììåToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->îÏğîãğàììåToolStripMenuItem->Text = L"Î ïğîãğàììå";
			this->îÏğîãğàììåToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::îÏğîãğàììåToolStripMenuItem_Click);
			// 
			// äàëååToolStripMenuItem
			// 
			this->äàëååToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"äàëååToolStripMenuItem.Image")));
			this->äàëååToolStripMenuItem->Name = L"äàëååToolStripMenuItem";
			this->äàëååToolStripMenuItem->Size = System::Drawing::Size(28, 20);
			this->äàëååToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::äàëååToolStripMenuItem_Click);
			// 
			// infoLabel
			// 
			this->infoLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->infoLabel->AutoSize = true;
			this->infoLabel->Location = System::Drawing::Point(13, 236);
			this->infoLabel->Name = L"infoLabel";
			this->infoLabel->Size = System::Drawing::Size(161, 13);
			this->infoLabel->TabIndex = 1;
			this->infoLabel->Text = L"Ïåğåòàùèòå ôàéëû íà ôîğìó.";
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
			this->numberLabel->Text = L"Ïîëó÷åíî: 0";
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

	private: System::Void îòêğûòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	
	private: System::Void î÷èñòèòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void îÏğîãğàììåToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void äàëååToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void çàêğûòüÏğèëîæåíèåToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
