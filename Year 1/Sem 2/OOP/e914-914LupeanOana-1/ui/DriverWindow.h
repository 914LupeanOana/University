//
// Created by Oana Lupean on 14.06.2022.
//

#ifndef E914_914LUPEANOANA_1_DRIVERWINDOW_H
#define E914_914LUPEANOANA_1_DRIVERWINDOW_H

#include <QWidget>
#include <QListWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "../domain/observer.h"
#include "../repository/CodeRepository.h"

class DriverWindow: public QWidget, public Observer {
Q_OBJECT
private:
    CodeRepository& codeRepository;
    Driver driver;
public:
    DriverWindow(QWidget *parent, CodeRepository &codeRepository, const Driver &driver);

private:
    QListWidget* RoadList;

    QLabel* status;
    QLabel* latit;
    QLabel* longit;
    QLabel* score;

    QLineEdit* newRoadDescriptionLineEdit;
    QLineEdit* newLatit;
    QLineEdit* newLongit;
    QPushButton* addRoadButton;
    QPushButton* northButton;
    QPushButton* southButton;
    QPushButton* eastButton;
    QPushButton* westButton;

    QPushButton* validateButton;



    void initializeUI();
    void connectSignalsAndSlots();

private slots:
    void handleAddRoadButton();
    void handleNorthButton();
    void handleSouthButton();
    void handleEastButton();
    void handleWestButton();
    void handleValidateButton();

   // void handleListSelectionChanged();

public:
    void update() override; // TODO: can this be private?
private:
    void updateRoadList();
    void updateLabels();
};



#endif //E914_914LUPEANOANA_1_DRIVERWINDOW_H
