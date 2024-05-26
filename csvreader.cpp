#include "csvreader.hpp"

// int CSVReader::numOfLines(char *file)
// {
//     string tempString;
//     int numOfLines = 0;
//     ifstream myFile(file);
//     while (getline(myFile, tempString))
//     {
//         numOfLines++;
//     }
//     return numOfLines - 1;
// }


// int CSVReader::numOfLines()
// {
//     return dataLines.size();
// }

CSVReader::CSVReader(char *fileName)
{
    ifstream inputFile(fileName);
    string line;
    string dataString;
    getline(inputFile, line);
    for (int i = 0; i < numOfLines(fileName); i++)
    {
        // getline(inputFile, line);
        // dataLines.push_back(line);
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

// void CSVReader::Print()
// {
//     for (int i = 0; i < data.size(); i++)
//     {
//         for (int j = 0; j < data[i].size(); j++)
//         {
//             cout << data[i][j] << " - ";
//         }
//         cout << endl;
//     }
// }

string CSVReader::getObject(int line , int column)
{
    return data[line - 1][column - 1];
}