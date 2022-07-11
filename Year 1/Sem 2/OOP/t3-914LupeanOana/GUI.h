//
// Created by Oana Lupean on 26.05.2022.
//

#ifndef UNTITLED6_GUI_H
#define UNTITLED6_GUI_H

#include <qwidget.h>
#include "Service.h"
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlabel.h>

class GUI:
        public QWidget {
private:
    Service &serv;

    QListWidget *myListWidget;

    QLineEdit *documents;

    QPushButton *showButton;

public:
    GUI(Service &srv);

private:
    void initGUI();

    void populate();

    void filter();

};

#endif //UNTITLED6_GUI_H
