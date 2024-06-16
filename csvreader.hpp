#pragma once
#include "requarment.hpp"

class CSVReader
{
public:
    CSVReader(char *fileName);
    string getObject(int line , int column);
private:
    vector<vector<string>> data;
};