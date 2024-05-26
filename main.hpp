#include "requarment.hpp"
#include "csvreader.hpp"
#include "student.hpp"

class Main
{
public:
    Main(char *majorsFile, char *studentsFile, char *coursesFile, char *professorsFile);

private:
    vector<Student *> studentsList;
    void makeStudentList(char* studentsFile);
};