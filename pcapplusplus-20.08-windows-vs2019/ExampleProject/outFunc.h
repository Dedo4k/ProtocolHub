#pragma once
#include <string>
#include <iomanip>

#include <Packet.h>
#include <TCPLayer.h>
#include <ARPLayer.h>
#include <DNSLayer.h>

//getting tcp flags as string
std::string printTcpFlags(pcpp::TcpLayer* tcpLayer)
{
	std::string result = "";
	if (tcpLayer->getTcpHeader()->synFlag == 1)
		result += " SYN";
	if (tcpLayer->getTcpHeader()->ackFlag == 1)
		result += " ACK";
	if (tcpLayer->getTcpHeader()->pshFlag == 1)
		result += " PSH";
	if (tcpLayer->getTcpHeader()->cwrFlag == 1)
		result += " CWR";
	if (tcpLayer->getTcpHeader()->urgFlag == 1)
		result += " URG";
	if (tcpLayer->getTcpHeader()->eceFlag == 1)
		result += " ECE";
	if (tcpLayer->getTcpHeader()->rstFlag == 1)
		result += " RST";
	if (tcpLayer->getTcpHeader()->finFlag == 1)
		result += " FIN";

	return result;
}

//getting arp operations as string
std::string printArpOperation(pcpp::ArpLayer* arpLayer)
{
	switch ((int)ntohs(arpLayer->getArpHeader()->opcode))
	{
	case 1:
		return "request";
		break;
	case 2:
		return "reply";
		break;
	default:
		return "error type";
		break;
	}
}

//getting dns operations as string
std::string printDnsOperation(pcpp::DnsLayer* dnsLayer)
{
	switch (ntohs(dnsLayer->getDnsHeader()->opcode))
	{
	case 0:
		return "Query";
		break;
	case 1:
		return "IQuery (Inverse Query, OBSOLETE)";
		break;
	case 2:
		return "Status";
		break;
	case 3:
		return "Unassigned";
		break;
	case 4:
		return "Notify";
		break;
	case 5:
		return "Update";
		break;
	case 6:
		return "DNS Stateful Operations (DSO)";
		break;
	default:
		return "Unassigned";
		break;
	}
}

//getting AIPN as name of protocol
std::string printIPv4Protocol(pcpp::IPv4Layer* ipLayer)
{
	switch (ipLayer->getIPv4Header()->protocol)
	{
	case 0:
		return "HOPOPT";
		break;
	case 1:
		return "ICMP";
		break;
	case 2:
		return "IGMP";
		break;
	case 4:
		return "IPIP";
		break;
	case 6:
		return "TCP";
		break;
	case 8:
		return "EGP";
		break;
	case 12:
		return "PUP";
		break;
	case 17:
		return "UDP";
		break;
	case 22:
		return "XNS-IDP";
		break;
	case 41:
		return "IPv6";
		break;
	case 43:
		return "IPv6-Route";
		break;
	case 44:
		return "IPv6-Frag";
		break;
	case 47:
		return "GRE";
		break;
	case 50:
		return "ESP";
		break;
	case 51:
		return "AH";
		break;
	case 58:
		return "IPv6-ICMP";
		break;
	case 59:
		return "IPv6-NoNxt";
		break;
	case 60:
		return "IPv6-Opts";
		break;
	default:
		return "Reserved";
		break;
	}
}

//getting http methods as string
std::string printHTTPMethods (pcpp::HttpRequestLayer* httpRq)
{
	switch (httpRq->getFirstLine()->getMethod())
	{
	case pcpp::HttpRequestLayer::HttpGET:
		return "GET";
		break;
	case pcpp::HttpRequestLayer::HttpHEAD:
		return "HEAD";
		break;
	case pcpp::HttpRequestLayer::HttpPOST:
		return "POST";
		break;
	case pcpp::HttpRequestLayer::HttpPUT:
		return "PUT";
		break;
	case pcpp::HttpRequestLayer::HttpDELETE:
		return "DELETE";
		break;
	case pcpp::HttpRequestLayer::HttpTRACE:
		return "TRACE";
		break;
	case pcpp::HttpRequestLayer::HttpOPTIONS:
		return "OPTIONS";
		break;
	case pcpp::HttpRequestLayer::HttpCONNECT:
		return "CONNECT";
		break;
	case pcpp::HttpRequestLayer::HttpPATCH:
		return "PATCH";
		break;
	case pcpp::HttpRequestLayer::HttpMethodUnknown:
		return "Unknown method";
		break;
	default:
		return "Error";
		break;
	}
}

//getting value and convert to hex as string
std::string dToX(int value)
{
	int temp;
	std::string result = "";
	char hex[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

	while (value > 0)
	{
		temp = value % 16;
		result = hex[temp] + result;
		value /= 16;
	}
	return result;
}