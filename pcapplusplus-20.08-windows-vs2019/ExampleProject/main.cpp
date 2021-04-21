#include <IPv4Layer.h>
#include <IPv6Layer.h>
#include <DNSLayer.h>
#include <UDPLayer.h>
#include <EthLayer.h>
#include <TcpLayer.h>
#include <HttpLayer.h>

#include <Packet.h>
#include <PcapFileDevice.h>
#include <stdio.h>
#include <stdlib.h>
#include <SystemUtils.h>

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

int main(int argc, char* argv[])
{
	// open a pcap file for reading
	pcpp::PcapFileReaderDevice reader("test2.pcap");
	if (!reader.open())
	{
		printf("Error opening the pcap file\n");
		return 1;
	}

	// read the packets from the file
	int counter = 0;
	pcpp::RawPacket rawPacket;
	while (reader.getNextPacket(rawPacket))
	{
		// parse the raw packet into a parsed packet
		pcpp::Packet parsedPacket(&rawPacket);

		//parse UDP protocol 
		if (parsedPacket.isPacketOfType(pcpp::UDP))
		{
			pcpp::UdpLayer* udp = parsedPacket.getLayerOfType<pcpp::UdpLayer>();

			printf("\n\t\tUDP\n");
			printf("Source UDP port: %d\n", (int)udp->getUdpHeader()->portSrc);
			printf("Destination UDP port: %d\n", (int)udp->getUdpHeader()->portDst);
			printf("Length of header and playload in bytes: %d\n", (int)udp->getUdpHeader()->length);
		}
		//parse UDP protocol 
		else if (parsedPacket.isPacketOfType(pcpp::TCP))
		{
			pcpp::TcpLayer* tcp = parsedPacket.getLayerOfType<pcpp::TcpLayer>();

			printf("\n\t\tTCP\n");
			printf("Source TCP port: %d\n", (int)tcp->getTcpHeader()->portSrc);
			printf("Destination TCP port: %d\n", (int)tcp->getTcpHeader()->portDst);
			printf("Window size: %d\n", (int)tcp->getTcpHeader()->windowSize);
			printf("TCP flags: %s\n", printTcpFlags(tcp).c_str());
		}
		//parse UDP protocol 
		else if (parsedPacket.isPacketOfType(pcpp::DNS))
		{
			pcpp::DnsLayer* dns = parsedPacket.getLayerOfType<pcpp::DnsLayer>();

			printf("\n\t\tDNS\n");
			printf("DNS authentic data: %d\n", (int)dns->getDnsHeader()->authenticData);
			printf("DNS transaction ID: %d\n", (int)dns->getDnsHeader()->transactionID);
		}
		//parse UDP protocol 
		else if (parsedPacket.isPacketOfType(pcpp::HTTP))
		{
			pcpp::HttpRequestLayer* httpRq = parsedPacket.getLayerOfType<pcpp::HttpRequestLayer>();

			printf("\n\t\tHTTP\n");
			printf("\tRequest layer\n");
			printf("HTTP URI: %s\n", httpRq->getFirstLine()->getUri().c_str());
			printf("HTTP host: %s\n", httpRq->getFieldByName(PCPP_HTTP_HOST_FIELD)->getFieldValue().c_str());
			printf("HTTP user-agent: %s\n", httpRq->getFieldByName(PCPP_HTTP_USER_AGENT_FIELD)->getFieldValue().c_str());
			printf("HTTP cookie: %s\n", httpRq->getFieldByName(PCPP_HTTP_COOKIE_FIELD)->getFieldValue().c_str());
			printf("HTTP full URL: %s\n", httpRq->getUrl().c_str());
		}
		//parse UDP protocol 
		else if (parsedPacket.isPacketOfType(pcpp::Ethernet))
		{
			pcpp::EthLayer* eth = parsedPacket.getLayerOfType<pcpp::EthLayer>();

			printf("\n\t\tETHERNET\n");
			printf("Ether type = 0x%X\n", eth->getEthHeader()->etherType);
			printf("Ethrenet source MAC address: %d\n", (int)eth->getEthHeader()->srcMac);
			printf("Ethrenet destination MAC address: %d\n", (int)eth->getEthHeader()->dstMac);
		}
		//parse UDP protocol 
		else if (parsedPacket.isPacketOfType(pcpp::IPv4))
		{
			pcpp::IPv4Layer* ip4 = parsedPacket.getLayerOfType<pcpp::IPv4Layer>();

			printf("\n\t\tIPv4\n");
			printf("Source IP: %d\n", (int)ip4->getIPv4Header()->ipSrc);
			printf("Destination IP: %d\n", (int)ip4->getIPv4Header()->ipDst);
			printf("IP ID: 0x%X\n", ip4->getIPv4Header()->ipId);
			printf("TTL (eight-bit): %d\n", (int)ip4->getIPv4Header()->timeToLive);
		}
		//parse UDP protocol 
		else
			printf("\nIDK! But not for a long time\n");
		
		counter++;
		printf("\n%d", counter);
	}
	// close the file
	reader.close();

	return 0;
}
