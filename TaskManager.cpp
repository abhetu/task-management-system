#include "TaskManager.h"
#include <iostream>
#include <algorithm>

void TaskManager::addTask(const Task& task) { tasks.push_back(task); }
void TaskManager::removeTask(const std::string& taskId) {
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(),
        [&](Task& task) { return task.getId() == taskId; }), tasks.end());
}
