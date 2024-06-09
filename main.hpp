#pragma once
#include "requarment.hpp"
#include "superCommand.hpp"

class Main
{
public:
    Main(char *inputCSV1, char *inputCSV2, char *inputCSV3, char *inputCSV4);
    void Run();

private:
    char *majorCSVFile, *studentCSVFile, *courseCSVFile, *professorCSVFile;
    vector<Student *> studentsList;
    vector<Professor *> professorList;
    vector<Course *> courseList;
    vector<Major *> majorList;
    vector<vector<string>> courseOffers;
    Users *defaultUser = new Users("0", "UT_account");
    LoginState loginState = LOGGED_OUT;
    string userWhoLogged = "";
    void SelectSubCommand(string inputSuperCommand, string inputSubCommand, string inputArguments);
    void MakeLoggedProgress(string subCommand);
    void MakeStudentList(char *studentCSV);
    void MakeProfessorList(char *professorCSV);
    void MakeCourseList(char *coursesCSV);
    void MakeMajorList(char *majorsCSV);
};