#include "post.hpp"

Post ::Post()
{
    postSubCommands = {"login", "logout", "post", "connect",
                       "course_offer", "my_courses"};
}

bool Post ::CheckSubCommand(string subCommand)
{
    for (int i = 0; i < postSubCommands.size(); i++)
    {
        if (subCommand == postSubCommands[i])
        {
            return true;
        }
    }
    return false;
}

void Post::RunCommand()
{
    //cout << "kos" << endl;
    string subCommand, seprator;
    cin >> subCommand >> seprator;
    if (!CheckSubCommand(subCommand) || seprator != "?")
    {
        cerr << "Not Found" << endl;
    }
}