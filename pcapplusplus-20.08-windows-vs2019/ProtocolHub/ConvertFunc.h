#pragma once
#include<iostream>

std::string& Convert_String_to_string(System::String^ s, std::string& os);		//������������ System::String^ � std::string
System::String^ Convert_string_to_String(std::string& os, System::String^ s);	//������������ std::string � System::String^
std::string& Convert_String_to_string(System::String^ s);						//������������ System::String^ � std::string
System::String^ Convert_string_to_String(std::string& os);						//������������ std::string � System::String^
char* Convert_String_to_char(System::String^ string);							//������������ System::String^ � char*
