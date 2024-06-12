#include "users.hpp"

Users::Users(string userName, string userPass, string userMajor, string userID)
{
    name = userName;
    password = userPass;
    majorID = userMajor;
    ID = userID;
}

Users::Users(string userID, string userPass)
{
    ID = userID;
    password = userPass;
}

bool Users::MatchPassword(string userPass)
{
    if (userPass == password)
    {
        return true;
    }
    return false;
}

void Users::Connect(string targetUserID)
{
    for (int i = 0; i < connectedUsers.size(); i++)
    {
        if (connectedUsers[i] == targetUserID)
        {
            throw ErrorHandler(3);
        }
    }
    connectedUsers.push_back(targetUserID);
}

void Users::AddPost(string title, string massage)
{
    vector<string> temp;
    temp.push_back(to_string(postListSize + 1));
    temp.push_back(title);
    temp.push_back(massage);
    postsList.push_back(temp);
    postListSize++;
}

void Users::DeletePost(string postNum)
{
    vector<string> temp;
    for (int i = 0; i < postsList.size(); i++)
    {
        if (postNum == postsList[i][0])
        {
            temp = postsList[i];
            for (int j = i + 1; j < postsList.size(); j++)
            {
                postsList[j - 1] = postsList[j];
            }
            postsList[postsList.size() - 1] = temp;
            postsList.pop_back();
            break;
        }
        else if (i == postsList.size() - 1)
        {
            throw ErrorHandler(2);
        }
    }
}

void Users::AddNotification(string userID , string userName , string notificationMassage)
{
    vector<string> temp;
    temp.push_back(userID);
    temp.push_back(userName);
    temp.push_back(notificationMassage);
    notifications.push_back(temp);
}

void Users::PrintNotification()
{
    if(notifications.size() == 0)
    {
        throw ErrorHandler(1);
    }
    for(int i = notifications.size() - 1 ; i >= 0 ; i--)
    {
        cout << notifications[i][0] << " " << notifications[i][1] << ": " << notifications[i][2] << endl;
    }
    notifications.clear();
}

void Users::PrintPosts(int line)
{
    cout << postsList[line][0] << " " << postsList[line][1] << endl;
}

void Users::PrintPostDetail(int line)
{
    cout << postsList[line][0] << " " << postsList[line][1] << " " << postsList[line][2] << endl;
}

bool Users::CheckPostExistence(string postID)
{
    for (int i = 0 ; i < postsList.size() ; i++)
    {
        if(postID == postsList[i][0])
        {
            return true;
        }
    }
    return false;
}
