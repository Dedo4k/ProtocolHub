#include "PacketHelper.h"

PacketHelper::PacketHelper(pcpp::RawPacket& _rawPacket)
{
	pcpp::Packet tempParsedPacket(&_rawPacket);
	parsedPacket = tempParsedPacket;
	parseAllInfo();
	parseBasicInfo();
}

PacketHelper::PacketHelper(pcpp::Packet& _parsedPacket)
{
	parsedPacket = _parsedPacket;
	parseAllInfo();
	parseBasicInfo();
}

void PacketHelper::parseBasicInfo()
{
	timespec temp = parsedPacket.getRawPacketReadOnly()->getPacketTimeStamp();
	localtime_s(&timestamp, &temp.tv_sec);
	setProtocolNameWithAIPN();
}

void PacketHelper::setProtocolNameWithAIPN()
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

void PacketHelper::parseAllInfo()
{
	std::string temp;
	for (pcpp::Layer* lay = parsedPacket.getFirstLayer(); lay != NULL; lay = lay->getNextLayer())
	{
		switch (lay->getProtocol())
		{
		case pcpp::UDP:
		{
			this->udp = true;
			pcpp::UdpLayer* udp = parsedPacket.getLayerOfType<pcpp::UdpLayer>();

			srcPort = (int)ntohs(udp->getUdpHeader()->portSrc);
			dstPort = (int)ntohs(udp->getUdpHeader()->portDst);

			temp = "\t\tUDP\n";
			temp += "Source UDP port:" + std::to_string((int)ntohs(udp->getUdpHeader()->portSrc)) + '\n';
			temp += "Destination UDP port: " + std::to_string((int)ntohs(udp->getUdpHeader()->portDst)) + '\n';
			temp += "Length of header and playload in bytes: " + std::to_string((int)ntohs(udp->getUdpHeader()->length)) + '\n';
			temp += "CheckSum: " + std::to_string((int)ntohs(udp->getUdpHeader()->headerChecksum)) + '\n';
			break;
		}
		case pcpp::TCP:
		{
			this->tcp = true;
			pcpp::TcpLayer* tcp = parsedPacket.getLayerOfType<pcpp::TcpLayer>();

			srcPort = (int)ntohs(tcp->getTcpHeader()->portSrc);
			dstPort = (int)ntohs(tcp->getTcpHeader()->portDst);

			temp = "\t\tTCP\n";
			temp += "Source TCP port: " + std::to_string((int)ntohs(tcp->getTcpHeader()->portSrc)) + '\n';
			temp += "Destination TCP port: " + std::to_string((int)ntohs(tcp->getTcpHeader()->portDst)) + '\n';
			temp += "Data offset: " + std::to_string((int)ntohs(tcp->getTcpHeader()->dataOffset)) + '\n';
			temp += "Reserved: " + std::to_string((int)ntohs(tcp->getTcpHeader()->reserved)) + '\n';
			temp += "TCP flags:" + printTcpFlags(tcp) + '\n';
			temp += "Window size: " + std::to_string((int)ntohs(tcp->getTcpHeader()->windowSize)) + '\n';
			temp += "Sequence number: " + std::to_string((int)ntohs(tcp->getTcpHeader()->sequenceNumber)) + '\n';
			temp += "Acknowledgment number: " + std::to_string((int)ntohs(tcp->getTcpHeader()->ackNumber)) + '\n';
			temp += "CheckSum: " + std::to_string((int)ntohs(tcp->getTcpHeader()->headerChecksum)) + '\n';
			temp += "Urgent point: " + std::to_string((int)ntohs(tcp->getTcpHeader()->urgentPointer)) + '\n';
			temp += "TCP options:" + printTcpOptionType(tcp) + "\n";
			break;
		}
		case pcpp::HTTPRequest:
		{
			this->http = true;
			pcpp::HttpRequestLayer* httpRq = parsedPacket.getLayerOfType<pcpp::HttpRequestLayer>();

			temp = "\t\tHTTP-Request\n";
			temp += "URI: " + httpRq->getFirstLine()->getUri() + '\n';
			temp += "HTTP version: " + printHTTPVersion(httpRq) + '\n';
			temp += "Full URL: " + httpRq->getUrl() + '\n';
			temp += "HTTP method: " + printHTTPMethods(httpRq) + '\n';
			temp += "\tFields:\n";
			pcpp::HeaderField* field = httpRq->getFirstField();
			temp += field->getFieldName() + ": " + field->getFieldValue() + '\n';
			for (size_t i = 1; i < httpRq->getFieldCount(); ++i)
			{
				field = httpRq->getNextField(field);
				temp += field->getFieldName() + ": " + field->getFieldValue() + '\n';
			}
			break;
		}
		case pcpp::HTTPResponse:
		{
			this->http = true;
			pcpp::HttpResponseLayer* httpRs = parsedPacket.getLayerOfType<pcpp::HttpResponseLayer>();

			temp = "\t\tHTTP-Response\n";
			temp += "Status: " + httpRs->getFirstLine()->getStatusCodeString() + '\n';
			temp += "HTTP version: " + printHTTPVersion(httpRs) + '\n';
			temp += "\tFields:\n";
			pcpp::HeaderField* field = httpRs->getFirstField();
			temp += field->getFieldName() + ": " + field->getFieldValue() + '\n';
			for (size_t i = 1; i < httpRs->getFieldCount(); ++i)
			{
				field = httpRs->getNextField(field);
				temp += field->getFieldName() + ": " + field->getFieldValue() + '\n';
			}
			break;
		}
		case pcpp::DNS:
		{
			this->dns = true;
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
		case pcpp::SSL:
		{
			this->tls = true;
			pcpp::SSLLayer* ssl = parsedPacket.getLayerOfType<pcpp::SSLLayer>();

			temp = "\t\t" + ssl->sslVersionToString(ssl->getRecordVersion()) + '\n';
			temp += "Record type: " + printSslRecordType(ssl) + '\n';
			temp += "Message: " + printSslMessage(parsedPacket, ssl) + '\n';
			if (printSslRecordType(ssl) == "Handshake")
				handshake = true;
			break;
		}
		case pcpp::SIP:
		{
			this->sip = true;
			pcpp::SipLayer* sip = parsedPacket.getLayerOfType<pcpp::SipLayer>();
			
			temp = "\t\tSIP\n";
			pcpp::HeaderField* field = sip->getFirstField();
			temp += field->getFieldName() + ": " + field->getFieldValue() + '\n';
			for (size_t i = 1; i < sip->getFieldCount(); ++i)
			{
				field = sip->getNextField(field);
				temp += field->getFieldName() + ": " + field->getFieldValue() + '\n';
			}

			break;
		}
		case pcpp::IPv4:
		{
			pcpp::IPv4Layer* ip4 = parsedPacket.getLayerOfType<pcpp::IPv4Layer>();

			srcIp = ip4->getSrcIpAddress();
			dstIp = ip4->getDstIpAddress();
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

pcpp::RawPacket* PacketHelper::getPacketRaw()
{
	return parsedPacket.getRawPacket();
}
pcpp::Packet PacketHelper::getParsedPacket()
{
	return parsedPacket;
}
pcpp::IPAddress PacketHelper::getSrcIp()
{
	return srcIp;
}
pcpp::IPAddress PacketHelper::getDstIp()
{
	return dstIp;
}
int PacketHelper::getSrcPort()
{
	return srcPort;
}
int PacketHelper::getDstPort()
{
	return dstPort;
}
tm PacketHelper::getTimestamp()
{
	return timestamp;
}
std::string PacketHelper::getTimestampAsString()
{
	std::string result="";
	
	result += std::to_string(timestamp.tm_mday) + '/';
	result += std::to_string(timestamp.tm_mon + 1) + '/';
	result += std::to_string(timestamp.tm_year + 1900) + '\t';
	result += std::to_string(timestamp.tm_sec) + ':';
	result += std::to_string(timestamp.tm_min + 1) + ':';
	result += std::to_string(timestamp.tm_hour + 1900);

	return result;
}
int PacketHelper::getAIPN()
{
	return AIPN;
}
std::string PacketHelper::getProtocolName()
{
	return protocolName;
}
std::vector<std::string> PacketHelper::getProtocols()
{
	return protocols;
}
bool PacketHelper::inSession()
{
	return session;
}
void PacketHelper::setSession(bool value)
{
	session = value;
}
bool PacketHelper::isTcp()
{
	return tcp;
}
bool PacketHelper::isHttp()
{
	return http;
}
bool PacketHelper::isTls()
{
	return tls;
}
bool PacketHelper::isUdp()
{
	return udp;
}
bool PacketHelper::isDns()
{
	return dns;
}
bool PacketHelper::isSip()
{
	return sip;
}
bool PacketHelper::isHandshake()
{
	return handshake;
}