//
// Created by Oana Lupean on 14.06.2022.
//

#include "DriverWindow.h"

#include <QVBoxLayout>
#include <QFormLayout>
#include <QMessageBox>
#include <sstream>
#include <string.h>


DriverWindow::DriverWindow(QWidget *parent, CodeRepository &codeRepository, const Driver &driver)
        : QWidget(parent), codeRepository(codeRepository),
          driver(driver) {
    codeRepository.add(this); // subscribe to the subject
    initializeUI();
    connectSignalsAndSlots();
}

void DriverWindow::initializeUI() {
    setWindowTitle(driver.getName().c_str());
    auto mainLayout = new QVBoxLayout(this);

    RoadList = new QListWidget(this);
    mainLayout->addWidget(RoadList);

    //set up labels
    status = new QLabel(this);
    mainLayout->addWidget(status);

    latit = new QLabel(this);
    mainLayout->addWidget(latit);

    longit = new QLabel(this);
    mainLayout->addWidget(longit);

    score = new QLabel(this);
    mainLayout->addWidget(score);

    auto addRoadForm = new QWidget(this);
    mainLayout->addWidget(addRoadForm);
    auto addRoadFormLayout = new QFormLayout(addRoadForm);


    auto newRoadDescriptionLabel = new QLabel("Road &description:", addRoadForm);
    newLatit = new QLineEdit(addRoadForm);
    newRoadDescriptionLabel->setBuddy(newLatit);
    addRoadFormLayout->addRow(newRoadDescriptionLabel, newLatit);


    auto newLatitDescriptionLabel = new QLabel("Road &latit:", addRoadForm);
    newRoadDescriptionLineEdit = new QLineEdit(addRoadForm);
    newLatitDescriptionLabel->setBuddy(newRoadDescriptionLineEdit);
    addRoadFormLayout->addRow(newLatitDescriptionLabel, newRoadDescriptionLineEdit);

    auto newLongitDescriptionLabel = new QLabel("Road &longit:", addRoadForm);
    newRoadDescriptionLineEdit = new QLineEdit(addRoadForm);
    newLongitDescriptionLabel->setBuddy(newRoadDescriptionLineEdit);
    addRoadFormLayout->addRow(newLongitDescriptionLabel, newRoadDescriptionLineEdit);


    // set up add new source file button
    addRoadButton = new QPushButton("&Add road", this);
    mainLayout->addWidget(addRoadButton);


    validateButton = new QPushButton("&Validate road", this);
    mainLayout->addWidget(validateButton);


    northButton = new QPushButton("&North", this);
    mainLayout->addWidget(northButton);


    southButton = new QPushButton("&South", this);
    mainLayout->addWidget(southButton);


    eastButton = new QPushButton("&East", this);
    mainLayout->addWidget(eastButton);

    westButton = new QPushButton("&West", this);
    mainLayout->addWidget(westButton);



    update();
}

void DriverWindow::connectSignalsAndSlots() {
    QObject::connect(addRoadButton, &QPushButton::clicked, this, &DriverWindow::handleAddRoadButton);
    QObject::connect(validateButton, &QPushButton::clicked, this, &DriverWindow::handleValidateButton);
    QObject::connect(northButton, &QPushButton::clicked, this, &DriverWindow::handleNorthButton);
    QObject::connect(southButton, &QPushButton::clicked, this, &DriverWindow::handleSouthButton);
    QObject::connect(westButton, &QPushButton::clicked, this, &DriverWindow::handleWestButton);
    QObject::connect(eastButton, &QPushButton::clicked, this, &DriverWindow::handleEastButton);
}

void DriverWindow::update() {
    updateRoadList();
    updateLabels();

}

void DriverWindow::updateRoadList() {
    auto roads = codeRepository.getRoads();

    RoadList->clear();
//    sourceFilesList->addItem("name,status,creator,reviewer");
    for (const auto &road: roads) {
        stringstream ss;
        ss << road;
        auto text = ss.str();
        auto item = new QListWidgetItem(text.c_str(), RoadList);

        RoadList->addItem(item);
//        sourceFilesList->addItem(ss.str().c_str());
    }
}


void showMessageBox(const QString &title, const QString &text) {
    auto messageBox = QMessageBox(QMessageBox::Information, title, text, QMessageBox::Ok, nullptr);
    messageBox.exec();
}

void DriverWindow::handleAddRoadButton() {
    try {
        auto name = newLatit->text().toStdString();
        auto latit = newRoadDescriptionLineEdit->text().toInt();
        auto longit = newRoadDescriptionLineEdit->text().toInt();
        codeRepository.addRoad(name, latit, longit, driver);
    }
    catch (std::exception& e) {
        showMessageBox("failed", e.what());

    }
}
void DriverWindow::handleValidateButton() {
    try {
        auto sourceFile = codeRepository.findSortedRoadByIndex(RoadList->currentRow());

        if (!sourceFile.isValidated()) {
            codeRepository.validateRoad(sourceFile.getDescription(), driver); }
        else {
            showMessageBox("Error","You can not validate this road.");
        }


    }
    catch (std::exception& e) { showMessageBox("failed", e.what()); }
}

void DriverWindow::updateLabels() {
    status->setText(("Status: " + driver.getStatus()).c_str());
    latit->setText(("Latit: " + to_string(driver.getLatit())).c_str());
    longit->setText(("Latit: " + to_string(driver.getLongit())).c_str());
    score->setText(("Score: " + to_string(driver.getScore())).c_str());

}

void DriverWindow::handleNorthButton(){
    codeRepository.updateDriverN(driver);
}

void DriverWindow::handleSouthButton(){
    codeRepository.updateDriverS(driver);
}

void DriverWindow::handleWestButton(){
    codeRepository.updateDriverW(driver);
}

void DriverWindow::handleEastButton(){
    codeRepository.updateDriverE(driver);
}