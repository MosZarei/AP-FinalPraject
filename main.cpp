#include "main.hpp"

Main::Main(char *inputCSV1, char *inputCSV2, char *inputCSV3, char *inputCSV4)
{
    MakeMajorList(inputCSV1);
    MakeStudentList(inputCSV2);
    MakeCourseList(inputCSV3);
    MakeProfessorList(inputCSV4);
    for (int i = 0; i < studentsList.size(); i++)
    {
        defaultUser->Connect(studentsList[i]->getID());
    }
    for (int i = 0; i < professorList.size(); i++)
    {
        defaultUser->Connect(professorList[i]->getID());
    }
}

void Main::MakeStudentList(char *studentsCSV)
{
    CSVReader studentsFile(studentsCSV);
    for (int i = 1; i <= numOfLines(studentsCSV); i++)
    {
        Student *newStudent = new Student(studentsFile.getObject(i, 1), studentsFile.getObject(i, 2), studentsFile.getObject(i, 3),
                                          studentsFile.getObject(i, 4), studentsFile.getObject(i, 5));
        studentsList.push_back(newStudent);
    }
}

void Main::MakeProfessorList(char *professorsCSV)
{
    CSVReader professorsFile(professorsCSV);
    for (int i = 1; i <= numOfLines(professorsCSV); i++)
    {
        Professor *newProfessor = new Professor(professorsFile.getObject(i, 1), professorsFile.getObject(i, 2), professorsFile.getObject(i, 3),
                                                professorsFile.getObject(i, 4), professorsFile.getObject(i, 5));
        professorList.push_back(newProfessor);
    }
}

void Main::MakeCourseList(char *coursesCSV)
{
    CSVReader coursesFile(coursesCSV);
    for (int i = 1; i <= numOfLines(coursesCSV); i++)
    {
        Course *newCourse = new Course(coursesFile.getObject(i, 1), coursesFile.getObject(i, 2), coursesFile.getObject(i, 3),
                                       coursesFile.getObject(i, 4), coursesFile.getObject(i, 5));
        courseList.push_back(newCourse);
    }
}

void Main::MakeMajorList(char *majorsCSV)
{
    CSVReader majorsFile(majorsCSV);
    for (int i = 1; i <= numOfLines(majorsCSV); i++)
    {
        Major *newMajor = new Major(majorsFile.getObject(i, 1), majorsFile.getObject(i, 2));
        majorList.push_back(newMajor);
    }
}

void Main::Run()
{
    while (true)
    {
        try
        {
            SuperCommand command(majorList, studentsList, courseList, professorList, defaultUser);
            command.GetInput();
            SelectSubCommand(command.GetSuperCommand(), command.GetSubCommand(), command.GetArguments());
            command.Update(majorList, studentsList, courseList, professorList, defaultUser);
        }
        catch (ErrorHandler &error)
        {
            error.GetErrorMassage();
        }
    }
}

void Main::SelectSubCommand(string inputSuperCommand, string inputSubCommand, string inputArguments)
{
    if (inputSuperCommand == "POST")
    {
        PostCommand command(majorList, studentsList, courseList, professorList, defaultUser, inputSubCommand, inputArguments, userWhoLogged, courseOffers);
        if ((loginState == LOGGED_OUT && inputSubCommand != "login") || (loginState == LOGGED_IN && inputSubCommand == "login"))
        {
            throw ErrorHandler(4);
        }
        else
        {
            command.RunCommand();
            if (inputSubCommand == "course_offer")
            {
                command.UpdateCourseOfferList(courseOffers);
            }
            if (inputSubCommand == "login")
            {
                userWhoLogged = command.GetUserWhoLogged();
            }
            else if (inputSubCommand == "logout")
            {
                userWhoLogged = "";
            }
            MakeLoggedProgress(inputSubCommand);
        }
    }
    else if (inputSuperCommand == "GET")
    {
        GetCommand command(majorList, studentsList, courseList, professorList, defaultUser, inputSubCommand, inputArguments, userWhoLogged, courseOffers);
        if (loginState == LOGGED_OUT)
        {
            throw ErrorHandler(4);
        }
        else
        {
            command.RunCommand();
        }
    }
    else if (inputSuperCommand == "PUT")
    {
        PutCommand command(majorList, studentsList, courseList, professorList, defaultUser, inputSubCommand, inputArguments, userWhoLogged, courseOffers);
        if (loginState == LOGGED_OUT)
        {
            throw ErrorHandler(4);
        }
        else
        {
            command.RunCommand();
        }
    }
    else if (inputSuperCommand == "DELETE")
    {
        DeleteCommand command(majorList, studentsList, courseList, professorList, defaultUser, inputSubCommand, inputArguments, userWhoLogged);
        if (loginState == LOGGED_OUT)
        {
            throw ErrorHandler(4);
        }
        else
        {
            command.RunCommand();
        }
    }
}

void Main::MakeLoggedProgress(string subCommand)
{
    if (subCommand == "login" && loginState == LOGGED_OUT)
    {
        loginState = LOGGED_IN;
        cout << "OK" << endl;
    }
    else if (subCommand == "login" && loginState == LOGGED_IN)
    {
        throw ErrorHandler(4);
    }
    if (subCommand == "logout" && loginState == LOGGED_IN)
    {
        loginState = LOGGED_OUT;
        cout << "OK" << endl;
    }
    else if (subCommand == "logout" && loginState == LOGGED_OUT)
    {
        throw ErrorHandler(4);
    }
}