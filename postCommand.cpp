#include "superCommand.hpp"

PostCommand::PostCommand(vector<Major *> inputMajorVector, vector<Student *> inputStudentVector,
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
        LogoutFunc(arguments);
    }
    else if (subCommand == "post")
    {
        PostFunc(arguments);
    }
    else if (subCommand == "connect")
    {
        ConnectFunc(arguments);
    }
    else if (subCommand == "course_offer")
    {
        if(userWhoLogged == "0")
        {
            CourseOfferFunc(arguments);
        }
        else
        {
            throw ErrorHandler(4);
        }
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
    CheckLoginCondditions(inputID, inputPassword);
    userWhoLogged = inputID;
}

void PostCommand::LogoutFunc(vector<string> inputArgs)
{
    if (inputArgs.size() != 0)
    {
        throw ErrorHandler(3);
    }
}

void PostCommand::ConnectFunc(vector<string> inputArgs)
{
    if (inputArgs.size() != 2)
    {
        throw ErrorHandler(3);
    }
    int idNum = stoi(inputArgs[1]);
    if (idNum < 1)
    {
        throw ErrorHandler(3);
    }
    ConnectUsers(userWhoLogged, inputArgs[1]);
    ConnectUsers(inputArgs[1], userWhoLogged);
    cout << "OK" << endl;
}

void PostCommand::PostFunc(vector<string> inputArgs)
{
    vector<string> localArgs;
    localArgs.push_back(inputArgs[0]);
    for (int i = 1; i < inputArgs.size(); i++)
    {
        if (inputArgs[i] == "massage" || inputArgs[i] == "title")
        {
            string title = "";
            string massage = "";
            for (int j = 1; j < i; j++)
            {
                title += inputArgs[j];
                title += " ";
            }
            localArgs.push_back(title);
            localArgs.push_back(inputArgs[i]);
            for (int k = i + 1; k < inputArgs.size(); k++)
            {
                massage += inputArgs[k];
                massage += " ";
            }
            localArgs.push_back(massage);
        }
    }
    if (localArgs.size() != 4)
    {
        throw ErrorHandler(3);
    }
    string postTitle, postMassage;
    if (localArgs[0] == "title")
    {
        postTitle = localArgs[1];
        postMassage = localArgs[3];
    }
    else
    {
        postTitle = localArgs[3];
        postMassage = localArgs[1];
    }
    AddPostToUserPage(userWhoLogged, postTitle, postMassage);
    cout << "OK" << endl;
}

void PostCommand::CourseOfferFunc(vector<string> inputArgs)
{
    if (inputArgs.size() != 12)
    {
        throw ErrorHandler(3);
    }
    string courseID, professorID, capacity, time, examDate, classNumber;
    vector<string> outputArgs;
    for (int i = 0; i < inputArgs.size() / 2; i++)
    {
        if (inputArgs[2 * i] == "course_id")
        {
            courseID = inputArgs[2 * i + 1];
        }
        else if (inputArgs[2 * i] == "professor_id")
        {
            professorID = inputArgs[2 * i + 1];
        }
        else if (inputArgs[2 * i] == "capacity")
        {
            capacity = inputArgs[2 * i + 1];
        }
        else if (inputArgs[2 * i] == "time")
        {
            time = inputArgs[2 * i + 1];
        }
        else if (inputArgs[2 * i] == "exam_date")
        {
            examDate = inputArgs[2 * i + 1];
        }
        else if (inputArgs[2 * i] == "class_number")
        {
            classNumber = inputArgs[2 * i + 1];
        }
    }
    outputArgs.push_back(courseID);
    outputArgs.push_back(professorID);
    outputArgs.push_back(capacity);
    outputArgs.push_back(time);
    outputArgs.push_back(examDate);
    outputArgs.push_back(classNumber);
    //cout << courseID << endl << professorID << endl << capacity << endl << time << endl << examDate << endl << classNumber << endl;
    if (stoi(courseID) < 1 || stoi(professorID) < 1 || stoi(capacity) < 1 || stoi(classNumber) < 1)
    {
        throw ErrorHandler(3);
    }
    CheckCourseAndProfessor(courseID, professorID, time , outputArgs);
    cout << "OK" << endl;
}