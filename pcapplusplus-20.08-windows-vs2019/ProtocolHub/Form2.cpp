#include "Form2.h"
#include "Service.h"

void curseProject1::Form2::StartParsingFiles(System::Collections::ArrayList^ systemFilePaths)
{
    Service::parseFilesInList(systemFilePaths);
}

System::Void curseProject1::Form2::íàçàäToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
    this->DialogResult = System::Windows::Forms::DialogResult::OK;
    return System::Void();
}
