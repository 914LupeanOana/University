//
// Created by Oana Lupean on 12.06.2022.
//

#include "Task.h"

Task::Task(const string &description, const string &status, const string &id) : description(
        description), status(status), id(id) {}

const string &Task::getDescription() const {
    return description;
}

const string &Task::getStatus() const {
    return status;
}

const string &Task::getID() const {
    return id;
}


ostream &operator<<(ostream &os, const Task &file) {
    os << file.description << "," << file.status << "," << file.id;
    return os;
}

istream &operator>>(istream &is, Task &file) {
    getline(is, file.description, ',');
    getline(is, file.status, ',');

    getline(is, file.id, '\n');


    return is;
}

void Task::start(const string &id) {
    status = "in_progress";
    this->id = id;
}

void Task::close(const string &id) {
    status = "closed";
    this->id = id;
}