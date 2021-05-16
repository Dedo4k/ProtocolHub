#include "Bytes.h"
#include <iostream>
#include "PacketHelper.h"
#include "SessionHelper.h"
#include "Service.h"
#include "ConvertFunc.h"
#include "findFunc.h"

std::vector<PacketHelper> packets2;
std::vector<SessionHelper> sessions2;

int counter1 = 0;
int counter2 = 1;
int counter3 = 2;
int counter4 = 3;

int box = 0;

int min;

void curseProject1::Bytes::startDrawingBytes(System::Collections::ArrayList^ systemFilePaths)
{
    if (sessions2.empty()) {
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
        min = findStartPoint(sessions2);
    }
    String^ str;
    std::vector<SessionHelper> sessions;
    int f1 = 0, f2 = 0, f3 = 0, f4 = 0;
    for (size_t i = 0; i < sessions2.size()&&i<4; i++)
    {
        switch (i)
        {
        case 0: sessions.push_back(sessions2[counter1]); f1 = 1; break;
        case 1: sessions.push_back(sessions2[counter2]); f2 = 2; break;
        case 2: sessions.push_back(sessions2[counter3]); f3 = 3; break;
        case 3: sessions.push_back(sessions2[counter4]); f4 = 4; break;
        }
    }
    //SessionHelper session1 = sessions2[counter1];
    //SessionHelper session2 = sessions2[counter2];
    //SessionHelper session3 = sessions2[counter3];
    //SessionHelper session4 = sessions2[counter4];
    switch (box)
    {
    case 0:
    {
        if (f1)
        {
            for (size_t i = 0; i < sessions[0].getBytes().size(); i++)
            {
                str += Convert_string_to_String(charToAscii(sessions[0].getBytes()[i])) + " ";
            }
            richTextBox1->Text = str;
            label2->Text = "Íîìåð: " + counter1 + "\n" + Convert_string_to_String(sessions[0].getSrcIp().toString()) + ":" + sessions[0].getSrcPort() + "->" + Convert_string_to_String(sessions[0].getDstIp().toString()) + ":" + sessions[0].getDstPort();
        }
        if (f2)
        {
            str = "";
            for (size_t i = 0; i < sessions[1].getBytes().size(); i++)
            {
                str += Convert_string_to_String(charToAscii(sessions[1].getBytes()[i])) + " ";
            }
            richTextBox2->Text = str;
            label3->Text = "Íîìåð: " + counter2 + "\n" + Convert_string_to_String(sessions[1].getSrcIp().toString()) + ":" + sessions[1].getSrcPort() + "->" + Convert_string_to_String(sessions[1].getDstIp().toString()) + ":" + sessions[1].getDstPort();
        }
        if (f3)
        {
            str = "";
            for (size_t i = 0; i < sessions[2].getBytes().size(); i++)
            {
                str += Convert_string_to_String(charToAscii(sessions[2].getBytes()[i])) + " ";
            }
            richTextBox3->Text = str;
            label4->Text = "Íîìåð: " + counter3 + "\n" + Convert_string_to_String(sessions[2].getSrcIp().toString()) + ":" + sessions[2].getSrcPort() + "->" + Convert_string_to_String(sessions[2].getDstIp().toString()) + ":" + sessions[2].getDstPort();
        }
        if (f4)
        {
            str = "";
            for (size_t i = 0; i < sessions[3].getBytes().size(); i++)
            {
                str += Convert_string_to_String(charToAscii(sessions[3].getBytes()[i])) + " ";
            }
            richTextBox4->Text = str;
            label5->Text = "Íîìåð: " + counter4 + "\n" + Convert_string_to_String(sessions[3].getSrcIp().toString()) + ":" + sessions[3].getSrcPort() + "->" + Convert_string_to_String(sessions[3].getDstIp().toString()) + ":" + sessions[3].getDstPort();
        }
        break;
    }
    case 1:
    {
        if (f1)
        {
            str = "";
            for (size_t i = 0; i < sessions[0].getBytes().size(); i++)
            {
                str += Convert_string_to_String(charToAscii(sessions[0].getBytes()[i])) + " ";
            }
            richTextBox1->Text = str;
            label2->Text = "Íîìåð: " + counter1 + "\n" + Convert_string_to_String(sessions[0].getSrcIp().toString()) + ":" + sessions[0].getSrcPort() + "->" + Convert_string_to_String(sessions[0].getDstIp().toString()) + ":" + sessions[0].getDstPort();
        }
        break;
    }
    case 2:
    {
        if (f2)
        {
            str = "";
            for (size_t i = 0; i < sessions[1].getBytes().size(); i++)
            {
                str += Convert_string_to_String(charToAscii(sessions[1].getBytes()[i])) + " ";
            }
            richTextBox2->Text = str;
            label3->Text = "Íîìåð: " + counter2 + "\n" + Convert_string_to_String(sessions[1].getSrcIp().toString()) + ":" + sessions[1].getSrcPort() + "->" + Convert_string_to_String(sessions[1].getDstIp().toString()) + ":" + sessions[1].getDstPort();
        }
        break;
    }
    case 3:
    {
        if (f3)
        {
            str = "";
            for (size_t i = 0; i < sessions[2].getBytes().size(); i++)
            {
                str += Convert_string_to_String(charToAscii(sessions[2].getBytes()[i])) + " ";
            }
            richTextBox3->Text = str;
            label4->Text = "Íîìåð: " + counter3 + "\n" + Convert_string_to_String(sessions[2].getSrcIp().toString()) + ":" + sessions[2].getSrcPort() + "->" + Convert_string_to_String(sessions[2].getDstIp().toString()) + ":" + sessions[2].getDstPort();
        }
        break;
    }
    case 4:
    {
        if (f4)
        {
            str = "";
            for (size_t i = 0; i < sessions[3].getBytes().size(); i++)
            {
                str += Convert_string_to_String(charToAscii(sessions[3].getBytes()[i])) + " ";
            }
            richTextBox4->Text = str;
            label5->Text = "Íîìåð: " + counter4 + "\n" + Convert_string_to_String(sessions[3].getSrcIp().toString()) + ":" + sessions[3].getSrcPort() + "->" + Convert_string_to_String(sessions[3].getDstIp().toString()) + ":" + sessions[3].getDstPort();
        }
        break;
    }
    default:
        break;
    }
}

System::Void curseProject1::Bytes::íàçàäToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    packets2.clear();
    sessions2.clear();
    this->Close();
    this->DialogResult = System::Windows::Forms::DialogResult::OK;
    return System::Void();
}

System::Void curseProject1::Bytes::çàêðûòüÏðèëîæåíèåToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Environment::Exit(0);
    return System::Void();
}

System::Void curseProject1::Bytes::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 1;
    counter1++;
    if (counter1 == 40)
        counter1 = 0;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Bytes::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 1;
    counter1--;
    if (counter1 == -1)
        counter1 = 39;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Bytes::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 2;
    counter2--;
    if (counter2 == -1)
        counter2 = 39;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Bytes::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 2;
    counter2++;
    if (counter2 == 40)
        counter2 = 0;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Bytes::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 3;
    counter3--;
    if (counter3 == -1)
        counter3 = 39;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Bytes::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 3;
    counter3++;
    if (counter3 == 40)
        counter3 = 0;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Bytes::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 4;
    counter4--;
    if (counter4 == -1)
        counter4 = 39;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Bytes::button8_Click(System::Object^ sender, System::EventArgs^ e)
{
    box = 4;
    counter4++;
    if (counter4 == 40)
        counter4 = 0;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Bytes::button9_Click(System::Object^ sender, System::EventArgs^ e)
{
    std::string str;
    Convert_String_to_string(textBox1->Text,str);
    std::vector<SessionHelper> sessions;// {sessions2[counter1], sessions2[counter2], sessions2[counter3], sessions2[counter4]};
    int i = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0;
    for (size_t i = 0; i < sessions2.size(),i<4; i++)
    {
        switch (i)
        {
        case 0: sessions.push_back(sessions2[counter1]); f1 = 1; break;
        case 1: sessions.push_back(sessions2[counter2]); f2 = 1; break;
        case 2: sessions.push_back(sessions2[counter3]); f3 = 1; break;
        case 3: sessions.push_back(sessions2[counter4]); f4 = 1; break;
        }
    }
    if (radioButton1->Checked) {
        int txtStart = 0, txtEnd = 0;
        int fl = 0, start = findSubstringAt(sessions, str), length = str.length(),
            fl1 = 0, fl0 = 0;
        if (start == -1)
            fl1 = 1;
        if (length == 0)
            fl0 = 1;
        String^ temp = richTextBox1->Text;
        for (size_t i = 0; i < temp->Length; i++)
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

        if (f1)
        {
            richTextBox1->SelectionBackColor = System::Drawing::Color::White;
            richTextBox1->SelectionStart = txtStart;
            richTextBox1->ScrollToCaret();
            richTextBox1->SelectionLength = txtEnd - txtStart;
            richTextBox1->SelectionBackColor = System::Drawing::Color::Blue;
        }
        if (f2)
        {
            richTextBox2->SelectionBackColor = System::Drawing::Color::White;
            richTextBox2->SelectionStart = txtStart;
            richTextBox2->ScrollToCaret();
            richTextBox2->SelectionLength = txtEnd - txtStart;
            richTextBox2->SelectionBackColor = System::Drawing::Color::Blue;
        }
        if (f3)
        {
            richTextBox3->SelectionBackColor = System::Drawing::Color::White;
            richTextBox3->SelectionStart = txtStart;
            richTextBox3->ScrollToCaret();
            richTextBox3->SelectionLength = txtEnd - txtStart;
            richTextBox3->SelectionBackColor = System::Drawing::Color::Blue;
        }
        if (f4)
        {
            richTextBox4->SelectionBackColor = System::Drawing::Color::White;
            richTextBox4->SelectionStart = txtStart;
            richTextBox4->ScrollToCaret();
            richTextBox4->SelectionLength = txtEnd - txtStart;
            richTextBox4->SelectionBackColor = System::Drawing::Color::Blue;
        }
    }
    else if (radioButton2->Checked) {
        std::vector<size_t> startPoints = findSubstring(sessions, str);
        int f1 = 0, f2 = 0, f3 = 0, f4 = 0;
        for (size_t i = 0; i < startPoints.size(); i++)
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
        if (f1)
        {
            start = startPoints[0], length = str.length();

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
        if (f2)
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
        if (f3)
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
        if (f4)
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
        
        if (f1)
        {
            richTextBox1->SelectionBackColor = System::Drawing::Color::White;
            richTextBox1->SelectionStart = txtStart1;
            richTextBox1->ScrollToCaret();
            richTextBox1->SelectionLength = txtEnd1 - txtStart1;
            richTextBox1->SelectionBackColor = System::Drawing::Color::Blue;
        }
        if (f2)
        {
            richTextBox2->SelectionBackColor = System::Drawing::Color::White;
            richTextBox2->SelectionStart = txtStart2;
            richTextBox2->ScrollToCaret();
            richTextBox2->SelectionLength = txtEnd2 - txtStart2;
            richTextBox2->SelectionBackColor = System::Drawing::Color::Blue;
        }
        if (f3)
        {
            richTextBox3->SelectionBackColor = System::Drawing::Color::White;
            richTextBox3->SelectionStart = txtStart3;
            richTextBox3->ScrollToCaret();
            richTextBox3->SelectionLength = txtEnd3 - txtStart3;
            richTextBox3->SelectionBackColor = System::Drawing::Color::Blue;
        }
        if (f4)
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
