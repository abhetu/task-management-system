#include "Database.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "Utils.h"

Database::Database(const std::string& userFile, const std::string& taskFile)
    : userFile(userFile), taskFile(taskFile) {}

void Database::loadUsers(std::vector<User>& users) {
    std::ifstream file(userFile);
    if (!file) {
        std::cerr << "Unable to open user file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string id, name, email;
        if (iss >> id >> name >> email) {
            users.emplace_back(id, name, email);
        }
    }
    file.close();
}

void Database::saveUsers(const std::vector<User>& users) {
    std::ofstream file(userFile);
    if (!file) {
        std::cerr << "Unable to open user file." << std::endl;
        return;
    }

    for (const User& user : users) {
        file << user.getId() << " " << user.getName() << " " << user.getEmail() << "\n";
    }
    file.close();
}

void Database::loadTasks(std::vector<Task>& tasks) {
    std::ifstream file(taskFile);
    if (!file) {
        std::cerr << "Unable to open task file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string id, title, description, deadlineStr;
        int priority;
        if (iss >> id >> title >> description >> deadlineStr >> priority) {
            std::time_t deadline = stringToTime(deadlineStr);
            tasks.emplace_back(id, title, description, deadline, priority);
        }
    }
    file.close();
}

void Database::saveTasks(const std::vector<Task>& tasks) {
    std::ofstream file(taskFile);
    if (!file) {
        std::cerr << "Unable to open task file." << std::endl;
        return;
    }

    for (const Task& task : tasks) {
        file << task.getId() << " " << task.getTitle() << " " << task.getDescription() << " "
            << timeToString(task.getDeadline()) << " " << task.getPriority() << "\n";
    }
    file.close();
}
