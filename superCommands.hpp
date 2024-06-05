#include "requarment.hpp"
#include "errors.hpp"

class SuperCommand
{
public:
    SuperCommand(string inputSuperCommand, string inputSeprator);
    string GetSuperCommand() { return superCommand; }

private:
    vector<string> superCommandsList = {"POST", "GET", "PUT", "DELETE"};
    bool CheckSuperCommandAndSeprator(string inputSuperCommand, string inputSeprator);
    string superCommand;
};