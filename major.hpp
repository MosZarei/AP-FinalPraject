#pragma once
#include "requarment.hpp"

class Major
{
public:
    Major(string majorID, string majorName);
    string getMajorName() { return mName; }
    string getID() { return mID; }

private:
    string mID, mName;
};