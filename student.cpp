#include "student.hpp"

Student::Student(string studentID, string studentName, string studentMajor, string studentSemester, string studentPass)
    : Users(studentName, studentPass, studentMajor, studentID)
{
    sSemester = studentSemester;
    sMajor = studentMajor;
}

bool Student::CanTakeCourse(string coursePre, vector<string> courseMajor, string time, string examDate)
{
    for (int i = 0; i < courseMajor.size(); i++)
    {
        if (sMajor == courseMajor[i] && stoi(sSemester) >= stoi(coursePre) && MatchClassAndExamTime(time, examDate))
        {
            return true;
        }
    }
    return false;
}

void Student::AddCourse(Course * courseLine)
{
    stdCourses.push_back(courseLine);
}

bool Student::MatchClassAndExamTime(string time, string examDate)
{
    if(stdCourses.size() == 0)
    {
        return true;
    }
    for (int i = 0; i < stdCourses.size(); i++)
    {
        if ((stdCourses[i]->GetExamDate() != examDate) && MatchClassTime(time))
        {
            return true;
        }
    }
    return false;
}

bool Student::MatchClassTime(string time)
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
    for (int i = 0; i < stdCourseTime.size(); i++)
    {
        if (stdCourseTime[i][0] == courseTime[0] &&
                ((stoi(courseTime[1]) >= stoi(stdCourseTime[i][1])) && (stoi(courseTime[1]) < stoi(stdCourseTime[i][2]))) ||
            ((stoi(courseTime[2]) > stoi(stdCourseTime[i][1])) && (stoi(courseTime[2]) <= stoi(stdCourseTime[i][2]))))
        {
            return false;
        }
    }
    stdCourseTime.push_back(courseTime);
    return true;
}

void Student::DeleteCourse(string courseID)
{
    vector<string> temp;
    int courseCounter = 0;
    bool isCourse = false;
    for (courseCounter; courseCounter < stdCourses.size(); courseCounter++)
    {
        if (courseID == stdCourses[courseCounter]->getID())
        {
            isCourse = true;
            break;
        }
    }
    if (!isCourse)
    {
        throw ErrorHandler(2);
    }
    stdCourses.push_back(stdCourses[courseCounter]);
    for (int i = courseCounter + 1; i < stdCourses.size(); i++)
    {
        stdCourses[i - 1] = stdCourses[i];
    }
    stdCourses.pop_back();
    stdCourses.pop_back();
}

void Student::PrintCourses()
{
    if (stdCourses.size() == 0)
    {
        throw ErrorHandler(1);
    }
    for (int i = 0; i < stdCourses.size(); i++)
    {
        cout << stdCourses[i]->getID() << " "
             << stdCourses[i]->getName() << " "
             << stdCourses[i]->GetCapacity() << " "
             << stdCourses[i]->GetProfName() << " "
             << stdCourses[i]->GetTime() << " "
             << stdCourses[i]->GetExamDate() << " "
             << stdCourses[i]->GetClassNum() << endl;
    }
}