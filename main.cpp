#include "main.hpp"

Main::Main(char *majorsCSV, char *studentsCSV, char *coursesCSV, char *professorsCSV)
{
    makeStudentList(studentsCSV);
    makeProfessorList(professorsCSV);
    makeCourseList(coursesCSV);
    makeMajorList(majorsCSV);
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

void Main::makeMajorList(char *majorsCSV)
{
    CSVReader majorsFile(majorsCSV);
    for (int i = 1; i <= numOfLines(majorsCSV); i++)
    {
        Major *newMajor = new Major(majorsFile.getObject(i, 1), majorsFile.getObject(i, 2));
        majorList.push_back(newMajor);
    }
}

void Main::CheckSuperCommand(string superCommand)
{
    int counter = 0;
    for (int i = 0 ; i < superCommandList.size() ; i++)
    {
        if (superCommand != superCommandList[i])
        {
            counter ++;
        }
    }
    if (counter == superCommandList.size())
    {
        throw ErrorHandler(3);
    }
}

void CheckSeprator(char seprator)
{
    if (seprator != '?')
    {
        throw ErrorHandler(3);
    }
}

void Main::GetInput()
{
    string superCommand, subCommand, commandArguments;
    char seprator;
    cin >> superCommand >> subCommand >> seprator;
    getline(cin, commandArguments);
    // try
    // {
    //     CheckSuperCommand(superCommand);
    //     CheckSeprator(seprator);
    //     Post postCommnd(subCommand , commandArguments);
    // }
    // catch (ErrorHandler &error)
    // {
    //     error.GetErrorMassage();
    // }
}

void Main::runProgram()
{
    while (true)
    {
        GetInput();
    }
    // string superCommand;
    // while (cin >> superCommand)
    // {
    //     if (superCommand == "POST")
    //     {
    //         Post post;
    //         post.RunCommand();
    //         // string commandType , separator;
    //         // cin >> commandType >> separator;
    //         // //cout << "POST COMMAND" << endl;
    //         // cout << commandType << "-" << separator << endl;
    //     }
    //     else if(superCommand == "GET")
    //     {
    //         cout << "GET COMMAND" << endl;
    //     }
    //     else if(superCommand == "PUT")
    //     {
    //         cout << "PUT COMMAND" << endl;
    //     }
    //     else if (superCommand == "DELETE")
    //     {
    //         cout << "DELETE COMMAND"<< endl;
    //     }
    //     else
    //     {
    //         cerr << "Bad Request" << endl;
    //     }
    // }
}