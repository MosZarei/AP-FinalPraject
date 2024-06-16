#pragma once
#include "requarment.hpp"
#include "errors.hpp"

class UserPosts
{
public:
    UserPosts(string postID, string postTitle, string postMessage, string postPohto);
    UserPosts(string postID, string postTitle, string postMessage);
    string GetPostID() { return ID; }
    string GetPostTitle() { return title; }
    string GetPostMessage() { return message; }
    string getPostPhoto() { return photo; }
    void MakeTAForm() { isTAForm = true; }
    bool IsTAForm() { return isTAForm; }
    void PrintDetail();
private:
    string ID, title, message, photo;
    bool isTAForm = false;
};