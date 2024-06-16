#pragma once
#include "requarment.hpp"
#include "course.hpp"

class TAForm
{
public:
    TAForm(string formID, Course *course);

private:
    string ID;
    Course *selectedCourse;
};