#pragma once
#include<iostream>

std::string& Convert_String_to_string(System::String^ s, std::string& os);		//конвертируем System::String^ в std::string
System::String^ Convert_string_to_String(std::string& os, System::String^ s);	//конвертируем std::string в System::String^
std::string& Convert_String_to_string(System::String^ s);						//конвертируем System::String^ в std::string
System::String^ Convert_string_to_String(std::string& os);						//конвертируем std::string в System::String^
char* Convert_String_to_char(System::String^ string);							//конвертируем System::String^ в char*
