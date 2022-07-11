//
// Created by Oana Lupean on 13.06.2022.
//

#ifndef TASKMANAGER_CODEREPOSITORY_H
#define TASKMANAGER_CODEREPOSITORY_H

#include <iostream>
#include <vector>
#include "../domain/Programmer.h"
#include "../domain/Task.h"
#include "../domain/observer.h"


using namespace std;

class CodeRepository: public Subject {
private:
    vector<Programmer> programmers;
    vector<Task> tasks;
public:
    CodeRepository();

    const vector<Programmer> &getProgrammers() const;
    const vector<Task> &getTasks() const;
    vector<Task> getSortedTasks() const;
    bool isIndexValid(int index) const { return index >= 0 and index < tasks.size(); }
    Task findSortedTasksByIndex(int index) const noexcept(false);
    void startTask(const string& description, Programmer& programmer) noexcept(false);
    void closeTask(const string& description, Programmer& programmer) noexcept(false);

    void addTask(const string& description, Programmer& programmer) noexcept(false);
    void deleteTask(int index) noexcept(false);

private:
    void readProgrammers();
    void readTasks();

    Task& findTasksByDescription(const string& description) noexcept(false);
};

#endif //TASKMANAGER_CODEREPOSITORY_H
