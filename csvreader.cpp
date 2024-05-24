#include "csvreader.hpp"

int CSVReader::numOfLines(char *file)
{
    string tempString;
    int numOfLines = 0;
    ifstream myFile(file);
    while (getline(myFile, tempString))
    {
        numOfLines++;
    }
    return numOfLines;
}

CSVReader::CSVReader(char *fileName)
{
    ifstream inputFile(fileName);
    string line;
    string dataString;
    vector<vector<string>> tempVector(numOfLines(fileName));
    for (int i = 0; i < numOfLines(fileName); i++)
    {
        getline(inputFile, line);
        stringstream streamLine(line);
        while (getline(streamLine, dataString, ','))
        {
            tempVector[i].push_back(dataString);
        }
    }
    for (int i = 0 ; i < tempVector.size() ; i++)
    {
        for (int j = 0 ; j < tempVector[i].size() ; j++)
        {
            cout << tempVector[i][j] << " - ";
        }
        cout << endl;
    }
    data = tempVector;
}

void CSVReader::Print()
{
    for (int i = 0; i < data.size(); i++)
    {
        cout << "salam";
        for (int j = 0; j > data[i].size(); j++)
        {
            cout << "khodafez";
            cout << data[i][j] << " - ";
        }
        cout << endl;
    }
}