#include "Bytes.h"
#include <iostream>
#include "PacketHelper.h"
#include "SessionHelper.h"
#include "Service.h"
#include "ConvertFunc.h"
#include "findFunc.h"

std::vector<PacketHelper> packets2;
std::vector<SessionHelper> sessions2;

int counter = 0;
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
    for (size_t i = 0; i < sessions2[counter].getBytes().size(); i++)
    {
        str += Convert_string_to_String(charToAscii(sessions2[counter].getBytes()[i])) + " ";
    }
    richTextBox1->Text = str;
    SessionHelper session = sessions2[counter];
    label1->Text = "Íîìåð: " + counter + " Íà÷àëî: " + (session.getTimeStart() - min) + " Êîíåö: " + (session.getTimeEnd() + session.getTimeStart() - min) +
                 "\nÐàçìåð: " + session.getBytes().length() +
                 "\nTCP: " + session.isTcp() +
                 "\nUDP: " + session.isUdp() +
                 "\nTLS: " + session.isTls() +
                 "\nDNS: " + session.isDns() +
                 "\nHTTP: " + session.isHttp() +
                 "\nSIP: " + session.isSip();
}

System::Void curseProject1::Bytes::íàçàäToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
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
    counter++;
    if (counter == 40)
        counter = 0;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Bytes::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    counter--;
    if (counter == -1)
        counter = 39;
    startDrawingBytes(systemFilePaths);
    return System::Void();
}
