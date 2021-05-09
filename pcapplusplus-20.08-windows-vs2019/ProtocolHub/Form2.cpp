#include "Form2.h"
#include "Service.h"
#include "PacketHelper.h"
#include "ConvertFunc.h"

std::vector<PacketHelper> packets;

void curseProject1::Form2::StartParsingFiles(System::Collections::ArrayList^ systemFilePaths)
{
    std::vector<std::string> stringFilePaths = Service::convertToString(systemFilePaths);
    packets = Service::getAllPackets(stringFilePaths);

    //DataTable^ dt = gcnew DataTable();
    //dt->Columns->Add("Time");
    //dt->Columns->Add("Source");
    //dt->Columns->Add("Destination");
    //dt->Columns->Add("Protocol");
    //dt->Columns->Add("Length");
    //dt->Columns->Add("Info");

    for each (PacketHelper packet in packets)
    {
        //DataRow^ dr = dt->NewRow();
        //dr["Time"] = Convert_string_to_String(packet.getTimestamp());         get time 
        //dr["Source"] = Convert_string_to_String(packet.getSrcIp().toString());
        //dr["Destination"] = Convert_string_to_String(packet.getDstIp().toString());
        //dr["Protocol"] = Convert_string_to_String(packet.getProtocolName());
        //dr["Length"] = Convert_string_to_String(packet.get);
        //dr["Info"] = Convert_string_to_String(packet.getFirstLayer());
        //dt->Rows->Add(dr);

        int i = dataGridView1->Rows->Add();

        dataGridView1->Rows[i]->Cells[0]->Value = "Time";                                                       //Time
        dataGridView1->Rows[i]->Cells[1]->Value = Convert_string_to_String(packet.getSrcIp().toString());       //Sourse
        dataGridView1->Rows[i]->Cells[2]->Value = Convert_string_to_String(packet.getDstIp().toString());       //Destination
        dataGridView1->Rows[i]->Cells[3]->Value = Convert_string_to_String(packet.getProtocolName());           //Protocol
        dataGridView1->Rows[i]->Cells[4]->Value = "Length";                                                     //Length
        dataGridView1->Rows[i]->Cells[5]->Value = Convert_string_to_String(packet.getFirstLayer());             //Info

        //packetsInfo->Text += Convert_string_to_String(packet.getProtocolName()) + "          " + Convert_string_to_String(packet.getFirstLayer()) + "\n";
        //for each (std::string info in packet.getProtocols())
        //{
        //    moreInfo->Text += Convert_string_to_String(info) + "\n";
        //}
        //moreInfo->Text += "\n";
    }
}

System::Void curseProject1::Form2::dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    //dataGridView1->CurrentRow
    for each (std::string info in packets[dataGridView1->CurrentCell->RowIndex].getProtocols())
    {
        moreInfo->Text += Convert_string_to_String(info) + "\n";
    }
    return System::Void();
}

System::Void curseProject1::Form2::íàçàäToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    packets.clear();
    this->Close();
    this->DialogResult = System::Windows::Forms::DialogResult::OK;
    return System::Void();
}
