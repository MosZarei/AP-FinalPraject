#pragma once
#include "requarment.hpp"
#include "csvreader.hpp"
#include "users.hpp"
#include "student.hpp"
#include "professor.hpp"
#include "course.hpp"
#include "major.hpp"
#include "errors.hpp"
#include "main.hpp"

class SuperCommand
{
public:
    SuperCommand(vector<Major *> inputMajorVector, vector<Student *> inputStudentVector, vector<Course *> inputCourseVector,
                 vector<Professor *> inputProfessorVector, Users *inputDefaultUser , vector<Course *> inputCourseOffers);
    void Update(vector<Major *> &inputMajorVector, vector<Student *> &inputStudentVector, vector<Course *> &inputCourseVector,
                vector<Professor *> &inputProfessorVector, Users *&inputDefalutUser);
    string GetSuperCommand() { return superCommand; }
    string GetSubCommand() { return subCommand; }
    string GetArguments() { return arguments; }
    void GetInput();
    void CheckLoginCondditions(string userID, string userPass);
    void ConnectUsers(string mainUserID, string targetUserId);
    void AddPostToUserPage(string userID, string title, string massage , string photoAddress);
    void DeletePostOfUserPage(string userID, string postNum);
    void ShowNotificaion(string userID);
    void CheckCourseAndProfessor(string courseID, string professorID, string time, Course * outputArgs);
    Course *FindCourse(string courseID);
    Course *FindCourseOffer(string courseID);
    bool IsCourse(string courseID);
    Professor *FindProfessor(string professorID);
    bool IsProfessor(string proID);
    Student *FindStudent(string studentID);
    bool IsStudent(string studentID);
    Major *FindMajor(string majorID);
    bool IsDefault(string userID);
    void CheckStudentConditions(string courseID , string userID , string courseTime , string courseExam , Course * courseLine);
    void DeleteStudentCourse(string userID , string courseID);
    void GetStudentCourses(string userID);
    void MainProfilePhoto(string photoAddress , string userID);
    void CheckProfessorConditions(string professorID , string courseID , string message);

private:
    vector<Student *> tempStudentsList;
    vector<Professor *> tempProfessorList;
    vector<Course *> tempCourseList;
    vector<Course *> tempCourseOffers;
    vector<Major *> tempMajorList;
    Users *tempDefaultUser;
    vector<string> superCommandList = {"POST", "GET", "DELETE", "PUT"};
    string superCommand, subCommand, seprator, arguments = "";
    bool CheckSuperCommand(string superCommand);
    void SendNotification(string userID, vector<string> connectedUsers, string notificationMassage);
};

class PostCommand : public SuperCommand
{
public:
    PostCommand(vector<Major *> inputMajorVector, vector<Student *> inputStudentVector,
                vector<Course *> inputCourseVector, vector<Professor *> inputProfessorVector,
                Users *inputDefaultUser, string inputSubCommand, string inputArguments, string inputUserWhoLogged, vector<Course *> inputCourseOffers);
    void RunCommand();
    void UpdateCourseOfferList(vector<Course *> &inputCourseOffer);
    string GetUserWhoLogged() { return userWhoLogged; }

private:
    vector<string> postSubCommandsList = {"login", "logout", "post", "connect", "course_offer" , "ta_form" , "ta_request"};
    string subCommand;
    vector<string> arguments;
    string userWhoLogged = "";
    vector<Course *> tempCourseOffer;
    bool CheckSubCommand(string inputSubCommand);
    void LoginFunc(vector<string> inputArgs);
    void LogoutFunc(vector<string> inputArgs);
    void ConnectFunc(vector<string> inputArgs);
    void PostFunc(vector<string> inputArgs);
    void CourseOfferFunc(vector<string> inputArgs);
    void ProfilePhotoFunc(vector<string> inputArgs);
    void PostTAForm(vector<string> inputArgs);
    void TARequsetFunc(vector<string> inputArgs);
};

class GetCommand : public SuperCommand
{
public:
    GetCommand(vector<Major *> inputMajorVector, vector<Student *> inputStudentVector,
               vector<Course *> inputCourseVector, vector<Professor *> inputProfessorVector,
               Users *inputDefaultUser, string inputSubCommand, string inputArguments, string inputUserWhoLogged, vector<Course *> inputCourseOfferList);
    void RunCommand();

private:
    vector<string> getSubCommandsList = {"courses", "personal_page", "post", "notification", "my_courses"};
    string subCommand;
    vector<string> arguments;
    string userWhoLogged = "";
    vector<Course *> tempCourseOfferList;
    Users *tempDefaultUser;
    bool CheckSubCommand(string inputSubCommand);
    void GetNotifications(vector<string> inputArgs);
    void GetCourses(vector<string> inputArgs);
    void GetMyCourses(vector<string> inputArgs);
    void GetPersonalPage(vector<string> inputArgs);
    void GetPost(vector<string> inputArgs);
};

class DeleteCommand : public SuperCommand
{
public:
    DeleteCommand(vector<Major *> inputMajorVector, vector<Student *> inputStudentVector,
                  vector<Course *> inputCourseVector, vector<Professor *> inputProfessorVector,
                  Users *inputDefaultUser, string inputSubCommand, string inputArguments, string inputUserWhoLogged , vector<Course *> inputCourseOfferList);
    void RunCommand();

private:
    vector<string> deleteSubCommandsList = {"post", "my_courses"};
    string subCommand;
    vector<string> arguments;
    string userWhoLogged = "";
    vector<Course *> tempCourseOfferList;
    bool CheckSubCommand(string inputSubComand);
    void DeletePostFunc(vector<string> inputArgs);
    void DeleteMyCourseFunc(vector<string> inputArgs);
};

class PutCommand : public SuperCommand
{
public:
    PutCommand(vector<Major *> inputMajorVector, vector<Student *> inputStudentVector,
               vector<Course *> inputCourseVector, vector<Professor *> inputProfessorVector,
               Users *inputDefaultUser, string inputSubCommand, string inputArguments, string inputUserWhoLogged, vector<Course *> inputCourseOfferList);
    void RunCommand();

private:
    vector<string> putSubCommandsList = {"my_courses"};
    string subCommand;
    vector<string> arguments;
    string userWhoLogged = "";
    vector<Course *> tempCourseOfferList;
    bool CheckSubCommand(string inputSubCommand);
    void PutMyCoursesFunc(vector<string> inputArgs);
};