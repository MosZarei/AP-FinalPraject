#include "requarment.hpp"

class CSVReader
{
public:
    CSVReader(char *fileName);
    void Print();
    string getObject(int line , int column);

private:
    vector<vector<string>> data;
    int numOfLines(char* file);
};