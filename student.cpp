#include "student.hpp"

Student::Student(string studentName, string studentPass, string studentMajor, string studentID, string studentSemester)
    : Users(studentName, studentPass, studentMajor)
{
    if (studentID == "" || studentSemester == "")
    {
        // handling exception
    }
    sID = studentID;
    semester = studentSemester;
}