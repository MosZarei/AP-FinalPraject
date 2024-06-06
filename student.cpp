#include "student.hpp"

Student::Student(string studentID, string studentName, string studentMajor, string studentSemester, string studentPass)
    : Users(studentName, studentPass, studentMajor)
{
    if (studentID == "" || studentSemester == "")
    {
        // handling exception
    }
    sID = studentID;
    sSemester = studentSemester;
}