#include "superCommand.hpp"

GetCommand::GetCommand(vector<Major *> inputMajorVector, vector<Student *> inputStudentVector,
                       vector<Course *> inputCourseVector, vector<Professor *> inputProfessorVector,
                       Users *inputDefaultUser, string inputSubCommand, string inputArguments, string inputUserWhoLogged, vector<vector<string>> inputCourseOffers)
    : SuperCommand(inputMajorVector, inputStudentVector, inputCourseVector, inputProfessorVector, inputDefaultUser, inputCourseOffers)
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
    userWhoLogged = inputUserWhoLogged;
}

bool GetCommand::CheckSubCommand(string inputSubCommand)
{
    for (int i = 0; i < getSubCommandsList.size(); i++)
    {
        if (inputSubCommand == getSubCommandsList[i])
        {
            return true;
        }
    }
    return false;
}

void GetCommand::RunCommand()
{
    if (subCommand == "courses")
    {
        // LoginFunc(arguments);
    }
    else if (subCommand == "personal_page")
    {
        // LogoutFunc(arguments);
    }
    else if (subCommand == "post")
    {
        // PostFunc(arguments);
    }
    else if (subCommand == "notification")
    {
        GetNotifications(arguments);
    }
    else if (subCommand == "my_courses")
    {
        // course_offer func
    }
}

void GetCommand::GetNotifications(vector<string> inputArgs)
{
    if (inputArgs.size() != 0)
    {
        throw ErrorHandler(3);
    }
    ShowNotificaion(userWhoLogged);
}