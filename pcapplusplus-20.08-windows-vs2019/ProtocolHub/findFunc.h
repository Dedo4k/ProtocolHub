#pragma once

#include "SessionHelper.h"

int findStartPoint(std::vector<SessionHelper>& sessions);

void findUnusingPackets(std::vector<SessionHelper>& packets);

std::vector<size_t> findSubstring(std::vector<std::string>& strings, std::string str);

int findSubstringAt(std::vector<std::string>& strings, std::string str);

std::vector<bool> findMatch(std::vector<std::string>& strings);

void fwriteSessionsPcapng(std::string fileapth, std::vector<SessionHelper>& sessions);