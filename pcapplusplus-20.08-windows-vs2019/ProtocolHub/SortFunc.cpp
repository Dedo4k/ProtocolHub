#include "SortFunc.h"

void sortByTimeStart(std::vector<SessionHelper>& sessions)
{
    if (sessions.size() < 1)
        return;
    else
    {
        for (int i = 0; i < sessions.size() - 1; ++i)
        {
            for (int j = (sessions.size() - 1); j > i; --j)
            {
                if (sessions[j - 1].getTimeStart() > sessions[j].getTimeStart())
                {
                    SessionHelper temp = sessions[j - 1];
                    sessions[j - 1] = sessions[j];
                    sessions[j] = temp;
                }
            }
        }
    }
}

void sortByByte(std::vector<SessionHelper>& sessions)
{
    if (sessions.size() < 1)
        return;
    else
    {
        for (int i = 0; i < sessions.size() - 1; ++i)
        {
            for (int j = (sessions.size() - 1); j > i; --j)
            {
                if (sessions[j-1].getBytes().size() > sessions[j].getBytes().size())
                {
                    SessionHelper temp = sessions[j - 1];
                    sessions[j - 1] = sessions[j];
                    sessions[j] = temp;
                }
            }
        }
    }
}
