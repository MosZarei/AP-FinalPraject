#pragma once
#include "requarment.hpp"

class Users
{
public:
    Users(string userName, string userPass, string userMajor);
    string getName() { return name; }
    string getPass() { return password; }
    string getMajor() { return majorID; }

private:
    string name;
    string password;
    string majorID;
    LoginState userLogged = LOGGED_OUT;
};