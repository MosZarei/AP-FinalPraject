#include "student.hpp"
#include "csvreader.hpp"

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

void Student::makeStudentsList(char* studentsCSV)
{
    CSVReader studentsFile(studentsCSV);
}