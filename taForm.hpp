#include "requarment.hpp"
#include "userPosts.hpp"
#include "course.hpp"

class TAForm : public UserPosts
{
public:
    TAForm(string formID, Course *course, string message);
    void PrintDetail();

private:
    string ID , title , formMessage;
    Course *selectedCourse;
};