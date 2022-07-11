#include "UI/UI.h"
#include "Tests/Tests.h"
#include "Repository/CSV_Watchlist.h"
#include "Repository/HTML_Watchlist.h"
#include "GUI/gui.h"
#include <QApplication>
#include <QPushButton>
#include "GUI/csv_html_gui/csv_html_gui.h"

int startwithgui(int argc, char* argv[])
{

    QApplication a{argc, argv};
    Repository repository { R"(/Users/oanalupean/CLionProjects/a11-12/Files/movies.txt)" };

    csv_html_gui start_GUI;
    start_GUI.show();

    QApplication::exec();

    WatchList* watchList;
    if(start_GUI.csvOrHtml()){

        watchList = new CSVWatchlist();
        watchList->setType("csv");
    }
    else{

        watchList = new HTMLWatchlist();
        watchList->setType("html");
    }

    Service service {repository, watchList};

    GUI gui_app{service};

    gui_app.show();


    return a.exec();
}

void startwithui() {
    Repository reposiotry(R"(/Users/oanalupean/CLionProjects/a11-12/Files/movies.txt)");

}


int main(int argc, char *argv[]) {
    startwithgui(argc, argv);
//   startwithui();
    return 0;
}