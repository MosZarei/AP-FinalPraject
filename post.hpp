#include "requarment.hpp"

class Post
{
public:
    Post();
    void RunCommand();
    bool CheckSubCommand(string subCommand);
private:
    vector<string> postSubCommands;
};