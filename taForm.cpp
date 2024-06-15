#include "taForm.hpp"

TAForm::TAForm(string formID , Course * course , string message)
        :UserPosts(formID , "TA form for " + course->getName() + " course" , message)
{
    selectedCourse = course;
    ID = formID;
    title = "TA form for " + course->getName() + " course";
    formMessage = message;
}

void TAForm::PrintDetail()
{
    cout << ID << " " << title << endl;
    cout << selectedCourse->getID() << " " << selectedCourse->getName() << " " << selectedCourse->GetCapacity() << " "
         << selectedCourse->GetProfName() << " " << selectedCourse->GetTime() << " " << selectedCourse->GetExamDate() << " " << selectedCourse->GetClassNum() << endl;
    cout << "\"" << formMessage << "\"" << endl;
}

