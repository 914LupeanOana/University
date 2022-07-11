#include <QApplication>
#include <QPushButton>
#include "GUI.h"
#include "Service.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Service service{"/Users/oanalupean/CLionProjects/untitled6/file.txt"};
    GUI gui{service};
    gui.show();
    return a.exec();
}
