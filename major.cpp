#include "major.hpp"

Major::Major(string majorID , string majorName)
{
    if (majorID == "" || majorName == "")
    {
        //handling exception
    }
    mID = majorID;
    mName = majorName;
}