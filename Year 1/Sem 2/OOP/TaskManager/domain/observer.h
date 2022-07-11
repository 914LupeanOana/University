//
// Created by Oana Lupean on 12.06.2022.
//

#ifndef TASKMANAGER_OBSERVER_H
#define TASKMANAGER_OBSERVER_H

#include <vector>

using namespace std;

class Observer {
public:
    virtual void update() = 0;
};

class Subject {
private:
    vector<Observer*> observers;
public:
    void add(Observer* o) { observers.push_back(o); }
    void notify() {
        for (const auto &observer: observers)
            observer->update();
    }
};

#endif //TASKMANAGER_OBSERVER_H
