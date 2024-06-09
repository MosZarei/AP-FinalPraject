#pragma once
#include "requarment.hpp"

class Course
{
public:
    Course(string courseID, string courseName, string courseCredit, string coursePre, string courseMajors);
    string getID() { return cID; }
    vector<string> getMajor();
    string getName() { return cName; }
    string GetPre() { return cPre; }

private:
    string cID, cName, cCredit, cPre, cMajorString;
    vector<string> cMajorVec;
};