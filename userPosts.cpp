#include "userPosts.hpp"

UserPosts::UserPosts(string postID, string postTitle, string postMessage, string postPhoto)
{
    ID = postID;
    title = postTitle;
    message = postMessage;
    photo = postPhoto;
}

UserPosts::UserPosts(string postID, string postTitle, string postMessage)
{
    ID = postID;
    title = postTitle;
    message = postMessage;
}

void UserPosts::PrintDetail()
{
    cout << ID << " " << "\"" << title << "\"" << " " << "\"" <<  message << "\"" << endl;
}