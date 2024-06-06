#include "main.hpp"

PostCommand::PostCommand(char *majorsCSV, char *studentsCSV, char *coursesCSV, char *professorsCSV , string inputSubCommand, string inputArguments)
            :Main(majorsCSV , studentsCSV , coursesCSV , professorsCSV)
{
    if (!CheckSubCommand(inputSubCommand))
    {
        throw ErrorHandler(2);
    }
    subCommand = inputSubCommand;
    stringstream argstream(inputArguments);
    string temp;
    while (getline(argstream, temp, ' '))
    {
        arguments.push_back(temp);
    }
}

bool PostCommand::CheckSubCommand(string inputSubCommand)
{
    for (int i = 0; i < postSubCommandsList.size(); i++)
    {
        if (inputSubCommand == postSubCommandsList[i])
        {
            return true;
        }
    }
    return false;
}

void PostCommand::RunCommand()
{
    if (subCommand == "login")
    {
        LoginFunc(arguments);
    }
    else if (subCommand == "logout")
    {
        // logout func
    }
    else if (subCommand == "post")
    {
        // post func
    }
    else if (subCommand == "connect")
    {
        // connect func
    }
    else if (subCommand == "course_offer")
    {
        // course_offer func
    }
}

void PostCommand::LoginFunc(vector<string> inputArgs)
{
    if (inputArgs.size() != 4)
    {
        throw ErrorHandler(3);
    }
    string inputID, inputPassword;
    if (inputArgs[0] == "id")
    {
        inputID = inputArgs[1];
        inputPassword = inputArgs[3];
    }
    else
    {
        inputID = inputArgs[3];
        inputPassword = inputArgs[1];
    }
    if (!IsUser(inputID))
    {
        throw ErrorHandler(2);
    }
    if (!IsUserPasswordMatch(inputID , inputPassword))
    {
        throw ErrorHandler(4);
    }
    if (isUserLoggedIn)
    {
        throw ErrorHandler(4);
    }
    MakeUserLoggedIn();
}