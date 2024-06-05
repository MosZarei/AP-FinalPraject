#pragma once
#include "requarment.hpp"

class ErrorHandler
{
public:
    ErrorHandler(int errorNum);
    void GetErrorMassage() { cerr << errorMassage << endl; }
private:
    string errorMassage = "";
};
