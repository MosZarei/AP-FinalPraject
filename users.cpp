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

void Users::AddPost(string title, string message, string photoAddress)
{
    UserPosts *newPost = new UserPosts(to_string(postListSize + 1), title, message, photoAddress);
    postList.push_back(newPost);
    postListSize++;
}

void Users::AddTAFormPost(string title , string message)
{
    UserPosts *newUserPost = new UserPosts(to_string(postListSize + 1) , title , message);
    newUserPost->MakeTAForm();
    postList.push_back(newUserPost);
    postListSize++;
}

void Users::DeletePost(string postNum)
{
    vector<UserPosts *> temp;
    for (int i = 0; i < postList.size(); i++)
    {
        if (postNum == postList[i]->GetPostID())
        {
            postList.push_back(postList[i]);
            for (int j = i + 1; j < postList.size(); j++)
            {
                postList[j - 1] = postList[j];
            }
            postList.pop_back();
            postList.pop_back();
            break;
        }
        else if (i == postList.size() - 1)
        {
            throw ErrorHandler(2);
        }
    }
}

void Users::AddNotification(string userID, string userName, string notificationMassage)
{
    vector<string> temp;
    temp.push_back(userID);
    temp.push_back(userName);
    temp.push_back(notificationMassage);
    notifications.push_back(temp);
}

void Users::PrintNotification()
{
    if (notifications.size() == 0)
    {
        throw ErrorHandler(1);
    }
    for (int i = notifications.size() - 1; i >= 0; i--)
    {
        cout << notifications[i][0] << " " << notifications[i][1] << ": " << notifications[i][2] << endl;
    }
    notifications.clear();
}

void Users::PrintPosts(int line)
{
    if (postList[line]->IsTAForm())
    {
        stringstream stream(postList[line]->GetPostTitle());
        string title;
        getline(stream, title, '|');
        cout << postList[line]->GetPostID() << " " << title << endl;
    }
    else
    {
         cout << postList[line]->GetPostID() << " " << "\"" << postList[line]->GetPostTitle() << "\"" << endl;
    }
}

void Users::PrintPostDetail(string postID)
{
    int postCounter = 0;
    for (postCounter; postCounter < postList.size(); postCounter++)
    {
        if (postList[postCounter]->GetPostID() == postID)
        {
            break;
        }
    }
    if (postList[postCounter]->IsTAForm())
    {
        stringstream stream(postList[postCounter]->GetPostTitle());
        string title, detail;
        getline(stream, title, '|');
        getline(stream, detail, '|');
        cout << postList[postCounter]->GetPostID() << " " << title << endl
             << detail << endl
             << "\"" << postList[postCounter]->GetPostMessage() << "\"" << endl;
    }
    else
    {
        cout << postList[postCounter]->GetPostID() << " " << "\"" << postList[postCounter]->GetPostTitle() << "\"" << " " << "\"" << postList[postCounter]->GetPostMessage() << "\"" << endl;
    }
}

bool Users::CheckPostExistence(string postID)
{
    for (int i = 0; i < postList.size(); i++)
    {
        if (postID == postList[i]->GetPostID())
        {
            return true;
        }
    }
    return false;
}

void Users::AddProfilePhoto(string photoAddress)
{
    profilePhoto = photoAddress;
}
