#pragma once
#include "users.hpp"
#include "course.hpp"
class Student : public Users
{
public:
    Student(string studentID, string studentName, string studentMajor, string studentSemester, string studentPass);
    vector<Student *> students;
    string getSemester() { return sSemester; }
    vector<Course *> getStudentCourses() { return stdCourses; }
    string getCourseName(int line) { return stdCourses[line]->getName(); }
    bool CanTakeCourse(string coursePre, vector<string> courseMajor, string time, string examDate);
    void AddCourse(Course *courseLine);
    void DeleteCourse(string courseID);
    void PrintCourses();

private:
    string sSemester, sMajor;
    vector<Course *> stdCourses;
    vector<vector<string>> stdCourseTime;
    bool MatchClassAndExamTime(string time, string examDate);
    bool MatchClassTime(string time);
};