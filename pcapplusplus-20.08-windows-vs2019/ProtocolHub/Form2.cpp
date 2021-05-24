#include "Form2.h"
#include "Service.h"
#include "ConvertFunc.h"
#include "Sessions.h"
#include "PacketHelper.h"
#include "findFunc.h"
#include "DataClass.h"

//std::vector<PacketHelper> packets;                                                                              //������ �������
int pages = 0;
int page = 0;
int counter = 1000;
int c1 = 0;
/*
������ ����� �� ������ ���������� ������
��������� ������ �������
��������� ��� ���������� ���������� � �������
*/
void curseProject1::Form2::StartParsingFiles(System::Collections::ArrayList^ systemFilePaths)
{
    std::vector<std::string> stringFilePaths = Service::convertToString(systemFilePaths);
    //packets = Service::getAllPackets(stringFilePaths);                                                          //�������� ������ �������
    if(pack.empty())
        pack = Service::getAllPackets(stringFilePaths);
    pages = pack.size() / 1000;
    toolStripComboBox1->Items->Clear();
    for (size_t i = 0; i < pages+1; i++)
    {
        toolStripComboBox1->Items->Add(i);
    }
    c1 = 1;
    toolStripComboBox1->SelectedIndex = page;
    c1 = 0;
    int k = 1;
    int q = 0;
    dataGridView1->Rows->Clear();
    for each (PacketHelper packet in pack)                                                                   //�������� �� ���� �������
    {                                                                                                           //��������� ���������� � �������
        if (q < page * 1000)
        {
            q++;
            continue;
        }
        if (k > counter)
            break;
        int i = dataGridView1->Rows->Add();
        dataGridView1->Rows[i]->Cells[0]->Value = q+k;                                                          //�
        dataGridView1->Rows[i]->Cells[1]->Value = Convert_string_to_String(packet.getSrcIp().toString());       //Sourse
        dataGridView1->Rows[i]->Cells[2]->Value = packet.getSrcPort();                                          //SrcPort
        dataGridView1->Rows[i]->Cells[3]->Value = Convert_string_to_String(packet.getDstIp().toString());       //Destination
        dataGridView1->Rows[i]->Cells[4]->Value = packet.getDstPort();                                          //SrcPort
        dataGridView1->Rows[i]->Cells[5]->Value = Convert_string_to_String(packet.getProtocolName());           //Protocol
        dataGridView1->Rows[i]->Cells[6]->Value = Convert_string_to_String(packet.getTimestampAsString());      //Time
        k++;
    }
    return System::Void();
}

/*
��������� ���� ��� ������ � �������� ��� ������� �� ������ "������" �� ������ ����
*/
System::Void curseProject1::Form2::������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    Sessions^ sessions = gcnew Sessions(systemFilePaths);
    sessions->ShowDialog(this);
    this->Show();
    return System::Void();
}

/*
��������� ���������� ��� ������� �� ������ "������� ����������" �� ������ ����
*/
System::Void curseProject1::Form2::�����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Environment::Exit(0);
    return System::Void();
}

/*
��������� ������� ���� ��� ������� �� ������ "�����" �� ������ ���� � ��������� ���� ��� ������ � �������
*/
System::Void curseProject1::Form2::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    pack.clear();
    sess.clear();
    pages = 0;
    //packets.clear();
    this->Close();
    this->DialogResult = System::Windows::Forms::DialogResult::OK;
    return System::Void();
}

/*
������� �������������� ���������� � ������ ��� ������� �� ��� �� �������
*/
System::Void curseProject1::Form2::dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    int i = 0;
    dataGridView2->Columns->Clear();
    for each (std::string info in pack[dataGridView1->CurrentCell->RowIndex].getProtocols())//���� packets
    {
        dataGridView2->Columns->Add(i.ToString(), Convert_string_to_String(info));
        i++;
    }
    return System::Void();
}

System::Void curseProject1::Form2::toolStripComboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (!c1)
    {
        page = toolStripComboBox1->SelectedIndex;
        StartParsingFiles(systemFilePaths);
    }
    return System::Void();
}
