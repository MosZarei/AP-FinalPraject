#include "requarment.hpp"
#include "errors.hpp"
#include "superCommands.hpp"

class SubCommand : public SuperCommand
{
public:
    SubCommand(string inputSuperCommand, string inputSubCommand, string inputSeprator, string inputArguments);

private:
    vector<string> postSubCommandsList = {"login", "logout", "post", "connect", "course_offer"};
    vector<string> getSubCommandsList = {"courses", "personal_page", "post", "notification", "my_courses"};
    vector<string> putSubCommandsList = {"my_courses"};
    vector<string> deleteSubCommandsList = {"post", "my_courses"};
    bool CheckSubCommand(string inputSubCommand);
};