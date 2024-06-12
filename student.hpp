#pragma once
#include "users.hpp"
class Student : public Users
{
public:
    Student(string studentID, string studentName, string studentMajor, string studentSemester, string studentPass);
    vector<Student *> students;
    string getSemester() { return sSemester; }
    vector<vector<string>> getStudentCourses() { return stdCourses; }
    string getCourseName(int line) { return stdCourses[line][6]; }
    bool CanTakeCourse(string coursePre, vector<string> courseMajor, string time, string examDate);
    void AddCourse(vector<string> courseLine);
    void DeleteCourse(string courseID);
    void PrintCourses();

private:
    string sSemester, sMajor;
    vector<vector<string>> stdCourses;
    vector<vector<string>> stdCourseTime;
    bool MatchClassAndExamTime(string time, string examDate);
    bool MatchClassTime(string time);
};