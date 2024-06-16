#pragma once
#include "requarment.hpp"
#include "errors.hpp"
#include "userPosts.hpp"
#include "course.hpp"

class Users
{
public:
    Users(string userName, string userPass, string userMajor, string userID);
    Users(string userID, string userPass);
    string getName() { return name; }
    string getPass() { return password; }
    string getMajor() { return majorID; }
    string getID() { return ID; }
    int getPostsNumber() { return postList.size(); }
    int GetPostListSize() { return postListSize; }
    vector<string> getConnectUsers() { return connectedUsers; }
    bool MatchPassword(string userPass);
    void Connect(string targetUserID);
    void AddPost(string title, string massage , string photoAddress);
    void AddTAFormPost(string title , string message);
    void DeletePost(string postNum);
    void AddNotification(string userID, string userName, string notificationMassage);
    void PrintNotification();
    void PrintPosts(int line);
    void PrintPostDetail(string postID);
    bool CheckPostExistence(string postID);
    void AddProfilePhoto(string photoAddress);
private:
    string name, password, majorID, ID , profilePhoto;
    vector<string> connectedUsers;
    vector<UserPosts*> postList;
    vector<vector<string>> notifications;
    int postListSize = 0;
};

