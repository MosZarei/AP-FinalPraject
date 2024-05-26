#include "requarment.hpp"

class CSVReader
{
public:
    CSVReader(char *fileName);
    void Print();
    string getObject(int line , int column);
    int numOfLines(char* file);

private:
    vector<vector<string>> data;
};