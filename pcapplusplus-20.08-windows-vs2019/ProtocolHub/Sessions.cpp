#include "Sessions.h"
#include "Service.h"
#include "ConvertFunc.h"
#include "PacketHelper.h"

std::vector<PacketHelper> packets1;

void curseProject1::Sessions::startDrawingSessions(System::Collections::ArrayList^ systemFilePaths)
{
    int i = 0;
    int UDP = 0;
    int TCP = 0;
    int DNS = 0;

    std::vector<std::string> stringFilePaths = Service::convertToString(systemFilePaths);
    packets1 = Service::getAllPackets(stringFilePaths);
    // Set automatic zooming
    chart1->ChartAreas[0]->AxisX->ScaleView->Zoomable = true;
    chart1->ChartAreas[0]->AxisY->ScaleView->Zoomable = true;

    //// Set automatic scrolling 
    chart1->ChartAreas[0]->CursorX->AutoScroll = true;
    chart1->ChartAreas[0]->CursorY->AutoScroll = true;

    //// Allow user selection for Zoom
    chart1->ChartAreas[0]->CursorX->IsUserSelectionEnabled = true;
    chart1->ChartAreas[0]->CursorY->IsUserSelectionEnabled = true;
    for each (PacketHelper packet in packets1)
    {  
        String^ temp = Convert_string_to_String(packet.getProtocolName());
        if (temp->Equals("UDP")) {
            temp += UDP;
            UDP++;
        }
        if (temp->Equals("TCP")) {
            temp += TCP;
            TCP++;
        }
        if (temp->Equals("DNS")) {
            temp += DNS;
            DNS++;
        }
        int x0 = std::rand() % 50;
        int x1 = std::rand() % 100;
        chart1->Series->Add(temp);
        chart1->Series[temp]->LabelToolTip = Convert_string_to_String(packet.getFirstLayer());
        chart1->Series[temp]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::RangeBar;
        chart1->Series[temp]->BorderColor = chart1->Series[temp]->Color;
        chart1->Series[temp]->BorderWidth = 5;
        chart1->Series[temp]->Points->AddXY(i++, x1, x0);
        chart1->Series[temp]->ToolTip = "Протокол: " + temp + " Начало: " + x1 + "c Конец: " + x0 + "c";
        chart1->Series[temp]->LegendToolTip = "Протокол: " + temp + " Начало: " + x1 + "c Конец: " + x0 + "c";
    }
}

System::Void curseProject1::Sessions::назадToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
    this->DialogResult = System::Windows::Forms::DialogResult::OK;
    return System::Void();
}

System::Void curseProject1::Sessions::trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    chart1->Series->Clear();
    chart1->ChartAreas[0]->AxisX->ScaleView->Size = trackBar1->Maximum - trackBar1->Value;
    startDrawingSessions(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Sessions::trackBar2_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    chart1->Series->Clear();
    chart1->ChartAreas[0]->AxisY->ScaleView->Size = trackBar2->Maximum - trackBar2->Value;
    startDrawingSessions(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Sessions::button1_Click(System::Object^ sender, System::EventArgs^ e)
{   
    chart1->Series->Clear();
    chart1->ChartAreas[0]->AxisX->ScaleView->ZoomReset();
    chart1->ChartAreas[0]->AxisY->ScaleView->ZoomReset();
    startDrawingSessions(systemFilePaths);
    return System::Void();
}
