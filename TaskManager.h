#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <vector>
#include "Task.h"

class TaskManager {
private:
    std::vector<Task> tasks;

public:
    void addTask(const Task& task);
    void removeTask(const std::string& taskId);
    Task* getTaskById(const std::string& taskId);
    std::vector<Task> getTasksByPriority(int priority);
    std::vector<Task> getTasksByDeadline(std::time_t deadline);

    void displayAllTasks() const;
};

#endif // TASKMANAGER_H
