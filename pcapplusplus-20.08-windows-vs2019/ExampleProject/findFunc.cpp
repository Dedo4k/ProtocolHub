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
void findUnusingPackets(std::vector<PacketHelper>& packets)
{
	for (size_t i = 0; i < packets.size(); ++i)
		if (!packets[i].inSession())
		{
			packets.erase(packets.begin()+i);
			--i;
		}
}

//find positions of substrings in sessions
std::vector<size_t> findSubstring(std::vector<SessionHelper>& sessions, std::string str)
{
	std::vector<size_t> result;
	for (size_t i = 0; i < sessions.size(); ++i)
		for (size_t j = 0; j < sessions[j].getBytes().length() - str.length(); ++j)
			if (sessions[i].getBytes().substr(j, j + str.length()) == str)
				result.push_back(j);
	return result;
}

//find position of substrings in sessions at the same position, returning -1 if not found
int findSubstringAt(std::vector<SessionHelper>& sessions, std::string str)
{
	std::vector<size_t> temp = findSubstring(sessions, str);
	if (temp.size() != sessions.size())
		return -1;
	else
	{
		size_t value = temp[0];
		for (size_t i = 0; i < temp.size(); ++i)
		{
			if (value != temp[i])
				return -1;
		}
		return value;
	}
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