#pragma once
#include "requarment.hpp"

class Course
{
public:
    Course(string courseID, string courseName, string courseCredit, string coursePre, string courseMajors);
    Course(string courseID, string courseName, string courseCapacity, string profName, string courseTime, string examDate, string classNum);
    string getID() { return ID; }
    vector<string> getMajor();
    string getName() { return name; }
    string GetCapacity() { return capacity; }
    string GetProfName() { return professorName; }
    string GetTime() { return time; }
    string GetExamDate() { return examDate; }
    string GetClassNum() { return classNumber; }
    string GetPre() { return pre; }

private:
    string ID, name, credit, pre, majorString,
        capacity, professorName, time, examDate, classNumber;
    vector<string> cMajorVec;
    vector<Users *> courseAdmins;
    vector<UserPosts *> coursePosts;
    vector<Student *> studentsWhoTakedCourse;
};