#pragma once
#include "requarment.hpp"
#include "csvreader.hpp"
#include "users.hpp"
#include "student.hpp"
#include "professor.hpp"
#include "course.hpp"
#include "major.hpp"
#include "errors.hpp"
#include "main.hpp"

class SuperCommand
{
public:
    SuperCommand(vector<Major *> inputMajorVector, vector<Student *> inputStudentVector, vector<Course *> inputCourseVector,
                 vector<Professor *> inputProfessorVector, Users *inputDefaultUser, vector<vector<string>> inputCourseOffers);
    void Update(vector<Major *> &inputMajorVector, vector<Student *> &inputStudentVector, vector<Course *> &inputCourseVector,
                vector<Professor *> &inputProfessorVector, Users *&inputDefalutUser, vector<vector<string>> &inputCourseOffers);
    string GetSuperCommand() { return superCommand; }
    string GetSubCommand() { return subCommand; }
    string GetArguments() { return arguments; }
    void GetInput();
    void CheckLoginCondditions(string userID, string userPass);
    void ConnectUsers(string mainUserID, string targetUserId);
    void AddPostToUserPage(string userID, string title, string massage);
    void DeletePostOfUserPage(string userID, string postNum);
    void ShowNotificaion(string userID);

private:
    vector<Student *> tempStudentsList;
    vector<Professor *> tempProfessorList;
    vector<Course *> tempCourseList;
    vector<Major *> tempMajorList;
    Users *tempDefaultUser;
    vector<vector<string>> tempCourseOffers;
    vector<string> superCommandList = {"POST", "GET", "DELETE", "PUT"};
    string superCommand, subCommand, seprator, arguments = "";
    bool CheckSuperCommand(string superCommand);
    Student *FindStudent(string userID);
    Professor *FindProfessor(string userID);
    void SendNotification(string userID, vector<string> connectedUsers, string notificationMassage);
};

class PostCommand : public SuperCommand
{
public:
    PostCommand(vector<Major *> inputMajorVector, vector<Student *> inputStudentVector,
                vector<Course *> inputCourseVector, vector<Professor *> inputProfessorVector,
                Users *inputDefaultUser, string inputSubCommand, string inputArguments, string inputUserWhoLogged, vector<vector<string>> inputCourseOffers);
    void RunCommand();
    string GetUserWhoLogged() { return userWhoLogged; }

private:
    vector<string> postSubCommandsList = {"login", "logout", "post", "connect", "course_offer"};
    string subCommand;
    vector<string> arguments;
    string userWhoLogged = "";
    bool CheckSubCommand(string inputSubCommand);
    void LoginFunc(vector<string> inputArgs);
    void LogoutFunc(vector<string> inputArgs);
    void ConnectFunc(vector<string> inputArgs);
    void PostFunc(vector<string> inputArgs);
    void CourseOfferFunc(vector<string> inputArgs);
};

class GetCommand : public SuperCommand
{
public:
    GetCommand(vector<Major *> inputMajorVector, vector<Student *> inputStudentVector,
               vector<Course *> inputCourseVector, vector<Professor *> inputProfessorVector,
               Users *inputDefaultUser, string inputSubCommand, string inputArguments, string inputUserWhoLogged, vector<vector<string>> inputCourseOffers);
    void RunCommand();

private:
    vector<string> getSubCommandsList = {"courses", "personal_page", "post", "notification", "my_courses"};
    string subCommand;
    vector<string> arguments;
    string userWhoLogged = "";
    bool CheckSubCommand(string inputSubCommand);
    void GetNotifications(vector<string> inputArgs);
};

class DeleteCommand : public SuperCommand
{
public:
    DeleteCommand(vector<Major *> inputMajorVector, vector<Student *> inputStudentVector,
                  vector<Course *> inputCourseVector, vector<Professor *> inputProfessorVector,
                  Users *inputDefaultUser, string inputSubCommand, string inputArguments, string inputUserWhoLogged, vector<vector<string>> inputCourseOffers);
    void RunCommand();

private:
    vector<string> deleteSubCommandsList = {"post", "my_courses"};
    string subCommand;
    vector<string> arguments;
    string userWhoLogged = "";
    bool CheckSubCommand(string inputSubComand);
    void DeletePostFunc(vector<string> inputArgs);
};