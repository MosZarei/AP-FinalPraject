#include "main.hpp"

void SelectSubCommand(char *majorsCSV, char *studentsCSV, char *coursesCSV, char *professorsCSV,
                      string inputSuperCommand, string inputSubCommand, string inputArguments)
{
    if (inputSuperCommand == "POST")
    {
        PostCommand command(majorsCSV, studentsCSV, coursesCSV, professorsCSV, inputSubCommand, inputArguments);
        command.RunCommand();
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

int main(int argc, char *argv[])
{
    Main program(argv[1], argv[2], argv[3], argv[4]);
    while (true)
    {
        try
        {
            program.GetInput();
            SelectSubCommand(argv[1], argv[2], argv[3], argv[4], program.GetSuperCommand(), program.GetSubCommand(), program.GetArguments());
        }
        catch (ErrorHandler &error)
        {
            error.GetErrorMassage();
        }
    }
}