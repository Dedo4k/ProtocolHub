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

//getting tcp option type as string
std::string printTcpOptionType(pcpp::TcpLayer* tcp)
{
	std::string result = "";
	for (pcpp::TcpOption tcpOption = tcp->getFirstTcpOption(); tcpOption.isNotNull(); tcpOption = tcp->getNextTcpOption(tcpOption))
	{
		switch (tcpOption.getTcpOptionType())
		{
		case pcpp::PCPP_TCPOPT_NOP:
			result += " Padding;";
			break;
		case pcpp::PCPP_TCPOPT_EOL:
			result += " End of options;";
			break;
		case pcpp::TCPOPT_MSS:
			result += " Segment size negotiating;";
			break;
		case pcpp::PCPP_TCPOPT_WINDOW:
			result += " Window scaling;";
			break;
		case pcpp::TCPOPT_SACK_PERM:
			result += " SACK permitted;";
			break;
		case pcpp::PCPP_TCPOPT_SACK:
			result += " SACK block;";
			break;
		case pcpp::TCPOPT_ECHO:
			result += " Echo";
			break;
		case pcpp::TCPOPT_ECHOREPLY:
			result += " Echo reply;";
			break;
		case pcpp::PCPP_TCPOPT_TIMESTAMP:
			result += " Timestamps;";
			break;
		case pcpp::TCPOPT_CC:
			result += " CC;";
			break;
		case pcpp::TCPOPT_CCNEW:
			result += " CC.NEW;";
			break;
		case pcpp::TCPOPT_CCECHO:
			result += " CC.ECHO;";
			break;
		case pcpp::TCPOPT_MD5:
			result += " MD5;";
			break;
		case pcpp::TCPOPT_MPTCP:
			result += " Multipath;";
			break;
		case pcpp::TCPOPT_SCPS:
			result += " SCPS capabilities;";
			break;
		case pcpp::TCPOPT_SNACK:
			result += " SCPS SNACK;";
			break;
		case pcpp::TCPOPT_RECBOUND:
			result += " SCPS record boundary;";
			break;
		case pcpp::TCPOPT_CORREXP:
			result += " SCPS corruption experienced;";
			break;
		case pcpp::TCPOPT_QS:
			result += " Quick-Start response;";
			break;
		case pcpp::TCPOPT_USER_TO:
			result += " User time-out;";
			break;
		case pcpp::TCPOPT_EXP_FD:
			result += " RFC3692-style Experiment 1;";
			break;
		case pcpp::TCPOPT_EXP_FE:
			result += " RFC3692-style Experiment 2;";
			break;
		case pcpp::TCPOPT_RVBD_PROBE:
			result += " Riverbed probe, non IANA registered option number;";
			break;
		case pcpp::TCPOPT_RVBD_TRPY:
			result += " Riverbed transparency, non IANA registered option number;";
			break;
		case pcpp::TCPOPT_Unknown:
			result += " Unknown option;";
			break;
		default:
			result += " Error;";
			break;
		}
	}

	if (result == "")
		return " No options";
	else
		return result;
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

//getting http version as string
std::string printHTTPVersion(pcpp::HttpRequestLayer* httpRq)
{
	switch (httpRq->getFirstLine()->getVersion())
	{
	case pcpp::ZeroDotNine:
		return "0.9";
		break;
	case pcpp::OneDotZero:
		return "1.0";
		break;
	case pcpp::OneDotOne:
		return "1.1";
		break;
	case pcpp::HttpVersionUnknown:
		return "Unknown version";
		break;
	default:
		return "Error";
		break;
	}
}

//getting http version as string
std::string printHTTPVersion(pcpp::HttpResponseLayer* httpRs)
{
	switch (httpRs->getFirstLine()->getVersion())
	{
	case pcpp::ZeroDotNine:
		return "0.9";
		break;
	case pcpp::OneDotZero:
		return "1.0";
		break;
	case pcpp::OneDotOne:
		return "1.1";
		break;
	case pcpp::HttpVersionUnknown:
		return "Unknown version";
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