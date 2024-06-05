#include "subCommands.hpp"

SubCommand::SubCommand(string inputSuperCommand, string inputSubCommand, string inputSeprator, string inputArguments)
    : SuperCommand(inputSuperCommand, inputSeprator)
{

}

bool CheckSubCommand(string inputSubCommand)
{
    string superCommand = GetSuperCommand();
}