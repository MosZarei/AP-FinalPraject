#include "superCommand.hpp"
#include <algorithm>

GetCommand::GetCommand(vector<Major *> inputMajorVector, vector<Student *> inputStudentVector,
                       vector<Course *> inputCourseVector, vector<Professor *> inputProfessorVector,
                       Users *inputDefaultUser, string inputSubCommand, string inputArguments, string inputUserWhoLogged, vector<vector<string>> inputCourseOfferList)
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
    tempCourseOfferList = inputCourseOfferList;
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
        GetCourses(arguments);
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

bool SortCourseList(vector<string> a, vector<string> b) { return a[0] < b[0]; }

void GetCommand::GetCourses(vector<string> inputArgs)
{
    bool isCourse = false;
    int courseListLine = 0;
    if (inputArgs.size() == 1 || inputArgs.size() > 2)
    {
        throw ErrorHandler(3);
    }
    if (inputArgs.size() == 0)
    {
        if (tempCourseOfferList.size() != 0)
        {
            sort(tempCourseOfferList.begin(), tempCourseOfferList.end(), SortCourseList);
            for (int i = 0; i < tempCourseOfferList.size(); i++)
            {
                cout << tempCourseOfferList[i][0] << " "
                     << FindCourse(tempCourseOfferList[i][0])->getName() << " "
                     << tempCourseOfferList[i][2] << " "
                     << FindProfessor(tempCourseOfferList[i][1])->getName() << endl;
            }
        }
        else
        {
            throw ErrorHandler(1);
        }
    }
    else if (inputArgs.size() == 2)
    {
        if (stoi(inputArgs[1]) < 1)
        {
            throw ErrorHandler(3);
        }
        for (courseListLine; courseListLine < tempCourseOfferList.size(); courseListLine++)
        {
            if (tempCourseOfferList[courseListLine][0] == inputArgs[1])
            {
                isCourse = true;
                break;
            }
        }
        if (!isCourse)
        {
            throw ErrorHandler(2);
        }
        cout << tempCourseOfferList[courseListLine][0] << " "
             << FindCourse(tempCourseOfferList[courseListLine][0])->getName() << " "
             << tempCourseOfferList[courseListLine][2] << " "
             << FindProfessor(tempCourseOfferList[courseListLine][1])->getName() << " "
             << tempCourseOfferList[courseListLine][3] << " "
             << tempCourseOfferList[courseListLine][4] << " "
             << tempCourseOfferList[courseListLine][5] << " " << endl;
    }
}