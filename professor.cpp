#include "professor.hpp"

Professor::Professor(string professorID, string professorName, string professorMajor, string professorPosition, string professorPass)
    : Users(professorName, professorPass, professorMajor)
{
    if (professorID == "" || professorPosition == "")
    {
        // hendling exception
    }
    pID = professorID;
    pPosition = professorPosition;
}