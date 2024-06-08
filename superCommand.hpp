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
                 vector<Professor *> inputProfessorVector, Users *inputDefaultUser);
    void Update(vector<Major *> &inputMajorVector, vector<Student *> &inputStudentVector, vector<Course *> &inputCourseVector,
                vector<Professor *> &inputProfessorVector, Users *&inputDefalutUser);
    string GetSuperCommand() { return superCommand; }
    string GetSubCommand() { return subCommand; }
    string GetArguments() { return arguments; }
    void GetInput();
    void CheckLoginCondditions(string userID, string userPass);

private:
    vector<Student *> tempStudentsList;
    vector<Professor *> tempProfessorList;
    vector<Course *> tempCourseList;
    vector<Major *> tempMajorList;
    Users *tempDefaultUser;
    vector<string> superCommandList = {"POST", "GET", "DELETE", "PUT"};
    string superCommand, subCommand, seprator, arguments = "";
    bool CheckSuperCommand(string superCommand);
};

class PostCommand : public SuperCommand
{
public:
    PostCommand(vector<Major *> inputMajorVector, vector<Student *> inputStudentVector,
                vector<Course *> inputCourseVector, vector<Professor *> inputProfessorVector,
                Users *inputDefaultUser, string inputSubCommand, string inputArguments, string inputUserWhoLogged);
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
};

class GetCommand : public SuperCommand
{
public:
    GetCommand(vector<Major *> inputMajorVector, vector<Student *> inputStudentVector,
               vector<Course *> inputCourseVector, vector<Professor *> inputProfessorVector,
               Users *inputDefaultUser, string inputSubCommand, string inputArguments, string inputUserWhoLogged);
    void RunCommand();
private:
    vector<string> getSubCommandsList = {"courses" , "personal_page" , "post" , "notification" , "my_courses"};
    string subCommand;
    vector<string> arguments;
    bool CheckSubCommand(string inputSubCommand);
};