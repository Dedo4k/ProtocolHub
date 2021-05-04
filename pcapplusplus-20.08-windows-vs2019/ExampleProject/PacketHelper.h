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
	PacketHelper(pcpp::RawPacket& _rawPacket)
	{
		pcpp::Packet tempParsedPacket(&_rawPacket);
		parsedPacket = tempParsedPacket;
		parseAllInfo();
		parseBasicInfo();
	}

	PacketHelper(pcpp::Packet& _parsedPacket)
	{
		parsedPacket = _parsedPacket;
		parseAllInfo();
		parseBasicInfo();

	}

	void parseBasicInfo()
	{
		timespec temp = parsedPacket.getRawPacketReadOnly()->getPacketTimeStamp();
		localtime_s(&timestamp, &temp.tv_sec);
		setProtocolNameWithAIPN();
		firstLayer = parsedPacket.getFirstLayer()->toString();
	}

	void setProtocolNameWithAIPN()
	{
		switch (AIPN)
		{
		case 0:
			protocolName = "HOPOPT";
			break;
		case 1:
			protocolName = "ICMP";
			break;
		case 2:
			protocolName = "IGMP";
			break;
		case 4:
			protocolName = "IPIP";
			break;
		case 6:
			protocolName = "TCP";
			break;
		case 8:
			protocolName = "EGP";
			break;
		case 12:
			protocolName = "PUP";
			break;
		case 17:
			protocolName = "UDP";
			break;
		case 22:
			protocolName = "XNS-IDP";
			break;
		case 41:
			protocolName = "IPv6";
			break;
		case 43:
			protocolName = "IPv6-Route";
			break;
		case 44:
			protocolName = "IPv6-Frag";
			break;
		case 47:
			protocolName = "GRE";
			break;
		case 50:
			protocolName = "ESP";
			break;
		case 51:
			protocolName = "AH";
			break;
		case 58:
			protocolName = "IPv6-ICMP";
			break;
		case 59:
			protocolName = "IPv6-NoNxt";
			break;
		case 60:
			protocolName = "IPv6-Opts";
			break;
		default:
			protocolName = "Reserved";
			break;
		}
	}

	void parseAllInfo()
	{
		std::string temp;
		for (pcpp::Layer* lay = parsedPacket.getFirstLayer(); lay != NULL; lay = lay->getNextLayer())
		{
			switch (lay->getProtocol())
			{
			case pcpp::UDP:
			{
				pcpp::UdpLayer* udp = parsedPacket.getLayerOfType<pcpp::UdpLayer>();

				temp = "\t\tUDP\n";
				temp += "Source UDP port:" + std::to_string((int)ntohs(udp->getUdpHeader()->portSrc)) + '\n';
				temp += "Destination UDP port: " + std::to_string((int)ntohs(udp->getUdpHeader()->portDst)) + '\n';
				temp += "Length of header and playload in bytes: " + std::to_string((int)ntohs(udp->getUdpHeader()->length)) + '\n';
				temp += "CheckSum: " + std::to_string((int)ntohs(udp->getUdpHeader()->headerChecksum)) + '\n';
				break;
			}
			case pcpp::TCP:
			{
				pcpp::TcpLayer* tcp = parsedPacket.getLayerOfType<pcpp::TcpLayer>();

				temp = "\t\tTCP\n";
				temp += "Source TCP port: " + std::to_string((int)ntohs(tcp->getTcpHeader()->portSrc)) + '\n';
				temp += "Destination TCP port: " + std::to_string((int)ntohs(tcp->getTcpHeader()->portDst));
				temp += "Data offset: " + std::to_string((int)ntohs(tcp->getTcpHeader()->dataOffset)) + '\n';
				temp += "Reserved: " + std::to_string((int)ntohs(tcp->getTcpHeader()->reserved)) + '\n';
				temp += "TCP flags:" + printTcpFlags(tcp) + '\n';
				temp += "Window size: " + std::to_string((int)ntohs(tcp->getTcpHeader()->windowSize)) + '\n';
				temp += "Sequence number: " + std::to_string((int)ntohs(tcp->getTcpHeader()->sequenceNumber)) + '\n';
				temp += "Acknowledgment number: " + std::to_string((int)ntohs(tcp->getTcpHeader()->ackNumber)) + '\n';
				temp += "CheckSum: " + std::to_string((int)ntohs(tcp->getTcpHeader()->headerChecksum)) + '\n';
				temp += "Urgent point: " + std::to_string((int)ntohs(tcp->getTcpHeader()->urgentPointer)) + '\n';
				break;
			}
			case pcpp::HTTP:
			{
				pcpp::HttpRequestLayer* httpRq = parsedPacket.getLayerOfType<pcpp::HttpRequestLayer>();

				temp = "\t\tHTTP\n";
				temp += "URI: " + httpRq->getFirstLine()->getUri() + '\n';
				temp += "Host: " + httpRq->getFieldByName(PCPP_HTTP_HOST_FIELD)->getFieldValue() + '\n';
				temp += "User-Agent: " + httpRq->getFieldByName(PCPP_HTTP_USER_AGENT_FIELD)->getFieldValue() + '\n';
				temp += "Cookie: " + httpRq->getFieldByName(PCPP_HTTP_COOKIE_FIELD)->getFieldValue() + '\n';
				temp += "Full URL: ", httpRq->getUrl() + '\n';
				temp += "HTTP method: " + printHTTPMethods(httpRq);
				break;
			}
			case pcpp::DNS:
			{
				pcpp::DnsLayer* dns = parsedPacket.getLayerOfType<pcpp::DnsLayer>();

				temp = "\t\tDNS\n";
				temp += "Authentic data: " + std::to_string((int)ntohs(dns->getDnsHeader()->authenticData)) + '\n';
				temp += "Transaction ID: " + std::to_string((int)ntohs(dns->getDnsHeader()->transactionID)) + '\n';
				temp += "Authoritative answer: " + std::to_string((int)ntohs(dns->getDnsHeader()->authoritativeAnswer)) + '\n';
				//temp += "Cheking disabled: " + std::to_string((int)ntohs(dns->getDnsHeader()->checkingDisabled)) + '\n';
				temp += "Number of additional: " + std::to_string((int)ntohs(dns->getDnsHeader()->numberOfAdditional)) + '\n';
				temp += "Number of answers: " + std::to_string((int)ntohs(dns->getDnsHeader()->numberOfAnswers)) + '\n';
				temp += "Number of authority: " + std::to_string((int)ntohs(dns->getDnsHeader()->numberOfAuthority)) + '\n';
				temp += "Number of questions: " + std::to_string((int)ntohs(dns->getDnsHeader()->numberOfQuestions)) + '\n';
				temp += "Operation - " + printDnsOperation(dns) + '\n';
				temp += "Query or response: " + std::to_string((int)ntohs(dns->getDnsHeader()->queryOrResponse)) + '\n';
				temp += "Recursion avaible: " + std::to_string((int)ntohs(dns->getDnsHeader()->recursionAvailable)) + '\n';
				temp += "Recursion desired: " + std::to_string((int)ntohs(dns->getDnsHeader()->recursionDesired)) + '\n';
				temp += "Response code: " + std::to_string((int)ntohs(dns->getDnsHeader()->responseCode)) + '\n';
				//temp += "Truncation: " + std::to_string((int)ntohs(dns->getDnsHeader()->truncation)) + '\n';
				//temp += "Zero: " + std::to_string((int)ntohs(dns->getDnsHeader()->zero)) + '\n';
				break;
			}
			/*case pcpp::SSL:
			{
				pcpp::SSLLayer* ssl = parsedPacket.getLayerOfType<pcpp::SSLLayer>();

				temp = "\t\tSSL/TLS 1.2\n";

				break;
			}
			case pcpp::SIP:
			{
				pcpp::SipLayer* sip = parsedPacket.getLayerOfType<pcpp::SipLayer>();

				temp = "\t\tSIP\n";

				break;
			}*/
			case pcpp::IPv4:
			{
				pcpp::IPv4Layer* ip4 = parsedPacket.getLayerOfType<pcpp::IPv4Layer>();

				srcIp = ip4->getSrcIpAddress();
				dstIp = ip4->getDstIpAddress();
				ttl = ip4->getIPv4Header()->timeToLive;
				AIPN = ip4->getIPv4Header()->protocol;

				temp = "\t\tIPv4\n";
				temp += "Source IP: " + ip4->getSrcIpAddress().toString() + '\n';
				temp += "Destination IP: " + ip4->getDstIpAddress().toString() + '\n';
				temp += "IP ID: 0x" + dToX((int)ntohs(ip4->getIPv4Header()->ipId)) + '\n';
				temp += "TTL: " + std::to_string((int)ip4->getIPv4Header()->timeToLive) + '\n';
				temp += "Fragment offset field: " + std::to_string((int)ntohs(ip4->getIPv4Header()->fragmentOffset)) + '\n';
				temp += "CheckSum: " + std::to_string((int)ntohs(ip4->getIPv4Header()->headerChecksum)) + '\n';
				temp += "Protocol: " + printIPv4Protocol(ip4) + '\n';
				break;
			}
			case pcpp::IPv6:
			{
				pcpp::IPv6Layer* ip6 = parsedPacket.getLayerOfType<pcpp::IPv6Layer>();

				temp = "\t\tIPv6\n";
				temp += "Source IP: " + ip6->getSrcIpAddress().toString() + '\n';
				temp += "Destination IP: " + ip6->getDstIpAddress().toString() + '\n';
				temp += "IP version: 0x" + dToX((int)ip6->getIPv6Header()->ipVersion) + '\n';
				temp += "Flow label: " + std::to_string((int)ip6->getIPv6Header()->flowLabel) + '\n';
				temp += "Hop limit: " + std::to_string((int)ip6->getIPv6Header()->hopLimit) + '\n';
				temp += "Next header type: 0x" + dToX((int)ip6->getIPv6Header()->nextHeader) + '\n';
				temp += "Size of payload: " + std::to_string((int)ntohs(ip6->getIPv6Header()->payloadLength)) + '\n';
				temp += "Traffic class: " + std::to_string((int)ip6->getIPv6Header()->trafficClass) + '\n';
				break;
			}
			default:
				temp = lay->toString() + '\n';
				break;
			}
			protocols.push_back(temp);
		}
	}

	pcpp::RawPacket* getPacketRaw()
	{
		return parsedPacket.getRawPacket();
	}
	pcpp::Packet getParsedPacket()
	{
		return parsedPacket;
	}
	std::string getAppName()
	{
		return appName;
	}
	pcpp::IPAddress getSrcIp()
	{
		return srcIp;
	}
	pcpp::IPAddress getDstIp()
	{
		return dstIp;
	}
	tm getTimestamp()
	{
		return timestamp;
	}
	int getTtl()
	{
		return ttl;
	}
	int getAIPN()
	{
		return AIPN;
	}
	std::string getProtocolName()
	{
		return protocolName;
	}
	std::string getFirstLayer()
	{
		return firstLayer;
	}
	std::vector<std::string> getProtocols()
	{
		return protocols;
	}
};