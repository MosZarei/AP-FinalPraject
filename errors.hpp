#pragma once
#include "requarment.hpp"

class ErrorHandler
{
public:
    ErrorHandler(int errorNum);
    void GetErrorMessage() { cerr << errorMessage << endl; }
private:
    string errorMessage = "";
};
