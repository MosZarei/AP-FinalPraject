#pragma once
#include "users.hpp"
class Professor : public Users
{
public:
    Professor(string professorID, string professorName, string professorMajor, string professorPositin, string professorPass);
    vector<Professor *> professors;
    string getID() { return pID; }
    string getPosition() { return pPosition; }

private:
    string pID;
    string pPosition;
};