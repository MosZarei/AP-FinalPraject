#include "superCommand.hpp"

DeleteCommand::DeleteCommand(vector<Major *> inputMajorVector, vector<Student *> inputStudentVector,
                             vector<Course *> inputCourseVector, vector<Professor *> inputProfessorVector,
                             Users *inputDefaultUser, string inputSubCommand, string inputArguments, string inputUserWhoLogged)
    : SuperCommand(inputMajorVector, inputStudentVector, inputCourseVector, inputProfessorVector, inputDefaultUser)
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

bool DeleteCommand::CheckSubCommand(string inputSubCommand)
{
    for (int i = 0; i < deleteSubCommandsList.size(); i++)
    {
        if (inputSubCommand == deleteSubCommandsList[i])
        {
            return true;
        }
    }
    return false;
}

void DeleteCommand::RunCommand()
{
    if (subCommand == "post")
    {
        DeletePostFunc(arguments);
    }
    else if (subCommand == "my_courses")
    {
        DeleteMyCourseFunc(arguments);
    }
}

void DeleteCommand::DeletePostFunc(vector<string> inputArgs)
{
    if (inputArgs.size() != 2)
    {
        throw ErrorHandler(3);
    }
    DeletePostOfUserPage(userWhoLogged, inputArgs[1]);
    cout << "OK" << endl;
}

void DeleteCommand::DeleteMyCourseFunc(vector<string> inputArgs)
{
    if(inputArgs.size() != 2)
    {
        throw ErrorHandler(3);
    }
    if(stoi(inputArgs[1]) < 1)
    {
        throw ErrorHandler(3);
    }
    DeleteStudentCourse(userWhoLogged , inputArgs[1]);
    cout << "OK" << endl;
}