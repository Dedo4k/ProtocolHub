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

//����� ��� ������ � ��������
class PacketHelper
{
private:
	//������������ �����
	pcpp::Packet parsedPacket;
	//���� ���������
	pcpp::IPAddress srcIp;
	//���� ���������
	pcpp::IPAddress dstIp;
	//���� ���������
	int srcPort;
	//���� ���������
	int dstPort;
	//��������� �����
	tm timestamp;
	//������������������ ���� �����
	int AIPN;
	//��� ���������
	std::string protocolName;
	//���������� � ����������
	std::vector<std::string> protocols;
	//�����
	bool session = false;
	bool tcp = false;
	bool http = false;
	bool tls = false;
	bool udp = false;
	bool dns = false;
	bool sip = false;
	bool handshake = false;
public:
	//�����������
	PacketHelper(pcpp::RawPacket& _rawPacket);
	//�����������
	PacketHelper(pcpp::Packet& _parsedPacket);
	//������� ����� ����������
	void parseBasicInfo();
	//��������� ����� ���������
	void setProtocolNameWithAIPN();
	//������� ���� ����������
	void parseAllInfo();
	//������ ����� �������� � �������� 
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
	//����� ����� �������� � ��������
};