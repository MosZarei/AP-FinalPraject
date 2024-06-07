#include "superCommand.hpp"

SuperCommand::SuperCommand(char *majorsCSV, char *studentsCSV, char *coursesCSV, char *professorsCSV)
{
    makeStudentList(studentsCSV);
    makeProfessorList(professorsCSV);
    makeCourseList(coursesCSV);
    makeMajorList(majorsCSV);
}

void SuperCommand::makeStudentList(char *studentsCSV)
{
    CSVReader studentsFile(studentsCSV);
    for (int i = 1; i <= numOfLines(studentsCSV); i++)
    {
        Student *newStudent = new Student(studentsFile.getObject(i, 1), studentsFile.getObject(i, 2), studentsFile.getObject(i, 3),
                                          studentsFile.getObject(i, 4), studentsFile.getObject(i, 5));
        studentsList.push_back(newStudent);
    }
}

void SuperCommand::makeProfessorList(char *professorsCSV)
{
    CSVReader professorsFile(professorsCSV);
    for (int i = 1; i <= numOfLines(professorsCSV); i++)
    {
        Professor *newProfessor = new Professor(professorsFile.getObject(i, 1), professorsFile.getObject(i, 2), professorsFile.getObject(i, 3),
                                                professorsFile.getObject(i, 4), professorsFile.getObject(i, 5));
        professorList.push_back(newProfessor);
    }
}

void SuperCommand::makeCourseList(char *coursesCSV)
{
    CSVReader coursesFile(coursesCSV);
    for (int i = 1; i <= numOfLines(coursesCSV); i++)
    {
        Course *newCourse = new Course(coursesFile.getObject(i, 1), coursesFile.getObject(i, 2), coursesFile.getObject(i, 3),
                                       coursesFile.getObject(i, 4), coursesFile.getObject(i, 5));
        courseList.push_back(newCourse);
    }
}

void SuperCommand::makeMajorList(char *majorsCSV)
{
    CSVReader majorsFile(majorsCSV);
    for (int i = 1; i <= numOfLines(majorsCSV); i++)
    {
        Major *newMajor = new Major(majorsFile.getObject(i, 1), majorsFile.getObject(i, 2));
        majorList.push_back(newMajor);
    }
}

bool SuperCommand::CheckSuperCommand(string superCommand)
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

void SuperCommand::GetInput()
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

void SuperCommand::CheckLoginCondditions(string userID , string userPass)
{
    int stdCounter = 0;
    int proCounter = 0;
    bool isStd = false;
    bool isPro = false;
    for (stdCounter ; stdCounter < studentsList.size() ; stdCounter++)
    {
        if (userID == studentsList[stdCounter]->getID())
        {
            isStd = true;
            break;
        }
    }
    for (proCounter ; proCounter < professorList.size() ; proCounter++)
    {
        if (userID == professorList[proCounter]->getID())
        {
            isPro = true;
            break;
        }
    }
    if (isStd || isPro)
    {
        if (isStd && !studentsList[stdCounter]->MatchPassword(userPass))
        {
            throw ErrorHandler(4);
        }
        if(isPro && !professorList[proCounter]->MatchPassword(userPass))
        {
            throw ErrorHandler(4);
        }
    }
    else
    {
        throw ErrorHandler(2);
    }
}