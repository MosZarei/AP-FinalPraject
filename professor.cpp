#include "professor.hpp"

Professor::Professor(string professorID, string professorName, string professorMajor, string professorPosition, string professorPass)
    : Users(professorName, professorPass, professorMajor , professorID)
{
    if (professorPosition == "")
    {
        // hendling exception
    }
    pPosition = professorPosition;
}