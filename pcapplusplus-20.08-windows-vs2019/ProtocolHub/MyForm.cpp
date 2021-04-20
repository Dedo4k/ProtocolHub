#include "MyForm.h"
#include <IPv4Layer.h>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Project3::MyForm form; //WinFormsTest - имя вашего проекта
    Application::Run(% form);
}