#include "superCommand.hpp"

PutCommand::PutCommand(vector<Major *> inputMajorVector, vector<Student *> inputStudentVector,
                       vector<Course *> inputCourseVector, vector<Professor *> inputProfessorVector,
                       Users *inputDefaultUser, string inputSubCommand, string inputArguments, string inputUserWhoLogged, vector<Course *> inputCourseOfferList)
    : SuperCommand(inputMajorVector, inputStudentVector, inputCourseVector, inputProfessorVector, inputDefaultUser , inputCourseOfferList)
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
    tempCourseOfferList = inputCourseOfferList;
}

bool PutCommand::CheckSubCommand(string inputSubCommand)
{
    for (int i = 0; i < putSubCommandsList.size(); i++)
    {
        if (inputSubCommand == putSubCommandsList[i])
        {
            return true;
        }
    }
    return false;
}

void PutCommand::RunCommand()
{
    if (subCommand == "my_courses")
    {
        PutMyCoursesFunc(arguments);
    }
}

void PutCommand::PutMyCoursesFunc(vector<string> inputArgs)
{
    bool isCourse = false;
    int courseCounter = 0;
    if (inputArgs.size() != 2)
    {
        throw ErrorHandler(3);
    }
    if (stoi(inputArgs[1]) < 1)
    {
        throw ErrorHandler(3);
    }
    for (courseCounter; courseCounter < tempCourseOfferList.size(); courseCounter++)
    {
        if (tempCourseOfferList[courseCounter]->getID() == inputArgs[1])
        {
            isCourse = true;
            break;
        }
    }
    if (!isCourse)
    {
        throw ErrorHandler(2);
    }
    CheckStudentConditions(inputArgs[1], userWhoLogged, tempCourseOfferList[courseCounter]->GetTime(), tempCourseOfferList[courseCounter]->GetExamDate(), tempCourseOfferList[courseCounter]);
    cout << "OK" << endl;
}