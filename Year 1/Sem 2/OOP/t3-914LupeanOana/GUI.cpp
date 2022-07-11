//
// Created by Oana Lupean on 26.05.2022.
//

#include "GUI.h"
#include "GUI.h"

#include "GUI.h"
#include <qlayout.h>
#include <qformlayout.h>
#include <qgridlayout.h>
#include "Domain.h"
#include <vector>
#include <QString>



GUI::GUI(Service& srv) : serv{srv} {
    this->initGUI();
    this->populate();

}

void GUI::initGUI() {
    this->myListWidget = new QListWidget{};

    this->documents = new QLineEdit{};

    this->showButton = new QPushButton{"Show"};

    QVBoxLayout* main = new QVBoxLayout(this);
    main->addWidget(this->myListWidget);


    QFormLayout* detail = new QFormLayout();
    detail->addRow("Documents", this->documents);
    main->addLayout(detail);


    QGridLayout* buttonLayout = new QGridLayout();
    buttonLayout->addWidget(this->showButton, 0, 1);
    main->addLayout(buttonLayout);



}

bool cmp(Domain a, Domain b){
    return a.get_name() < b.get_name();
}

void GUI::populate() {
    this->myListWidget->clear();
    vector<Domain>something = this->serv.load_content();

    sort(something.begin(), something.end(), cmp);

    for(auto& each : something)
        this->myListWidget->addItem(QString::fromStdString(each.output()));
}

void GUI::filter(){
    string keywords = this->documents->text().toStdString();

    vector<Domain>all = this->serv.load_content();

    this->myListWidget->clear();

    for(auto each : all){
        vector<string>mine = each.get_keywords();
        for(auto now : mine){
            std::size_t found;
            found=now.find(keywords);
            if (found!=std::string::npos){
                this->myListWidget->addItem(QString::fromStdString(each.output()));
                break;
            }
        }
    }
}