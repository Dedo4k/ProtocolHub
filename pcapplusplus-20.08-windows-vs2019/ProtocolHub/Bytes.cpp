#include "Bytes.h"
#include <iostream>
#include "PacketHelper.h"
#include "SessionHelper.h"
#include "Service.h"
#include "ConvertFunc.h"
#include "findFunc.h"
#include "DataClass.h"

//std::vector<PacketHelper> packets2;                                                                         //вектор пакетов
//std::vector<SessionHelper> sessions2;                                                                       //вектор сессий
std::vector<SessionHelper> sessions;
int l1 = 0, l2 = 0, l3 = 0, l4 = 0, l5 = 0, l6 = 0, l7 = 0, l8 = 0;
//int counter1 = 0;                                                                                           //номер сессии для "richTextBox1"
//int counter2 = 1;                                                                                           //номер сессии для "richTextBox2"
//int counter3 = 2;                                                                                           //номер сессии для "richTextBox3"
//int counter4 = 3;                                                                                           //номер сессии для "richTextBox4"
//
//int box = 0;                                                                                                //номер "richTextBox", который был изменён

/*
Вывод информации в "richTextBox" в зависимости от того, какие номера сессий были выставлены для каждого
*/
void curseProject1::Bytes::startDrawingBytes(System::Collections::ArrayList^ systemFilePaths)
{
    //if (sessBytes.empty())                                                                                  //если вектор сессий пуст, то формируем его 
    //{
    //    std::vector<std::string> stringFilePaths = Service::convertToString(systemFilePaths);
    //    if(pack.empty())
    //        pack = Service::getAllPackets(stringFilePaths);
    //    bool flag = true;
    //    while (flag && sessBytes.size() < 40)
    //    {
    //        SessionHelper session(pack);
    //        if (session.isSession())
    //            sessBytes.push_back(session);
    //        else
    //            flag = false;
    //    }
    //}
    sessions.clear();
    String^ str;
    int f1 = 0, f2 = 0, f3 = 0, f4 = 0;
    for (size_t i = 0; i < sessBytes.size()&&i<4; i++)                                                      //формируем вектор сессий для вывода в "richTextBox"
    {                                                                                                       //выставляем флаги для вывода сессий в "richTextBox"
        switch (i)
        {
        case 0: sessions.push_back(sessBytes[counter1]); f1 = 1; break;
        case 1: sessions.push_back(sessBytes[counter2]); f2 = 2; break;
        case 2: sessions.push_back(sessBytes[counter3]); f3 = 3; break;
        case 3: sessions.push_back(sessBytes[counter4]); f4 = 4; break;
        }
    }
    switch (box)                                                                                            //изменяем "richTextBox" в зависимости от того, какой был изменён
    {
    case 0:                                                                                                 //первоначальная инициализация
    {
        if (f1)                                                                                             //проверка существования
        {
            for (size_t i = 0; i < sessions[0].getBytes()[0].length(); i++)
            {
                str += Convert_string_to_String(charToAscii(sessions[0].getBytes()[0][i])) + " ";
            }
            richTextBox1->Text = str;
            comboBox1->Items->Clear();
            for (size_t i = 0; i < sessBytes.size(); i++)
            {
                comboBox1->Items->Add(sessBytes[i].getNum());
            }
            l1 = 1;
            comboBox1->Text = sessBytes[counter1].getNum().ToString();
            l1 = 0;
            for (size_t i = 0; i < sessions[0].getPackets().size(); i++)
            {
                comboBox2->Items->Add(i);
            }
            l2 = 1;
            comboBox2->Text = packetCounter1.ToString();
            l2 = 0;
            label2->Text = "Номер сессии: ";
            label8->Text = "Номер пакета: ";
            label9->Text = Convert_string_to_String(sessions[0].getSrcIp().toString()) + ":" + sessions[0].getSrcPort() + "->" + Convert_string_to_String(sessions[0].getDstIp().toString()) + ":" + sessions[0].getDstPort();
        }
        if (f2)                                                                                             //проверка существования
        {
            str = "";
            for (size_t i = 0; i < sessions[1].getBytes()[0].length(); i++)
            {
                str += Convert_string_to_String(charToAscii(sessions[1].getBytes()[0][i])) + " ";
            }
            richTextBox2->Text = str;
            comboBox4->Items->Clear();
            for (size_t i = 0; i < sessBytes.size(); i++)
            {
                comboBox4->Items->Add(sessBytes[i].getNum());
            }
            l4 = 1;
            comboBox4->Text = sessBytes[counter2].getNum().ToString();
            l4 = 0;
            for (size_t i = 0; i < sessions[1].getPackets().size(); i++)
            {
                comboBox3->Items->Add(i);
            }
            l3 = 1;
            comboBox3->Text = packetCounter2.ToString();
            l3 = 0;
            label3->Text = "Номер сессии: ";
            label7->Text = "Номер пакета: ";
            label10->Text = Convert_string_to_String(sessions[1].getSrcIp().toString()) + ":" + sessions[1].getSrcPort() + "->" + Convert_string_to_String(sessions[1].getDstIp().toString()) + ":" + sessions[1].getDstPort();
        }
        if (f3)                                                                                             //проверка существования
        {
            str = "";
            for (size_t i = 0; i < sessions[2].getBytes()[0].length(); i++)
            {
                str += Convert_string_to_String(charToAscii(sessions[2].getBytes()[0][i])) + " ";
            }
            richTextBox3->Text = str;
            comboBox6->Items->Clear();
            for (size_t i = 0; i < sessBytes.size(); i++)
            {
                comboBox6->Items->Add(sessBytes[i].getNum());
            }
            l6 = 1;
            comboBox6->Text = sessBytes[counter3].getNum().ToString();
            l6 = 0;
            for (size_t i = 0; i < sessions[2].getPackets().size(); i++)
            {
                comboBox5->Items->Add(i);
            }
            l5 = 1;
            comboBox5->Text = packetCounter3.ToString();
            l5 = 0;
            label4->Text = "Номер сессии: ";
            label6->Text = "Номер пакета: ";
            label11->Text = Convert_string_to_String(sessions[2].getSrcIp().toString()) + ":" + sessions[2].getSrcPort() + "->" + Convert_string_to_String(sessions[2].getDstIp().toString()) + ":" + sessions[2].getDstPort();
        }
        if (f4)                                                                                             //проверка существования
        {
            str = "";
            for (size_t i = 0; i < sessions[3].getBytes()[0].length(); i++)
            {
                str += Convert_string_to_String(charToAscii(sessions[3].getBytes()[0][i])) + " ";
            }
            richTextBox4->Text = str;
            comboBox8->Items->Clear();
            for (size_t i = 0; i < sessBytes.size(); i++)
            {
                comboBox8->Items->Add(sessBytes[i].getNum());
            }
            l8 = 1;
            comboBox8->Text = sessBytes[counter4].getNum().ToString();
            l8 = 0;
            for (size_t i = 0; i < sessions[3].getPackets().size(); i++)
            {
                comboBox7->Items->Add(i);
            }
            l7 = 1;
            comboBox7->Text = packetCounter4.ToString();
            l7 = 0;
            label5->Text = "Номер сессии: ";
            label1->Text = "Номер пакета: ";
            label12->Text = Convert_string_to_String(sessions[3].getSrcIp().toString()) + ":" + sessions[3].getSrcPort() + "->" + Convert_string_to_String(sessions[3].getDstIp().toString()) + ":" + sessions[3].getDstPort();
        }
        break;
    }
    case 1:                                                                                                 //если был изменён "richTextBox1"
    {
        if (f1)                                                                                             //проверка существования
        {
            str = "";
            for (size_t i = 0; i < sessions[0].getBytes()[packetCounter1].length(); i++)
            {
                str += Convert_string_to_String(charToAscii(sessions[0].getBytes()[packetCounter1][i])) + " ";
            }
            richTextBox1->Text = str;
            comboBox2->Items->Clear();
            for (size_t i = 0; i < sessions[0].getPackets().size(); i++)
            {
                comboBox2->Items->Add(i);
            }
            l1 = 1;
            comboBox1->Text = sessBytes[counter1].getNum().ToString();
            l1 = 0;
            l2 = 1;
            comboBox2->Text = packetCounter1.ToString();
            l2 = 0;
            label9->Text = Convert_string_to_String(sessions[0].getSrcIp().toString()) + ":" + sessions[0].getSrcPort() + "->" + Convert_string_to_String(sessions[0].getDstIp().toString()) + ":" + sessions[0].getDstPort();
        }
        break;
    }
    case 2:                                                                                                 //если был изменён "richTextBox2"
    {
        if (f2)                                                                                             //первоначальная инициализация
        {
            str = "";
            for (size_t i = 0; i < sessions[1].getBytes()[packetCounter2].length(); i++)
            {
                str += Convert_string_to_String(charToAscii(sessions[1].getBytes()[packetCounter2][i])) + " ";
            }
            richTextBox2->Text = str;
            comboBox3->Items->Clear();
            for (size_t i = 0; i < sessions[1].getPackets().size(); i++)
            {
                comboBox3->Items->Add(i);
            }
            l4 = 1;
            comboBox4->Text = sessBytes[counter2].getNum().ToString();
            l4 = 0;
            l3 = 1;
            comboBox3->Text = packetCounter2.ToString();
            l3 = 0;
            label10->Text = Convert_string_to_String(sessions[1].getSrcIp().toString()) + ":" + sessions[1].getSrcPort() + "->" + Convert_string_to_String(sessions[1].getDstIp().toString()) + ":" + sessions[1].getDstPort();
        }
        break;
    }
    case 3:                                                                                                 //если был изменён "richTextBox3"
    {
        if (f3)                                                                                             //первоначальная инициализация
        {
            str = "";
            for (size_t i = 0; i < sessions[2].getBytes()[packetCounter3].length(); i++)
            {
                str += Convert_string_to_String(charToAscii(sessions[2].getBytes()[packetCounter3][i])) + " ";
            }
            richTextBox3->Text = str;
            comboBox5->Items->Clear();
            for (size_t i = 0; i < sessions[2].getPackets().size(); i++)
            {
                comboBox5->Items->Add(i);
            }
            l6 = 1;
            comboBox6->Text = sessBytes[counter3].getNum().ToString();
            l6 = 0;
            l5 = 1;
            comboBox5->Text = packetCounter3.ToString();
            l5 = 0;
            label11->Text = Convert_string_to_String(sessions[2].getSrcIp().toString()) + ":" + sessions[2].getSrcPort() + "->" + Convert_string_to_String(sessions[2].getDstIp().toString()) + ":" + sessions[2].getDstPort();
        }
        break;
    }
    case 4:                                                                                                 //если был изменён "richTextBox4"
    {
        if (f4)                                                                                             //первоначальная инициализация
        {
            str = "";
            for (size_t i = 0; i < sessions[3].getBytes()[packetCounter4].length(); i++)
            {
                str += Convert_string_to_String(charToAscii(sessions[3].getBytes()[packetCounter4][i])) + " ";
            }
            richTextBox4->Text = str;
            comboBox7->Items->Clear();
            for (size_t i = 0; i < sessions[3].getPackets().size(); i++)
            {
                comboBox7->Items->Add(i);
            }
            l8 = 1;
            comboBox8->Text = sessBytes[counter4].getNum().ToString();
            l8 = 0;
            l7 = 1;
            comboBox7->Text = packetCounter4.ToString();
            l7 = 0;
            label12->Text = Convert_string_to_String(sessions[3].getSrcIp().toString()) + ":" + sessions[3].getSrcPort() + "->" + Convert_string_to_String(sessions[3].getDstIp().toString()) + ":" + sessions[3].getDstPort();
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
    //packets2.clear();
    //sessions2.clear();
    box = 0;
    //counter1 = 0;
    //counter2 = 1;
    //counter3 = 2;
    //counter4 = 3;
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
    packetCounter1 = 0;
    if (counter1 == sessBytes.size())
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
    packetCounter1 = 0;
    if (counter1 == sessBytes.size() || counter1 == -1)
        counter1 = sessBytes.size()-1;
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
    packetCounter2 = 0;
    if (counter2 == sessBytes.size() || counter2 == -1)
        counter2 = sessBytes.size()-1;
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
    packetCounter2 = 0;
    if (counter2 == sessBytes.size())
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
    packetCounter3 = 0;
    if (counter3 == sessBytes.size() || counter3 == -1)
        counter3 = sessBytes.size()-1;
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
    packetCounter3 = 0;
    if (counter3 == sessBytes.size())
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
    packetCounter4 = 0;
    if (counter4 == sessBytes.size() || counter4 == -1)
        counter4 = sessBytes.size()-1;
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
    packetCounter4 = 0;
    if (counter4 == sessBytes.size())
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
    std::vector<std::string> sessions;
    int i = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0;
    for (size_t i = 0; i < sessBytes.size()&&i<4; i++)                                                              //формируем вектор сессий для сортировок
    {                                                                                                               //выставляем флаги для сортировки сессий
        switch (i)
        {
        case 0: sessions.push_back(sessBytes[counter1].getBytes()[packetCounter1]); f1 = 1; break;
        case 1: sessions.push_back(sessBytes[counter2].getBytes()[packetCounter2]); f2 = 1; break;
        case 2: sessions.push_back(sessBytes[counter3].getBytes()[packetCounter3]); f3 = 1; break;
        case 3: sessions.push_back(sessBytes[counter4].getBytes()[packetCounter4]); f4 = 1; break;
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
            richTextBox1->SelectionBackColor = SystemColors::Control;
            richTextBox1->SelectionStart = txtStart;
            richTextBox1->ScrollToCaret();
            richTextBox1->SelectionLength = txtEnd - txtStart;
            richTextBox1->SelectionBackColor = System::Drawing::Color::Blue;
        }
        if (f2)                                                                                                     //проверка существования
        {
            richTextBox2->SelectionBackColor = SystemColors::Control;
            richTextBox2->SelectionStart = txtStart;
            richTextBox2->ScrollToCaret();
            richTextBox2->SelectionLength = txtEnd - txtStart;
            richTextBox2->SelectionBackColor = System::Drawing::Color::Blue;
        }
        if (f3)                                                                                                     //проверка существования
        {
            richTextBox3->SelectionBackColor = SystemColors::Control;
            richTextBox3->SelectionStart = txtStart;
            richTextBox3->ScrollToCaret();
            richTextBox3->SelectionLength = txtEnd - txtStart;
            richTextBox3->SelectionBackColor = System::Drawing::Color::Blue;
        }
        if (f4)                                                                                                     //проверка существования
        {
            richTextBox4->SelectionBackColor = SystemColors::Control;
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
            richTextBox1->SelectionBackColor = SystemColors::Control;
            richTextBox1->SelectionStart = txtStart1;
            richTextBox1->ScrollToCaret();
            richTextBox1->SelectionLength = txtEnd1 - txtStart1;
            richTextBox1->SelectionBackColor = System::Drawing::Color::Blue;
        }
        if (f2)                                                                                                     //проверка существования
        {
            richTextBox2->SelectionBackColor = SystemColors::Control;
            richTextBox2->SelectionStart = txtStart2;
            richTextBox2->ScrollToCaret();
            richTextBox2->SelectionLength = txtEnd2 - txtStart2;
            richTextBox2->SelectionBackColor = System::Drawing::Color::Blue;
        }
        if (f3)                                                                                                     //проверка существования
        {
            richTextBox3->SelectionBackColor = SystemColors::Control;
            richTextBox3->SelectionStart = txtStart3;
            richTextBox3->ScrollToCaret();
            richTextBox3->SelectionLength = txtEnd3 - txtStart3;
            richTextBox3->SelectionBackColor = System::Drawing::Color::Blue;
        }
        if (f4)                                                                                                     //проверка существования
        {
            richTextBox4->SelectionBackColor = SystemColors::Control;
            richTextBox4->SelectionStart = txtStart4;
            richTextBox4->ScrollToCaret();
            richTextBox4->SelectionLength = txtEnd4 - txtStart4;
            richTextBox4->SelectionBackColor = System::Drawing::Color::Blue;
        }
    }
    return System::Void();
}

System::Void curseProject1::Bytes::button16_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 1;
    packetCounter1--;
    if(sessions.size()>=1)
    if (packetCounter1 == sessions[0].getPackets().size() || packetCounter1 == -1)
        packetCounter1 = sessions[0].getPackets().size() - 1;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Bytes::button17_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 1;
    packetCounter1++;
    if(sessions.size()>=1)
    if (packetCounter1 == sessions[0].getPackets().size())
        packetCounter1 = 0;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Bytes::button14_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 2;
    packetCounter2--;
    if(sessions.size()>=2)
    if (packetCounter2 == sessions[1].getPackets().size() || packetCounter2 == -1)
        packetCounter2 = sessions[1].getPackets().size() - 1;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Bytes::button15_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 2;
    packetCounter2++;
    if(sessions.size()>=2)
    if (packetCounter2 == sessions[1].getPackets().size())
        packetCounter2 = 0;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Bytes::button12_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 3;
    packetCounter3--;
    if(sessions.size()>=3)
    if (packetCounter3 == sessions[2].getPackets().size() || packetCounter3 == -1)
        packetCounter3 = sessions[2].getPackets().size() - 1;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Bytes::button13_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 3;
    packetCounter3++;
    if(sessions.size()>=3)
    if (packetCounter3 == sessions[2].getPackets().size())
        packetCounter3 = 0;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Bytes::button10_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 4;
    packetCounter4--;
    if(sessions.size()>=4)
    if (packetCounter4 == sessions[3].getPackets().size() || packetCounter4 == -1)
        packetCounter4 = sessions[3].getPackets().size() - 1;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Bytes::button11_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 4;
    packetCounter4++;
    if(sessions.size()>=4)
    if (packetCounter4 == sessions[3].getPackets().size())
        packetCounter4 = 0;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Bytes::comboBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
    if (e->KeyChar == (int)Keys::Enter) {
        e->Handled = true;
        int input = System::Convert::ToInt16(comboBox1->Text);
        for (size_t i = 0; i < sessBytes.size(); i++)
        {
            if (sessBytes[i].getNum() == input)
            {
                box = 1;
                counter1 = i;
                packetCounter1 = 0;
                startDrawingBytes(systemFilePaths);
            }
        }
    }
    return System::Void();
}

System::Void curseProject1::Bytes::comboBox4_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
    if (e->KeyChar == (int)Keys::Enter) {
        e->Handled = true;
        int input = System::Convert::ToInt16(comboBox4->Text);
        for (size_t i = 0; i < sessBytes.size(); i++)
        {
            if (sessBytes[i].getNum() == input)
            {
                box = 2;
                counter2 = i;
                packetCounter2 = 0;
                startDrawingBytes(systemFilePaths);
            }
        }
    }
    return System::Void();
}

System::Void curseProject1::Bytes::comboBox6_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
    if (e->KeyChar == (int)Keys::Enter) {
        e->Handled = true;
        int input = System::Convert::ToInt16(comboBox6->Text);
        for (size_t i = 0; i < sessBytes.size(); i++)
        {
            if (sessBytes[i].getNum() == input)
            {
                box = 3;
                counter3 = i;
                packetCounter3 = 0;
                startDrawingBytes(systemFilePaths);
            }
        }
    }
    return System::Void();
}

System::Void curseProject1::Bytes::comboBox8_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
    if (e->KeyChar == (int)Keys::Enter) {
        e->Handled = true;
        int input = System::Convert::ToInt16(comboBox8->Text);
        for (size_t i = 0; i < sessBytes.size(); i++)
        {
            if (sessBytes[i].getNum() == input)
            {
                box = 4;
                counter4 = i;
                packetCounter4 = 0;
                startDrawingBytes(systemFilePaths);
            }
        }
    }
    return System::Void();
}

System::Void curseProject1::Bytes::comboBox2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
    if (e->KeyChar == (int)Keys::Enter) {
        e->Handled = true;
        int input = System::Convert::ToInt16(comboBox2->Text);
        if (input>=0 && input<sessions[0].getPackets().size())
        {
            box = 1;
            packetCounter1 = input;
            startDrawingBytes(systemFilePaths);
        }
    }
    return System::Void();
}

System::Void curseProject1::Bytes::comboBox3_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
    if (e->KeyChar == (int)Keys::Enter) {
        e->Handled = true;
        int input = System::Convert::ToInt16(comboBox3->Text);
        if (input >= 0 && input < sessions[1].getPackets().size())
        {
            box = 2;
            packetCounter2 = input;
            startDrawingBytes(systemFilePaths);
        }
    }
    return System::Void();
}

System::Void curseProject1::Bytes::comboBox5_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
    if (e->KeyChar == (int)Keys::Enter) {
        e->Handled = true;
        int input = System::Convert::ToInt16(comboBox5->Text);
        if (input >= 0 && input < sessions[2].getPackets().size())
        {
            box = 3;
            packetCounter3 = input;
            startDrawingBytes(systemFilePaths);
        }
    }
    return System::Void();
}

System::Void curseProject1::Bytes::comboBox7_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
    if (e->KeyChar == (int)Keys::Enter) {
        e->Handled = true;
        int input = System::Convert::ToInt16(comboBox7->Text);
        if (input >= 0 && input < sessions[3].getPackets().size())
        {
            box = 4;
            packetCounter4 = input;
            startDrawingBytes(systemFilePaths);
        }
    }
    return System::Void();
}

System::Void curseProject1::Bytes::comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (!l1)
    {
        box = 1;
        counter1 = comboBox1->SelectedIndex;
        packetCounter1 = 0;
        startDrawingBytes(systemFilePaths);
    }
    return System::Void();
}

System::Void curseProject1::Bytes::comboBox4_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (!l4)
    {
        box = 2;
        counter2 = comboBox4->SelectedIndex;
        packetCounter2 = 0;
        startDrawingBytes(systemFilePaths);
    }
    return System::Void();
}

System::Void curseProject1::Bytes::comboBox6_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (!l6)
    {
        box = 3;
        counter3 = comboBox6->SelectedIndex;
        packetCounter3 = 0;
        startDrawingBytes(systemFilePaths);
    }
    return System::Void();
}

System::Void curseProject1::Bytes::comboBox8_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (!l8)
    {
        box = 4;
        counter4 = comboBox8->SelectedIndex;
        packetCounter4 = 0;
        startDrawingBytes(systemFilePaths);
    }
    return System::Void();
}

System::Void curseProject1::Bytes::comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (!l2)
    {
        box = 1;
        packetCounter1 = comboBox2->SelectedIndex;
        startDrawingBytes(systemFilePaths);
    }
    return System::Void();
}

System::Void curseProject1::Bytes::comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (!l3)
    {
        box = 2;
        packetCounter2 = comboBox3->SelectedIndex;
        startDrawingBytes(systemFilePaths);
    }
    return System::Void();
}

System::Void curseProject1::Bytes::comboBox5_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (!l5)
    {
        box = 3;
        packetCounter3 = comboBox5->SelectedIndex;
        startDrawingBytes(systemFilePaths);
    }
    return System::Void();
}

System::Void curseProject1::Bytes::comboBox7_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (!l7)
    {
        box = 4;
        packetCounter4 = comboBox7->SelectedIndex;
        startDrawingBytes(systemFilePaths);
    }
    return System::Void();
}

System::Void curseProject1::Bytes::textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
    if (e->KeyChar == (int)Keys::Enter) {
        button9->PerformClick();
    }
    return System::Void();
}
