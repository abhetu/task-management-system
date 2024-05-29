#include "UserManager.h"
#include <iostream>
#include <algorithm>

void UserManager::addUser(const User& user) { users.push_back(user); }

void UserManager::removeUser(const std::string& userId) {
    users.erase(std::remove_if(users.begin(), users.end(),
        [&](User& user) { return user.getId() == userId; }), users.end());
}

User* UserManager::getUserById(const std::string& userId) {
    for (User& user : users) {
        if (user.getId() == userId) {
            return &user;
        }
    }
    return nullptr;
}

void UserManager::displayAllUsers() const {
    for (const User& user : users) {
        user.displayUser();
        std::cout << "--------------------" << std::endl;
    }
}
