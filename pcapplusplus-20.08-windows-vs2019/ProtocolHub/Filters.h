#pragma once

namespace curseProject1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Filters : public System::Windows::Forms::Form
	{
	public:
		Filters(System::Collections::ArrayList^ filters)
		{
			this->filters = gcnew System::Collections::ArrayList(filters);
			InitializeComponent();
			initFilters();
		}

	protected:
		~Filters()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Collections::ArrayList^ filters;
	private: System::Windows::Forms::CheckedListBox^ checkedListBox1;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox3;



	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Filters::typeid));
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->BackColor = System::Drawing::SystemColors::Control;
			this->checkedListBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->checkedListBox1->CheckOnClick = true;
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"TCP", L"UDP", L"TLS", L"DNS", L"HTTP",
					L"SIP"
			});
			this->checkedListBox1->Location = System::Drawing::Point(12, 32);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(58, 90);
			this->checkedListBox1->TabIndex = 0;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(13, 9);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(65, 17);
			this->checkBox1->TabIndex = 1;
			this->checkBox1->Text = L"Enabled";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->Click += gcnew System::EventHandler(this, &Filters::checkBox1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(130, 146);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(91, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Apply filters";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Filters::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 146);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(91, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Clear all filters";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Filters::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(146, 9);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Select all";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Filters::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(146, 39);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Clear all";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Filters::button4_Click);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(96, 68);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(125, 17);
			this->checkBox2->TabIndex = 6;
			this->checkBox2->Text = L"�� ������� ������";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &Filters::checkBox2_CheckedChanged);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(95, 92);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(126, 17);
			this->checkBox3->TabIndex = 7;
			this->checkBox3->Text = L"�� ���������� ����";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &Filters::checkBox3_CheckedChanged);
			// 
			// Filters
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(233, 181);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->checkedListBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Location = System::Drawing::Point(96, 47);
			this->Name = L"Filters";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"Filters";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public: void initFilters();
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void checkBox1_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
		private: System::Void checkBox3_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
};
}