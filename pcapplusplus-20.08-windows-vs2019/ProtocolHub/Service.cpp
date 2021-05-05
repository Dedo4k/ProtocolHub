
#include "Service.h"
#include "ConvertFunc.h"

void Service::parseFilesInList(System::Collections::ArrayList^ systemFilePaths)
{
	for each (String^ systemFilePath in systemFilePaths)
	{
		std::string stringFilePath;
		Convert_String_to_string(systemFilePath, stringFilePath);
		parseFile(stringFilePath);
	}
}

void Service::parseFile(std::string stringFilePath)
{
	pcpp::PcapFileReaderDevice reader(stringFilePath.c_str());
	if (!reader.open())
	{
		printf("Error opening the pcap file\n");
	}

	// read the packets from the file
	pcpp::RawPacket rawPacket;
	while (reader.getNextPacket(rawPacket))
	{
		// parse the raw packet into a parsed packet
		pcpp::Packet parsedPacket(&rawPacket);

		if (parsedPacket.isPacketOfType(pcpp::UDP))
		{
			pcpp::UdpLayer* udp = parsedPacket.getLayerOfType<pcpp::UdpLayer>();
			
			printf("\n\t\tUDP\n");
			printf("Source UDP port: %d\n", (int)udp->getUdpHeader()->portSrc);
			printf("Destination UDP port: %d\n", (int)udp->getUdpHeader()->portDst);
			printf("Length of header and playload in bytes: %d\n", (int)udp->getUdpHeader()->length);
		}
		else if (parsedPacket.isPacketOfType(pcpp::TCP))
		{
			pcpp::TcpLayer* tcp = parsedPacket.getLayerOfType<pcpp::TcpLayer>();

			printf("\n\t\tTCP\n");
			printf("Source TCP port: %d\n", (int)tcp->getTcpHeader()->portSrc);
			printf("Destination TCP port: %d\n", (int)tcp->getTcpHeader()->portDst);
			printf("Window size: %d\n", (int)tcp->getTcpHeader()->windowSize);
		}
		else if (parsedPacket.isPacketOfType(pcpp::DNS))
		{
			pcpp::DnsLayer* dns = parsedPacket.getLayerOfType<pcpp::DnsLayer>();

			printf("\n\t\tDNS\n");
			printf("DNS authentic data: %d\n", (int)dns->getDnsHeader()->authenticData);
			printf("DNS transaction ID: %d\n", (int)dns->getDnsHeader()->transactionID);
		}
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
		else if (parsedPacket.isPacketOfType(pcpp::Ethernet))
		{
			pcpp::EthLayer* eth = parsedPacket.getLayerOfType<pcpp::EthLayer>();

			printf("\n\t\tETHERNET\n");
			printf("Ether type = 0x%X\n", eth->getEthHeader()->etherType);
			printf("Ethrenet source MAC address: %d\n", (int)eth->getEthHeader()->srcMac);
			printf("Ethrenet destination MAC address: %d\n", (int)eth->getEthHeader()->dstMac);
		}
		else if (parsedPacket.isPacketOfType(pcpp::IPv4))
		{
			pcpp::IPv4Layer* ip4 = parsedPacket.getLayerOfType<pcpp::IPv4Layer>();

			printf("\n\t\tIPv4\n");
			printf("Source IP: %d\n", (int)ip4->getIPv4Header()->ipSrc);
			printf("Destination IP: %d\n", (int)ip4->getIPv4Header()->ipDst);
			printf("IP ID: 0x%X\n", ip4->getIPv4Header()->ipId);
			printf("TTL (eight-bit): %d\n", (int)ip4->getIPv4Header()->timeToLive);
		}
		else
			printf("\nIDK! But not for a long time\n");

	}
	// close the file
	reader.close();
}
