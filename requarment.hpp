#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

extern char COMMA;
extern int numOfLines(char *file);

enum LoginState
{
    LOGGED_IN,
    LOGGED_OUT
};
