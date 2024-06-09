#pragma once
#include "users.hpp"
class Student : public Users
{
public:
    Student(string studentID, string studentName, string studentMajor, string studentSemester, string studentPass);
    vector<Student *> students;
    string getSemester() { return sSemester; }
    bool CanTakeCourse(string coursePre , vector<string> courseMajor , string time , string examDate);
    void AddCourse(vector<string> courseLine);
    void DeleteCourse(string courseID);
    void PrintCourses();

private:
    string sSemester , sMajor;
    vector<vector<string>> stdCourses;
    vector<vector<string>> stdCourseTime;
    bool MatchClassAndExamTime(string time , string examDate);
    bool MatchClassTime(string time);
};