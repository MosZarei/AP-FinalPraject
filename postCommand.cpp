#include "superCommand.hpp"

vector<string> RemoveSpaces(string input)
{
    vector<string> output;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, ' '))
    {
        if (temp != "")
        {
            output.push_back(temp);
        }
    }
    return output;
}

PostCommand::PostCommand(vector<Major *> inputMajorVector, vector<Student *> inputStudentVector,
                         vector<Course *> inputCourseVector, vector<Professor *> inputProfessorVector,
                         Users *inputDefaultUser, string inputSubCommand, string inputArguments, string inputUserWhoLogged, vector<Course *> inputCourseOffers)
    : SuperCommand(inputMajorVector, inputStudentVector, inputCourseVector, inputProfessorVector, inputDefaultUser , inputCourseOffers)
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
    else if (subCommand == "ta_form")
    {
        if (IsProfessor(userWhoLogged))
        {
            PostTAForm(arguments);
        }
        else
        {
            throw ErrorHandler(4);
        }
    }
    else if(subCommand == "ta_request")
    {
        if(IsStudent(userWhoLogged))
        {
            //TARequestFunc(arguments);
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
    if (firstTempVector.size() != 5)
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
        if (firstTempVector[1] == " title ")
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
    AddPostToUserPage(userWhoLogged, postTitle, postMessage, postPhoto);
    // cout << "OK" << endl;
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
    if (stoi(courseID) < 1 || stoi(professorID) < 1 || stoi(capacity) < 1 || stoi(classNumber) < 1)
    {
        throw ErrorHandler(3);
    }
    Course *newCourseOffer = new Course(courseID, FindCourse(courseID)->getName(),
                                        capacity, FindProfessor(professorID)->getName(),
                                        time, examDate, classNumber);
    // outputArgs.push_back(courseID);
    // outputArgs.push_back(FindProfessor(professorID)->getName());
    // outputArgs.push_back(capacity);
    // outputArgs.push_back(time);
    // outputArgs.push_back(examDate);
    // outputArgs.push_back(classNumber);
    // outputArgs.push_back(FindCourse(courseID)->getName());
    CheckCourseAndProfessor(courseID, professorID, time, newCourseOffer);
    tempCourseOffer.push_back(newCourseOffer);
    cout << "OK" << endl;
}

void PostCommand::UpdateCourseOfferList(vector<Course *> &inputCourseOffer)
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

void PostCommand::PostTAForm(vector<string> inputArgs)
{
    vector<string> correctArgs;
    if (inputArgs[0] == "course_id")
    {
        string fullArg = "";
        for (int i = 0; i < inputArgs.size(); i++)
        {
            fullArg += inputArgs[i];
            if (i != inputArgs.size() - 1)
            {
                fullArg += " ";
            }
        }
        stringstream fullArgStream(fullArg);
        string temp;
        getline(fullArgStream, temp, '"');
        correctArgs = RemoveSpaces(temp);
        getline(fullArgStream, temp, '"');
        correctArgs.push_back(temp);
    }
    else if (inputArgs[0] == "message")
    {
        string fullArg = "";
        for (int i = 0; i < inputArgs.size(); i++)
        {
            fullArg += inputArgs[i];
            if (i != inputArgs.size() - 1)
            {
                fullArg += " ";
            }
        }
        stringstream fullArgStream(fullArg);
        string temp;
        getline(fullArgStream, temp, '"');
        correctArgs = RemoveSpaces(temp);
        getline(fullArgStream, temp, '"');
        correctArgs.push_back(temp);
        getline(fullArgStream, temp, '"');
        vector<string> tempV = RemoveSpaces(temp);
        for (int i = 0; i < tempV.size(); i++)
        {
            correctArgs.push_back(tempV[i]);
        }
    }
    string courseID, message;
    if (correctArgs.size() != 4)
    {
        throw ErrorHandler(3);
    }
    if (correctArgs[0] == "course_id")
    {
        if (correctArgs[2] == "message")
        {
            courseID = correctArgs[1];
            message = correctArgs[3];
        }
    }
    else if (correctArgs[0] == "message")
    {
        if (correctArgs[2] == "course_id")
        {
            courseID = correctArgs[3];
            message = correctArgs[1];
        }
    }
    else
    {
        throw ErrorHandler(3);
    }
    CheckProfessorConditions(userWhoLogged, courseID, message);
    throw ErrorHandler(0);
}

void PostCommand::TARequsetFunc(vector<string> inputArgs)
{
    if(inputArgs.size() != 4)
    {
        throw ErrorHandler(3);
    }
    string profID , formID;
    if(inputArgs[0] == "professor_id")
    {
        if(inputArgs[2] == "form_id")
        {
            profID = inputArgs[1];
            formID = inputArgs[3];
        }
    }
    else if(inputArgs[0] == "form_id")
    {
        if(inputArgs[2] == "professor_id")
        {
            profID = inputArgs[3];
            formID = inputArgs[1];
        }
    }
    else
    {
        throw ErrorHandler(3);
    }
}
