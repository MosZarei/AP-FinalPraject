#include "errors.hpp"

ErrorHandler::ErrorHandler(int errorNum)
{
    switch (errorNum)
    {
    case 1:
        errorMassage = "Empty";
        break;
    case 2:
        errorMassage = "Not Found";
        break;
    case 3:
        errorMassage = "Bad Request";
        break;
    case 4:
        errorMassage = "Permission Denied";
        break;
    default:
        errorMassage = "Error number is invalid!";
        break;
    }
}