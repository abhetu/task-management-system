#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include "User.h"

class UserManager {
private:
    std::vector<User> users;

public:
    void addUser(const User& user);
    void removeUser(const std::string& userId);
    User* getUserById(const std::string& userId);

    void displayAllUsers() const;
};

#endif // USERMANAGER_H
