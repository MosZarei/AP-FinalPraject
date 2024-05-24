#include "requarment.hpp"

class CSVReader
{
public:
    CSVReader(char *fileName);
    void Print();

private:
    vector<vector<string>> data;
    int numOfLines(char* file);
};