#include "requarment.hpp"

char COMMA = ',';
string SEPRATOR = "?";

int numOfLines(char *file)
{
    string tempString;
    int numOfLines = 0;
    ifstream myFile(file);
    while (getline(myFile, tempString))
    {
        numOfLines++;
    }
    return numOfLines - 1;
}