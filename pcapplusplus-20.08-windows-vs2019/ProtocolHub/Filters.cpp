#include "Filters.h"
#include "Sessions.h"

System::Void curseProject1::Filters::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    System::Collections::ArrayList^ filters = gcnew System::Collections::ArrayList;
    Sessions^ sessions = (Sessions^)this->Owner;
    for (size_t i = 0; i < checkedListBox1->Items->Count; i++)
    {
        filters->Add((checkedListBox1->GetItemChecked(i)).ToString());
    }
    sessions->setFilters(filters);
    sessions->startDrawingSessions(sessions->getSystemFilePaths());
    this->Close();
    this->DialogResult = System::Windows::Forms::DialogResult::OK;
}

System::Void curseProject1::Filters::checkBox1_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (checkBox1->Checked) {
        checkedListBox1->Enabled = false;
    }
    else {
        checkedListBox1->Enabled = true;
    }
    return System::Void();
}

System::Void curseProject1::Filters::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    if(checkedListBox1->Enabled)
    for (size_t i = 0; i < checkedListBox1->Items->Count; i++)
    {
        checkedListBox1->SetItemChecked(i, true);
    }
    return System::Void();
}

System::Void curseProject1::Filters::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    if(checkedListBox1->Enabled)
    for (size_t i = 0; i < checkedListBox1->Items->Count; i++)
    {
        checkedListBox1->SetItemChecked(i, false);
    }
    return System::Void();
}
