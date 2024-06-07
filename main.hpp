#pragma once
#include "requarment.hpp"
#include "superCommand.hpp"

class Main
{
public:
    Main(char *inputCSV1, char *inputCSV2, char *inputCSV3, char *inputCSV4);
    void Run();
private:
    char *majorCSVFile, *studentCSVFile, *courseCSVFile, *professorCSVFile;
    LoginState loginState = LOGGED_OUT;
    void SelectSubCommand(char *majorsCSV, char *studentsCSV, char *coursesCSV, char *professorsCSV,
                          string inputSuperCommand, string inputSubCommand, string inputArguments);
    void MakeLoggedProgress(string subCommand);
};