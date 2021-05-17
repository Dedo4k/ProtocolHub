#pragma once
#include "PacketHelper.h"

class SessionHelper
{
private:
	//имя приложения
	std::string appName = "";
	//айпи источника
	pcpp::IPAddress srcIp;
	//айпи приемника
	pcpp::IPAddress dstIp;
	//порт источника
	int srcPort;
	//порт приемника
	int dstPort;
	//время начала
	int timeStart = 86400;
	//время конца (количество секунд после начала)
	size_t timeEnd=0;
	//пакеты сессии
	std::vector<PacketHelper> packets;
	//байты сессии
	std::string bytes;
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
	//конструктор
	SessionHelper(std::vector<PacketHelper> &packets);
	//начало блока геттеров
	std::string getAppName();
	pcpp::IPAddress getSrcIp();
	pcpp::IPAddress getDstIp();
	int getSrcPort();
	int getDstPort();
	int getTimeStart();
	size_t getTimeEnd();
	std::vector<PacketHelper> getPackets();
	std::string getBytes();
	bool isSession();
	bool isTcp();
	bool isHttp();
	bool isTls();
	bool isUdp();
	bool isDns();
	bool isSip();
	bool isHandshake();
	//конец блока геттеров
};

