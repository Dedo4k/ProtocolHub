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

using namespace System;

ref class Service
{
public:

	static void parseFilesInList(System::Collections::ArrayList^ systemFilePaths);

	static void parseFile(std::string stringFilePath);
};