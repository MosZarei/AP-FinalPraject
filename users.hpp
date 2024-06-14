#pragma once
#include "requarment.hpp"
#include "errors.hpp"
#include "userPosts.hpp"

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
    vector<string> getConnectUsers() { return connectedUsers; }
    bool MatchPassword(string userPass);
    void Connect(string targetUserID);
    void AddPost(string title, string massage , string photoAddress);
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
    //vector<vector<string>> postsList;
    vector<UserPosts*> postList;
    vector<vector<string>> notifications;
    int postListSize = 0;
};