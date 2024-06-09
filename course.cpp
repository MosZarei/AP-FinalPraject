#include "course.hpp"

Course::Course(string courseID, string courseName, string courseCredit, string coursePre, string courseMajors)
{
    if (courseID == "" || courseName == "" || courseCredit == "" || coursePre == "" || courseMajors == "")
    {
        //handling exception
    }
    cID = courseID;
    cName = courseName;
    cCredit = courseCredit;
    cPre = coursePre;
    cMajorString = courseMajors;
}

vector<string> Course::getMajor()
{
    stringstream majorStream (cMajorString);
    string temp;
    while (getline(majorStream , temp , SEMICOLON))
    {
        cMajorVec.push_back(temp);
    }
    return cMajorVec;
}