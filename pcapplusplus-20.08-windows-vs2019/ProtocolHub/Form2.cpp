#include "Form2.h"
#include "Service.h"
#include "PacketHelper.h"
#include "ConvertFunc.h"

void curseProject1::Form2::StartParsingFiles(System::Collections::ArrayList^ systemFilePaths)
{
    std::vector<std::string> stringFilePaths = Service::convertToString(systemFilePaths);
    std::vector<PacketHelper> packets = Service::getAllPackets(stringFilePaths);
    for each (PacketHelper packet in packets)
    {
        packetsInfo->Text += Convert_string_to_String(packet.getProtocolName()) + "          " + Convert_string_to_String(packet.getFirstLayer()) + "\n";
        for each (std::string info in packet.getProtocols())
        {
            moreInfo->Text += Convert_string_to_String(info) + "\n";
        }
        moreInfo->Text += "\n";
    }
}

System::Void curseProject1::Form2::íàçàäToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
    this->DialogResult = System::Windows::Forms::DialogResult::OK;
    return System::Void();
}
