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
    SessionHelper session1 = sessions2[counter1];
    SessionHelper session2 = sessions2[counter2];
    SessionHelper session3 = sessions2[counter3];
    SessionHelper session4 = sessions2[counter4];
    switch (box)
    {
    case 0:
    {
        for (size_t i = 0; i < session1.getBytes().size(); i++)
        {
            str += Convert_string_to_String(charToAscii(session1.getBytes()[i])) + " ";
        }
        richTextBox1->Text = str;
        label2->Text = "Íîìåð: " + counter1 + "\n" + Convert_string_to_String(session1.getSrcIp().toString()) + ":" + session1.getSrcPort() + "->" + Convert_string_to_String(session1.getDstIp().toString()) + ":" + session1.getDstPort();

        str = "";
        for (size_t i = 0; i < session2.getBytes().size(); i++)
        {
            str += Convert_string_to_String(charToAscii(session2.getBytes()[i])) + " ";
        }
        richTextBox2->Text = str;
        label3->Text = "Íîìåð: " + counter2 + "\n" + Convert_string_to_String(session2.getSrcIp().toString()) + ":" + session2.getSrcPort() + "->" + Convert_string_to_String(session2.getDstIp().toString()) + ":" + session2.getDstPort();
        
        str = "";
        for (size_t i = 0; i < session3.getBytes().size(); i++)
        {
            str += Convert_string_to_String(charToAscii(session3.getBytes()[i])) + " ";
        }
        richTextBox3->Text = str;
        label4->Text = "Íîìåð: " + counter3 + "\n" + Convert_string_to_String(session3.getSrcIp().toString()) + ":" + session3.getSrcPort() + "->" + Convert_string_to_String(session3.getDstIp().toString()) + ":" + session3.getDstPort();
       
        str = "";
        for (size_t i = 0; i < session4.getBytes().size(); i++)
        {
            str += Convert_string_to_String(charToAscii(session4.getBytes()[i])) + " ";
        }
        richTextBox4->Text = str;
        label5->Text = "Íîìåð: " + counter4 + "\n" + Convert_string_to_String(session4.getSrcIp().toString()) + ":" + session4.getSrcPort() + "->" + Convert_string_to_String(session4.getDstIp().toString()) + ":" + session4.getDstPort();
        break;
    }
    case 1:
    {
        str = "";
        for (size_t i = 0; i < session1.getBytes().size(); i++)
        {
            str += Convert_string_to_String(charToAscii(session1.getBytes()[i])) + " ";
        }
        richTextBox1->Text = str;
        label2->Text = "Íîìåð: " + counter1 + "\n" + Convert_string_to_String(session1.getSrcIp().toString()) + ":" + session1.getSrcPort() + "->" + Convert_string_to_String(session1.getDstIp().toString()) + ":" + session1.getDstPort();
        break;
    }
    case 2:
    {
        str = "";
        for (size_t i = 0; i < session2.getBytes().size(); i++)
        {
            str += Convert_string_to_String(charToAscii(session2.getBytes()[i])) + " ";
        }
        richTextBox2->Text = str;
        label3->Text = "Íîìåð: " + counter2 + "\n" + Convert_string_to_String(session2.getSrcIp().toString()) + ":" + session2.getSrcPort() + "->" + Convert_string_to_String(session2.getDstIp().toString()) + ":" + session2.getDstPort();
        break;
    }
    case 3:
    {
        str = "";
        for (size_t i = 0; i < session3.getBytes().size(); i++)
        {
            str += Convert_string_to_String(charToAscii(session3.getBytes()[i])) + " ";
        }
        richTextBox3->Text = str;
        label4->Text = "Íîìåð: " + counter3 + "\n" + Convert_string_to_String(session3.getSrcIp().toString()) + ":" + session3.getSrcPort() + "->" + Convert_string_to_String(session3.getDstIp().toString()) + ":" + session3.getDstPort();
        break;
    }
    case 4:
    {
        str = "";
        for (size_t i = 0; i < session4.getBytes().size(); i++)
        {
            str += Convert_string_to_String(charToAscii(session4.getBytes()[i])) + " ";
        }
        richTextBox4->Text = str;
        label5->Text = "Íîìåð: " + counter4 + "\n" + Convert_string_to_String(session4.getSrcIp().toString()) + ":" + session4.getSrcPort() + "->" + Convert_string_to_String(session4.getDstIp().toString()) + ":" + session4.getDstPort();
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
    std::vector<SessionHelper> sessions {sessions2[counter1], sessions2[counter2], sessions2[counter3], sessions2[counter4]};
    if (radioButton1->Checked) {
        int start = findSubstringAt(sessions, str);
        std::cout << start << '\n';
    }
    else if (radioButton2->Checked) {
        std::vector<size_t> startPoints = findSubstring(sessions, str);
        for (size_t i = 0; i < startPoints.size(); ++i)
            std::cout << startPoints[i] << '\n';
    }
    return System::Void();
}
