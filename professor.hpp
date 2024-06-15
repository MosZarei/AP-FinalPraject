#pragma once
#include "users.hpp"
#include "course.hpp"
class Professor : public Users
{
public:
    Professor(string professorID, string professorName, string professorMajor, string professorPositin, string professorPass);
    vector<Professor *> professors;
    string getPosition() { return pPosition; }
    string getCourseName(int line) { return professorCourses[line]->getName(); }
    bool CanGetCourse(vector<string> courseMajorsID);
    bool MatchTime(string time, Course *courseLine);
    bool HaveCourse(string courseID);
    void AddTAForm(Course *selectedCourse , string message);
    vector<Course *> getProfessorCourses() { return professorCourses; }

private:
    string pPosition;
    vector<vector<string>> courseOfferTime;
    vector<Course *> professorCourses;
    vector<TAForm *> TAFormsList;
};