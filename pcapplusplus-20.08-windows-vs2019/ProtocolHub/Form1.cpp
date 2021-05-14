#include "Form1.h"

System::Void curseProject1::Form1::Drag_Drop(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e)
{
	msclr::interop::marshal_context context;
	for each (String ^ systemFilePath in (array<String^>^) e->Data->GetData(DataFormats::FileDrop))
	{
		if (systemFilePath->Contains(".pcap") || systemFilePath->Contains(".pcapng")) {
			this->systemFilePaths->Add(systemFilePath);
			outLabel->Text += systemFilePath + "\n";
		}
		else {
			//outLabel->Text += systemFilePath + " �� ��������������.\n";
		}
	}
	numberLabel->Text = "��������: " + systemFilePaths->Count;
	infoLabel->Text = "���������� ����� �� �����.";
    return System::Void();
}

System::Void curseProject1::Form1::Drag_Enter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e)
{   
	if (e->Data->GetDataPresent(DataFormats::FileDrop)) {
		e->Effect = DragDropEffects::Copy;
		infoLabel->Text = "��������� ����.";
	}
	else {
		infoLabel->Text = "������ ��� ��������������.";
	}
    return System::Void();
}

System::Void curseProject1::Form1::Drag_Leave(System::Object^ sender, System::EventArgs^ e)
{
	infoLabel->Text = "���������� ����� �� �����.";
    return System::Void();
}

System::Void curseProject1::Form1::�������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	OpenFileDialog^ openFileDiaolog = gcnew OpenFileDialog();
	openFileDiaolog->InitialDirectory = "c:\\";
	openFileDiaolog->Title = "�������� ����";
	openFileDiaolog->RestoreDirectory = true;

	if (openFileDiaolog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if (openFileDiaolog->FileName->Contains(".pcap") || openFileDiaolog->FileName->Contains(".pcapng")) {
			this->systemFilePaths->Add(openFileDiaolog->FileName);
			outLabel->Text += openFileDiaolog->FileName + "\n";
		}
		else {
			//outLabel->Text += openFileDiaolog->FileName + " �� ��������������.\n";
		}
		numberLabel->Text = "��������: " + systemFilePaths->Count;
	}

	return System::Void();
}

System::Void curseProject1::Form1::��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	systemFilePaths->Clear();
	numberLabel->Text = "��������: 0";
	outLabel->Text = "";
	return System::Void();
}

System::Void curseProject1::Form1::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("�����-�� ���������� � ���������.", "� ���������.");
	return System::Void();
}

System::Void curseProject1::Form1::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
	Form2^ form2 = gcnew Form2(systemFilePaths);
	form2->ShowDialog();
	this->Show();
	return System::Void();
}

System::Void curseProject1::Form1::�����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Environment::Exit(0);
	return System::Void();
}
