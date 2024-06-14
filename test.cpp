#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string photoArg = " image picAddress ";
    vector<string> args;
    stringstream ss (photoArg);
    string temp;
    while(getline(ss , temp , ' '))
    {
        args.push_back(temp);
    }
    for (int i = 0 ; i < args.size() ; i++)
    {
        cout << "-" << args[i] << "-";
    }
    return 0;
}