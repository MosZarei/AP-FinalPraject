#include "student.hpp"

Student::Student(string studentID, string studentName, string studentMajor, string studentSemester, string studentPass)
    : Users(studentName, studentPass, studentMajor , studentID)
{
    if (studentSemester == "")
    {
        // handling exception
    }
    sSemester = studentSemester;
    sMajor = studentMajor;
}

bool Student::CanTakeCourse(string coursePre , vector <string> courseMajor)
{
    for (int i = 0 ; i < courseMajor.size() ; i++)
    {
        if(sMajor == courseMajor[i] && sSemester >= coursePre)
        {
            return true;
        }
    }
    return false;
}