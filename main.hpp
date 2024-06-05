#pragma once
#include "requarment.hpp"
#include "csvreader.hpp"
#include "student.hpp"
#include "professor.hpp"
#include "course.hpp"
#include "major.hpp"
#include "post.hpp"
#include "errors.hpp"
#include "postCommand.hpp"
#include "getCommand.hpp"
#include "putCommand.hpp"
#include "deleteCommand.hpp"

class Main
{
public:
    Main(char *majorsCSV, char *studentsCSV, char *coursesCSV, char *professorsCSV);
    Main() {}
    void runProgram();
    bool IsUser(string userID);

private:
    vector<Student *> studentsList;
    vector<Professor *> professorList;
    vector<Course *> courseList;
    vector<Major *> majorList;
    vector<string> superCommandList = {"POST", "GET", "DELETE", "PUT"};
    string superCommand , subCommand , seprator , arguments = "";
    void makeStudentList(char *studentsCSV);
    void makeProfessorList(char *professorsCSV);
    void makeCourseList(char *coursesCSV);
    void makeMajorList(char *majorsCSV);
    void GetInput();
    bool CheckSuperCommand(string superCommand);
    void SelectSubCommand();
};