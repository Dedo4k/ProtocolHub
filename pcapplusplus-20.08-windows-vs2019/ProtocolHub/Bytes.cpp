#include "Bytes.h"
#include <iostream>
#include "PacketHelper.h"
#include "SessionHelper.h"
#include "Service.h"
#include "ConvertFunc.h"
#include "findFunc.h"
#include "DataClass.h"

//std::vector<PacketHelper> packets2;                                                                         //������ �������
//std::vector<SessionHelper> sessions2;                                                                       //������ ������
std::vector<SessionHelper> sessions;

//int counter1 = 0;                                                                                           //����� ������ ��� "richTextBox1"
//int counter2 = 1;                                                                                           //����� ������ ��� "richTextBox2"
//int counter3 = 2;                                                                                           //����� ������ ��� "richTextBox3"
//int counter4 = 3;                                                                                           //����� ������ ��� "richTextBox4"
//
//int box = 0;                                                                                                //����� "richTextBox", ������� ��� ������

/*
����� ���������� � "richTextBox" � ����������� �� ����, ����� ������ ������ ���� ���������� ��� �������
*/
void curseProject1::Bytes::startDrawingBytes(System::Collections::ArrayList^ systemFilePaths)
{
    //if (sessBytes.empty())                                                                                  //���� ������ ������ ����, �� ��������� ��� 
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
    for (size_t i = 0; i < sessBytes.size()&&i<4; i++)                                                      //��������� ������ ������ ��� ������ � "richTextBox"
    {                                                                                                       //���������� ����� ��� ������ ������ � "richTextBox"
        switch (i)
        {
        case 0: sessions.push_back(sessBytes[counter1]); f1 = 1; break;
        case 1: sessions.push_back(sessBytes[counter2]); f2 = 2; break;
        case 2: sessions.push_back(sessBytes[counter3]); f3 = 3; break;
        case 3: sessions.push_back(sessBytes[counter4]); f4 = 4; break;
        }
    }
    switch (box)                                                                                            //�������� "richTextBox" � ����������� �� ����, ����� ��� ������
    {
    case 0:                                                                                                 //�������������� �������������
    {
        if (f1)                                                                                             //�������� �������������
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
            comboBox1->SelectedIndex = counter1;
            for (size_t i = 0; i < sessions[0].getPackets().size(); i++)
            {
                comboBox2->Items->Add(i);
            }
            comboBox2->SelectedIndex = packetCounter1;
            label2->Text = "����� ������: ";
            label8->Text = "����� ������: ";
            label9->Text = Convert_string_to_String(sessions[0].getSrcIp().toString()) + ":" + sessions[0].getSrcPort() + "->" + Convert_string_to_String(sessions[0].getDstIp().toString()) + ":" + sessions[0].getDstPort();
        }
        if (f2)                                                                                             //�������� �������������
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
            comboBox4->SelectedIndex = counter2;
            for (size_t i = 0; i < sessions[1].getPackets().size(); i++)
            {
                comboBox3->Items->Add(i);
            }
            comboBox3->SelectedIndex = packetCounter2;
            label3->Text = "����� ������: ";
            label7->Text = "����� ������: ";
            label10->Text = Convert_string_to_String(sessions[1].getSrcIp().toString()) + ":" + sessions[1].getSrcPort() + "->" + Convert_string_to_String(sessions[1].getDstIp().toString()) + ":" + sessions[1].getDstPort();
        }
        if (f3)                                                                                             //�������� �������������
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
            comboBox6->SelectedIndex = counter3;
            for (size_t i = 0; i < sessions[2].getPackets().size(); i++)
            {
                comboBox5->Items->Add(i);
            }
            comboBox5->SelectedIndex = packetCounter3;
            label4->Text = "����� ������: ";
            label6->Text = "����� ������: ";
            label11->Text = Convert_string_to_String(sessions[2].getSrcIp().toString()) + ":" + sessions[2].getSrcPort() + "->" + Convert_string_to_String(sessions[2].getDstIp().toString()) + ":" + sessions[2].getDstPort();
        }
        if (f4)                                                                                             //�������� �������������
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
            comboBox8->SelectedIndex = counter4;
            for (size_t i = 0; i < sessions[3].getPackets().size(); i++)
            {
                comboBox7->Items->Add(i);
            }
            comboBox7->SelectedIndex = packetCounter4;
            label5->Text = "����� ������: ";
            label1->Text = "����� ������: ";
            label12->Text = Convert_string_to_String(sessions[3].getSrcIp().toString()) + ":" + sessions[3].getSrcPort() + "->" + Convert_string_to_String(sessions[3].getDstIp().toString()) + ":" + sessions[3].getDstPort();
        }
        break;
    }
    case 1:                                                                                                 //���� ��� ������ "richTextBox1"
    {
        if (f1)                                                                                             //�������� �������������
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
            comboBox1->SelectedIndex = counter1;
            comboBox2->SelectedIndex = packetCounter1;
        }
        break;
    }
    case 2:                                                                                                 //���� ��� ������ "richTextBox2"
    {
        if (f2)                                                                                             //�������������� �������������
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
            comboBox4->SelectedIndex = counter2;
            comboBox3->SelectedIndex = packetCounter2;
        }
        break;
    }
    case 3:                                                                                                 //���� ��� ������ "richTextBox3"
    {
        if (f3)                                                                                             //�������������� �������������
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
            comboBox6->SelectedIndex = counter3;
            comboBox5->SelectedIndex = packetCounter3;
        }
        break;
    }
    case 4:                                                                                                 //���� ��� ������ "richTextBox4"
    {
        if (f4)                                                                                             //�������������� �������������
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
            comboBox8->SelectedIndex = counter4;
            comboBox7->SelectedIndex = packetCounter4;
        }
        break;
    }
    default:
        break;
    }
}

/*
��������� ������� ���� ��� ������� �� ������ "�����" �� ������ ����
*/
System::Void curseProject1::Bytes::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
��������� ���������� ��� ������� �� ������ "������� ����������" �� ������ ����
*/
System::Void curseProject1::Bytes::�����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Environment::Exit(0);
    return System::Void();
}

/*
����������� ����� ������ ��� "richTextBox1" ��� ������� �� ������ "button1"
�������� ����� "startDrawingBytes"
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
��������� ����� ������ ��� "richTextBox1" ��� ������� �� ������ "button2"
�������� ����� "startDrawingBytes"
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
��������� ����� ������ ��� "richTextBox2" ��� ������� �� ������ "button3"
�������� ����� "startDrawingBytes"
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
����������� ����� ������ ��� "richTextBox2" ��� ������� �� ������ "button4"
�������� ����� "startDrawingBytes"
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
��������� ����� ������ ��� "richTextBox3" ��� ������� �� ������ "button5"
�������� ����� "startDrawingBytes"
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
����������� ����� ������ ��� "richTextBox3" ��� ������� �� ������ "button6"
�������� ����� "startDrawingBytes"
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
��������� ����� ������ ��� "richTextBox4" ��� ������� �� ������ "button7"
�������� ����� "startDrawingBytes"
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
����������� ����� ������ ��� "richTextBox4" ��� ������� �� ������ "button8"
�������� ����� "startDrawingBytes"
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
��������� ����� ������ � ������� ������ � ������������ � ���, ����� ����� ��� ������
*/
System::Void curseProject1::Bytes::button9_Click(System::Object^ sender, System::EventArgs^ e)
{
    std::string str;
    Convert_String_to_string(textBox1->Text,str);
    std::vector<SessionHelper> sessions;
    int i = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0;
    for (size_t i = 0; i < sessBytes.size()&&i<4; i++)                                                              //��������� ������ ������ ��� ����������
    {                                                                                                               //���������� ����� ��� ���������� ������
        switch (i)
        {
        case 0: sessions.push_back(sessBytes[counter1]); f1 = 1; break;
        case 1: sessions.push_back(sessBytes[counter2]); f2 = 1; break;
        case 2: sessions.push_back(sessBytes[counter3]); f3 = 1; break;
        case 3: sessions.push_back(sessBytes[counter4]); f4 = 1; break;
        }
    }
    if (radioButton1->Checked)                                                                                      //���� ��� ������ ����� �� ����� ������� 
    {
        int txtStart = 0, txtEnd = 0;
        int fl = 0, start = 0/*findSubstringAt(sessions, str)*/, length = str.length(),                                  //start - ������� ������� ����������
            fl1 = 0, fl0 = 0;
        if (start == -1)                                                                                            //��������, ���� �� ����������
            fl1 = 1;
        if (length == 0)                                                                                            //�������� ����� �������� �����
            fl0 = 1;
        String^ temp = richTextBox1->Text;
        for (size_t i = 0; i < temp->Length; i++)                                                                   //����� ������ � ����� �������� ����� � "richTextBox"
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

        if (f1)                                                                                                     //�������� �������������
        {
            richTextBox1->SelectionBackColor = System::Drawing::Color::White;
            richTextBox1->SelectionStart = txtStart;
            richTextBox1->ScrollToCaret();
            richTextBox1->SelectionLength = txtEnd - txtStart;
            richTextBox1->SelectionBackColor = System::Drawing::Color::Blue;
        }
        if (f2)                                                                                                     //�������� �������������
        {
            richTextBox2->SelectionBackColor = System::Drawing::Color::White;
            richTextBox2->SelectionStart = txtStart;
            richTextBox2->ScrollToCaret();
            richTextBox2->SelectionLength = txtEnd - txtStart;
            richTextBox2->SelectionBackColor = System::Drawing::Color::Blue;
        }
        if (f3)                                                                                                     //�������� �������������
        {
            richTextBox3->SelectionBackColor = System::Drawing::Color::White;
            richTextBox3->SelectionStart = txtStart;
            richTextBox3->ScrollToCaret();
            richTextBox3->SelectionLength = txtEnd - txtStart;
            richTextBox3->SelectionBackColor = System::Drawing::Color::Blue;
        }
        if (f4)                                                                                                     //�������� �������������
        {
            richTextBox4->SelectionBackColor = System::Drawing::Color::White;
            richTextBox4->SelectionStart = txtStart;
            richTextBox4->ScrollToCaret();
            richTextBox4->SelectionLength = txtEnd - txtStart;
            richTextBox4->SelectionBackColor = System::Drawing::Color::Blue;
        }
    }
    else if (radioButton2->Checked)                                                                                 //���� ��� ������ ����� �� ������ ��������
    {
        std::vector<size_t> startPoints/* = findSubstring(sessions, str)*/;                                             //������ � ������� ����������� � ������ ������
        int f1 = 0, f2 = 0, f3 = 0, f4 = 0;
        for (size_t i = 0; i < startPoints.size(); i++)                                                             //���������� ����� ��� ������������
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
        if (f1)                                                                                                     //�������� �������������
        {
            start = startPoints[0], length = str.length();                                                          //����� ������ � ����� �������� ����� � "richTextBox1"

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
        if (f2)                                                                                                     //����� ������ � ����� �������� ����� � "richTextBox2"
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
        if (f3)                                                                                                     //����� ������ � ����� �������� ����� � "richTextBox3"
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
        if (f4)                                                                                                     //����� ������ � ����� �������� ����� � "richTextBox4"
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
        
        if (f1)                                                                                                     //�������� �������������
        {
            richTextBox1->SelectionBackColor = System::Drawing::Color::White;
            richTextBox1->SelectionStart = txtStart1;
            richTextBox1->ScrollToCaret();
            richTextBox1->SelectionLength = txtEnd1 - txtStart1;
            richTextBox1->SelectionBackColor = System::Drawing::Color::Blue;
        }
        if (f2)                                                                                                     //�������� �������������
        {
            richTextBox2->SelectionBackColor = System::Drawing::Color::White;
            richTextBox2->SelectionStart = txtStart2;
            richTextBox2->ScrollToCaret();
            richTextBox2->SelectionLength = txtEnd2 - txtStart2;
            richTextBox2->SelectionBackColor = System::Drawing::Color::Blue;
        }
        if (f3)                                                                                                     //�������� �������������
        {
            richTextBox3->SelectionBackColor = System::Drawing::Color::White;
            richTextBox3->SelectionStart = txtStart3;
            richTextBox3->ScrollToCaret();
            richTextBox3->SelectionLength = txtEnd3 - txtStart3;
            richTextBox3->SelectionBackColor = System::Drawing::Color::Blue;
        }
        if (f4)                                                                                                     //�������� �������������
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

System::Void curseProject1::Bytes::button16_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 1;
    packetCounter1--;
    if (packetCounter1 == sessions[0].getPackets().size() || packetCounter1 == -1)
        packetCounter1 = sessions[0].getPackets().size() - 1;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Bytes::button17_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 1;
    packetCounter1++;
    if (packetCounter1 == sessions[0].getPackets().size())
        packetCounter1 = 0;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Bytes::button14_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 2;
    packetCounter2--;
    if (packetCounter2 == sessions[1].getPackets().size() || packetCounter2 == -1)
        packetCounter2 = sessions[1].getPackets().size() - 1;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Bytes::button15_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 2;
    packetCounter2++;
    if (packetCounter2 == sessions[1].getPackets().size())
        packetCounter2 = 0;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Bytes::button12_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 3;
    packetCounter3--;
    if (packetCounter3 == sessions[2].getPackets().size() || packetCounter3 == -1)
        packetCounter3 = sessions[2].getPackets().size() - 1;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Bytes::button13_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 3;
    packetCounter3++;
    if (packetCounter3 == sessions[2].getPackets().size())
        packetCounter3 = 0;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Bytes::button10_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 4;
    packetCounter4--;
    if (packetCounter4 == sessions[3].getPackets().size() || packetCounter4 == -1)
        packetCounter4 = sessions[3].getPackets().size() - 1;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Bytes::button11_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 4;
    packetCounter4++;
    if (packetCounter4 == sessions[3].getPackets().size())
        packetCounter4 = 0;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}
