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

Users::Users(string userName , string userPass)
{
    name = userName;
    password = userPass;
}

bool Users::MatchPassword(string userPass)
{
    if (userPass == password)
    {
        return true;
    }
    return false;
}
