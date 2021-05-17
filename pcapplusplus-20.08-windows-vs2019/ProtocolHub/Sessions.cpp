#include "Sessions.h"
#include "Service.h"
#include "ConvertFunc.h"
#include "PacketHelper.h"
#include "SessionHelper.h"
#include "findFunc.h"
#include <thread>
#include "Form2.h"
#include "Filters.h"
#include "Bytes.h"
#include "SortFunc.h"

std::vector<PacketHelper> packets1;                                                                         //������ �������
std::vector<SessionHelper> sessions1;                                                                       //������ ������

/*
�������� ����� �� ��������� � ������ � ������� ������� ������ ���� ��������������� ������ �������� Handshake
����� ������ ����� ���������
*/
void curseProject1::Sessions::drawHandshake()
{
    int i = 0;
    for each (SessionHelper session in sessions1)                                                           //�������� �� ���� �������
    {
        if (session.isHandshake())                                                                          //��������� ���� Handshake
        {
            if (i < dataGridView1->Rows->Count)
            {
                dataGridView1->Rows[i]->Cells[0]->Style->BackColor = System::Drawing::Color::Red;
                chart1->Series[sessions1.size() - 1 - i]->Color = System::Drawing::Color::Red;
            }
        }
        if (i < chart1->Series->Count)
        {
            chart1->Series[i]->CustomProperties = "PixelPointWidth = 200";                                  // ���������� ����� ������ ��� 40 ���������� 200
        }
        i++;
    }
}

/*
��������� �� ������� ������� ������ ������
������� ������ � ����������� � ������������� ���������
*/
void curseProject1::Sessions::startDrawingSessions(System::Collections::ArrayList^ systemFilePaths)
{

    int i = 0, filter = 0, min, max;
    bool flag = true;
    std::vector<std::string> stringFilePaths = Service::convertToString(systemFilePaths);
    packets1 = Service::getAllPackets(stringFilePaths);                                                     //�������� ������ �������
    sessions1.clear();
    while (flag && sessions1.size() < 40)                                                                   //��������� ������ ������ �� ������ 40
    {
        SessionHelper session(packets1);
        if (session.isSession())
            sessions1.push_back(session);
        else
            flag = false;
    }

    if (sessions1.size())                                                                                   //����� ��������� �������� ��� min � max
    {
        min = sessions1[0].getTimeStart();
        max = (sessions1[0].getTimeEnd() + sessions1[0].getTimeStart());
    }

    for each (SessionHelper session in sessions1)                                                           //������� ����������� � ������������ �������� ������� ����� ������
    {
        if (session.getTimeStart() < min)
            min = session.getTimeStart();
        if ((session.getTimeEnd() + session.getTimeStart()) > max)
            max = session.getTimeEnd() + session.getTimeStart();
    }

    trackBar1->Maximum = 42;                                                                                //����� �������� ��� trackBar
    trackBar2->Maximum = max - min;
    
    chart1->ChartAreas[0]->AxisX->ScaleView->Zoomable = true;                                               // Set automatic zooming
    chart1->ChartAreas[0]->AxisY->ScaleView->Zoomable = true;

    chart1->ChartAreas[0]->CursorX->AutoScroll = true;                                                      // Set automatic scrolling 
    chart1->ChartAreas[0]->CursorY->AutoScroll = true;

    chart1->ChartAreas[0]->CursorX->IsUserSelectionEnabled = true;                                          // Allow user selection for Zoom
    chart1->ChartAreas[0]->CursorY->IsUserSelectionEnabled = true;
    
    dataGridView1->Columns[0]->DefaultCellStyle->Alignment = System::Windows::Forms::DataGridViewContentAlignment::BottomCenter;
    dataGridView1->Rows->Clear();
    chart1->Series->Clear();

    for (size_t i = 0; i < filters->Count; i++)                                                             //�������� ���������� ������������ ��������
    {
        if (filters[i]->Equals("True") && i<6)
            filter++;
    }

    if (filters->Count && filters[7]->Equals("True"))                                                       //��������� �� ������� ������ 
    {                                                     
        sortByTimeStart(sessions1);
    }
    else if (filters->Count && filters[8]->Equals("True"))                                                  //��������� �� ���������� ����
    {
        sortByByte(sessions1);
    }

    for each (SessionHelper session in sessions1)                                                           //������� ������ �������� ������������ ��������
    {  
        if (filter) {                                                                                       //���� "filter=0" �� ������� ��� ������
            //int counter = filter;                                                                         //����� ������� ����� ������� ����������
            int counter = 0;
            if ((filters[0]->Equals("True")) && session.isTcp()) {                                          //���� TCP
                //counter--;
                counter++;
            }
            if ((filters[1]->Equals("True")) && session.isUdp()) {                                          //���� UDP
                //counter--;
                counter++;
            }
            if ((filters[2]->Equals("True")) && session.isTls()) {                                          //���� TLS
                //counter--;
                counter++;
            }
            if ((filters[3]->Equals("True")) && session.isDns()) {                                          //���� DNS
                //counter--;
                counter++;
            }
            if ((filters[4]->Equals("True")) && session.isHttp()) {                                         //���� HTTP
                //counter--;
                counter++;
            }
            if ((filters[5]->Equals("True")) && session.isSip()) {                                          //���� SIP
                //counter--;
                counter++;
            }
            if (counter) {                                                                                  //���� ���� �� ���� �� ���������� ���� � ������, �� �������
                String^ temp = i.ToString();
                chart1->Series->Add(temp);
                chart1->Series[temp]->CustomProperties = "PixelPointWidth = 200";
                chart1->Series[temp]->LabelToolTip = "�����: " + temp + " ������: " + (session.getTimeStart() - min) + " �����: " + (session.getTimeEnd() + session.getTimeStart() - min) +
                                                     "\n������: " + session.getBytes().length() +
                                                     "\nHandshake: " + session.isHandshake() +
                                                     "\nTCP: " + session.isTcp() +
                                                     "\nUDP: " + session.isUdp() +
                                                     "\nTLS: " + session.isTls() +
                                                     "\nDNS: " + session.isDns() +
                                                     "\nHTTP: " + session.isHttp() +
                                                     "\nSIP: " + session.isSip();
                chart1->Series[temp]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::RangeBar;
                chart1->Series[temp]->Points->AddXY(i, session.getTimeStart() - min, session.getTimeEnd() + session.getTimeStart() - min);
                chart1->Series[temp]->ToolTip = "�����: " + temp + " ������: " + (session.getTimeStart() - min) + " �����: " + (session.getTimeEnd() + session.getTimeStart() - min) +
                                                "\n������: " + session.getBytes().length() +
                                                "\nHandshake: " + session.isHandshake() +
                                                "\nTCP: " + session.isTcp() +
                                                "\nUDP: " + session.isUdp() +
                                                "\nTLS: " + session.isTls() +
                                                "\nDNS: " + session.isDns() +
                                                "\nHTTP: " + session.isHttp() +
                                                "\nSIP: " + session.isSip();

                int a = dataGridView1->Rows->Add();
                dataGridView1->Rows[a]->Cells[0]->Value = i++;
                dataGridView1->Rows[a]->Cells[0]->ToolTipText = "�����: " + temp + " ������: " + (session.getTimeStart() - min) + " �����: " + (session.getTimeEnd() + session.getTimeStart() - min) +
                                                                "\n������: " + session.getBytes().length() +
                                                                "\nHandshake: " + session.isHandshake() +
                                                                "\nTCP: " + session.isTcp() +
                                                                "\nUDP: " + session.isUdp() +
                                                                "\nTLS: " + session.isTls() +
                                                                "\nDNS: " + session.isDns() +
                                                                "\nHTTP: " + session.isHttp() +
                                                                "\nSIP: " + session.isSip();
                continue;
            }
            else continue;
        }
        String^ temp = i.ToString();
        chart1->Series->Add(temp);
        chart1->Series[temp]->LabelToolTip = "�����: " + temp + " ������: " + (session.getTimeStart() - min) + " �����: " + (session.getTimeEnd() + session.getTimeStart() - min) +
                                                "\n������: " + session.getBytes().length() +
                                                "\nHandshake: " + session.isHandshake() +
                                                "\nTCP: " + session.isTcp() +
                                                "\nUDP: " + session.isUdp() +
                                                "\nTLS: " + session.isTls() +
                                                "\nDNS: " + session.isDns() +
                                                "\nHTTP: " + session.isHttp() +
                                                "\nSIP: " + session.isSip();
        chart1->Series[temp]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::RangeBar;
        chart1->Series[temp]->Points->AddXY(i, session.getTimeStart() - min, session.getTimeEnd() + session.getTimeStart() - min);
        chart1->Series[temp]->ToolTip = "�����: " + temp + " ������: " + (session.getTimeStart() - min) + " �����: " + (session.getTimeEnd() + session.getTimeStart() - min) +
                                        "\n������: " + session.getBytes().length() +
                                        "\nHandshake: " + session.isHandshake() +
                                        "\nTCP: " + session.isTcp() +
                                        "\nUDP: " + session.isUdp() +
                                        "\nTLS: " + session.isTls() +
                                        "\nDNS: " + session.isDns() +
                                        "\nHTTP: " + session.isHttp() +
                                        "\nSIP: " + session.isSip();

        int a = dataGridView1->Rows->Add();
        dataGridView1->Rows[a]->Cells[0]->Value = i++;
        dataGridView1->Rows[a]->Cells[0]->ToolTipText = "�����: " + temp + " ������: " + (session.getTimeStart() - min) + " �����: " + (session.getTimeEnd() + session.getTimeStart() - min) +
                                                        "\n������: " + session.getBytes().length() +
                                                        "\nHandshake: " + session.isHandshake() +
                                                        "\nTCP: " + session.isTcp() +
                                                        "\nUDP: " + session.isUdp() +
                                                        "\nTLS: " + session.isTls() +
                                                        "\nDNS: " + session.isDns() +
                                                        "\nHTTP: " + session.isHttp() +
                                                        "\nSIP: " + session.isSip();
    }
}

/*
���������� ������ ���������� �����
*/
System::Collections::ArrayList^ curseProject1::Sessions::getSystemFilePaths()
{
    return systemFilePaths;
}

/*
�������� ������� �������� �������������� �������
*/
void curseProject1::Sessions::startFinding()
{
    findUnusingPackets(packets1);
}

/*
����� ������ ������������ ��������
*/
void curseProject1::Sessions::setFilters(System::Collections::ArrayList^ filters)
{
    this->filters = filters;
}

/*
��������� ������� ���� ��� ������� �� ������ "�����" �� ������ ���� � ��������� ���� ��� ������ � ��������
*/
System::Void curseProject1::Sessions::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    sessions1.clear();
    packets1.clear();
    this->Close();
    this->DialogResult = System::Windows::Forms::DialogResult::OK;
    return System::Void();
}

/*
��������� ���� �������� ��� ������� �� ������ "�������" �� ������ ����
*/
System::Void curseProject1::Sessions::�������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Filters^ filters = gcnew Filters(this->filters);
    filters->ShowDialog(this);
    return System::Void();
}

/*
��������� ���� � ��������� ��� ������� �� ������ "��������" �� ������ ����
*/
System::Void curseProject1::Sessions::��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Bytes^ bytes = gcnew Bytes(this->systemFilePaths);
    bytes->ShowDialog(this);
    return System::Void();
}

/*
��������� ���������� ��� ������� �� ������ "������� ����������" �� ������ ����
*/
System::Void curseProject1::Sessions::�����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Environment::Exit(0);
    return System::Void();
}

/*
�������� ������� ������ ��� ��������� "trackBar1"
*/
System::Void curseProject1::Sessions::trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    chart1->ChartAreas[0]->AxisX->ScaleView->Size = trackBar1->Maximum - trackBar1->Value;
    return System::Void();
}

/*
�������� ������� ������� ��� ��������� "trackBar2"
*/
System::Void curseProject1::Sessions::trackBar2_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    chart1->ChartAreas[0]->AxisY->ScaleView->Size = trackBar2->Maximum - trackBar2->Value;
    return System::Void();
}

/*
�������� ������� ������ ��� ��������� "trackBar1"
*/
System::Void curseProject1::Sessions::trackBar1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    chart1->ChartAreas[0]->AxisX->ScaleView->Size = trackBar1->Maximum - trackBar1->Value;
    return System::Void();
}

/*
�������� ������� ������� ��� ��������� "trackBar2"
*/
System::Void curseProject1::Sessions::trackBar2_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    chart1->ChartAreas[0]->AxisY->ScaleView->Size = trackBar2->Maximum - trackBar2->Value;
    return System::Void();
}

/*
��������������� ��������������� ��� ������� �� ������ "button1"
*/
System::Void curseProject1::Sessions::button1_Click(System::Object^ sender, System::EventArgs^ e)
{   
    chart1->ChartAreas[0]->AxisX->ScaleView->ZoomReset();
    chart1->ChartAreas[0]->AxisY->ScaleView->ZoomReset();
    trackBar1->Value = trackBar1->Minimum;
    trackBar2->Value = trackBar2->Minimum;
    return System::Void();
}

/*
�������� ������� �������� ������������� �������
��������� ���� � �����������
*/
System::Void curseProject1::Sessions::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("�������� ���� �� �������� ��� �������������� ������.", "��������!");
    
    findUnusingPackets(packets1);
    return System::Void();
}

/*
����� ������ ����� ��������� ��� � ���������������
*/
System::Void curseProject1::Sessions::chart1_AxisViewChanged(System::Object^ sender, System::Windows::Forms::DataVisualization::Charting::ViewEventArgs^ e)
{
    for (size_t i = 0; i < chart1->Series->Count; i++)
    {
        chart1->Series[i]->CustomProperties = "PixelPointWidth = 200";
    }
    return System::Void();
}
