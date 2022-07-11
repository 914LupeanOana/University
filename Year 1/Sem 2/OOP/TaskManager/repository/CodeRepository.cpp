//
// Created by Oana Lupean on 13.06.2022.
//

#include "CodeRepository.h"
#include <fstream>
#include <algorithm>

CodeRepository::CodeRepository() {
    readProgrammers();
    readTasks();
}

const vector<Programmer> &CodeRepository::getProgrammers() const {
    return programmers;
}

const vector<Task> &CodeRepository::getTasks() const {
    return tasks;
}

void CodeRepository::readProgrammers() {
    string filename = "programmer.txt";
    ifstream f(filename);

    if (!f.is_open()) {
        fprintf(stderr, "Could not read from %s\n", filename.c_str());
        return;
    }

    Programmer p;
    while (f >> p) { programmers.push_back(p); }

}

void CodeRepository::readTasks()  {
    string filename = "task.txt"; // NOTE: add a blank line at the end, due to the SourceFile operator>>
    ifstream f(filename);

    if (!f.is_open()) {
        fprintf(stderr, "Could not read from %s\n", filename.c_str());
        return;
    }

    Task p;
    while (f >> p) { tasks.push_back(p); }
}

void CodeRepository::addTask(const string &description, Programmer &programmer) noexcept(false)  {
    if (description.empty()) throw std::runtime_error("Source file name must not be empty");


    tasks.emplace_back(description, "open", "");
    notify();
}

void CodeRepository::deleteTask(int index) noexcept(false) {

   tasks.erase(tasks.begin()+index);


}

vector<Task> CodeRepository::getSortedTasks() const {
    auto sortedTasks = this->tasks;

    // sort the source files by status
    std::sort(sortedTasks.begin(), sortedTasks.end(), [](const Task& t1, const Task& t2) {
        return t1.getStatus() > t2.getStatus();
    });

    return sortedTasks;
}

Task CodeRepository::findSortedTasksByIndex(int index) const noexcept(false) {
    if (not isIndexValid(index))
        throw std::runtime_error("Invalid task selected");

    return getSortedTasks()[index];
}

void CodeRepository::startTask(const string &description, Programmer &programmer) noexcept(false)  {
    // can throw, but, theoretically, it shouldn't since the original source of the name is the source files vector
    auto& taskss = findTasksByDescription(description);

    taskss.start(programmer.getName());

    notify();
}

void CodeRepository::closeTask(const string &description, Programmer &programmer) noexcept(false)  {
    // can throw, but, theoretically, it shouldn't since the original source of the name is the source files vector
    auto& taskss = findTasksByDescription(description);

    taskss.close(programmer.getID());

    notify();
}

Task &CodeRepository::findTasksByDescription(const string& description) noexcept(false) {
    for (auto &taskss: tasks)
        if (taskss.getDescription() == description)
            return taskss;

    throw std::runtime_error("Invalid source file selected"); // NOTE: the message is wrong. That source file just doesn't exist.
}
