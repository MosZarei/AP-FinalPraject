#include "main.hpp"

Main::Main(char *majorsCSV, char *studentsCSV, char *coursesCSV, char *professorsCSV)
{
    makeStudentList(studentsCSV);
}

void Main::makeStudentList(char *studentsCSV)
{
    CSVReader studentsFile(studentsCSV);
    for (int i = 1; i <= numOfLines(studentsCSV) ; i++)
    {
        Student *student = new Student(studentsFile.getObject(i,1) , studentsFile.getObject(i,2) , studentsFile.getObject(i,3) , studentsFile.getObject(i,4) , studentsFile.getObject(i,5));
        studentsList.push_back(student);
    }
}