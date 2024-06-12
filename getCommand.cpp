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
    tempDefaultUser = inputDefaultUser;
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
        GetPersonalPage(arguments);
    }
    else if (subCommand == "post")
    {
        GetPost(arguments);
    }
    else if (subCommand == "notification")
    {
        GetNotifications(arguments);
    }
    else if (subCommand == "my_courses")
    {
        GetMyCourses(arguments);
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
            if (tempCourseOfferList.size() >= 1)
            {
                sort(tempCourseOfferList.begin(), tempCourseOfferList.end(), SortCourseList);
            }
            for (int i = 0; i < tempCourseOfferList.size(); i++)
            {
                cout << tempCourseOfferList[i][0] << " "
                     << FindCourse(tempCourseOfferList[i][0])->getName() << " "
                     << tempCourseOfferList[i][2] << " "
                     << tempCourseOfferList[i][1] << endl;
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
             << tempCourseOfferList[courseListLine][1] << " "
             << tempCourseOfferList[courseListLine][3] << " "
             << tempCourseOfferList[courseListLine][4] << " "
             << tempCourseOfferList[courseListLine][5] << " " << endl;
    }
}

void GetCommand::GetMyCourses(vector<string> inputArgs)
{
    if (inputArgs.size() != 0)
    {
        throw ErrorHandler(3);
    }
    GetStudentCourses(userWhoLogged);
}

void GetCommand::GetPersonalPage(vector<string> inputArgs)
{
    if (inputArgs.size() != 2)
    {
        throw ErrorHandler(3);
    }
    if (stoi(inputArgs[1]) < 0)
    {
        throw ErrorHandler(3);
    }
    if (IsStudent(inputArgs[1]))
    {
        cout << FindStudent(inputArgs[1])->getName() << " " << FindMajor(FindStudent(inputArgs[1])->getMajor())->getMajorName() << " "
             << FindStudent(inputArgs[1])->getSemester() << " ";
        for (int i = 0; i < FindStudent(inputArgs[1])->getStudentCourses().size(); i++)
        {
            cout << FindStudent(inputArgs[1])->getCourseName(i);
            if (i != FindStudent(inputArgs[1])->getStudentCourses().size() - 1)
            {
                cout << ",";
            }
        }
        cout << endl;
        for (int i = FindStudent(inputArgs[1])->getPostsNumber() - 1; i >= 0; i--)
        {
            FindStudent(inputArgs[1])->PrintPosts(i);
        }
    }
    else if (IsProfessor(inputArgs[1]))
    {
        cout << FindProfessor(inputArgs[1])->getName() << " " << FindMajor(FindProfessor(inputArgs[1])->getMajor())->getMajorName() << " "
             << FindProfessor(inputArgs[1])->getPosition() << " ";
        for (int i = 0 ; i < FindProfessor(inputArgs[1])->getProfessorCourses().size() ; i++)
        {
            cout << FindProfessor(inputArgs[1])->get
        }
    }
    else if (inputArgs[1] == "0")
    {
        cout << "UT_account" << endl;
        for (int i = tempDefaultUser->getPostsNumber() - 1; i >= 0; i--)
        {
            tempDefaultUser->PrintPosts(i);
        }
    }
    else
    {
        throw ErrorHandler(2);
    }
}

void GetCommand::GetPost(vector<string> inputArgs)
{
    if (inputArgs.size() != 4)
    {
        throw ErrorHandler(3);
    }
    string userID;
    string postID;
    if (inputArgs[0] == "id")
    {
        userID = inputArgs[1];
        postID = inputArgs[3];
    }
    else
    {
        postID = inputArgs[1];
        userID = inputArgs[3];
    }
    if (stoi(userID) < 0 || stoi(postID) < 1)
    {
        throw ErrorHandler(3);
    }
    if (IsStudent(userID))
    {
        if (!FindStudent(userID)->CheckPostExistence(postID))
        {
            throw ErrorHandler(2);
        }
        cout << FindStudent(userID)->getName() << " " << FindMajor(FindStudent(userID)->getMajor())->getMajor() << " "
             << FindStudent(userID)->getSemester() << " ";
        for (int i = 0; i < FindStudent(userID)->getStudentCourses().size(); i++)
        {
            cout << FindStudent(userID)->getCourseName(i);
            if (i != FindStudent(userID)->getStudentCourses().size() - 1)
            {
                cout << ",";
            }
        }
        cout << endl;
        for (int i = FindStudent(userID)->getPostsNumber() - 1; i >= 0; i--)
        {
            FindStudent(userID)->PrintPostDetail(i);
        }
    }
    else if (IsProfessor(userID))
    {
    }
    else if (userID == "0")
    {
        cout << "UT_account" << endl;
        for (int i = tempDefaultUser->getPostsNumber() - 1; i >= 0; i--)
        {
            tempDefaultUser->PrintPostDetail(i);
        }
    }
    else
    {
        throw ErrorHandler(2);
    }
}