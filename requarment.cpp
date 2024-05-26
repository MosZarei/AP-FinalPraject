#include "requarment.hpp"

char COMMA = ',';

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