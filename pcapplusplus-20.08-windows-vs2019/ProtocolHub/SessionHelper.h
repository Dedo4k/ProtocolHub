#pragma once
#include "PacketHelper.h"

class SessionHelper
{
private:
	//��� ����������
	std::string appName = "";
	//���� ���������
	pcpp::IPAddress srcIp;
	//���� ���������
	pcpp::IPAddress dstIp;
	//���� ���������
	int srcPort;
	//���� ���������
	int dstPort;
	//����� ������
	int timeStart = 86400;
	//����� ����� (���������� ������ ����� ������)
	size_t timeEnd=0;
	//������ ������
	std::vector<PacketHelper> packets;
	//����� ������
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
	//�����������
	SessionHelper(std::vector<PacketHelper> &packets);
	//������ ����� ��������
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
	//����� ����� ��������
};

