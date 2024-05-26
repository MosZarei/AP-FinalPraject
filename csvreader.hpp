#include "requarment.hpp"

class CSVReader
{
public:
    CSVReader(char *fileName);
    void Print();
    string getObject(int line , int column);
    //string getSpecificLine(int lineNumber);

private:
    vector<vector<string>> data;
};