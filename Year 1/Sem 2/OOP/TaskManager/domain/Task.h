//
// Created by Oana Lupean on 12.06.2022.
//

#ifndef TASKMANAGER_TASK_H
#define TASKMANAGER_TASK_H

#include <iostream>

using namespace std;

class Task {
private:
    string description;
    string status; // revised/not_revised
    string id;

public:
    Task(const string &description, const string &status, const string &id);
    Task() = default;

    const string &getDescription() const;
    const string &getStatus() const;
    const string &getID() const;


    bool isOpen() const { return status == "open"; }
    bool isInProgress() const { return status == "in_progress"; }
    bool isClosed() const { return status == "closed"; }

    friend ostream &operator<<(ostream &os, const Task &file);
    friend istream &operator>>(istream &is, Task &file);

    void start(const string &id);
    void close(const string &id);
};

#endif //TASKMANAGER_TASK_H
