#pragma once
#include <string>

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