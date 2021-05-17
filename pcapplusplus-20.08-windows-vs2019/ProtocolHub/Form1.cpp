#include "Form1.h"
#include "Form2.h"
#include <msclr/marshal_cppstd.h>

/*
Принимает пути передаваемых файлов
Проверяет расширение файлов
Формирует список из полученных путей
Изменяем outLabel - полученные файлы
Изменяет numberLabel - количество полученных файлов
Изменяет infoLabel
*/
System::Void curseProject1::Form1::Drag_Drop(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e)
{
	msclr::interop::marshal_context context;
	for each (String ^ systemFilePath in (array<String^>^) e->Data->GetData(DataFormats::FileDrop))				//проходим по всем переданным файлам
	{
		if (systemFilePath->Contains(".pcap") || systemFilePath->Contains(".pcapng")) {							//проверяем расширения
			this->systemFilePaths->Add(systemFilePath);															//добавляем в список
			outLabel->Text += systemFilePath + "\n";
		}
	}
	numberLabel->Text = "Получено: " + systemFilePaths->Count;
	infoLabel->Text = "Перетащите файлы на форму.";
    return System::Void();
}

/*
Изменяет infoLabel когда перетаскиваемый объект находится на форме
*/
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

/*
Изменяет infoLabel когда перетаскиваемый объект покидает пределы формы
*/
System::Void curseProject1::Form1::Drag_Leave(System::Object^ sender, System::EventArgs^ e)
{
	infoLabel->Text = "Перетащите файлы на форму.";
    return System::Void();
}

/*
Открывает проводник для выбора файла при нажатии на кнопку "Открыть" из панели меню
Изменяем outLabel - полученные файлы
Изменяет numberLabel - количество полученных файлов
*/
System::Void curseProject1::Form1::открытьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	OpenFileDialog^ openFileDiaolog = gcnew OpenFileDialog();													//открывает проводник по пути С:
	openFileDiaolog->InitialDirectory = "c:\\";
	openFileDiaolog->Title = "Выберите файл";
	openFileDiaolog->RestoreDirectory = true;
	if (openFileDiaolog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if (openFileDiaolog->FileName->Contains(".pcap") || openFileDiaolog->FileName->Contains(".pcapng")) {	//проверяет выбранный файл
			this->systemFilePaths->Add(openFileDiaolog->FileName);												//добавляем в список
			outLabel->Text += openFileDiaolog->FileName + "\n";
		}
		numberLabel->Text = "Получено: " + systemFilePaths->Count;
	}
	return System::Void();
}


/*
Очищает список полученных путей при нажатии на кнопку "Очистить" из панели меню
Изменяем outLabel
Изменяем numberLabel
*/
System::Void curseProject1::Form1::очиститьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	systemFilePaths->Clear();
	outLabel->Text = "";
	numberLabel->Text = "Получено: 0";
	return System::Void();
}

/*
Открывает окно с информацией о программе при нажатии на кнопку "О программе" из панели меню
*/
System::Void curseProject1::Form1::оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Какая-то информация о программе.", "О программе.");
	return System::Void();
}

/*
Открывает окно для работы с пакетами при нажатии на кнопку "Далее" из панели меню
*/
System::Void curseProject1::Form1::далееToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
	Form2^ form2 = gcnew Form2(systemFilePaths);
	form2->ShowDialog();
	this->Show();
	return System::Void();
}

/*
Закрывает приложение при нажатии на кнопку "Закрыть приложение" из панели меню
*/
System::Void curseProject1::Form1::закрытьПриложениеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Environment::Exit(0);
	return System::Void();
}
