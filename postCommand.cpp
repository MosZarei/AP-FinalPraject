#include "superCommand.hpp"

PostCommand::PostCommand(vector<Major *> inputMajorVector, vector<Student *> inputStudentVector,
                         vector<Course *> inputCourseVector, vector<Professor *> inputProfessorVector,
                         Users *inputDefaultUser, string inputSubCommand, string inputArguments, string inputUserWhoLogged, vector<vector<string>> inputCourseOffers)
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
    tempCourseOffer = inputCourseOffers;
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
        if (userWhoLogged == "0")
        {
            CourseOfferFunc(arguments);
        }
        else
        {
            throw ErrorHandler(4);
        }
    }
    else if (subCommand == "profile_photo")
    {
        ProfilePhotoFunc(arguments);
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
    string fullArg = "";
    for (int i = 0; i < inputArgs.size(); i++)
    {
        fullArg += inputArgs[i];
        fullArg += " ";
    }
    stringstream fullArgStream(fullArg);
    string temp;
    vector<string> firstTempVector;
    while (getline(fullArgStream, temp, '"'))
    {
        firstTempVector.push_back(temp);
    }
    if(firstTempVector.size()!=5)
    {
        throw ErrorHandler(3);
    }
    string postTitle, postMessage, postPhoto = "";
    if (firstTempVector[0] == "title ")
    {
        if (firstTempVector[2] == " message ")
        {
            postTitle = firstTempVector[1];
            postMessage = firstTempVector[3];
            if (firstTempVector.size() == 5)
            {
                stringstream ss(firstTempVector[4]);
                for (int i = 0; i < 3; i++)
                {
                    getline(ss, postPhoto, ' ');
                }
            }
        }
        else
        {
            postTitle = firstTempVector[1];
            postMessage = firstTempVector[4];
            stringstream ss(firstTempVector[2]);
            for (int i = 0; i < 3; i++)
            {
                getline(ss, postPhoto, ' ');
            }
        }
    }
    else if (firstTempVector[0] == "message ")
    {
        if (firstTempVector[2] == " title ")
        {
            postMessage = firstTempVector[1];
            postTitle = firstTempVector[3];
            if (firstTempVector.size() == 5)
            {
                stringstream ss(firstTempVector[4]);
                for (int i = 0; i < 3; i++)
                {
                    getline(ss, postPhoto, ' ');
                }
            }
        }
        else
        {
            postMessage = firstTempVector[1];
            postTitle = firstTempVector[4];
            stringstream ss(firstTempVector[2]);
            for (int i = 0; i < 3; i++)
            {
                getline(ss, postPhoto, ' ');
            }
        }
    }
    else
    {
        stringstream ss(firstTempVector[0]);
        for (int i = 0; i < 3; i++)
        {
            getline(ss, postPhoto, ' ');
        }
        if(firstTempVector[1] == " title ")
        {
            postTitle = firstTempVector[2];
            postMessage = firstTempVector[4];
        }
        else
        {
            postMessage = firstTempVector[2];
            postTitle = firstTempVector[4];
        }
    }
    AddPostToUserPage(userWhoLogged, postTitle, postMessage , postPhoto);
    //cout << "OK" << endl;
    throw ErrorHandler(0);
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
    outputArgs.push_back(FindProfessor(professorID)->getName());
    outputArgs.push_back(capacity);
    outputArgs.push_back(time);
    outputArgs.push_back(examDate);
    outputArgs.push_back(classNumber);
    outputArgs.push_back(FindCourse(courseID)->getName());
    if (stoi(courseID) < 1 || stoi(professorID) < 1 || stoi(capacity) < 1 || stoi(classNumber) < 1)
    {
        throw ErrorHandler(3);
    }
    CheckCourseAndProfessor(courseID, professorID, time, outputArgs);
    tempCourseOffer.push_back(outputArgs);
    cout << "OK" << endl;
}

void PostCommand::UpdateCourseOfferList(vector<vector<string>> &inputCourseOffer)
{
    inputCourseOffer = tempCourseOffer;
}

void PostCommand::ProfilePhotoFunc(vector<string> inputArgs)
{
    if (inputArgs.size() != 2)
    {
        throw ErrorHandler(3);
    }
    MainProfilePhoto(inputArgs[1], userWhoLogged);
    throw ErrorHandler(0);
}