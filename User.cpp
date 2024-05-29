#include "User.h"
#include <algorithm>
#include <iostream>

User::User(const std::string& id, const std::string& name, const std::string& email)
    : id(id), name(name), email(email) {}

std::string User::getId() const { return id; }
std::string User::getName() const { return name; }
std::string User::getEmail() const { return email; }
std::vector<Task>& User::getTasks() { return tasks; }

void User::setName(const std::string& name) { this->name = name; }
void User::setEmail(const std::string& email) { this->email = email; }

void User::addTask(const Task& task) { tasks.push_back(task); }
void User::removeTask(const std::string& taskId) {
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(),
        [&](Task& task) { return task.getId() == taskId; }), tasks.end());
}

Task* User::getTaskById(const std::string& taskId) {
    for (Task& task : tasks) {
        if (task.getId() == taskId) {
            return &task;
        }
    }
    return nullptr;
}

void User::displayUser() const {
    std::cout << "User ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Tasks: " << std::endl;
    for (const Task& task : tasks) {
        task.displayTask();
    }
}
