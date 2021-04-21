#include <IPv4Layer.h>
#include <IPv6Layer.h>
#include <DNSLayer.h>
#include <UDPLayer.h>
#include <EthLayer.h>
#include <TcpLayer.h>
#include <HttpLayer.h>
#include <ArpLayer.h>

#include <Layer.h>
#include <Packet.h>
#include <PcapFileDevice.h>
#include <stdio.h>
#include <stdlib.h>
#include <SystemUtils.h>

//getting tcp flags as string
std::string printTcpFlags(pcpp::TcpLayer* tcpLayer)
{
	std::string result = "";
	if (tcpLayer->getTcpHeader()->synFlag == 1)
		result += "SYN ";
	if (tcpLayer->getTcpHeader()->ackFlag == 1)
		result += "ACK ";
	if (tcpLayer->getTcpHeader()->pshFlag == 1)
		result += "PSH ";
	if (tcpLayer->getTcpHeader()->cwrFlag == 1)
		result += "CWR ";
	if (tcpLayer->getTcpHeader()->urgFlag == 1)
		result += "URG ";
	if (tcpLayer->getTcpHeader()->eceFlag == 1)
		result += "ECE ";
	if (tcpLayer->getTcpHeader()->rstFlag == 1)
		result += "RST ";
	if (tcpLayer->getTcpHeader()->finFlag == 1)
		result += "FIN ";

	return result;
}

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

int main(int argc, char* argv[])
{
	// open a pcap file for reading
	pcpp::PcapFileReaderDevice reader("ex.pcap");
	if (!reader.open())
	{
		printf("Error opening the pcap file\n");
		return 1;
	}

	//count of parsed protcols
	int counter = 0;

	// read the packets from the file
	pcpp::RawPacket rawPacket;
	while (reader.getNextPacket(rawPacket))
	{
		// parse the raw packet into a parsed packet
		pcpp::Packet parsedPacket(&rawPacket);
		for (pcpp::Layer* lay = parsedPacket.getFirstLayer(); lay != NULL; lay = lay->getNextLayer())
		{
			printf("\n%s\n",lay->toString().c_str());
			if (lay->getProtocol() == pcpp::UDP)
			{
				pcpp::UdpLayer* udp = parsedPacket.getLayerOfType<pcpp::UdpLayer>();

				printf("\n\t\tUDP\n");
				printf("Source UDP port: %d\n", (int)ntohs(udp->getUdpHeader()->portSrc));
				printf("Destination UDP port: %d\n", (int)ntohs(udp->getUdpHeader()->portDst));
				printf("Length of header and playload in bytes: %d\n", (int)ntohs(udp->getUdpHeader()->length));
				printf("CheckSum: %d\n", (int)ntohs(udp->getUdpHeader()->headerChecksum));
			}
			else if (lay->getProtocol() == pcpp::TCP)
			{
				pcpp::TcpLayer* tcp = parsedPacket.getLayerOfType<pcpp::TcpLayer>();

				printf("\n\t\tTCP\n");
				printf("Source TCP port: %d\n", (int)ntohs(tcp->getTcpHeader()->portSrc));
				printf("Destination TCP port: %d\n", (int)ntohs(tcp->getTcpHeader()->portDst));
				printf("Data offset: %d\n", (int)ntohs(tcp->getTcpHeader()->dataOffset));
				printf("Reserved: %d\n", (int)ntohs(tcp->getTcpHeader()->reserved));
				printf("TCP flags: %s\n", printTcpFlags(tcp).c_str());
				printf("Window size: %d\n", (int)ntohs(tcp->getTcpHeader()->windowSize));
				printf("Sequence number: %d\n", (int)ntohl(tcp->getTcpHeader()->sequenceNumber));
				printf("Acknowledgment number: %d\n", (int)ntohl(tcp->getTcpHeader()->ackNumber));
				printf("CheckSum: %d\n", (int)ntohs(tcp->getTcpHeader()->headerChecksum));
				printf("Urgent point: %d\n", (int)ntohs(tcp->getTcpHeader()->urgentPointer));
			}
			else if(lay->getProtocol() == pcpp::DNS)
			{
				pcpp::DnsLayer* dns = parsedPacket.getLayerOfType<pcpp::DnsLayer>();

				printf("\n\t\tDNS\n");
				printf("Authentic data: %d\n", (int)ntohs(dns->getDnsHeader()->authenticData));
				printf("Transaction ID: %d\n", (int)ntohs(dns->getDnsHeader()->transactionID));
				printf("Authoritative answer: %d\n", (int)ntohs(dns->getDnsHeader()->authoritativeAnswer));
				printf("Cheking disabled: %d\n", (int)ntohs(dns->getDnsHeader()->checkingDisabled));
				printf("Number of additional: %d\n", (int)ntohs(dns->getDnsHeader()->numberOfAdditional));
				printf("Number of answers: %d\n", (int)ntohs(dns->getDnsHeader()->numberOfAnswers));
				printf("Number of authority: %d\n", (int)ntohs(dns->getDnsHeader()->numberOfAuthority));
				printf("Number of questions: %d\n", (int)ntohs(dns->getDnsHeader()->numberOfQuestions));
				printf("Opcode: %d\n", (int)ntohs(dns->getDnsHeader()->opcode));
				printf("Query or response: %d\n", (int)ntohs(dns->getDnsHeader()->queryOrResponse));
				printf("Recursion avaible: %d\n", (int)ntohs(dns->getDnsHeader()->recursionAvailable));
				printf("Recursion desired: %d\n", (int)ntohs(dns->getDnsHeader()->recursionDesired));
				printf("Response code: %d\n", (int)ntohs(dns->getDnsHeader()->responseCode));
				printf("Truncation: %d\n", (int)ntohs(dns->getDnsHeader()->truncation));
				printf("Zero: %d\n", (int)ntohs(dns->getDnsHeader()->zero));
			}
			else if (lay->getProtocol() == pcpp::HTTP)
			{
				pcpp::HttpRequestLayer* httpRq = parsedPacket.getLayerOfType<pcpp::HttpRequestLayer>();

				printf("\n\t\tHTTP\n");
				printf("HTTP URI: %s\n", httpRq->getFirstLine()->getUri().c_str());
				printf("HTTP host: %s\n", httpRq->getFieldByName(PCPP_HTTP_HOST_FIELD)->getFieldValue().c_str());
				printf("HTTP user-agent: %s\n", httpRq->getFieldByName(PCPP_HTTP_USER_AGENT_FIELD)->getFieldValue().c_str());
				printf("HTTP cookie: %s\n", httpRq->getFieldByName(PCPP_HTTP_COOKIE_FIELD)->getFieldValue().c_str());
				printf("HTTP full URL: %s\n", httpRq->getUrl().c_str());
			}
			else if (lay->getProtocol() == pcpp::Ethernet)
			{
				pcpp::EthLayer* eth = parsedPacket.getLayerOfType<pcpp::EthLayer>();

				printf("\n\t\tETHERNET\n");
				printf("Ether type = 0x%X\n", eth->getEthHeader()->etherType);
				printf("Ethrenet source MAC address: %s\n", eth->getSourceMac().toString().c_str());
				printf("Ethrenet destination MAC address: %s\n", eth->getDestMac().toString().c_str());
			}
			else if (lay->getProtocol() == pcpp::ARP)
			{
				pcpp::ArpLayer* arp = parsedPacket.getLayerOfType<pcpp::ArpLayer>();

				printf("\n\t\tARP\n");
				printf("HTYPE: 0x%X\n", (int)ntohs(arp->getArpHeader()->hardwareType));
				printf("PTYPE: 0x%X\n", (int)ntohs(arp->getArpHeader()->protocolType));
				printf("Hardware size: %d\n", (int)arp->getArpHeader()->hardwareSize);
				printf("Protocol size: %d\n", (int)arp->getArpHeader()->protocolSize);
				printf("Sender hardware address: %s\n", arp->getSenderMacAddress().toString().c_str());
				printf("Sender protocol address: %s\n", arp->getSenderIpAddr().toString().c_str());
				printf("Target hardware address: %s\n", arp->getTargetMacAddress().toString().c_str());
				printf("Target protocol address: %s\n", arp->getTargetIpAddr().toString().c_str());
				printf("Operation type - %s\n", printArpOperation(arp).c_str());
			}
			else if (lay->getProtocol() == pcpp::IPv4)
			{
				pcpp::IPv4Layer* ip4 = parsedPacket.getLayerOfType<pcpp::IPv4Layer>();

				printf("\n\t\tIPv4\n");
				
				printf("Source IP: %s\n", ip4->getSrcIpAddress().toString().c_str());
				printf("Destination IP: %s\n", ip4->getDstIpAddress().toString().c_str());
				printf("IP ID: 0x%X\n", (int)ntohs(ip4->getIPv4Header()->ipId));
				printf("TTL: %d\n", (int)ip4->getIPv4Header()->timeToLive);
				printf("Fragment offset field: %d\n", (int)ntohs(ip4->getIPv4Header()->fragmentOffset));
				printf("CheckSum: %d\n", (int)ntohs(ip4->getIPv4Header()->headerChecksum));
				printf("IP header length: %d\n", (int)ip4->getIPv4Header()->internetHeaderLength);
				printf("IP version: 0x%X\n", (int)ip4->getIPv4Header()->ipVersion);
				printf("Protocol: %d\n", (int)ip4->getIPv4Header()->protocol);
				printf("Total length: %d\n", (int)ntohs(ip4->getIPv4Header()->totalLength));
				printf("TTL (eight-bit): %d\n", (int)ip4->getIPv4Header()->typeOfService);
			}
			else if (lay->getProtocol() == pcpp::IPv6)
			{
				pcpp::IPv6Layer* ip6 = parsedPacket.getLayerOfType<pcpp::IPv6Layer>();

				printf("\n\t\tIPv6\n");
				printf("Source IP: %s\n", ip6->getSrcIpAddress().toString().c_str());
				printf("Destination IP: %s\n", ip6->getDstIpAddress().toString().c_str());
				printf("IP version: 0x%X\n", (int)ip6->getIPv6Header()->ipVersion);
				printf("Flow label: %d\n", (int)ip6->getIPv6Header()->flowLabel);
				printf("Hop limit: %d\n", (int)ip6->getIPv6Header()->hopLimit);
				printf("Next header type: 0x%X\n", (int)ip6->getIPv6Header()->nextHeader);
				printf("Size of payload: %d\n", (int)ntohs(ip6->getIPv6Header()->payloadLength));
				printf("Traffic class: %d\n", (int)ip6->getIPv6Header()->trafficClass);
			}
			else
				printf("\nIDK! But not for a long time\n");
			++counter;
		}

	}

	printf("\nCount of protocols: %d\n", counter);
	// close the file
	reader.close();

	return 0;
}
