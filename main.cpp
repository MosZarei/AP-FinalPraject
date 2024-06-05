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

bool Main::CheckSuperCommand(string superCommand)
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

void Main::GetInput()
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

void Main::SelectSubCommand()
{
    if (superCommand == "POST")
    {
        PostCommand command(subCommand , arguments);
    }
    else if (superCommand == "GET")
    {
        //GetCommand command(subCommand , argumenrs);
    }
    else if (superCommand == "PUT")
    {
        //PutCommand command(subCommand , argumenrs);
    }
    else if (superCommand == "DELETE")
    {
        //DeleteCommand command(subCommand , argumenrs);
    }
}

bool Main::IsUser(string userID)
{
    //int check = 0;
    for (int i = 0 ; i < studentsList.size() ; i++)
    {
        if (userID == studentsList[i]->getID())
        {
            return true;
        }
    }
    for (int i = 0 ; i < professorList.size() ; i++)
    {
        if(userID == professorList[i]->getID())
        {
            return true;
        }
    }
    return false;
}

void Main::runProgram()
{
    while (true)
    {
        try
        {
            GetInput();
            SelectSubCommand();
            //cout << superCommand << " - " << subCommand << " - " << seprator << " - " << arguments << endl;
        }
        catch (ErrorHandler &error)
        {
            error.GetErrorMassage();
        }
    }
}