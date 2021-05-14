#pragma once

namespace curseProject1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для filterButtons
	/// </summary>
	public ref class filterButtons : public System::Windows::Forms::Form
	{
	public:
		filterButtons(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~filterButtons()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckedListBox^ checkedListBox1;

	private: System::Windows::Forms::Button^ ButtonClear;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::CheckedListBox^ checkedListBox3;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Button^ button3;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->ButtonClear = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->checkedListBox3 = (gcnew System::Windows::Forms::CheckedListBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->CheckOnClick = true;
			this->checkedListBox1->Enabled = false;
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"TCP", L"HTTP", L"TLS", L"RTMP", L"JABBER",
					L"UDP", L"SIP", L"MGCP", L"BTORRENT"
			});
			this->checkedListBox1->Location = System::Drawing::Point(12, 151);
			this->checkedListBox1->MultiColumn = true;
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(581, 72);
			this->checkedListBox1->TabIndex = 0;
			this->checkedListBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &filterButtons::checkedListBox1_SelectedIndexChanged);
			// 
			// ButtonClear
			// 
			this->ButtonClear->Location = System::Drawing::Point(12, 311);
			this->ButtonClear->Name = L"ButtonClear";
			this->ButtonClear->Size = System::Drawing::Size(134, 23);
			this->ButtonClear->TabIndex = 2;
			this->ButtonClear->Text = L"Clear All Filters";
			this->ButtonClear->UseVisualStyleBackColor = true;
			this->ButtonClear->Click += gcnew System::EventHandler(this, &filterButtons::ButtonClear_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(426, 107);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(79, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Sellect All";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &filterButtons::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(511, 107);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(82, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Clear All";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &filterButtons::button2_Click);
			// 
			// checkedListBox3
			// 
			this->checkedListBox3->CheckOnClick = true;
			this->checkedListBox3->Enabled = false;
			this->checkedListBox3->FormattingEnabled = true;
			this->checkedListBox3->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"UDP Mangement Protocols\t\t", L"DNS", L"SNMP",
					L"NBNS", L"LLMNR", L"SSDP", L"BOOTP"
			});
			this->checkedListBox3->Location = System::Drawing::Point(12, 233);
			this->checkedListBox3->MultiColumn = true;
			this->checkedListBox3->Name = L"checkedListBox3";
			this->checkedListBox3->Size = System::Drawing::Size(581, 72);
			this->checkedListBox3->TabIndex = 5;
			this->checkedListBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &filterButtons::checkedListBox3_SelectedIndexChanged);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(12, 107);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(74, 21);
			this->checkBox1->TabIndex = 6;
			this->checkBox1->Text = L"Enable";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &filterButtons::checkBox1_CheckedChanged);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(426, 311);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(165, 23);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Apply Filters";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &filterButtons::button3_Click);
			// 
			// filterButtons
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(603, 446);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->checkedListBox3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->ButtonClear);
			this->Controls->Add(this->checkedListBox1);
			this->Name = L"filterButtons";
			this->Text = L"filterButtons";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void checkedListBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
	{

	}

	private: System::Void checkedListBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		/*
		if (checkedListBox2->GetItemCheckState(0) == CheckState::Checked)
			for (int i = 0; i < checkedListBox1->Items->Count; i++)
				checkedListBox1->SetItemCheckState(i, CheckState::Indeterminate);*/
	}

		   //Отключить все галочки
	private: System::Void ButtonClear_Click(System::Object^ sender, System::EventArgs^ e) 
	{	
		for (int i = 0; i < checkedListBox1->Items->Count; i++)
			checkedListBox1->SetItemChecked(i, false);
		checkBox1->CheckState =CheckState::Unchecked;
	}

		   //Отключить галочки только на 1м боксе
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{		
		for (int i = 0; i < checkedListBox1->Items->Count; i++)
			checkedListBox1->SetItemCheckState(i, CheckState::Unchecked);
	}



		   //Ставит на всех фильтрах галочки
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	for (int i = 0; i < checkedListBox1->Items->Count; i++)
		checkedListBox1->SetItemCheckState(i, CheckState::Indeterminate);
}


private: System::Void checkedListBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	//
}


	   //Активация фильтров(если есть флаг enablded то активируем)
private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{

	checkedListBox1->Enabled = checkBox1->Checked;
	checkedListBox3->Enabled = checkBox1->Checked;
}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	//чекаются все галочки на фильтрах и соб в кол

}
};
}
