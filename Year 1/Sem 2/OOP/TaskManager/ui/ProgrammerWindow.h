//
// Created by Oana Lupean on 13.06.2022.
//

#ifndef TASKMANAGER_PROGRAMMERWINDOW_H
#define TASKMANAGER_PROGRAMMERWINDOW_H

#include <QWidget>
#include <QListWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "../domain/observer.h"
#include "../repository/CodeRepository.h"

class ProgrammerWindow: public QWidget, public Observer {
Q_OBJECT
private:
    CodeRepository& codeRepository;
    Programmer programmer;
public:
    ProgrammerWindow(QWidget *parent, CodeRepository &codeRepository, const Programmer &programmer);

private:
    QListWidget* TaskList;

    QLineEdit* newTaskDescriptionLineEdit;
    QPushButton* addTaskButton;
    QPushButton* removeTaskButton;

    QPushButton* startButton;
    QPushButton* closeButton;

    void initializeUI();
    void connectSignalsAndSlots();

private slots:
    void handleAddTaskButton();
    void handleRemoveTaskButton();
    void handleStartButton();
    void handleCloseButton();
    void handleListSelectionChanged();

public:
    void update() override; // TODO: can this be private?
private:
    void updateTaskList();

};

#endif //TASKMANAGER_PROGRAMMERWINDOW_H
