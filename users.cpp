#include "users.hpp"

Users::Users(string userName, string userPass, string userMajor)
{
    if (userName == "" || userPass == "" || userMajor == "")
    {
        // handling exception
    }
    name = userName;
    password = userPass;
    majorID = userMajor;
}

bool Users::MatchPassword(string userPass)
{
    if (userPass == password)
    {
        return true;
    }
    return false;
}

bool Users::LoggedIn()
{
    if (userLogged == LOGGED_IN)
    {
        return true;
    }
    return false;
}

void Users::MakeLoggedIn()
{
    userLogged = LOGGED_IN;
    cout << "OK" << endl;
}