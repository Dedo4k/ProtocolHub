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
#include "PacketHelper.h"

using namespace System;

ref class Service
{
public:
	static std::vector<PacketHelper> getAllPackets(std::vector<std::string> stringFilePaths);

	static System::Collections::ArrayList^ parseAll(System::Collections::ArrayList^ systemFilePaths);

	static std::vector<std::string> convertToString(System::Collections::ArrayList^ systemFilePaths);

	static void parseFilesInList(System::Collections::ArrayList^ systemFilePaths);

	static void parseFile(std::string stringFilePath);
};