#pragma once
#include "requarment.hpp"

class Users
{
public:
    Users(string userName, string userPass, string userMajor);
    Users(string userName , string userPass);
    string getName() { return name; }
    string getPass() { return password; }
    string getMajor() { return majorID; }
    bool MatchPassword(string userPass);
private:
    string name , password , majorID;
};