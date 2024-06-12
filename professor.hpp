#pragma once
#include "users.hpp"
class Professor : public Users
{
public:
    Professor(string professorID, string professorName, string professorMajor, string professorPositin, string professorPass);
    vector<Professor *> professors;
    string getPosition() { return pPosition; }
    bool CanGetCourse(vector<string> courseMajorsID);
    bool MatchTime(string time , vector<string> courseLine);
    vector<vector<string>> getProfessorCourses() { return professorCourses; }
private:
    string pPosition;
    vector<vector<string>> courseOfferTime;
    vector<vector<string>> professorCourses;
};