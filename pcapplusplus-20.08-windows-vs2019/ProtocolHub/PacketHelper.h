#pragma once
#include <Packet.h>
#include <Layer.h>
#include <PcapFileDevice.h>
#include <SystemUtils.h>

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
	//source ip
	pcpp::IPAddress srcIp;
	//destenation ip
	pcpp::IPAddress dstIp;
	//source port
	int srcPort;
	//destination port
	int dstPort;
	//timestamp
	tm timestamp;
	//assigned ip number
	int AIPN;
	//name of protocol (with AIPN)
	std::string protocolName;
	//info as string about all protocols
	std::vector<std::string> protocols;
	//flag is it object is part of session
	bool session = false;
	//flags
	bool tcp = false;
	bool http = false;
	bool tls = false;
	bool udp = false;
	bool dns = false;
	bool sip = false;
	bool handshake = false;
public:
	PacketHelper(pcpp::RawPacket& _rawPacket);

	PacketHelper(pcpp::Packet& _parsedPacket);

	void parseBasicInfo();

	void setProtocolNameWithAIPN();

	void parseAllInfo();

	pcpp::RawPacket* getPacketRaw();
	pcpp::Packet getParsedPacket();
	pcpp::IPAddress getSrcIp();
	pcpp::IPAddress getDstIp();
	int getSrcPort();
	int getDstPort();
	tm getTimestamp();
	std::string getTimestampAsString();
	int getAIPN();
	std::string getProtocolName();
	std::vector<std::string> getProtocols();
	bool inSession();
	void setSession(bool value);
	bool isTcp();
	bool isHttp();
	bool isTls();
	bool isUdp();
	bool isDns();
	bool isSip();
	bool isHandshake();
};