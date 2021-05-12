#pragma once

#include "SessionHelper.h"

int findStartPoint(std::vector<SessionHelper>& sessions);

void findUnusingPackets(std::vector<PacketHelper>& packets);

std::vector<size_t> findSubstring(std::vector<SessionHelper>& sessions, std::string str);

int findSubstringAt(std::vector<SessionHelper>& sessions, std::string str);