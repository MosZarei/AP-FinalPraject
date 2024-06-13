#include "errors.hpp"

ErrorHandler::ErrorHandler(int errorNum)
{
    switch (errorNum)
    {
    case 0:
        errorMessage = "OK";
        break;
    case 1:
        errorMessage = "Empty";
        break;
    case 2:
        errorMessage = "Not Found";
        break;
    case 3:
        errorMessage = "Bad Request";
        break;
    case 4:
        errorMessage = "Permission Denied";
        break;
    default:
        errorMessage = "Error number is invalid!";
        break;
    }
}