#include "findFunc.h"

//find minimal time of start
int findStartPoint(std::vector<SessionHelper>& sessions)
{
	int result = 86400;

	for (size_t i = 0; i < sessions.size(); i++)
		if (sessions[i].getTimeStart() < result)
			result = sessions[i].getTimeStart();

	return result;
}

//find and delete packets, that unusing at sessions
void findUnusingPackets(std::vector<SessionHelper>& sessions)
{
	for (size_t i = 0; i < sessions.size(); ++i)
	{
		while (sessions[i].getPackets().size() > 40)
			sessions[i].deleteLastPacket();
	}
}

//find positions of substrings in sessions
std::vector<size_t> findSubstring(std::vector<std::string>& strings, std::string str)
{
	std::vector<size_t> result;
	for (size_t i = 0; i < strings.size(); ++i)
	{
		size_t pos = strings[i].find(str);
		if (pos != std::string::npos)
			result.push_back(pos);
		else
			result.push_back(-1);
	}
	return result;
}

//find position of substrings in sessions at the same position, returning -1 if not found
int findSubstringAt(std::vector<std::string>& strings, std::string str)
{
	std::vector<size_t> temp = findSubstring(strings, str);
	size_t value;
	if(temp.size())
		value = temp[0];
	for (size_t i = 0; i < temp.size(); ++i)
	{
		if (value != temp[i])
			return -1;
	}
	return value;
}

std::vector<bool> findMatch(std::vector<std::string>& strings)
{
	std::vector<bool> result;

	//if vector is empty
	if (strings.size() < 1) return;

	long maxSize = strings[0].size();
	long minSize = strings[0].size();
	long i = 0;

	//find min and max size
	for (int j; j < strings.size(); ++j)
	{
		if (strings[i].size() > maxSize)
			maxSize = strings[i].size();
		if (strings[i].size() < minSize)
			minSize = strings[i].size();
	}

	//compare symbols
	for (; i < minSize; ++i)
	{
		bool flag = true;
		char sym = strings[0][i];
		for (size_t j = 0; j < strings.size(); ++j)
			if (strings[j][i] != sym)
				flag = false;
		result.push_back(flag);
	}
	//if some elements more then another one, set match false
	for (; i < maxSize; ++i)
		result.push_back(false);

	return result;
}

void fwriteSessionsPcapng(std::string filepath, std::vector<SessionHelper>& sessions)
{
	pcpp::PcapNgFileWriterDevice writer(filepath.c_str());

	if (!writer.open())
	{
		std::cout << "File open error!\n";
		return;
	}

	for (size_t i = 0; i < sessions.size(); ++i)
	{
		for (size_t j = 0; j < sessions[i].getPackets().size(); ++j)
		{
			writer.writePacket(*sessions[i].getPackets()[j].getPacketRaw());
		}
	}
	writer.close();
}