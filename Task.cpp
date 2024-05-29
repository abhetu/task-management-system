#include "Task.h"
#include <iostream>

Task::Task(const std::string& id, const std::string& title, const std::string& description, std::time_t deadline, int priority)
    : id(id), title(title), description(description), deadline(deadline), priority(priority) {}

std::string Task::getId() const { return id; }
std::string Task::getTitle() const { return title; }
std::string Task::getDescription() const { return description; }
std::time_t Task::getDeadline() const { return deadline; }
int Task::getPriority() const { return priority; }

void Task::setTitle(const std::string& title) { this->title = title; }
void Task::setDescription(const std::string& description) { this->description = description; }
void Task::setDeadline(std::time_t deadline) { this->deadline = deadline; }
void Task::setPriority(int priority) { this->priority = priority; }

void Task::displayTask() const {
    std::cout << "Task ID: " << id << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Deadline: " << std::ctime(&deadline);
    std::cout << "Priority: " << priority << std::endl;
}
