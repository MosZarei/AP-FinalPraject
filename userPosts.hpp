#include "requarment.hpp"
#include "errors.hpp"

class UserPosts
{
public:
    UserPosts(string postID, string postTitle, string postMessage, string postPohto);
    string GetPostID() { return ID; }
    string GetPostTitle() { return title; }
    string GetPostMessage() { return message; }
    string getPostPhoto() { return photo; }

private:
    string ID, title, message, photo;
};