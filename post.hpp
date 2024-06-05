#pragma once
#include "requarment.hpp"
#include "errors.hpp"

class Post
{
public:
    Post(string subCommand , string arguments);
    void RunCommand();
    void CheckSubCommand(string subCommand);
private:
    vector<string> postSubCommands = {"login", "logout", "post", "connect",
                                      "course_offer", "my_courses"};
    string subCommand;
    string arguments;
};