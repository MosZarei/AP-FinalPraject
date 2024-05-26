#include "users.hpp"
class Student : public Users
{
public:
    Student(string studentName, string studentPass, string studentMajor, string studentID, string studentSemester);
    vector<Student *> students;

private:
    string sID;
    string semester;
    void makeStudentsList(char* studentsCSV);
};