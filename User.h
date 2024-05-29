#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Task.h"

class User {
private:
    std::string id;
    std::string name;
    std::string email;
    std::vector<Task> tasks;

public:
    User(const std::string& id, const std::string& name, const std::string& email);

    std::string getId() const;
    std::string getName() const;
    std::string getEmail() const;
    std::vector<Task>& getTasks();

    void setName(const std::string& name);
    void setEmail(const std::string& email);

    void addTask(const Task& task);
    void removeTask(const std::string& taskId);
    Task* getTaskById(const std::string& taskId);

    void displayUser() const;
};

#endif // USER_H
