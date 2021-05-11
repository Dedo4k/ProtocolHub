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
	std::vector<PacketHelper>::iterator it = packets.begin();
	while (it != packets.end())
	{
		if (!it->inSession())
		{
			packets.erase(it);
			it=packets.begin();
		}
		else
			++it;
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