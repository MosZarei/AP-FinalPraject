#include "csvreader.hpp"

CSVReader::CSVReader(char *fileName)
{
    ifstream inputFile(fileName);
    string line;
    string dataString;
    getline(inputFile, line);
    for (int i = 0; i < numOfLines(fileName); i++)
    {
        vector<string> tempVector;
        getline(inputFile, line);
        stringstream streamLine(line);
        while (getline(streamLine, dataString,COMMA))
        {
            tempVector.push_back(dataString);
        }
        data.push_back(tempVector);
    }
}

string CSVReader::getObject(int line , int column)
{
    return data[line - 1][column - 1];
}