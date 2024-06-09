#pragma once
#include "users.hpp"
class Student : public Users
{
public:
    Student(string studentID, string studentName, string studentMajor, string studentSemester, string studentPass);
    vector<Student *> students;
    string getSemester() { return sSemester; }
    bool CanTakeCourse(string coursePre , vector<string> courseMajor);

private:
    string sSemester , sMajor;
};