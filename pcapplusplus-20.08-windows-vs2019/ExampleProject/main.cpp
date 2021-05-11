#include "SessionHelper.h"
#include "findFunc.h"

int main(int argc, char* argv[])
{
	system("color 0a");

	// open a pcap file for reading
	pcpp::PcapFileReaderDevice reader("my.pcap");
	if (!reader.open())
	{
		printf("Error opening the pcap file\n");
		return 1;
	}

	std::vector<PacketHelper> packets;
	std::vector<SessionHelper> sessions;
	// read the packets from the file
	pcpp::RawPacket rawPacket;

	while (reader.getNextPacket(rawPacket))
	{
		PacketHelper pack(rawPacket);
		if (pack.getSrcIp().toString() == "0.0.0.0" || pack.getDstIp().toString() == "0.0.0.0")
			continue;
		else
			packets.push_back(pack);
	}
	bool flag = true;
	while (flag && sessions.size() < 40)
	{
		SessionHelper sess(packets);
		if (sess.isSession())
			sessions.push_back(sess);
		else
			flag = false;
	}

	//find unusing packets and delete them
	std::cout << packets.size() << std::endl;
	findUnusingPackets(packets);
	std::cout << packets.size();

	int startPoint = findStartPoint(sessions);
	for (size_t i = 0; i < sessions.size(); i++)
	{
		std::cout << "\n-------------------------------------------\n";
		std::cout << sessions[i].getSrcIp().toString() << ':' << sessions[i].getSrcPort()
			<< '\t' << sessions[i].getDstIp().toString() << ':' << sessions[i].getDstPort()
			<< '\n' << sessions[i].getTimeStart()-startPoint << "->" << sessions[i].getTimeStart()
			+ sessions[i].getTimeEnd() - startPoint;
		std::cout << "\n-------------------------------------------\n";
		for (size_t j = 0; j < sessions[i].getBytes().size(); j++)
		{
			std::cout << charToAscii((char)sessions[i].getBytes()[j]) << ' ';
		}
		std::cout << "\n-------------------------------------------\n";
	}

	std::cout<<"\nCount of session: " << sessions.size() << '\n';
	// close the file
	reader.close();

	system("pause");
	system("color 0f");

	return 0;
}
