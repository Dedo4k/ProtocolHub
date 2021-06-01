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
#include "DataClass.h"


int sessPages = 0;
int sessPage = 0;
int sessCounter = 50;
int a1 = 0;


//std::vector<PacketHelper> packets1;                                                                         //вектор пакетов
//std::vector<SessionHelper> sessions1;                                                                       //вектор сессий

/*
Выделяет линию на диаграмме и ячейку в таблице красным цветом если соответствующая сессия является Handshake
Задаёт ширину линий диаграммы
*/
void curseProject1::Sessions::drawHandshake()
{
    int i = 0;
    for each (SessionHelper session in sess)                                                           //Проходим по всем сессиям
    {
        if (session.isHandshake())                                                                          //Проверяем если Handshake
        {
            if (i < dataGridView1->Rows->Count)
            {
                dataGridView1->Rows[i]->Cells[0]->Style->BackColor = System::Drawing::Color::Red;
                //chart1->Series[sess.size() - 1 - i]->Color = System::Drawing::Color::Red;
            }
        }
        if (i < chart1->Series->Count)
        {
            //chart1->Series[i]->CustomProperties = "PixelPointWidth = 200";                                  // оптимально чтобы влезли все 40 желательно 200
        }
        i++;
    }
}

/*
Формирует из вектора пакетов вектор сессий
Выводит сессии в соответсвии с выставленными фильтрами
*/
void curseProject1::Sessions::startDrawingSessions(System::Collections::ArrayList^ systemFilePaths)
{
    int i = 0, filter = 0;// , min, max;
    bool flag = true;
    std::vector<std::string> stringFilePaths = Service::convertToString(systemFilePaths);
    //packets1 = Service::getAllPackets(stringFilePaths);                                                     //получаем вектор пакетов
    //sessions1.clear();
    //sess.clear();
    sessBytes.clear();
    counter1 = 0;
    counter2 = 1;
    counter3 = 2;
    counter4 = 3;
    packetCounter1 = 0;
    packetCounter2 = 0;
    packetCounter3 = 0;
    packetCounter4 = 0;
    if (sess.empty())
    {
        while (flag)                                                                   //формируем вектор сессий
        {
            SessionHelper session(pack);
            if (session.isSession())
                sess.push_back(session);
            else
                flag = false;
        }

        for (size_t i = 0; i < sess.size(); i++)
            sess[i].setNum(i);

        if (sess.size())                                                                                   //задаём начальные значения для min и max
        {
            min = sess[0].getTimeStart();
            max = (sess[0].getTimeEnd() + sess[0].getTimeStart());
        }

        for each (SessionHelper session in sess)                                                           //находим минимальное и максимальное значение времени среди сессий
        {
            if (session.getTimeStart() < min)
                min = session.getTimeStart();
            if ((session.getTimeEnd() + session.getTimeStart()) > max)
                max = session.getTimeEnd() + session.getTimeStart();
        }
    }

    sessPages = sess.size() / sessCounter;

    comboBox1->Items->Clear();
    for (size_t i = 0; i < sessPages+1; i++)
    {
        comboBox1->Items->Add(i);
    }
    a1 = 1;
    comboBox1->SelectedIndex = sessPage;
    a1 = 0;

    trackBar1->Maximum = 50;                                                                                //задаём значения для trackBar
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

    for (size_t i = 0; i < filters->Count; i++)                                                             //получаем количество выставленных фильтров
    {
        if (filters[i]->Equals("True") && i<6)
            filter++;
    }

    if (filters->Count && filters[7]->Equals("True"))                                                       //сортируем по времени начала 
    {                                                     
        sortByTimeStart(sess);
    }
    else if (filters->Count && filters[8]->Equals("True"))                                                  //сортируем по количеству байт
    {
        sortByByte(sess);
    }
    int k = 1;
    int q = 0;
    for each (SessionHelper session in sess)                                                           //выводим сессии согласно выставленным фильтрам
    {  
        if (q < sessPage * sessCounter) 
        {
            q++;
            continue;
        }
        if (k > sessCounter)
            break;
        if (filter) {                                                                                       //если "filter=0" то выводит все сессии
            //int counter = filter;                                                                         //иначе смотрим какие фильтры выставлены
            int counter = 0;
            if ((filters[0]->Equals("True")) && session.isTcp()) {                                          //если TCP
                //counter--;
                counter++;
            }
            if ((filters[1]->Equals("True")) && session.isUdp()) {                                          //если UDP
                //counter--;
                counter++;
            }
            if ((filters[2]->Equals("True")) && session.isTls()) {                                          //если TLS
                //counter--;
                counter++;
            }
            if ((filters[3]->Equals("True")) && session.isDns()) {                                          //если DNS
                //counter--;
                counter++;
            }
            if ((filters[4]->Equals("True")) && session.isHttp()) {                                         //если HTTP
                //counter--;
                counter++;
            }
            if ((filters[5]->Equals("True")) && session.isSip()) {                                          //если SIP
                //counter--;
                counter++;
            }
            if (counter) {                                                                                  //если хотя бы один из протоколов есть в сессии, то выводим
                sessBytes.push_back(session);
                String^ temp = session.getNum().ToString();
                chart1->Series->Add(temp);
                //chart1->Series[temp]->CustomProperties = "PixelPointWidth = 200";
                chart1->Series[temp]->LabelToolTip = "Номер: " + temp + " Начало: " + (session.getTimeStart() - min) + " Конец: " + (session.getTimeEnd() + session.getTimeStart() - min) +
                                                     //"\nРазмер: " + session.getBytes().length() +
                                                     "\nHandshake: " + session.isHandshake() +
                                                     "\nTCP: " + session.isTcp() +
                                                     "\nUDP: " + session.isUdp() +
                                                     "\nTLS: " + session.isTls() +
                                                     "\nDNS: " + session.isDns() +
                                                     "\nHTTP: " + session.isHttp() +
                                                     "\nSIP: " + session.isSip();
                chart1->Series[temp]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::RangeBar;
                chart1->Series[temp]->Points->AddXY(i++, session.getTimeStart() - min, session.getTimeEnd() + session.getTimeStart() - min);
                chart1->Series[temp]->ToolTip = "Номер: " + temp + " Начало: " + (session.getTimeStart() - min) + " Конец: " + (session.getTimeEnd() + session.getTimeStart() - min) +
                                                //"\nРазмер: " + session.getBytes().length() +
                                                "\nHandshake: " + session.isHandshake() +
                                                "\nTCP: " + session.isTcp() +
                                                "\nUDP: " + session.isUdp() +
                                                "\nTLS: " + session.isTls() +
                                                "\nDNS: " + session.isDns() +
                                                "\nHTTP: " + session.isHttp() +
                                                "\nSIP: " + session.isSip();

                int a = dataGridView1->Rows->Add();
                dataGridView1->Rows[a]->Cells[0]->Value = session.getNum();
                dataGridView1->Rows[a]->Cells[0]->ToolTipText = "Номер: " + temp + " Начало: " + (session.getTimeStart() - min) + " Конец: " + (session.getTimeEnd() + session.getTimeStart() - min) +
                                                                //"\nРазмер: " + session.getBytes().length() +
                                                                "\nHandshake: " + session.isHandshake() +
                                                                "\nTCP: " + session.isTcp() +
                                                                "\nUDP: " + session.isUdp() +
                                                                "\nTLS: " + session.isTls() +
                                                                "\nDNS: " + session.isDns() +
                                                                "\nHTTP: " + session.isHttp() +
                                                                "\nSIP: " + session.isSip();
                k++;
                continue;
            }
            else continue;
        }
        sessBytes.push_back(session);
        String^ temp = session.getNum().ToString();
        chart1->Series->Add(temp);
        chart1->Series[temp]->LabelToolTip = "Номер: " + temp + " Начало: " + (session.getTimeStart() - min) + " Конец: " + (session.getTimeEnd() + session.getTimeStart() - min) +
                                                //"\nРазмер: " + session.getBytes().length() +
                                                "\nHandshake: " + session.isHandshake() +
                                                "\nTCP: " + session.isTcp() +
                                                "\nUDP: " + session.isUdp() +
                                                "\nTLS: " + session.isTls() +
                                                "\nDNS: " + session.isDns() +
                                                "\nHTTP: " + session.isHttp() +
                                                "\nSIP: " + session.isSip();
        chart1->Series[temp]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::RangeBar;
        chart1->Series[temp]->Points->AddXY(i++, session.getTimeStart() - min, session.getTimeEnd() + session.getTimeStart() - min);
        chart1->Series[temp]->ToolTip = "Номер: " + temp + " Начало: " + (session.getTimeStart() - min) + " Конец: " + (session.getTimeEnd() + session.getTimeStart() - min) +
                                        //"\nРазмер: " + session.getBytes().length() +
                                        "\nHandshake: " + session.isHandshake() +
                                        "\nTCP: " + session.isTcp() +
                                        "\nUDP: " + session.isUdp() +
                                        "\nTLS: " + session.isTls() +
                                        "\nDNS: " + session.isDns() +
                                        "\nHTTP: " + session.isHttp() +
                                        "\nSIP: " + session.isSip();

        int a = dataGridView1->Rows->Add();
        dataGridView1->Rows[a]->Cells[0]->Value = session.getNum();
        dataGridView1->Rows[a]->Cells[0]->ToolTipText = "Номер: " + temp + " Начало: " + (session.getTimeStart() - min) + " Конец: " + (session.getTimeEnd() + session.getTimeStart() - min) +
                                                        //"\nРазмер: " + session.getBytes().length() +
                                                        "\nHandshake: " + session.isHandshake() +
                                                        "\nTCP: " + session.isTcp() +
                                                        "\nUDP: " + session.isUdp() +
                                                        "\nTLS: " + session.isTls() +
                                                        "\nDNS: " + session.isDns() +
                                                        "\nHTTP: " + session.isHttp() +
                                                        "\nSIP: " + session.isSip();
        k++;
    }
}

/*
Возвращает список полученных путей
*/
System::Collections::ArrayList^ curseProject1::Sessions::getSystemFilePaths()
{
    return systemFilePaths;
}

/*
Вызывает функцию удаления неиспользуемых пакетов
*/
void curseProject1::Sessions::startFinding()
{
    findUnusingPackets(pack);
}

/*
Задаёт список выставленных фильтров
*/
void curseProject1::Sessions::setFilters(System::Collections::ArrayList^ filters)
{
    this->filters = filters;
}

/*
Закрывает текущее окно при нажатии на кнопку "Назад" из пенели меню и открывает окно для работы с пакетами
*/
System::Void curseProject1::Sessions::назадToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    //sess.clear();
    //pack.clear();
    this->Close();
    this->DialogResult = System::Windows::Forms::DialogResult::OK;
    return System::Void();
}

/*
Открывает окно фильтров при нажатии на кнопку "Фильтры" из панели меню
*/
System::Void curseProject1::Sessions::фильтрыToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Filters^ filters = gcnew Filters(this->filters);
    filters->ShowDialog(this);
    return System::Void();
}

/*
Открывает окно с байтовкой при нажатии на кнопку "Байтовка" из панели меню
*/
System::Void curseProject1::Sessions::байтовкаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Bytes^ bytes = gcnew Bytes(this->systemFilePaths);
    bytes->ShowDialog(this);
    return System::Void();
}

/*
Закрывает приложение при нажатии на кнопку "Закрыть приложение" из панели меню
*/
System::Void curseProject1::Sessions::закрытьПриложениеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Environment::Exit(0);
    return System::Void();
}

/*
Изменяет масштаб сессий при прокрутке "trackBar1"
*/
System::Void curseProject1::Sessions::trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    chart1->ChartAreas[0]->AxisX->ScaleView->Size = trackBar1->Maximum - trackBar1->Value;
    return System::Void();
}

/*
Изменяет масштаб времени при прокрутке "trackBar2"
*/
System::Void curseProject1::Sessions::trackBar2_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    chart1->ChartAreas[0]->AxisY->ScaleView->Size = trackBar2->Maximum - trackBar2->Value;
    return System::Void();
}

/*
Изменяет масштаб сессий при прокрутке "trackBar1"
*/
System::Void curseProject1::Sessions::trackBar1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    chart1->ChartAreas[0]->AxisX->ScaleView->Size = trackBar1->Maximum - trackBar1->Value;
    return System::Void();
}

/*
Изменяет масштаб времени при прокрутке "trackBar2"
*/
System::Void curseProject1::Sessions::trackBar2_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
    chart1->ChartAreas[0]->AxisY->ScaleView->Size = trackBar2->Maximum - trackBar2->Value;
    return System::Void();
}

/*
Восстанавливает масштабирование при нажатии на кнопку "button1"
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
Вызывает функцию удаления неиспоьзуемых пакетов
Открывает окно с информацией
*/
System::Void curseProject1::Sessions::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("Подожите пока не удалятся все неиспользуемые пакеты.", "Внимание!");
    
    findUnusingPackets(pack);
    return System::Void();
}

/*
Задаёт ширину линий диаграммы при её масштабировании
*/
System::Void curseProject1::Sessions::chart1_AxisViewChanged(System::Object^ sender, System::Windows::Forms::DataVisualization::Charting::ViewEventArgs^ e)
{
    //for (size_t i = 0; i < chart1->Series->Count; i++)
    //{
    //    //chart1->Series[i]->CustomProperties = "PixelPointWidth = 200";
    //}
    return System::Void();
}

System::Void curseProject1::Sessions::comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (!a1) 
    {
        sessPage = comboBox1->SelectedIndex;
        startDrawingSessions(systemFilePaths);
    }
    return System::Void();
}

System::Void curseProject1::Sessions::comboBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
    if (e->KeyChar == (int)Keys::Enter) {
        e->Handled = true;
        int input = Convert::ToInt16(comboBox1->Text);
        if (input>=0 && input <=sessPages) {
            sessPage = input;
            comboBox1->SelectedIndex = input;
            startDrawingSessions(systemFilePaths);
        }
    }
    return System::Void();
}
