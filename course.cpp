#include "course.hpp"

Course::Course(string courseID, string courseName, string courseCredit, string coursePre, string courseMajors)
{
    ID = courseID;
    name = courseName;
    credit = courseCredit;
    pre = coursePre;
    majorString = courseMajors;
}

Course::Course(string courseID , string courseName , string courseCapacity , string profName , string courseTime , string courseExamDate , string classNum)
{
    ID = courseID;
    name = courseName;
    capacity = courseCapacity;
    professorName = profName;
    time = courseTime;
    examDate = courseExamDate;
    classNumber = classNum;
}

vector<string> Course::getMajor()
{
    stringstream majorStream (majorString);
    string temp;
    vector<string> tempV;
    while (getline(majorStream , temp , SEMICOLON))
    {
        tempV.push_back(temp);
    }

    return tempV;
}