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

//класс для работы с пакетами
class PacketHelper
{
private:
	//распарсенный пакет
	pcpp::Packet parsedPacket;
	//айпи источника
	pcpp::IPAddress srcIp;
	//айпи приемника
	pcpp::IPAddress dstIp;
	//порт источника
	int srcPort;
	//порт приемника
	int dstPort;
	//временные рамки
	tm timestamp;
	//зарегистрированный айпи номер
	int AIPN;
	//имя протокола
	std::string protocolName;
	//информация о протоколах
	std::vector<std::string> protocols;
	//флаги
	bool session = false;
	bool tcp = false;
	bool http = false;
	bool tls = false;
	bool udp = false;
	bool dns = false;
	bool sip = false;
	bool handshake = false;
public:
	//конструктор
	PacketHelper(pcpp::RawPacket& _rawPacket);
	//конструктор
	PacketHelper(pcpp::Packet& _parsedPacket);
	//парсинг общей информации
	void parseBasicInfo();
	//получение имени протокола
	void setProtocolNameWithAIPN();
	//парсинг всей информации
	void parseAllInfo();
	//начало блока геттеров и сеттеров 
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
	//конец блока геттеров и сеттеров
};