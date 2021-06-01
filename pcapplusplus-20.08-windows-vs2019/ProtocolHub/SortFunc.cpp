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
                long size1 = 0, size2 = 0;
                for (size_t k = 0; k < sessions[j-1].getBytes().size(); ++k)
                    size1 += sessions[j-1].getBytes()[k].length();
                for (size_t k = 0; k < sessions[j].getBytes().size(); ++k)
                    size2 += sessions[j].getBytes()[k].length();

                if (size1 > size2)
                {
                    SessionHelper temp = sessions[j - 1];
                    sessions[j - 1] = sessions[j];
                    sessions[j] = temp;
                }
            }
        }
    }
}
