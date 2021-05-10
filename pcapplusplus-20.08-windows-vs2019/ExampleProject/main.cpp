#include "PacketHelper.h"
#include <Layer.h>
#include <Packet.h>
#include <PcapFileDevice.h>
#include <stdio.h>
#include <stdlib.h>
#include <SystemUtils.h>

int main(int argc, char* argv[])
{
	system("color 0a");

	// open a pcap file for reading
	pcpp::PcapFileReaderDevice reader("http.pcap");
	if (!reader.open())
	{
		printf("Error opening the pcap file\n");
		return 1;
	}

	//count of parsed protcols
	int counter = 0;

	// read the packets from the file
	pcpp::RawPacket rawPacket;
	while (reader.getNextPacket(rawPacket) && counter < 50)
	{
		PacketHelper pack(rawPacket);
		std::cout << std::endl << pack.getSrcIp().toString() << '\t' << pack.getDstIp().toString()
			<< '\t' << pack.getProtocolName() << '\t'<<pack.getTimestampAsString()<<'\t'
			<< std::endl << std::endl;

		for (size_t i = 0; i < pack.getProtocols().size(); ++i)
			std::cout << pack.getProtocols()[i] << std::endl;
		std::cout << "-----------------------------------------------" << std::endl << std::endl;
		++counter;
	}

	std::cout<<"\nCount of packets: " << counter << '\n';
	// close the file
	reader.close();

	system("pause");
	system("color 0f");

	return 0;
}
