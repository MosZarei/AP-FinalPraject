#pragma once
#include "requarment.hpp"
#include "errors.hpp"

class Users
{
public:
    Users(string userName, string userPass, string userMajor, string userID);
    Users(string userID, string userPass);
    string getName() { return name; }
    string getPass() { return password; }
    string getMajor() { return majorID; }
    string getID() { return ID; }
    vector<string> getConnectUsers() { return connectedUsers; }
    bool MatchPassword(string userPass);
    void Connect(string targetUserID);
    void AddPost(string title, string massage);
    void DeletePost(string postNum);
    void AddNotification(string userID , string userName , string notificationMassage);
    void PrintNotification();
    void PtintPosts()
    {
        for (int i = 0; i < postsList.size(); i++)
        {
            cout << postsList[i][0] << " " << postsList[i][1] << " " << postsList[i][2] << endl;
        }
    }

private:
    string name, password, majorID, ID;
    vector<string> connectedUsers;
    vector<vector<string>> postsList;
    vector<vector<string>> notifications;
    int postListSize = 0;
};