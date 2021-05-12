#include "SessionHelper.h"

SessionHelper::SessionHelper(std::vector<PacketHelper> &allpackets)
{
	bool flag = true;
	size_t iter = 0;
	//finding first packet for new session
	for (size_t i = 0; i < allpackets.size(); ++i)
	{
		if (!allpackets[i].inSession())
		{
			this->srcIp = allpackets[i].getSrcIp();
			this->dstIp = allpackets[i].getDstIp();
			this->srcPort = allpackets[i].getSrcPort();
			this->dstPort = allpackets[i].getDstPort();
			this->packets.push_back(allpackets[i]);
			iter = i + 1;
			allpackets[i].setSession(true);
			flag = false;
			break;
		}
	}
	//if no packets for new session
	if (flag == true)
	{
		is = false;
		return;
	}
	//finding another packets for this session
	for (size_t i = iter; i < allpackets.size(); ++i)
	{
		if (!allpackets[i].inSession())
		{
			if (srcIp == allpackets[i].getSrcIp() && dstIp == allpackets[i].getDstIp()
				&& srcPort == allpackets[i].getSrcPort() && dstPort == allpackets[i].getDstPort())
			{
				packets.push_back(allpackets[i]);
				allpackets[i].setSession(true);
			}
		}
	}
	//setting flags
	for (size_t i = 0; i < packets.size(); ++i)
	{
		if (packets[i].isDns())
			dns = true;
		if (packets[i].isHandshake())
			handshake = true;
		if (packets[i].isHttp())
			http = true;
		if (packets[i].isSip())
			sip = true;
		if (packets[i].isTcp())
			tcp = true;
		if (packets[i].isTls())
			tls = true;
		if (packets[i].isUdp())
			udp = true;
	}
	//setting timeStart
	tm time = packets[0].getTimestamp();
	for (size_t i = 0; i < packets.size(); i++)
	{
		if (packets[i].getTimestamp().tm_mday < time.tm_mday)
		{
			if (-1 * 24 * 60 * 60 - tmToSec(packets[i].getTimestamp()) < timeStart)
			{
				timeStart = -1 * 24 * 60 * 60 - tmToSec(packets[i].getTimestamp());
				time = packets[i].getTimestamp();
			}
		}
		else
		{
			if (tmToSec(packets[i].getTimestamp()) < timeStart)
			{
				timeStart = tmToSec(packets[i].getTimestamp());
				time = packets[i].getTimestamp();
			}
		}
	}
	//setting timeEnd
	time = packets[0].getTimestamp();
	for (size_t i = 0; i < packets.size(); i++)
	{
		if (timeStart < 0)
		{
			timeEnd = (-1* timeStart) + tmToSec(packets[i].getTimestamp());
			time = packets[i].getTimestamp();
		}
		else
		{
			if (tmToSec(packets[i].getTimestamp()) > timeStart)
			{
				timeEnd = tmToSec(packets[i].getTimestamp()) - timeStart;
				time = packets[i].getTimestamp();
			}
		}
	}
	if (timeEnd == timeStart)
		++timeEnd;
	//getting data as bytes
	for (size_t i = 0; i < packets.size(); ++i)
	{
		for (size_t j = 0; j < packets[i].getPacketRaw()->getRawDataLen(); ++j)
		{
			char ch = packets[i].getPacketRaw()->getRawData()[j];
			if (ch<257 && ch>-1)
				bytes += ch;
		}
	}
}

std::string SessionHelper::getAppName()
{
	return appName;
}
pcpp::IPAddress SessionHelper::getSrcIp()
{
	return srcIp;
}
pcpp::IPAddress SessionHelper::getDstIp()
{
	return dstIp;
}
int SessionHelper::getSrcPort()
{
	return srcPort;
}
int SessionHelper::getDstPort()
{
	return dstPort;
}
int SessionHelper::getTimeStart()
{
	return timeStart;
}
size_t SessionHelper::getTimeEnd()
{
	return timeEnd;
}
std::vector<PacketHelper> SessionHelper::getPackets()
{
	return packets;
}
std::string SessionHelper::getBytes()
{
	return bytes;
}
bool SessionHelper::isSession()
{
	return is;
}
bool SessionHelper::isTcp()
{
	return tcp;
}
bool SessionHelper::isHttp()
{
	return http;
}
bool SessionHelper::isTls()
{
	return tls;
}
bool SessionHelper::isUdp()
{
	return udp;
}
bool SessionHelper::isDns()
{
	return dns;
}
bool SessionHelper::isSip()
{
	return sip;
}
bool SessionHelper::isHandshake()
{
	return handshake;
}