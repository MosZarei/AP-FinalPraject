#pragma once
#include "requarment.hpp"
#include "errors.hpp"
#include "main.hpp"

class PostCommand : public Main
{
public:
    PostCommand(string inputSubCommand, string inputArguments);
    void RunCommand();

private:
    vector<string> postSubCommandsList = {"login", "logout", "post", "connect", "course_offer"};
    string subCommand;
    vector<string> arguments;
    bool CheckSubCommand(string inputSubCommand);
    void LoginFunc(vector<string> inputArgs);
};