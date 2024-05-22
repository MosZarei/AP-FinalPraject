#include "requarment.hpp"

class CSVReader
{
public:
    CSVReader(char *fileName);

private:
    vector<vector<string>> data;
};