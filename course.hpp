#pragma once
#include "requarment.hpp"

class Course
{
public:
    Course(string courseID, string courseName, string courseCredit, string coursePre, string courseMajors);
    string getID() { return cID; }
    string getMajor() { return cMajor; }

private:
    string cID, cName, cCredit, cPre, cMajor;
};