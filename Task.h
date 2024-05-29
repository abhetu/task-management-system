#ifndef TASK_H
#define TASK_H

#include <string>
#include <ctime>

class Task {
private:
    std::string id;
    std::string title;
    std::string description;
    std::time_t deadline;
    int priority;

public:
    Task(const std::string& id, const std::string& title, const std::string& description, std::time_t deadline, int priority);

    std::string getId() const;
    std::string getTitle() const;
    std::string getDescription() const;
    std::time_t getDeadline() const;
    int getPriority() const;

    void setTitle(const std::string& title);
    void setDescription(const std::string& description);
    void setDeadline(std::time_t deadline);
    void setPriority(int priority);

    void displayTask() const;
};

#endif // TASK_H
