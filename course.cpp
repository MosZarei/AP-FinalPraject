#include "course.hpp"

Course::Course(string courseID, string courseName, string courseCredit, string coursePre, string courseMajors)
{
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
    vector<string> tempV;
    while (getline(majorStream , temp , SEMICOLON))
    {
        tempV.push_back(temp);
    }

    return tempV;
}