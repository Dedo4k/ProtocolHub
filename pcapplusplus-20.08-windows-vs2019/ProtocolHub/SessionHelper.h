#pragma once
#include "PacketHelper.h"

class SessionHelper
{
private:
	//name of app
	std::string appName = "";
	//number of session
	size_t num;
	//source ip
	pcpp::IPAddress srcIp;
	//destination ip
	pcpp::IPAddress dstIp;
	//source port
	int srcPort;
	//desination port
	int dstPort;
	//seconds of start
	int timeStart = 86400;
	//seconds from "timeStart" of end
	size_t timeEnd=0;
	//vector of packets
	std::vector<PacketHelper> packets;
	//vector of bytes
	std::vector<std::string> bytes;
	//flags
	bool is = true;
	bool tcp = false;
	bool http = false;
	bool tls = false;
	bool udp = false;
	bool dns = false;
	bool sip = false;
	bool handshake = false;
public:
	SessionHelper(std::vector<PacketHelper> &packets);
	
	std::string getAppName();
	void setNum(size_t value);
	size_t getNum();
	pcpp::IPAddress getSrcIp();
	pcpp::IPAddress getDstIp();
	int getSrcPort();
	int getDstPort();
	int getTimeStart();
	size_t getTimeEnd();
	std::vector<PacketHelper> getPackets();
	std::vector<std::string> getBytes();
	bool isSession();
	bool isTcp();
	bool isHttp();
	bool isTls();
	bool isUdp();
	bool isDns();
	bool isSip();
	bool isHandshake();
};

