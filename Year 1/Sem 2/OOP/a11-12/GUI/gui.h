//

//

#ifndef A11_12_914_MARTI_NICOLAE_VLAD_GUI_H
#define A11_12_914_MARTI_NICOLAE_VLAD_GUI_H
#include <QWidget>
#include "Service.h"
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QRadioButton>
#include "../Exceptions/Validators.h"
#include <QTableView>
#include <QShortcut>
#include <QHeaderView>


QT_BEGIN_NAMESPACE
namespace Ui { class GUI; }
QT_END_NAMESPACE

class GUI : public QWidget {
Q_OBJECT

public:
    explicit GUI(Service &service, QWidget *parent = nullptr);

    ~GUI() override;

private:
    Ui::GUI *ui;
    Service &service;


    void addMovie();
    void removeMovie();
    void updateMovie();

    void populateWatchlist();
    void addMovieToWatchlist();
    void removeFromWatchlist();
    void connectSignals();
    int getSelectedIndex();
    void listChanged();

    void like();
    //void openLink();
    int getSelectedIndexWatchlist();

    void searchMovies();

    void populateList(std::vector<Movie> movies);

    void saveAndOpen();
};


#endif //A11_12_914_MARTI_NICOLAE_VLAD_GUI_H
