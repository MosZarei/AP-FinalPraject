#pragma once
#include "users.hpp"
class Student : public Users
{
public:
    Student(string studentID, string studentName, string studentMajor, string studentSemester, string studentPass);
    vector<Student *> students;
    string getID() { return sID; }
    string getSemester() { return sSemester; }

private:
    string sID;
    string sSemester;
    // void makeStudentsList(char* studentsCSV);
};