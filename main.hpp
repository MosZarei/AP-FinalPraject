#pragma once
#include "requarment.hpp"
#include "csvreader.hpp"
#include "student.hpp"
#include "professor.hpp"
#include "course.hpp"
#include "major.hpp"
#include "post.hpp"

class Main
{
public:
    Main(char *majorsCSV, char *studentsCSV, char *coursesCSV, char *professorsCSV);
    void runProgram();

private:
    vector<Student *> studentsList;
    vector<Professor *> professorList;
    vector<Course *> courseList;
    vector<Major *> majorList;
    vector <string> superCommandList = {"POST" , "GET" , "DELETE" , "PUT"};
    void makeStudentList(char *studentsCSV);
    void makeProfessorList(char *professorsCSV);
    void makeCourseList(char *coursesCSV);
    void makeMajorList(char* majorsCSV);
    void GetInput();
    void CheckSuperCommand(string superCommand);
};