#include "main.hpp"

Main::Main(char *majorsCSV, char *studentsCSV, char *coursesCSV, char *professorsCSV)
{
    makeStudentList(studentsCSV);
    makeProfessorList(professorsCSV);
    makeCourseList(coursesCSV);
}

void Main::makeStudentList(char *studentsCSV)
{
    CSVReader studentsFile(studentsCSV);
    for (int i = 1; i <= numOfLines(studentsCSV); i++)
    {
        Student *newStudent = new Student(studentsFile.getObject(i, 1), studentsFile.getObject(i, 2), studentsFile.getObject(i, 3),
                                          studentsFile.getObject(i, 4), studentsFile.getObject(i, 5));
        studentsList.push_back(newStudent);
    }
}

void Main::makeProfessorList(char *professorsCSV)
{
    CSVReader professorsFile(professorsCSV);
    for (int i = 1; i <= numOfLines(professorsCSV); i++)
    {
        Professor *newProfessor = new Professor(professorsFile.getObject(i, 1), professorsFile.getObject(i, 2), professorsFile.getObject(i, 3),
                                                professorsFile.getObject(i, 4), professorsFile.getObject(i, 5));
        professorList.push_back(newProfessor);
    }
}

void Main::makeCourseList(char *coursesCSV)
{
    CSVReader coursesFile(coursesCSV);
    for (int i = 1; i <= numOfLines(coursesCSV); i++)
    {
        Course *newCourse = new Course(coursesFile.getObject(i, 1), coursesFile.getObject(i, 2), coursesFile.getObject(i, 3),
                                       coursesFile.getObject(i, 4), coursesFile.getObject(i, 5));
        courseList.push_back(newCourse);
    }
}

void Main::makeMajorList(char* majorsCSV)
{
    CSVReader majorsFile(majorsCSV);
    for (int i = 1 ; i <= numOfLines(majorsCSV) ; i++)
    {
        Major *newMajor = new Major(majorsFile.getObject(i , 1) , majorsFile.getObject(i , 2));
        majorList.push_back(newMajor);
    }
}

void Main::printData(int userNumber)
{
    cout << professorList[userNumber]->getName() << " - "
         << professorList[userNumber]->getPass() << endl;
}