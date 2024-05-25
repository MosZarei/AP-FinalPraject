#include "users.hpp"
class Student : public Users
{
public:
    Student(string studentName , string studentPass , string studentMajor , string studentID , string studentSemester);
private:
    string sID;
    string semester;
};