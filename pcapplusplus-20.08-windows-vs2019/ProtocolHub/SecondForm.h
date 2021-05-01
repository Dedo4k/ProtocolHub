#pragma once
//#include "Service.h"

namespace curseProject1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class SecondForm : public System::Windows::Forms::Form
	{
	public:
		SecondForm(ArrayList^ systemFilePaths)
		{
			InitializeComponent(systemFilePaths);
			DrawFilePaths();
			
			
		}

	protected:
		~SecondForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Collections::ArrayList^ systemFilePaths;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(System::Collections::ArrayList^ systemFilePaths)
		{
			this->systemFilePaths = (gcnew System::Collections::ArrayList(systemFilePaths));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(10, 10);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 25);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Назад";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SecondForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 50);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1000, 500);
			this->label1->TabIndex = 0;
			this->label1->Text = L"";
			// 
			// SecondForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->ClientSize = System::Drawing::Size(1200, 900);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"SecondForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SecondForm";
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Hide();
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
		}
		
		public: void DrawFilePaths() {
			for each (String^ systemFilePath in this->systemFilePaths)
			{
				label1->Text += systemFilePath + "\n";
			}
		}
	};
}
