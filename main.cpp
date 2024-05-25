#include "csvreader.hpp"
int main(int argc , char* argv[])
{
    CSVReader studentsFile(argv[1]);
    cout << studentsFile.getObject(2,1) << endl;
    return 0;
}