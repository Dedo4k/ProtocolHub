#include "FirstForm.h"
#include "Form1.h"
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main() {

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    curseProject1::Form1 form; //WinFormsTest - имя вашего проекта
    Application::Run(% form);
}