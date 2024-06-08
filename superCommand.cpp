#include "superCommand.hpp"

SuperCommand::SuperCommand(vector<Major *> inputMajorVector, vector<Student *> inputStudentVector,
                           vector<Course *> inputCourseVector, vector<Professor *> inputProfessorVector)
{
    tempMajorList = inputMajorVector;
    tempStudentsList = inputStudentVector;
    tempCourseList = inputCourseVector;
    tempProfessorList = inputProfessorVector;
}

void SuperCommand::Update(vector<Major *> &inputMajorVector, vector<Student *> &inputStudentVector,
                           vector<Course *> &inputCourseVector, vector<Professor *> &inputProfessorVector)
{
    inputMajorVector = tempMajorList;
    inputStudentVector = tempStudentsList;
    inputCourseVector = tempCourseList;
    inputProfessorVector = tempProfessorList;
}

bool SuperCommand::CheckSuperCommand(string superCommand)
{
    for (int i = 0; i < superCommandList.size(); i++)
    {
        if (superCommand == superCommandList[i])
        {
            return true;
        }
    }
    return false;
}

bool CheckSeprator(string seprator)
{
    if (seprator == SEPRATOR)
    {
        return true;
    }
    return false;
}

void SuperCommand::GetInput()
{
    vector<string> inputs;
    string input, line;
    getline(cin, line);
    stringstream lineStream(line);
    while (getline(lineStream, input, ' '))
    {
        inputs.push_back(input);
    }
    if (!CheckSuperCommand(inputs[0]) || !CheckSeprator(inputs[2]))
    {
        throw ErrorHandler(3);
    }
    else
    {
        for (int i = 0; i < inputs.size(); i++)
        {
            switch (i)
            {
            case 0:
                superCommand = inputs[i];
                break;
            case 1:
                subCommand = inputs[i];
                break;
            case 2:
                seprator = inputs[i];
                break;
            }
        }
        if (inputs.size() > 3)
        {
            arguments = (inputs[3] + " ");
            for (int i = 4; i < inputs.size(); i++)
            {
                arguments += (inputs[i] + " ");
            }
        }
    }
}

void SuperCommand::CheckLoginCondditions(string userID, string userPass)
{
    int stdCounter = 0;
    int proCounter = 0;
    bool isStd = false;
    bool isPro = false;
    for (stdCounter; stdCounter < tempStudentsList.size(); stdCounter++)
    {
        if (userID == tempStudentsList[stdCounter]->getID())
        {
            isStd = true;
            break;
        }
    }
    for (proCounter; proCounter < tempProfessorList.size(); proCounter++)
    {
        if (userID == tempProfessorList[proCounter]->getID())
        {
            isPro = true;
            break;
        }
    }
    if (isStd || isPro)
    {
        if (isStd && !tempStudentsList[stdCounter]->MatchPassword(userPass))
        {
            throw ErrorHandler(4);
        }
        if (isPro && !tempProfessorList[proCounter]->MatchPassword(userPass))
        {
            throw ErrorHandler(4);
        }
    }
    else
    {
        throw ErrorHandler(2);
    }
}