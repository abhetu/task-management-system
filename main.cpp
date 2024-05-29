#include <iostream>
#include "Task.h"
#include "User.h"
#include "TaskManager.h"
#include "UserManager.h"
#include "Database.h"
#include "Utils.h"

int main() {
    std::cout << "Task Management System" << std::endl;

    // Sample tasks
    Task task1("T001", "Implement Task class", "Write unit tests for Task class", std::time(nullptr), 1);
    Task task2("T002", "Implement User class", "Write unit tests for User class", std::time(nullptr), 2);

    // Sample users
    User user1("U001", "Alice", "alice@example.com");
    User user2("U002", "Bob", "bob@example.com");

    // Assign tasks to users
    user1.addTask(task1);
    user2.addTask(task2);

    // Display users and their tasks
    std::cout << "User 1:" << std::endl;
    user1.displayUser();
    std::cout << std::endl << "User 2:" << std::endl;
    user2.displayUser();

    // TaskManager functionality
    TaskManager taskManager;
    taskManager.addTask(task1);
    taskManager.addTask(task2);

    // Display all tasks managed by TaskManager
    std::cout << "\nTasks managed by TaskManager:" << std::endl;
    taskManager.displayAllTasks();

    // UserManager functionality
    UserManager userManager;
    userManager.addUser(user1);
    userManager.addUser(user2);

    // Display all users managed by UserManager
    std::cout << "\nUsers managed by UserManager:" << std::endl;
    userManager.displayAllUsers();

    // Database functionality
    Database database("users.txt", "tasks.txt");

    // Saving users and tasks to the database
    std::vector<User> users = {user1, user2};
    std::vector<Task> tasks = {task1, task2};
    database.saveUsers(users);
    database.saveTasks(tasks);

    // Loading users and tasks from the database
    std::vector<User> loadedUsers;
    std::vector<Task> loadedTasks;
    database.loadUsers(loadedUsers);
    database.loadTasks(loadedTasks);

    std::cout << "\nLoaded users from database:" << std::endl;
    for (const auto& user : loadedUsers) {
        user.displayUser();
    }

    std::cout << "\nLoaded tasks from database:" << std::endl;
    for (const auto& task : loadedTasks) {
        task.displayTask();
    }

    return 0;
}
