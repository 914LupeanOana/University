//
// Created by Oana Lupean on 14.06.2022.
//

#include <QApplication>
#include <QPushButton>
#include "repository/CodeRepository.h"
#include "ui/DriverWindow.h"


int main(int argc, char *argv[]) {
    CodeRepository codeRepository;
    vector<DriverWindow*> windows;

    QApplication a(argc, argv);
    for (const auto &programmer: codeRepository.getDrivers()) {
        auto window = new DriverWindow(nullptr, codeRepository, programmer);
        window->show();
        windows.push_back(window);
    }

    const auto execResult = QApplication::exec();

    for (const auto &window: windows) delete window;

    return execResult;
}
