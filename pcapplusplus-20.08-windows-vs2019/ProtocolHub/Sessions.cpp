#include "Sessions.h"
#include "Service.h"
#include "ConvertFunc.h"
#include "PacketHelper.h"
#include "SessionHelper.h"
#include "findFunc.h"
#include <thread>

std::vector<PacketHelper> packets1;
std::vector<SessionHelper> sessions;

void treadFunc(void) {
    findUnusingPackets(packets1);
}

void curseProject1::Sessions::startDrawingSessions(System::Collections::ArrayList^ systemFilePaths)
{

    int i = 0;
    int UDP = 0;
    int TCP = 0;
    int DNS = 0;

    std::vector<std::string> stringFilePaths = Service::convertToString(systemFilePaths);
    packets1 = Service::getAllPackets(stringFilePaths);
    
    bool flag = true;
    while (flag && sessions.size() < 40)
    {
        SessionHelper session(packets1);
        if (session.isSession())
            sessions.push_back(session);
        else
            flag = false;
    }

    //std::thread th(&findUnusingPackets, packets1);

    int min = sessions[0].getTimeStart();
    int max = (sessions[0].getTimeEnd() + sessions[0].getTimeStart());
    for each (SessionHelper session in sessions)
    {
        if (session.getTimeStart() < min)
            min = session.getTimeStart();
        if ((session.getTimeEnd() + session.getTimeStart()) > max)
            max = session.getTimeEnd() + session.getTimeStart();
    }

    trackBar1->Maximum = 41;
    trackBar2->Maximum = max - min;

    // Set automatic zooming
    chart1->ChartAreas[0]->AxisX->ScaleView->Zoomable = true;
    chart1->ChartAreas[0]->AxisY->ScaleView->Zoomable = true;

    //// Set automatic scrolling 
    chart1->ChartAreas[0]->CursorX->AutoScroll = true;
    chart1->ChartAreas[0]->CursorY->AutoScroll = true;

    //// Allow user selection for Zoom
    chart1->ChartAreas[0]->CursorX->IsUserSelectionEnabled = true;
    chart1->ChartAreas[0]->CursorY->IsUserSelectionEnabled = true;
    for each (SessionHelper session in sessions)
    {  
        String^ temp = i.ToString();
        chart1->Series->Add(temp);
        chart1->Series[temp]->LabelToolTip = "Номер: " + temp + " Начало: " + session.getTimeStart() + " Конец: " + (session.getTimeEnd()+session.getTimeStart());
        chart1->Series[temp]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::RangeBar;
        chart1->Series[temp]->BorderColor = chart1->Series[temp]->Color;
        chart1->Series[temp]->BorderWidth = 5;
        chart1->Series[temp]->Points->AddXY(i++, session.getTimeStart() - min, session.getTimeEnd() + session.getTimeStart() - min);
        chart1->Series[temp]->ToolTip = "Номер: " + temp + " Начало: " + (session.getTimeStart() - min) + " Конец: " + (session.getTimeEnd() + session.getTimeStart() - min);
        chart1->Series[temp]->LegendToolTip = "Номер: " + temp + " Начало: " + (session.getTimeStart() - min) + " Конец: " + (session.getTimeEnd() + session.getTimeStart() - min);
    }
    //th.join();
}

void curseProject1::Sessions::startFinding()
{
    findUnusingPackets(packets1);
}

System::Void curseProject1::Sessions::назадToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->thread->Join();
    sessions.clear();
    packets1.clear();
    this->Close();
    this->DialogResult = System::Windows::Forms::DialogResult::OK;
    return System::Void();
}

System::Void curseProject1::Sessions::trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    chart1->Series->Clear();
    chart1->ChartAreas[0]->AxisX->ScaleView->Size = trackBar1->Maximum - trackBar1->Value;
    this->thread->Join();
    startDrawingSessions(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Sessions::trackBar2_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    chart1->Series->Clear();
    chart1->ChartAreas[0]->AxisY->ScaleView->Size = trackBar2->Maximum - trackBar2->Value;
    this->thread->Join();
    startDrawingSessions(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Sessions::button1_Click(System::Object^ sender, System::EventArgs^ e)
{   
    chart1->Series->Clear();
    chart1->ChartAreas[0]->AxisX->ScaleView->ZoomReset();
    chart1->ChartAreas[0]->AxisY->ScaleView->ZoomReset();
    trackBar1->Value = trackBar1->Minimum;
    trackBar2->Value = trackBar2->Minimum;
    this->thread->Join();
    startDrawingSessions(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Sessions::trackBar1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    chart1->Series->Clear();
    chart1->ChartAreas[0]->AxisX->ScaleView->Size = trackBar1->Maximum - trackBar1->Value;
    this->thread->Join();
    startDrawingSessions(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Sessions::trackBar2_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    chart1->Series->Clear();
    chart1->ChartAreas[0]->AxisY->ScaleView->Size = trackBar2->Maximum - trackBar2->Value;
    this->thread->Join();
    startDrawingSessions(systemFilePaths);
    return System::Void();
}

System::Void curseProject1::Sessions::Sessions_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
    this->thread->Join();
    return System::Void();
}
