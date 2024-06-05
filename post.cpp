#include "post.hpp"

Post ::Post(string inputSubCommand, string inputArguments)
{
    CheckSubCommand(inputSubCommand);
    subCommand = inputSubCommand;
    arguments = inputArguments;
}

void Post::CheckSubCommand(string subCommand)
{
    int counter = 0;
    for (int i = 0; i < postSubCommands.size(); i++)
    {
        if (subCommand != postSubCommands[i])
        {
            counter++;
        }
    }
    if (counter == postSubCommands.size())
    {
        throw ErrorHandler(2);
    }
}

// void Post::RunCommand()
// {
//     // cout << "kos" << endl;
//     string subCommand, seprator;
//     cin >> subCommand >> seprator;
//     if (!CheckSubCommand(subCommand) || seprator != "?")
//     {
//         cerr << "Not Found" << endl;
//     }
// }