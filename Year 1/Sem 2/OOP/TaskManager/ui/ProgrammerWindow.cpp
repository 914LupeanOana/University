//
// Created by Oana Lupean on 13.06.2022.
//

#include "ProgrammerWindow.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QMessageBox>
#include <sstream>
#include <string.h>


ProgrammerWindow::ProgrammerWindow(QWidget *parent, CodeRepository &codeRepository, const Programmer &programmer)
        : QWidget(parent), codeRepository(codeRepository),
          programmer(programmer) {
    codeRepository.add(this); // subscribe to the subject
    initializeUI();
    connectSignalsAndSlots();
}

void ProgrammerWindow::initializeUI() {
    setWindowTitle(programmer.getName().c_str());
    auto mainLayout = new QVBoxLayout(this);

    // set up source files list widget
    TaskList = new QListWidget(this);
    mainLayout->addWidget(TaskList);


    // set up add source file form
    auto addTaskForm = new QWidget(this);
    mainLayout->addWidget(addTaskForm);
    auto addSourceFileFormLayout = new QFormLayout(addTaskForm);

    // set up source file name line edit/input
    auto newTaskDescriptionLabel = new QLabel("Task &description:", addTaskForm);
    newTaskDescriptionLineEdit = new QLineEdit(addTaskForm);
    newTaskDescriptionLabel->setBuddy(newTaskDescriptionLineEdit);
    addSourceFileFormLayout->addRow(newTaskDescriptionLabel, newTaskDescriptionLineEdit);

    // set up add new source file button
    addTaskButton = new QPushButton("&Add task", this);
    mainLayout->addWidget(addTaskButton);


    removeTaskButton = new QPushButton("&Remove task", this);
    mainLayout->addWidget(removeTaskButton);

    // set up revise button
    startButton = new QPushButton("&Start", this);
    mainLayout->addWidget(startButton);
    //startButton->setDisabled(true);

    closeButton = new QPushButton("&Done", this);
    mainLayout->addWidget(closeButton);
    closeButton->setDisabled(true);

    update();
}

void ProgrammerWindow::connectSignalsAndSlots() {
    QObject::connect(addTaskButton, &QPushButton::clicked, this, &ProgrammerWindow::handleAddTaskButton);
    QObject::connect(removeTaskButton, &QPushButton::clicked, this, &ProgrammerWindow::handleRemoveTaskButton);
    QObject::connect(startButton, &QPushButton::clicked, this, &ProgrammerWindow::handleStartButton);
    QObject::connect(closeButton, &QPushButton::clicked, this, &ProgrammerWindow::handleCloseButton);
    QObject::connect(TaskList, &QListWidget::itemSelectionChanged, this, &ProgrammerWindow::handleListSelectionChanged);
}

void ProgrammerWindow::update() {
    updateTaskList();

}

void ProgrammerWindow::updateTaskList() {
    auto tasks = codeRepository.getSortedTasks();

    TaskList->clear();
//    sourceFilesList->addItem("name,status,creator,reviewer");
    for (const auto &taskss: tasks) {
        stringstream ss;
        ss << taskss;
        auto text = ss.str();
        auto item = new QListWidgetItem(text.c_str(), TaskList);

        TaskList->addItem(item);
//        sourceFilesList->addItem(ss.str().c_str());
    }
}


void showMessageBox(const QString &title, const QString &text) {
    auto messageBox = QMessageBox(QMessageBox::Information, title, text, QMessageBox::Ok, nullptr);
    messageBox.exec();
}

void ProgrammerWindow::handleAddTaskButton() {
    try {
        auto name = newTaskDescriptionLineEdit->text().toStdString();
        codeRepository.addTask(name, programmer);
    }
    catch (std::exception& e) {
        showMessageBox("failed", e.what());
//        auto failureMessageBox = QMessageBox(QMessageBox::Information, "failed", e.what(), QMessageBox::Ok, this);
//        failureMessageBox.exec();
    }
}


void ProgrammerWindow::handleRemoveTaskButton() {
    try {
        auto row = TaskList->currentRow();
        codeRepository.deleteTask(row);
    }
    catch (std::exception& e) {
        showMessageBox("failed", e.what());
//        auto failureMessageBox = QMessageBox(QMessageBox::Information, "failed", e.what(), QMessageBox::Ok, this);
//        failureMessageBox.exec();
    }
}


void ProgrammerWindow::handleStartButton() {
    try {
        auto sourceFile = codeRepository.findSortedTasksByIndex(TaskList->currentRow());

        if (sourceFile.isOpen()) {
            codeRepository.startTask(sourceFile.getDescription(), programmer); }
        else {
            showMessageBox("Error","You can not open this task.");
        }


    }
    catch (std::exception& e) { showMessageBox("failed", e.what()); }
}

void ProgrammerWindow::handleCloseButton() {
    try {
        auto sourceFile = codeRepository.findSortedTasksByIndex(TaskList->currentRow());
        //codeRepository.addTask(sourceFile.getID(), programmer);
        //codeRepository.addTask(programmer.getID(), programmer);

        if (sourceFile.getID() == programmer.getID() or sourceFile.getID() == programmer.getName())  {
            codeRepository.closeTask(sourceFile.getDescription(), programmer);

        }
        else {
            showMessageBox("Error","You can not close this task.");
        }



    }
    catch (std::exception& e) { showMessageBox("failed", e.what()); }
}

void ProgrammerWindow::handleListSelectionChanged() {
    auto row = TaskList->currentRow();
    auto sortedTasks = codeRepository.getSortedTasks();

    if (not codeRepository.isIndexValid(row)) {
        closeButton->setDisabled(true);
        return;
    }

    auto sourceFile = sortedTasks[row];
    if (sourceFile.isInProgress() and (sourceFile.getID() == programmer.getID() or sourceFile.getID() == programmer.getName())) {
        closeButton->setEnabled(true);
    }
    

    //closeButton->setEnabled(shouldEnableCloseButton);
}