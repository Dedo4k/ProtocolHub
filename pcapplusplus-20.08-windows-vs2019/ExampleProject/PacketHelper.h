#pragma once
#include <Packet.h>

#include <HTTPLayer.h>
#include <TcpLayer.h>
#include <UdpLayer.h>
#include <IPv4Layer.h>
#include <IPv6Layer.h>
#include <DNSLayer.h>
#include <SSLLayer.h>
#include <SipLayer.h>

#include <iostream>
#include <string>
#include <vector>
#include <iterator>

#include "outFunc.h"

//class for working with inteface
class PacketHelper
{
private:
	//parsed packet
	pcpp::Packet parsedPacket;
	//name of app
	std::string appName = "";
	//source ip
	pcpp::IPAddress srcIp;
	//destenation ip
	pcpp::IPAddress dstIp;
	//timestamp
	tm timestamp;
	//time to live
	int ttl;
	//assigned ip number
	int AIPN;
	//name of protocol (with AIPN)
	std::string protocolName;
	//first layer info
	std::string firstLayer;
	//info as string about all protocols
	std::vector<std::string> protocols;

public:
	PacketHelper(pcpp::RawPacket& _rawPacket);

	PacketHelper(pcpp::Packet& _parsedPacket);

	void parseBasicInfo();

	void setProtocolNameWithAIPN();

	void parseAllInfo();

	pcpp::RawPacket* getPacketRaw();
	pcpp::Packet getParsedPacket();
	std::string getAppName();
	pcpp::IPAddress getSrcIp();
	pcpp::IPAddress getDstIp();
	tm getTimestamp();
	int getTtl();
	int getAIPN();
	std::string getProtocolName();
	std::string getFirstLayer();
	std::vector<std::string> getProtocols();
};