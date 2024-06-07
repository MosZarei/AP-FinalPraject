#include "main.hpp"

Main::Main(char *inputCSV1, char *inputCSV2, char *inputCSV3, char *inputCSV4)
{
    majorCSVFile = inputCSV1;
    studentCSVFile = inputCSV2;
    courseCSVFile = inputCSV3;
    professorCSVFile = inputCSV4;
}

void Main::Run()
{
    while (true)
    {
        try
        {
            SuperCommand command(majorCSVFile, studentCSVFile, courseCSVFile, professorCSVFile);
            command.GetInput();
            SelectSubCommand(majorCSVFile, studentCSVFile, courseCSVFile, professorCSVFile,
                             command.GetSuperCommand(), command.GetSubCommand(), command.GetArguments());
        }
        catch (ErrorHandler &error)
        {
            error.GetErrorMassage();
        }
    }
}

void Main::SelectSubCommand(char *majorsCSV, char *studentsCSV, char *coursesCSV, char *professorsCSV,
                            string inputSuperCommand, string inputSubCommand, string inputArguments)
{
    if (inputSuperCommand == "POST")
    {
        PostCommand command(majorsCSV, studentsCSV, coursesCSV, professorsCSV, inputSubCommand, inputArguments);
        command.RunCommand();
        MakeLoggedProgress(inputSubCommand);
    }
    else if (inputSuperCommand == "GET")
    {
        // GetCommand command(subCommand , argumenrs);
    }
    else if (inputSuperCommand == "PUT")
    {
        // PutCommand command(subCommand , argumenrs);
    }
    else if (inputSuperCommand == "DELETE")
    {
        // DeleteCommand command(subCommand , argumenrs);
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