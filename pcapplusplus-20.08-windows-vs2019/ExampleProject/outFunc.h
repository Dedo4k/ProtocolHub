#pragma once
#include <string>
#include <iomanip>

#include <Packet.h>
#include <HTTPLayer.h>
#include <TcpLayer.h>
#include <UdpLayer.h>
#include <IPv4Layer.h>
#include <IPv6Layer.h>
#include <DNSLayer.h>
#include <SSLLayer.h>
#include <SipLayer.h>

//getting tcp flags as string
std::string printTcpFlags(pcpp::TcpLayer* tcp);

//getting tcp option type as string
std::string printTcpOptionType(pcpp::TcpLayer* tcp);

//getting dns operations as string
std::string printDnsOperation(pcpp::DnsLayer* dns);

//getting AIPN as name of protocol
std::string printIPv4Protocol(pcpp::IPv4Layer* ip);

//getting http methods as string
std::string printHTTPMethods(pcpp::HttpRequestLayer* httpRq);

//getting http version as string
std::string printHTTPVersion(pcpp::HttpRequestLayer* httpRq);

//getting http version as string
std::string printHTTPVersion(pcpp::HttpResponseLayer* httpRs);

//getting ssl record type as string
std::string printSslRecordType(pcpp::SSLLayer* ssl);

//getting ssl message as string
std::string printSslMessage(pcpp::Packet& parsedPacket, pcpp::SSLLayer* ssl);

//getting value and convert to hex as string
std::string dToX(int value);

size_t tmToSec(tm &value);