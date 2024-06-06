#pragma once
#include "requarment.hpp"

class Users
{
public:
    Users(string userName, string userPass, string userMajor);
    string getName() { return name; }
    string getPass() { return password; }
    string getMajor() { return majorID; }
    bool MatchPassword(string userPass);
    bool LoggedIn();
    void MakeLoggedIn();
private:
    string name;
    string password;
    string majorID;
    LoginState userLogged = LOGGED_OUT;
};