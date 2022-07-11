//

//

// You may need to build the project (run Qt uic code generator) to get "ui_csv_html_gui.h" resolved

#include "csv_html_gui.h"
#include "ui_csv_html_gui.h"


csv_html_gui::csv_html_gui(QWidget *parent) :
        QWidget(parent), ui(new Ui::csv_html_gui) {
    ui->setupUi(this);
    this->connectSignals();

}

csv_html_gui::~csv_html_gui() {
    delete ui;
}

void csv_html_gui::pushCSV() {

    this->csv = true;
    csv_html_gui::close();
}

void csv_html_gui::connectSignals(){

    QObject::connect(this->ui->csvButton, &QPushButton::clicked, this, &csv_html_gui::pushCSV);
    QObject::connect(this->ui->htmlButton, &QPushButton::clicked, this, &csv_html_gui::pushHTML);

}

void csv_html_gui::pushHTML() {

    this->csv = false;
    csv_html_gui::close();
}

bool csv_html_gui::csvOrHtml() {

    return this->csv;
}