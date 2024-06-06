#pragma once
#include "requarment.hpp"
#include "csvreader.hpp"
#include "student.hpp"
#include "professor.hpp"
#include "course.hpp"
#include "major.hpp"
#include "errors.hpp"
// #include "postCommand.hpp"
#include "getCommand.hpp"
#include "putCommand.hpp"
#include "deleteCommand.hpp"

class Main
{
public:
    Main(char *majorsCSV, char *studentsCSV, char *coursesCSV, char *professorsCSV);
    string GetSuperCommand() { return superCommand; }
    string GetSubCommand() { return subCommand; }
    string GetArguments() { return arguments; }
    void GetInput();
    void runProgram();
    bool IsUser(string userID);
    bool IsUserPasswordMatch(string userID, string userPass);
    //bool IsUserLoggedIn() { return isUserLoggedIn; }
    void MakeUserLoggedIn();
    bool isUserLoggedIn = false;

private:
    vector<Student *> studentsList;
    vector<Professor *> professorList;
    vector<Course *> courseList;
    vector<Major *> majorList;
    vector<string> superCommandList = {"POST", "GET", "DELETE", "PUT"};
    string superCommand, subCommand, seprator, arguments = "";
    void makeStudentList(char *studentsCSV);
    void makeProfessorList(char *professorsCSV);
    void makeCourseList(char *coursesCSV);
    void makeMajorList(char *majorsCSV);
    bool CheckSuperCommand(string superCommand);
    void SelectSubCommand();
};

class PostCommand : public Main
{
public:
    PostCommand(char *majorsCSV, char *studentsCSV, char *coursesCSV, char *professorsCSV, string inputSubCommand, string inputArguments);
    void RunCommand();

private:
    vector<string> postSubCommandsList = {"login", "logout", "post", "connect", "course_offer"};
    string subCommand;
    vector<string> arguments;
    bool CheckSubCommand(string inputSubCommand);
    void LoginFunc(vector<string> inputArgs);
};