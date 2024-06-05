#include "superCommands.hpp"

SuperCommand::SuperCommand(string inputSuperCommand , string inputSeprator)
{
    if (!CheckSuperCommandAndSeprator(inputSuperCommand , inputSeprator))
    {
        throw ErrorHandler(3);
    }
    else
    {
        superCommand = inputSuperCommand;
    }
}

bool SuperCommand::CheckSuperCommandAndSeprator(string inputSuperCommand , string inputSeprator)
{
    for (int i = 0 ; i < superCommandsList.size(); i++)
    {
        if (inputSuperCommand == superCommandsList[i] && inputSeprator == SEPRATOR)
        {
            return true;
        }
    }
    return false;
}