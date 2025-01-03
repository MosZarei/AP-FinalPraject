#include "superCommand.hpp"

SuperCommand::SuperCommand(vector<Major *> inputMajorVector, vector<Student *> inputStudentVector, vector<Course *> inputCourseVector,
                           vector<Professor *> inputProfessorVector, Users *inputDefalutUser, vector<Course *> inputCourseOffers)
{
    tempMajorList = inputMajorVector;
    tempStudentsList = inputStudentVector;
    tempCourseList = inputCourseVector;
    tempProfessorList = inputProfessorVector;
    tempDefaultUser = inputDefalutUser;
    tempCourseOffers = inputCourseOffers;
}

void SuperCommand::Update(vector<Major *> &inputMajorVector, vector<Student *> &inputStudentVector, vector<Course *> &inputCourseVector,
                          vector<Professor *> &inputProfessorVector, Users *&inputDefalutUser)
{
    inputMajorVector = tempMajorList;
    inputStudentVector = tempStudentsList;
    inputCourseVector = tempCourseList;
    inputProfessorVector = tempProfessorList;
    inputDefalutUser = tempDefaultUser;
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
    bool isDefaultUser = false;
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
    if (userID == tempDefaultUser->getID())
    {
        isDefaultUser = true;
    }
    if (isStd || isPro || isDefaultUser)
    {
        if (isStd && !tempStudentsList[stdCounter]->MatchPassword(userPass))
        {
            throw ErrorHandler(4);
        }
        if (isPro && !tempProfessorList[proCounter]->MatchPassword(userPass))
        {
            throw ErrorHandler(4);
        }
        if (isDefaultUser && !tempDefaultUser->MatchPassword(userPass))
        {
            throw ErrorHandler(4);
        }
    }
    else
    {
        throw ErrorHandler(2);
    }
}

void SuperCommand::ConnectUsers(string mainUserID, string targetUserId)
{
    bool isPro = false;
    bool isStd = false;
    int stdCounter = 0;
    int proCounter = 0;
    for (stdCounter; stdCounter < tempStudentsList.size(); stdCounter++)
    {
        if (targetUserId == tempStudentsList[stdCounter]->getID())
        {
            isStd = true;
            break;
        }
    }
    for (proCounter; proCounter < tempProfessorList.size(); proCounter++)
    {
        if (targetUserId == tempProfessorList[proCounter]->getID())
        {
            isPro = true;
            break;
        }
    }
    if (isPro || isStd)
    {
        if (isPro)
        {
            tempProfessorList[proCounter]->Connect(mainUserID);
        }
        else if (isStd)
        {
            tempStudentsList[stdCounter]->Connect(mainUserID);
        }
    }
    else
    {
        throw ErrorHandler(2);
    }
}

void SuperCommand::AddPostToUserPage(string userID, string title, string massage, string photoAddress)
{
    if (IsStudent(userID))
    {
        FindStudent(userID)->AddPost(title, massage, photoAddress);
        SendNotification(userID, FindStudent(userID)->getConnectUsers(), "New Post");
    }
    else if (IsProfessor(userID))
    {
        FindProfessor(userID)->AddPost(title, massage, photoAddress);
        SendNotification(userID, FindProfessor(userID)->getConnectUsers(), "New Post");
    }
    else if (IsDefault(userID))
    {
        tempDefaultUser->AddPost(title, massage, photoAddress);
        SendNotification(userID, tempDefaultUser->getConnectUsers(), "New Post");
    }
}

void SuperCommand::DeletePostOfUserPage(string userID, string postNum)
{
    bool isPro = false;
    bool isStd = false;
    int stdCounter = 0;
    int proCounter = 0;
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
    if (isStd)
    {
        tempStudentsList[stdCounter]->DeletePost(postNum);
    }
    else if (isPro)
    {
        tempProfessorList[proCounter]->DeletePost(postNum);
    }
    else
    {
        throw ErrorHandler(2);
    }
}

void SuperCommand::SendNotification(string userID, vector<string> connectedUsers, string notificationMassage)
{
    string userName;
    bool isPro = false;
    bool isStd = false;
    bool isDefault = false;
    int stdCounter = 0;
    int proCounter = 0;
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
    if (userID == "0")
    {
        isDefault = true;
    }
    if (isStd)
    {
        userName = tempStudentsList[stdCounter]->getName();
    }
    else if (isPro)
    {
        userName = tempProfessorList[proCounter]->getName();
    }
    else if (isDefault)
    {
        userName = tempDefaultUser->getPass();
    }
    for (int i = 0; i < connectedUsers.size(); i++)
    {
        isPro = false;
        isStd = false;
        stdCounter = 0;
        proCounter = 0;
        for (stdCounter; stdCounter < tempStudentsList.size(); stdCounter++)
        {
            if (connectedUsers[i] == tempStudentsList[stdCounter]->getID())
            {
                isStd = true;
                break;
            }
        }
        for (proCounter; proCounter < tempProfessorList.size(); proCounter++)
        {
            if (connectedUsers[i] == tempProfessorList[proCounter]->getID())
            {
                isPro = true;
                break;
            }
        }
        if (isStd)
        {
            tempStudentsList[stdCounter]->AddNotification(userID, userName, notificationMassage);
        }
        else if (isPro)
        {
            tempProfessorList[proCounter]->AddNotification(userID, userName, notificationMassage);
        }
    }
}

void SuperCommand::ShowNotificaion(string userID)
{
    bool isPro = false;
    bool isStd = false;
    int stdCounter = 0;
    int proCounter = 0;
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
    if (isStd)
    {
        tempStudentsList[stdCounter]->PrintNotification();
    }
    else if (isPro)
    {
        tempProfessorList[proCounter]->PrintNotification();
    }
}

void SuperCommand::CheckCourseAndProfessor(string courseID, string professorID, string time, Course *outputArgs)
{
    bool isCourse = false;
    bool isPro = false;
    int courseCounter = 0;
    int proCounter = 0;
    for (courseCounter; courseCounter < tempCourseList.size(); courseCounter++)
    {
        if (tempCourseList[courseCounter]->getID() == courseID)
        {
            isCourse = true;
            break;
        }
    }
    for (proCounter; proCounter < tempProfessorList.size(); proCounter++)
    {
        if (tempProfessorList[proCounter]->getID() == professorID)
        {
            isPro = true;
            break;
        }
    }
    for (int i = 0; i < tempStudentsList.size(); i++)
    {
        if (tempStudentsList[i]->getID() == professorID)
        {
            throw ErrorHandler(4);
        }
    }
    if (!isCourse || !isPro)
    {
        throw ErrorHandler(2);
    }
    if (!tempProfessorList[proCounter]->CanGetCourse(tempCourseList[courseCounter]->getMajor()))
    {
        throw ErrorHandler(4);
    }
    if (!tempProfessorList[proCounter]->MatchTime(time, outputArgs))
    {
        throw ErrorHandler(4);
    }
    SendNotification(professorID, tempDefaultUser->getConnectUsers(), "New Course Offering");
}

Course *SuperCommand::FindCourse(string courseID)
{
    int courseCounter = 0;
    for (courseCounter; courseCounter < tempCourseList.size(); courseCounter++)
    {
        if (courseID == tempCourseList[courseCounter]->getID())
        {
            return tempCourseList[courseCounter];
        }
    }
}

Course *SuperCommand::FindCourseOffer(string courseID)
{
    int courseCounter = 0;
    for (courseCounter; courseCounter < tempCourseOffers.size(); courseCounter++)
    {
        if (courseID == tempCourseOffers[courseCounter]->getID())
        {
            return tempCourseOffers[courseCounter];
        }
    }
}

bool SuperCommand::IsCourse(string courseID)
{
    int courseCounter = 0;
    for (courseCounter; courseCounter < tempCourseList.size(); courseCounter++)
    {
        if (courseID == tempCourseList[courseCounter]->getID())
        {
            return true;
        }
    }
    return false;
}

Professor *SuperCommand::FindProfessor(string professorID)
{
    int proCounter = 0;
    for (proCounter; proCounter < tempProfessorList.size(); proCounter++)
    {
        if (professorID == tempProfessorList[proCounter]->getID())
        {
            return tempProfessorList[proCounter];
        }
    }
}

bool SuperCommand::IsProfessor(string professorID)
{
    int proCounter = 0;
    for (proCounter; proCounter < tempProfessorList.size(); proCounter++)
    {
        if (professorID == tempProfessorList[proCounter]->getID())
        {
            return true;
        }
    }
    return false;
}

Student *SuperCommand::FindStudent(string studentID)
{
    int stdCounter = 0;
    for (stdCounter; stdCounter < tempStudentsList.size(); stdCounter++)
    {
        if (studentID == tempStudentsList[stdCounter]->getID())
        {
            return tempStudentsList[stdCounter];
        }
    }
}

bool SuperCommand::IsStudent(string studentID)
{
    int stdCounter = 0;
    for (stdCounter; stdCounter < tempStudentsList.size(); stdCounter++)
    {
        if (studentID == tempStudentsList[stdCounter]->getID())
        {
            return true;
        }
    }
    return false;
}

Major *SuperCommand::FindMajor(string majorID)
{
    int majCounter = 0;
    for (majCounter; majCounter < tempMajorList.size(); majCounter++)
    {
        if (majorID == tempMajorList[majCounter]->getID())
        {
            return tempMajorList[majCounter];
        }
    }
}

bool SuperCommand::IsDefault(string userID)
{
    if (userID == "0")
    {
        return true;
    }
    else
    {
        return false;
    }
}

void SuperCommand::CheckStudentConditions(string courseID, string userID, string courseTime, string courseExam, Course *courseLine)
{
    int stdCounter = 0;
    for (stdCounter; stdCounter < tempStudentsList.size(); stdCounter++)
    {
        if (userID == tempStudentsList[stdCounter]->getID())
        {
            break;
        }
    }
    if (!tempStudentsList[stdCounter]->CanTakeCourse(FindCourse(courseID)->GetPre(), FindCourse(courseID)->getMajor(), courseTime, courseExam))
    {
        throw ErrorHandler(4);
    }
    tempStudentsList[stdCounter]->AddCourse(courseLine);
    SendNotification(userID, tempStudentsList[stdCounter]->getConnectUsers(), "Get Course");
}

void SuperCommand::DeleteStudentCourse(string userID, string courseID)
{
    int stdCounter = 0;
    for (stdCounter; stdCounter < tempStudentsList.size(); stdCounter++)
    {
        if (userID == tempStudentsList[stdCounter]->getID())
        {
            break;
        }
    }
    tempStudentsList[stdCounter]->DeleteCourse(courseID);
    SendNotification(userID, tempStudentsList[stdCounter]->getConnectUsers(), "Delete Course");
}

void SuperCommand::GetStudentCourses(string userID)
{
    int stdCounter = 0;
    for (stdCounter; stdCounter < tempStudentsList.size(); stdCounter++)
    {
        if (userID == tempStudentsList[stdCounter]->getID())
        {
            break;
        }
    }
    tempStudentsList[stdCounter]->PrintCourses();
}

void SuperCommand::MainProfilePhoto(string photoAddress, string userID)
{
    if (IsStudent(userID))
    {
        FindStudent(userID)->AddProfilePhoto(photoAddress);
    }
    else if (IsProfessor(userID))
    {
        FindProfessor(userID)->AddProfilePhoto(photoAddress);
    }
    else if (userID == "0")
    {
        tempDefaultUser->AddProfilePhoto(photoAddress);
    }
}

void SuperCommand::CheckProfessorConditions(string professorID, string courseID, string message)
{
    if (!IsCourse(courseID))
    {
        throw ErrorHandler(2);
    }
    if (!FindProfessor(professorID)->HaveCourse(courseID))
    {
        throw ErrorHandler(4);
    }
    string title = "TA form for ";
    title += FindCourse(courseID)->getName();
    title += " course";
    title += "|";
    title = title + courseID + " " + FindCourseOffer(courseID)->getName() + " " +
            FindCourseOffer(courseID)->GetCapacity() + " " + FindCourseOffer(courseID)->GetProfName() + " " +
            FindCourseOffer(courseID)->GetTime() + " " + FindCourseOffer(courseID)->GetExamDate() + " " + FindCourseOffer(courseID)->GetClassNum();
    FindProfessor(professorID)->AddTAForm(FindCourse(courseID), message , title);
    SendNotification(professorID, FindProfessor(professorID)->getConnectUsers(), "New Form");
}