#include "FirstForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    curseProject1::FirstForm form; //WinFormsTest - ��� ������ �������
    Application::Run(% form);
}