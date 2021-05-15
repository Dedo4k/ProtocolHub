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
			//outLabel->Text += systemFilePath + " не поддерживается.\n";
		}
	}
	numberLabel->Text = "Получено: " + systemFilePaths->Count;
	infoLabel->Text = "Перетащите файлы на форму.";
    return System::Void();
}

System::Void curseProject1::Form1::Drag_Enter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e)
{   
	if (e->Data->GetDataPresent(DataFormats::FileDrop)) {
		e->Effect = DragDropEffects::Copy;
		infoLabel->Text = "Отпустите мышь.";
	}
	else {
		infoLabel->Text = "Ошибка при перетаскивании.";
	}
    return System::Void();
}

System::Void curseProject1::Form1::Drag_Leave(System::Object^ sender, System::EventArgs^ e)
{
	infoLabel->Text = "Перетащите файлы на форму.";
    return System::Void();
}

System::Void curseProject1::Form1::открытьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	OpenFileDialog^ openFileDiaolog = gcnew OpenFileDialog();
	openFileDiaolog->InitialDirectory = "c:\\";
	openFileDiaolog->Title = "Выберите файл";
	openFileDiaolog->RestoreDirectory = true;

	if (openFileDiaolog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if (openFileDiaolog->FileName->Contains(".pcap") || openFileDiaolog->FileName->Contains(".pcapng")) {
			this->systemFilePaths->Add(openFileDiaolog->FileName);
			outLabel->Text += openFileDiaolog->FileName + "\n";
		}
		else {
			//outLabel->Text += openFileDiaolog->FileName + " не поддерживается.\n";
		}
		numberLabel->Text = "Получено: " + systemFilePaths->Count;
	}

	return System::Void();
}

System::Void curseProject1::Form1::очиститьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	systemFilePaths->Clear();
	numberLabel->Text = "Получено: 0";
	outLabel->Text = "";
	return System::Void();
}

System::Void curseProject1::Form1::оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Какая-то информация о программе.", "О программе.");
	return System::Void();
}

System::Void curseProject1::Form1::далееToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
	Form2^ form2 = gcnew Form2(systemFilePaths);
	form2->ShowDialog();
	this->Show();
	return System::Void();
}

System::Void curseProject1::Form1::закрытьПриложениеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Environment::Exit(0);
	return System::Void();
}
