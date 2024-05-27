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
    cMajor = courseMajors;
}