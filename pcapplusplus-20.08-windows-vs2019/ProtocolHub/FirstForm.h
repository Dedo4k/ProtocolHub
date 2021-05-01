#pragma once
#include <msclr/marshal_cppstd.h>
#include "SecondForm.h"

static std::vector<std::string> stringFilePaths;					

namespace curseProject1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FirstForm : public System::Windows::Forms::Form
	{
	public:
		FirstForm(void)
		{
			this->systemFilePaths = (gcnew System::Collections::ArrayList());
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		~FirstForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Collections::ArrayList^ systemFilePaths;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::DirectoryServices::DirectoryEntry^ directoryEntry1;
	private: System::ComponentModel::Container^ components;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{	
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->directoryEntry1 = (gcnew System::DirectoryServices::DirectoryEntry());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 800);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(211, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Перетащите файлы на форму.";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 780);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(144, 17);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Передано файлов: 0";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 12);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(113, 31);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Открыть";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FirstForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(127, 12);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(113, 31);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Очистить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &FirstForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(240, 12);
			this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(113, 31);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Парсить";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &FirstForm::button3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(0, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 17);
			this->label2->TabIndex = 9;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(180, 780);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(143, 17);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Получено файлов: 0";
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->Controls->Add(this->label2);
			this->panel1->Location = System::Drawing::Point(13, 670);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1150, 100);
			this->panel1->TabIndex = 11;
			// 
			// FirstForm
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->ClientSize = System::Drawing::Size(1182, 853);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label1);
			this->ForeColor = System::Drawing::SystemColors::Desktop;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"FirstForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FirstForm";
			this->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &FirstForm::FirstForm_DragDrop);
			this->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &FirstForm::FirstForm_DragEnter);
			this->DragLeave += gcnew System::EventHandler(this, &FirstForm::FirstForm_DragLeave);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	public: int numberOfDraggedFiles;

	private: System::Void FirstForm_DragDrop(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e) {
		msclr::interop::marshal_context context;
		label1->Text = "Перетащите файлы на форму.";
		numberOfDraggedFiles += ((array<String^>^) e->Data->GetData(DataFormats::FileDrop))->Length;
		label5->Text = "Передано файлов: " + numberOfDraggedFiles;
		for each (String ^ systemFilePath in (array<String^>^) e->Data->GetData(DataFormats::FileDrop))
		{
			if (systemFilePath->Contains(".pcap") || systemFilePath->Contains(".pcapng")) {
				stringFilePaths.push_back(context.marshal_as<std::string>(systemFilePath));
				this->systemFilePaths->Add(systemFilePath);
			}
			else {
				label2->Text += systemFilePath + " не поддерживается.\n";
			}
		}
		label3->Text = "Получено файлов: " + stringFilePaths.size();
	}

	private: System::Void FirstForm_DragEnter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e) {
		if (e->Data->GetDataPresent(DataFormats::FileDrop)) {
			e->Effect = DragDropEffects::Copy;
			label1->Text = "Отпустите мышь.";
		}
		else {
			label1->Text = "Ошибка при перетаскивании.";
		}
	}

	private: System::Void FirstForm_DragLeave(System::Object^ sender, System::EventArgs^ e) {
		label1->Text = "Перетащите файлы на форму.";
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		numberOfDraggedFiles = 0;
		stringFilePaths.clear();
		this->systemFilePaths->Clear();
		label2->Text = "";
		label5->Text = "Передано файлов: 0";
		label3->Text = "Получено файлов: 0";
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {				
		msclr::interop::marshal_context context;

		OpenFileDialog^ openFileDiaolog = gcnew OpenFileDialog();
		openFileDiaolog->InitialDirectory = "c:\\";
		openFileDiaolog->Title = "Выберите файл";
		openFileDiaolog->RestoreDirectory = true;
		
		if (openFileDiaolog->ShowDialog() == System::Windows::Forms::DialogResult::OK) 
		{
			numberOfDraggedFiles++;
			label5->Text = "Передано файлов: " + numberOfDraggedFiles;
			if (openFileDiaolog->FileName->Contains(".pcap") || openFileDiaolog->FileName->Contains(".pcapng")) {
				stringFilePaths.push_back(context.marshal_as<std::string>(openFileDiaolog->FileName));
				this->systemFilePaths->Add(openFileDiaolog->FileName);
			}
			else {
				label2->Text += openFileDiaolog->FileName + " не поддерживается.\n";
			}
			label3->Text = "Получено файлов: " + stringFilePaths.size();
		}
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		SecondForm^ secondForm = (gcnew SecondForm(this->systemFilePaths));
		secondForm->ShowDialog();
		this->Show();
	}

};
}
