#include "professor.hpp"

Professor::Professor(string professorID, string professorName, string professorMajor, string professorPosition, string professorPass)
    : Users(professorName, professorPass, professorMajor, professorID)
{
    if (professorPosition == "")
    {
        // hendling exception
    }
    pPosition = professorPosition;
}

bool Professor::CanGetCourse(string courseMajorID)
{
    vector<string> courseMajorsID;
    stringstream stream(courseMajorID);
    string temp;
    while (getline(stream, temp, SEMICOLON))
    {
        courseMajorsID.push_back(temp);
    }
    for (int i = 0; i < courseMajorsID.size(); i++)
    {
        if (getMajor() == courseMajorsID[i])
        {
            return true;
        }
    }
    return false;
}

bool Professor::MatchTime(string time)
{
    vector<string> courseTime;
    stringstream stream(time);
    string temp;
    getline(stream, temp, ':');
    courseTime.push_back(temp);
    getline(stream, temp, ':');
    stringstream stream2(temp);
    while (getline(stream2, temp, '-'))
    {
        courseTime.push_back(temp);
    }
    for (int i = 0; i < courseOfferTime.size(); i++)
    {
        if (courseOfferTime[i][0] == courseTime[0] &&
                ((stoi(courseTime[1]) >= stoi(courseOfferTime[i][1])) && (stoi(courseTime[1]) < stoi(courseOfferTime[i][2]))) ||
            ((stoi(courseTime[2]) > stoi(courseOfferTime[i][1])) && (stoi(courseTime[2]) <= stoi(courseOfferTime[i][2]))))
        {
            return false;
        }
    }
    courseOfferTime.push_back(courseTime);
    return true;
}