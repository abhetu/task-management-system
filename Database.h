#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include "User.h"
#include "Task.h"

class Database {
private:
    std::string userFile;
    std::string taskFile;

public:
    Database(const std::string& userFile, const std::string& taskFile);

    void loadUsers(std::vector<User>& users);
    void saveUsers(const std::vector<User>& users);

    void loadTasks(std::vector<Task>& tasks);
    void saveTasks(const std::vector<Task>& tasks);
};

#endif // DATABASE_H
