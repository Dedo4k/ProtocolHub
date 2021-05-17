#include "findFunc.h"

//поиск минимального времени начала
int findStartPoint(std::vector<SessionHelper>& sessions)
{
	int result = 86400;

	for (size_t i = 0; i < sessions.size(); i++)
		if (sessions[i].getTimeStart() < result)
			result = sessions[i].getTimeStart();

	return result;
}

//поиск и удаление неиспользуемых пакетов
void findUnusingPackets(std::vector<PacketHelper>& packets)
{
	for (size_t i = 0; i < packets.size(); ++i)
		if (!packets[i].inSession())
		{
			packets.erase(packets.begin()+i);
			--i;
		}
}

//поиск позиций подстрок в байтах
std::vector<size_t> findSubstring(std::vector<SessionHelper>& sessions, std::string str)
{
	std::vector<size_t> result;
	for (size_t i = 0; i < sessions.size(); ++i)
	{
		size_t pos = sessions[i].getBytes().find(str);
		if (pos != std::string::npos)
			result.push_back(pos);
		else
			result.push_back(-1);
	}
	return result;
}

//поиск одинаовой позиции подстрок в байтах 
int findSubstringAt(std::vector<SessionHelper>& sessions, std::string str)
{
	std::vector<size_t> temp = findSubstring(sessions, str);
	size_t value = temp[0];
	for (size_t i = 0; i < temp.size(); ++i)
	{
		if (value != temp[i])
			return -1;
	}
	return value;
}

//запись пакетов в pcapng файл
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