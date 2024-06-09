#include "student.hpp"

Student::Student(string studentID, string studentName, string studentMajor, string studentSemester, string studentPass)
    : Users(studentName, studentPass, studentMajor , studentID)
{
    if (studentSemester == "")
    {
        // handling exception
    }
    sSemester = studentSemester;
}