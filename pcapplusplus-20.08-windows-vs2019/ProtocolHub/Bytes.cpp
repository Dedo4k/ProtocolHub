#include "Bytes.h"
#include <iostream>
#include "PacketHelper.h"
#include "SessionHelper.h"
#include "Service.h"
#include "ConvertFunc.h"
#include "findFunc.h"

std::vector<PacketHelper> packets2;                                                                         //вектор пакетов
std::vector<SessionHelper> sessions2;                                                                       //вектор сессий

int counter1 = 0;                                                                                           //номер сессии для "richTextBox1"
int counter2 = 1;                                                                                           //номер сессии для "richTextBox2"
int counter3 = 2;                                                                                           //номер сессии для "richTextBox3"
int counter4 = 3;                                                                                           //номер сессии для "richTextBox4"

int box = 0;                                                                                                //номер "richTextBox", который был изменён

/*
Вывод информации в "richTextBox" в зависимости от того, какие номера сессий были выставлены для каждого
*/
void curseProject1::Bytes::startDrawingBytes(System::Collections::ArrayList^ systemFilePaths)
{
    if (sessions2.empty())                                                                                  //если вектор сессий пуст, то формируем его 
    {
        std::vector<std::string> stringFilePaths = Service::convertToString(systemFilePaths);
        packets2 = Service::getAllPackets(stringFilePaths);
        bool flag = true;
        while (flag && sessions2.size() < 40)
        {
            SessionHelper session(packets2);
            if (session.isSession())
                sessions2.push_back(session);
            else
                flag = false;
        }
    }

    String^ str;
    std::vector<SessionHelper> sessions;
    int f1 = 0, f2 = 0, f3 = 0, f4 = 0;
    for (size_t i = 0; i < sessions2.size()&&i<4; i++)                                                      //формируем вектор сессий для вывода в "richTextBox"
    {                                                                                                       //выставляем флаги для вывода сессий в "richTextBox"
        switch (i)
        {
        case 0: sessions.push_back(sessions2[counter1]); f1 = 1; break;
        case 1: sessions.push_back(sessions2[counter2]); f2 = 2; break;
        case 2: sessions.push_back(sessions2[counter3]); f3 = 3; break;
        case 3: sessions.push_back(sessions2[counter4]); f4 = 4; break;
        }
    }
    switch (box)                                                                                            //изменяем "richTextBox" в зависимости от того, какой был изменён
    {
    case 0:                                                                                                 //первоначальная инициализация
    {
        if (f1)                                                                                             //проверка существования
        {
            for (size_t i = 0; i < sessions[0].getBytes().size(); i++)
            {
                str += Convert_string_to_String(charToAscii(sessions[0].getBytes()[i])) + " ";
            }
            richTextBox1->Text = str;
            label2->Text = "Номер: " + counter1 + "\n" + Convert_string_to_String(sessions[0].getSrcIp().toString()) + ":" + sessions[0].getSrcPort() + "->" + Convert_string_to_String(sessions[0].getDstIp().toString()) + ":" + sessions[0].getDstPort();
        }
        if (f2)                                                                                             //проверка существования
        {
            str = "";
            for (size_t i = 0; i < sessions[1].getBytes().size(); i++)
            {
                str += Convert_string_to_String(charToAscii(sessions[1].getBytes()[i])) + " ";
            }
            richTextBox2->Text = str;
            label3->Text = "Номер: " + counter2 + "\n" + Convert_string_to_String(sessions[1].getSrcIp().toString()) + ":" + sessions[1].getSrcPort() + "->" + Convert_string_to_String(sessions[1].getDstIp().toString()) + ":" + sessions[1].getDstPort();
        }
        if (f3)                                                                                             //проверка существования
        {
            str = "";
            for (size_t i = 0; i < sessions[2].getBytes().size(); i++)
            {
                str += Convert_string_to_String(charToAscii(sessions[2].getBytes()[i])) + " ";
            }
            richTextBox3->Text = str;
            label4->Text = "Номер: " + counter3 + "\n" + Convert_string_to_String(sessions[2].getSrcIp().toString()) + ":" + sessions[2].getSrcPort() + "->" + Convert_string_to_String(sessions[2].getDstIp().toString()) + ":" + sessions[2].getDstPort();
        }
        if (f4)                                                                                             //проверка существования
        {
            str = "";
            for (size_t i = 0; i < sessions[3].getBytes().size(); i++)
            {
                str += Convert_string_to_String(charToAscii(sessions[3].getBytes()[i])) + " ";
            }
            richTextBox4->Text = str;
            label5->Text = "Номер: " + counter4 + "\n" + Convert_string_to_String(sessions[3].getSrcIp().toString()) + ":" + sessions[3].getSrcPort() + "->" + Convert_string_to_String(sessions[3].getDstIp().toString()) + ":" + sessions[3].getDstPort();
        }
        break;
    }
    case 1:                                                                                                 //если был изменён "richTextBox1"
    {
        if (f1)                                                                                             //проверка существования
        {
            str = "";
            for (size_t i = 0; i < sessions[0].getBytes().size(); i++)
            {
                str += Convert_string_to_String(charToAscii(sessions[0].getBytes()[i])) + " ";
            }
            richTextBox1->Text = str;
            label2->Text = "Номер: " + counter1 + "\n" + Convert_string_to_String(sessions[0].getSrcIp().toString()) + ":" + sessions[0].getSrcPort() + "->" + Convert_string_to_String(sessions[0].getDstIp().toString()) + ":" + sessions[0].getDstPort();
        }
        break;
    }
    case 2:                                                                                                 //если был изменён "richTextBox2"
    {
        if (f2)                                                                                             //первоначальная инициализация
        {
            str = "";
            for (size_t i = 0; i < sessions[1].getBytes().size(); i++)
            {
                str += Convert_string_to_String(charToAscii(sessions[1].getBytes()[i])) + " ";
            }
            richTextBox2->Text = str;
            label3->Text = "Номер: " + counter2 + "\n" + Convert_string_to_String(sessions[1].getSrcIp().toString()) + ":" + sessions[1].getSrcPort() + "->" + Convert_string_to_String(sessions[1].getDstIp().toString()) + ":" + sessions[1].getDstPort();
        }
        break;
    }
    case 3:                                                                                                 //если был изменён "richTextBox3"
    {
        if (f3)                                                                                             //первоначальная инициализация
        {
            str = "";
            for (size_t i = 0; i < sessions[2].getBytes().size(); i++)
            {
                str += Convert_string_to_String(charToAscii(sessions[2].getBytes()[i])) + " ";
            }
            richTextBox3->Text = str;
            label4->Text = "Номер: " + counter3 + "\n" + Convert_string_to_String(sessions[2].getSrcIp().toString()) + ":" + sessions[2].getSrcPort() + "->" + Convert_string_to_String(sessions[2].getDstIp().toString()) + ":" + sessions[2].getDstPort();
        }
        break;
    }
    case 4:                                                                                                 //если был изменён "richTextBox4"
    {
        if (f4)                                                                                             //первоначальная инициализация
        {
            str = "";
            for (size_t i = 0; i < sessions[3].getBytes().size(); i++)
            {
                str += Convert_string_to_String(charToAscii(sessions[3].getBytes()[i])) + " ";
            }
            richTextBox4->Text = str;
            label5->Text = "Номер: " + counter4 + "\n" + Convert_string_to_String(sessions[3].getSrcIp().toString()) + ":" + sessions[3].getSrcPort() + "->" + Convert_string_to_String(sessions[3].getDstIp().toString()) + ":" + sessions[3].getDstPort();
        }
        break;
    }
    default:
        break;
    }
}

/*
Закрывает текущее окно при нажатии на кнопку "Назад" из панели меню
*/
System::Void curseProject1::Bytes::назадToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    packets2.clear();
    sessions2.clear();
    box = 0;
    counter1 = 0;
    counter2 = 1;
    counter3 = 2;
    counter4 = 3;
    this->Close();
    this->DialogResult = System::Windows::Forms::DialogResult::OK;
    return System::Void();
}

/*
Закрывает приложение при нажатии на кнопку "Закрыть приложение" из панели меню
*/
System::Void curseProject1::Bytes::закрытьПриложениеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Environment::Exit(0);
    return System::Void();
}

/*
Увеличивает номер сессии для "richTextBox1" при нажатии на кнопку "button1"
Вызывает метод "startDrawingBytes"
*/
System::Void curseProject1::Bytes::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 1;
    counter1++;
    if (counter1 == sessions2.size() || counter1 == 40)
        counter1 = 0;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

/*
Умегьшает номер сессии для "richTextBox1" при нажатии на кнопку "button2"
Вызывает метод "startDrawingBytes"
*/
System::Void curseProject1::Bytes::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 1;
    counter1--;
    if (counter1 == sessions2.size() || counter1 == -1)
        counter1 = sessions2.size()-1;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

/*
Умегьшает номер сессии для "richTextBox2" при нажатии на кнопку "button3"
Вызывает метод "startDrawingBytes"
*/
System::Void curseProject1::Bytes::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 2;
    counter2--;
    if (counter2 == sessions2.size() || counter2 == -1)
        counter2 = sessions2.size()-1;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

/*
Увеличивает номер сессии для "richTextBox2" при нажатии на кнопку "button4"
Вызывает метод "startDrawingBytes"
*/
System::Void curseProject1::Bytes::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 2;
    counter2++;
    if (counter2 == sessions2.size() || counter2 == 40)
        counter2 = 0;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

/*
Умегьшает номер сессии для "richTextBox3" при нажатии на кнопку "button5"
Вызывает метод "startDrawingBytes"
*/
System::Void curseProject1::Bytes::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 3;
    counter3--;
    if (counter3 == sessions2.size() || counter3 == -1)
        counter3 = sessions2.size()-1;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

/*
Увеличивает номер сессии для "richTextBox3" при нажатии на кнопку "button6"
Вызывает метод "startDrawingBytes"
*/
System::Void curseProject1::Bytes::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 3;
    counter3++;
    if (counter3 == sessions2.size() || counter3 == 40)
        counter3 = 0;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

/*
Умегьшает номер сессии для "richTextBox4" при нажатии на кнопку "button7"
Вызывает метод "startDrawingBytes"
*/
System::Void curseProject1::Bytes::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 4;
    counter4--;
    if (counter4 == sessions2.size() || counter4 == -1)
        counter4 = sessions2.size()-1;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

/*
Увеличивает номер сессии для "richTextBox4" при нажатии на кнопку "button8"
Вызывает метод "startDrawingBytes"
*/
System::Void curseProject1::Bytes::button8_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 4;
    counter4++;
    if (counter4 == sessions2.size() || counter4 == 40)
        counter4 = 0;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

/*
Выполняет поиск строки в векторе сессий в соответствии с тем, какой поиск был выбран
*/
System::Void curseProject1::Bytes::button9_Click(System::Object^ sender, System::EventArgs^ e)
{
    std::string str;
    Convert_String_to_string(textBox1->Text,str);
    std::vector<SessionHelper> sessions;
    int i = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0;
    for (size_t i = 0; i < sessions2.size()&&i<4; i++)                                                              //формируем вектор сессий для сортировок
    {                                                                                                               //выставляем флаги для сортировки сессий
        switch (i)
        {
        case 0: sessions.push_back(sessions2[counter1]); f1 = 1; break;
        case 1: sessions.push_back(sessions2[counter2]); f2 = 1; break;
        case 2: sessions.push_back(sessions2[counter3]); f3 = 1; break;
        case 3: sessions.push_back(sessions2[counter4]); f4 = 1; break;
        }
    }
    if (radioButton1->Checked)                                                                                      //если был выбран поиск по одной позиции 
    {
        int txtStart = 0, txtEnd = 0;
        int fl = 0, start = findSubstringAt(sessions, str), length = str.length(),                                  //start - позиция первого совпадения
            fl1 = 0, fl0 = 0;
        if (start == -1)                                                                                            //проверка, было ли совпадение
            fl1 = 1;
        if (length == 0)                                                                                            //проверка длины искомого слова
            fl0 = 1;
        String^ temp = richTextBox1->Text;
        for (size_t i = 0; i < temp->Length; i++)                                                                   //поиск начала и конца искомого слова в "richTextBox"
        {
            if (fl1 == 1 || fl0 == 1)
                break;
            if (length == 0) {
                txtEnd = i;
                break;
            }
            if (!fl && start == 0) {
                txtStart = i;
                fl = 1;
            }
            if (!fl && temp[i].Equals(' '))
                start--;
            if (fl) {
                if (temp[i].Equals(' '))
                    length--;
            }
        }

        if (f1)                                                                                                     //проверка существования
        {
            richTextBox1->SelectionBackColor = System::Drawing::Color::White;
            richTextBox1->SelectionStart = txtStart;
            richTextBox1->ScrollToCaret();
            richTextBox1->SelectionLength = txtEnd - txtStart;
            richTextBox1->SelectionBackColor = System::Drawing::Color::Blue;
        }
        if (f2)                                                                                                     //проверка существования
        {
            richTextBox2->SelectionBackColor = System::Drawing::Color::White;
            richTextBox2->SelectionStart = txtStart;
            richTextBox2->ScrollToCaret();
            richTextBox2->SelectionLength = txtEnd - txtStart;
            richTextBox2->SelectionBackColor = System::Drawing::Color::Blue;
        }
        if (f3)                                                                                                     //проверка существования
        {
            richTextBox3->SelectionBackColor = System::Drawing::Color::White;
            richTextBox3->SelectionStart = txtStart;
            richTextBox3->ScrollToCaret();
            richTextBox3->SelectionLength = txtEnd - txtStart;
            richTextBox3->SelectionBackColor = System::Drawing::Color::Blue;
        }
        if (f4)                                                                                                     //проверка существования
        {
            richTextBox4->SelectionBackColor = System::Drawing::Color::White;
            richTextBox4->SelectionStart = txtStart;
            richTextBox4->ScrollToCaret();
            richTextBox4->SelectionLength = txtEnd - txtStart;
            richTextBox4->SelectionBackColor = System::Drawing::Color::Blue;
        }
    }
    else if (radioButton2->Checked)                                                                                 //если был выбран поиск по разным позициям
    {
        std::vector<size_t> startPoints = findSubstring(sessions, str);                                             //вектор с первыми совпадениям в каждой сессии
        int f1 = 0, f2 = 0, f3 = 0, f4 = 0;
        for (size_t i = 0; i < startPoints.size(); i++)                                                             //выставляем флаги для существующих
        {
            switch (i)
            {
            case 0: f1 = 1; break;
            case 1: f2 = 2; break;
            case 2: f3 = 3; break;
            case 3: f4 = 4; break;
            }
        }

        int txtStart1 = 0, txtEnd1 = 0,
            txtStart2 = 0, txtEnd2 = 0,
            txtStart3 = 0, txtEnd3 = 0,
            txtStart4 = 0, txtEnd4 = 0,
            fl = 0, fl0 = 0, fl1 = 0, fl2 = 0, fl3 = 0, fl4 = 0;
        String^ temp; int start; int length;
        if (f1)                                                                                                     //проверка существования
        {
            start = startPoints[0], length = str.length();                                                          //поиск начала и конца искомого слова в "richTextBox1"

            if (start == -1)
                fl1 = 1;
            if (length == 0)
                fl0 = 1;
            temp = richTextBox1->Text;
            for (size_t i = 0; i < temp->Length; i++)
            {
                if (fl1 == 1 || fl0 == 1)
                    break;
                if (length == 0) {
                    txtEnd1 = i;
                    break;
                }
                if (!fl && start == 0) {
                    txtStart1 = i;
                    fl = 1;
                }
                if (!fl && temp[i].Equals(' '))
                    start--;
                if (fl) {
                    if (temp[i].Equals(' '))
                        length--;
                }
            }
        }
        if (f2)                                                                                                     //поиск начала и конца искомого слова в "richTextBox2"
        {
            start = startPoints[1]; length = str.length();
            fl = 0;
            if (start == -1)
                fl2 = 1;
            temp = richTextBox2->Text;
            for (size_t i = 0; i < temp->Length; i++)
            {
                if (fl2 == 1 || fl0 == 1)
                    break;
                if (length == 0) {
                    txtEnd2 = i;
                    break;
                }
                if (!fl && start == 0) {
                    txtStart2 = i;
                    fl = 1;
                }
                if (!fl && temp[i].Equals(' '))
                    start--;
                if (fl) {
                    if (temp[i].Equals(' '))
                        length--;
                }
            }
        }
        if (f3)                                                                                                     //поиск начала и конца искомого слова в "richTextBox3"
        {
            start = startPoints[2]; length = str.length();
            fl = 0;
            if (start == -1)
                fl3 = 1;
            temp = richTextBox3->Text;
            for (size_t i = 0; i < temp->Length; i++)
            {
                if (fl3 == 1 || fl0 == 1)
                    break;
                if (length == 0) {
                    txtEnd3 = i;
                    break;
                }
                if (!fl && start == 0) {
                    txtStart3 = i;
                    fl = 1;
                }
                if (!fl && temp[i].Equals(' '))
                    start--;
                if (fl) {
                    if (temp[i].Equals(' '))
                        length--;
                }
            }
        }
        if (f4)                                                                                                     //поиск начала и конца искомого слова в "richTextBox4"
        {
            start = startPoints[3]; length = str.length();
            fl = 0;
            if (start == -1)
                fl4 = 1;
            temp = richTextBox4->Text;
            for (size_t i = 0; i < temp->Length; i++)
            {
                if (fl4 == 1 || fl0 == 1)
                    break;
                if (length == 0) {
                    txtEnd4 = i;
                    break;
                }
                if (!fl && start == 0) {
                    txtStart4 = i;
                    fl = 1;
                }
                if (!fl && temp[i].Equals(' '))
                    start--;
                if (fl) {
                    if (temp[i].Equals(' '))
                        length--;
                }
            }
        }
        
        if (f1)                                                                                                     //проверка существования
        {
            richTextBox1->SelectionBackColor = System::Drawing::Color::White;
            richTextBox1->SelectionStart = txtStart1;
            richTextBox1->ScrollToCaret();
            richTextBox1->SelectionLength = txtEnd1 - txtStart1;
            richTextBox1->SelectionBackColor = System::Drawing::Color::Blue;
        }
        if (f2)                                                                                                     //проверка существования
        {
            richTextBox2->SelectionBackColor = System::Drawing::Color::White;
            richTextBox2->SelectionStart = txtStart2;
            richTextBox2->ScrollToCaret();
            richTextBox2->SelectionLength = txtEnd2 - txtStart2;
            richTextBox2->SelectionBackColor = System::Drawing::Color::Blue;
        }
        if (f3)                                                                                                     //проверка существования
        {
            richTextBox3->SelectionBackColor = System::Drawing::Color::White;
            richTextBox3->SelectionStart = txtStart3;
            richTextBox3->ScrollToCaret();
            richTextBox3->SelectionLength = txtEnd3 - txtStart3;
            richTextBox3->SelectionBackColor = System::Drawing::Color::Blue;
        }
        if (f4)                                                                                                     //проверка существования
        {
            richTextBox4->SelectionBackColor = System::Drawing::Color::White;
            richTextBox4->SelectionStart = txtStart4;
            richTextBox4->ScrollToCaret();
            richTextBox4->SelectionLength = txtEnd4 - txtStart4;
            richTextBox4->SelectionBackColor = System::Drawing::Color::Blue;
        }
    }
    return System::Void();
}
