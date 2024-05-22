#include "users.hpp"

Users::Users(string userName , string userPass)
{
    if (userName == "" || userPass == "")
    {
        //handling exception
    }
    name = userName;
    password = userPass;
}