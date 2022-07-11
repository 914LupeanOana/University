//

//

// You may need to build the project (run Qt uic code generator) to get "ui_GUI.h" resolved

#include "gui.h"
#include "ui_GUI.h"


GUI::GUI(Service& service, QWidget *parent) :
        QWidget(parent), ui(new Ui::GUI), service(service) {
    ui->setupUi(this);
    this->populateList(this->service.getAllRepository());
    this->connectSignals();
    this->searchMovies();
}

GUI::~GUI() {
    delete ui;
}

void GUI::populateList(std::vector<Movie> movies) {

    if (this->ui->movieList->count() > 0)
        this->ui->movieList->clear();

    for (auto movie : movies){

        QString itemInList = QString::fromStdString(movie.getTitle() + ", " + movie.getGenre() + ", " + std::to_string(movie.getYear()) + ", " +
                                                    std::to_string(movie.getLikes()) + ", " + movie.getTrailer());
        this->ui->movieList->addItem(itemInList);
    }

    if(!movies.empty())
        this->ui->movieList->setCurrentRow(0);
}

void GUI::connectSignals(){

    QObject::connect(this->ui->addButton, &QPushButton::clicked, this, &GUI::addMovie);

    QObject::connect(this->ui->movieList, &QListWidget::itemSelectionChanged, this, [this](){ this->listChanged(); });

    QObject::connect(this->ui->removeButton, &QPushButton::clicked,this,&GUI::removeMovie);

    QObject::connect(this->ui->updateButton, &QPushButton::clicked,this,&GUI::updateMovie);

    QObject::connect(this->ui->addWatchlist, &QPushButton::clicked, this, &GUI::addMovieToWatchlist);

    QObject::connect(this->ui->removeWatchlist, &QPushButton::clicked, this, &GUI::removeFromWatchlist);

    //QObject::connect(this->ui->open,&QPushButton::clicked,this, &GUI::openLink);

    QObject::connect(this->ui->like, &QPushButton::clicked, this, &GUI::like);

    QObject::connect(this->ui->searchBar, &QLineEdit::textChanged, this, &GUI::searchMovies);

    QObject::connect(this->ui->pushButton, &QPushButton::clicked, this, &GUI::saveAndOpen);
}

int GUI::getSelectedIndex(){

    if(this->ui->movieList->count() == 0)
        return -1;

    QModelIndexList index = this->ui->movieList->selectionModel()->selectedIndexes();

    if(index.size() == 0)
    {
        this->ui->lineEdit_title->clear();
        this->ui->lineEdit_year->clear();
        this->ui->lineEdit_genre->clear();
        this->ui->lineEdit_likes->clear();
        this->ui->lineEdit_trailer->clear();
        return -1;
    }

    int inx = index.at(0).row();
    return inx;
}

void GUI::listChanged(){

    int i = this->getSelectedIndex();
    if(i < 0)
        return;

    if(i > this->service.getAllRepository().size())
        return;

    Movie movie = this->service.getAllRepository()[i];

    this->ui->lineEdit_title->setText(QString::fromStdString(movie.getTitle()));
    this->ui->lineEdit_genre->setText(QString::fromStdString(movie.getGenre()));
    this->ui->lineEdit_year->setText(QString::fromStdString(std::to_string(movie.getYear())));
    this->ui->lineEdit_likes->setText(QString::fromStdString(std::to_string(movie.getLikes())));
    this->ui->lineEdit_trailer->setText(QString::fromStdString(movie.getTrailer()));

}

void GUI::addMovie(){

    std::string title = this->ui->lineEdit_title->text().toStdString();
    std::string genre = this->ui->lineEdit_genre->text().toStdString();
    int year = stoi (this->ui->lineEdit_year->text().toStdString());
    int likes = stoi (this->ui->lineEdit_likes->text().toStdString());
    std::string link = this->ui->lineEdit_trailer->text().toStdString();

    this->service.addRepository(Movie(title,genre,year,likes,link));
    this->populateList(this->service.getAllRepository());
}

void GUI::removeMovie(){

    int i= this->getSelectedIndex();
    this->service.deleteRepository(i);
    this->populateList(this->service.getAllRepository());
}

void GUI::updateMovie(){

    int i= this->getSelectedIndex();

    std::string title = this->ui->lineEdit_title->text().toStdString();
    std::string genre = this->ui->lineEdit_genre->text().toStdString();
    int year = stoi (this->ui->lineEdit_year->text().toStdString());
    int likes = stoi (this->ui->lineEdit_likes->text().toStdString());
    std::string link = this->ui->lineEdit_trailer->text().toStdString();

    Movie movie(title,genre,year,likes,link);

    this->service.updateRepository(i,movie);

    this->populateList(this->service.getAllRepository());
}

void GUI::populateWatchlist() {

    if (this->ui->watchList->count() > 0)
        this->ui->watchList->clear();

    for (auto movie : this->service.getAllWatchList()){

        QString itemInList = QString::fromStdString(movie.getTitle() + ", " + movie.getGenre() + ", " + std::to_string(movie.getYear()) + ", " +
                                                    std::to_string(movie.getLikes()) + ", " + movie.getTrailer());
        this->ui->watchList->addItem(itemInList);
    }

    if(!this->service.getAllWatchList().empty())
        this->ui->watchList->setCurrentRow(0);
}

void GUI::addMovieToWatchlist(){

    int i = this->getSelectedIndex();

    Movie movie = this->service.getAllRepository()[i];

    this->service.addWatchList(movie);
    this->service.saveWatchlist();

    this->populateWatchlist();
}

void GUI::removeFromWatchlist(){

    int i = this->getSelectedIndexWatchlist();

    this->service.deleteWatchList(i);
    this->service.saveWatchlist();

    this->populateWatchlist();
}

int GUI::getSelectedIndexWatchlist(){

    if(this->ui->watchList->count() == 0)
        return -1;

    QModelIndexList index = this->ui->watchList->selectionModel()->selectedIndexes();

    if(index.size() == 0)
    {
        this->ui->lineEdit_title->clear();
        this->ui->lineEdit_year->clear();
        this->ui->lineEdit_genre->clear();
        this->ui->lineEdit_likes->clear();
        this->ui->lineEdit_trailer->clear();
        return -1;
    }

    int inx = index.at(0).row();
    return inx;
}
/*
void GUI::openLink(){

    int i = this->getSelectedIndexWatchlist();

    Movie movie = this->service.getAllWatchList()[i];

    movie.playTrailer();
}
*/
void GUI::like(){

    int i = this->getSelectedIndexWatchlist();

    Movie movie = this->service.getAllWatchList()[i];

    int j = this->service.findPos(movie);

    this->service.incrementLikesService(j,i);
    this->populateWatchlist();
    this->populateList(this->service.getAllRepository());
}

void GUI::searchMovies() {

    QString size = this->ui->searchBar->text();

    if(size.isEmpty())
    {
        this->populateList(this->service.getAllRepository());
    }

    std::string int_size = size.toStdString();
    std::vector<Movie> new_coats;

    for (const auto coat : this->service.getAllRepository())
    {
        if(coat.getGenre().find(int_size) != std::string::npos)
            new_coats.push_back(coat);
    }

//    for (auto movie : new_coats){
//
//        QString itemInList = QString::fromStdString(movie.getTitle() + ", " + movie.getGenre() + ", " + std::to_string(movie.getYear()) + ", " +
//                                                    std::to_string(movie.getLikes()) + ", " + movie.getTrailer());
//        this->ui->movieList->addItem(itemInList);
//    }
    this->populateList(new_coats);

    if(!this->service.getAllRepository().empty())
        this->ui->movieList->setCurrentRow(0);

    if(size.isEmpty())
    {
        this->populateList(this->service.getAllRepository());
    }
}

void GUI::saveAndOpen(){

    this->service.saveWatchlist();
    this->service.openInAppWatchlist();
}