/********************************************************************************
** Form generated from reading UI file 'GUI.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUI
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_9;
    QLabel *project;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *admin;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_search;
    QLineEdit *searchBar;
    QListWidget *movieList;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *updateButton;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_title;
    QLineEdit *lineEdit_genre;
    QLineEdit *lineEdit_year;
    QLineEdit *lineEdit_likes;
    QLineEdit *lineEdit_trailer;
    QVBoxLayout *verticalLayout_7;
    QPushButton *addWatchlist;
    QPushButton *undoButton;
    QPushButton *redoButton;
    QVBoxLayout *verticalLayout_6;
    QLabel *user;
    QListWidget *watchList;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton;
    QPushButton *open;
    QVBoxLayout *verticalLayout_5;
    QPushButton *like;
    QPushButton *removeWatchlist;

    void setupUi(QWidget *GUI)
    {
        if (GUI->objectName().isEmpty())
            GUI->setObjectName(QString::fromUtf8("GUI"));
        GUI->resize(947, 593);
        gridLayout = new QGridLayout(GUI);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        project = new QLabel(GUI);
        project->setObjectName(QString::fromUtf8("project"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Tempus Sans ITC")});
        font.setPointSize(20);
        project->setFont(font);

        verticalLayout_9->addWidget(project);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        admin = new QLabel(GUI);
        admin->setObjectName(QString::fromUtf8("admin"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Tempus Sans ITC")});
        font1.setPointSize(16);
        admin->setFont(font1);

        verticalLayout_3->addWidget(admin);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_search = new QLabel(GUI);
        label_search->setObjectName(QString::fromUtf8("label_search"));
        QFont font2;
        font2.setPointSize(12);
        label_search->setFont(font2);

        horizontalLayout_2->addWidget(label_search);

        searchBar = new QLineEdit(GUI);
        searchBar->setObjectName(QString::fromUtf8("searchBar"));
        searchBar->setFont(font2);

        horizontalLayout_2->addWidget(searchBar);


        verticalLayout_3->addLayout(horizontalLayout_2);

        movieList = new QListWidget(GUI);
        movieList->setObjectName(QString::fromUtf8("movieList"));
        movieList->setFont(font2);

        verticalLayout_3->addWidget(movieList);

        addButton = new QPushButton(GUI);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setFont(font2);

        verticalLayout_3->addWidget(addButton);

        removeButton = new QPushButton(GUI);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe UI")});
        font3.setPointSize(12);
        font3.setBold(false);
        removeButton->setFont(font3);

        verticalLayout_3->addWidget(removeButton);

        updateButton = new QPushButton(GUI);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));
        updateButton->setFont(font3);

        verticalLayout_3->addWidget(updateButton);


        horizontalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_6 = new QLabel(GUI);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);

        verticalLayout->addWidget(label_6);

        label_7 = new QLabel(GUI);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font2);

        verticalLayout->addWidget(label_7);

        label_8 = new QLabel(GUI);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font2);

        verticalLayout->addWidget(label_8);

        label_9 = new QLabel(GUI);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font2);

        verticalLayout->addWidget(label_9);

        label_10 = new QLabel(GUI);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font2);

        verticalLayout->addWidget(label_10);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_title = new QLineEdit(GUI);
        lineEdit_title->setObjectName(QString::fromUtf8("lineEdit_title"));
        lineEdit_title->setFont(font2);

        verticalLayout_2->addWidget(lineEdit_title);

        lineEdit_genre = new QLineEdit(GUI);
        lineEdit_genre->setObjectName(QString::fromUtf8("lineEdit_genre"));
        lineEdit_genre->setFont(font2);

        verticalLayout_2->addWidget(lineEdit_genre);

        lineEdit_year = new QLineEdit(GUI);
        lineEdit_year->setObjectName(QString::fromUtf8("lineEdit_year"));
        lineEdit_year->setFont(font2);

        verticalLayout_2->addWidget(lineEdit_year);

        lineEdit_likes = new QLineEdit(GUI);
        lineEdit_likes->setObjectName(QString::fromUtf8("lineEdit_likes"));

        verticalLayout_2->addWidget(lineEdit_likes);

        lineEdit_trailer = new QLineEdit(GUI);
        lineEdit_trailer->setObjectName(QString::fromUtf8("lineEdit_trailer"));

        verticalLayout_2->addWidget(lineEdit_trailer);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_8->addLayout(horizontalLayout);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        addWatchlist = new QPushButton(GUI);
        addWatchlist->setObjectName(QString::fromUtf8("addWatchlist"));
        addWatchlist->setFont(font2);

        verticalLayout_7->addWidget(addWatchlist);

        undoButton = new QPushButton(GUI);
        undoButton->setObjectName(QString::fromUtf8("undoButton"));

        verticalLayout_7->addWidget(undoButton);

        redoButton = new QPushButton(GUI);
        redoButton->setObjectName(QString::fromUtf8("redoButton"));

        verticalLayout_7->addWidget(redoButton);


        verticalLayout_8->addLayout(verticalLayout_7);


        horizontalLayout_4->addLayout(verticalLayout_8);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        user = new QLabel(GUI);
        user->setObjectName(QString::fromUtf8("user"));
        user->setFont(font1);

        verticalLayout_6->addWidget(user);

        watchList = new QListWidget(GUI);
        watchList->setObjectName(QString::fromUtf8("watchList"));
        watchList->setFont(font2);

        verticalLayout_6->addWidget(watchList);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        pushButton = new QPushButton(GUI);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_4->addWidget(pushButton);

        open = new QPushButton(GUI);
        open->setObjectName(QString::fromUtf8("open"));

        verticalLayout_4->addWidget(open);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        like = new QPushButton(GUI);
        like->setObjectName(QString::fromUtf8("like"));

        verticalLayout_5->addWidget(like);

        removeWatchlist = new QPushButton(GUI);
        removeWatchlist->setObjectName(QString::fromUtf8("removeWatchlist"));

        verticalLayout_5->addWidget(removeWatchlist);


        horizontalLayout_3->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_6);


        verticalLayout_9->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout_9, 0, 0, 1, 1);


        retranslateUi(GUI);

        QMetaObject::connectSlotsByName(GUI);
    } // setupUi

    void retranslateUi(QWidget *GUI)
    {
        GUI->setWindowTitle(QCoreApplication::translate("GUI", "GUI", nullptr));
        project->setText(QCoreApplication::translate("GUI", "MOVIE ORGANISER", nullptr));
        admin->setText(QCoreApplication::translate("GUI", "ADMIN", nullptr));
        label_search->setText(QCoreApplication::translate("GUI", "SEARCH:", nullptr));
        addButton->setText(QCoreApplication::translate("GUI", "ADD", nullptr));
        removeButton->setText(QCoreApplication::translate("GUI", "REMOVE", nullptr));
        updateButton->setText(QCoreApplication::translate("GUI", "UPDATE", nullptr));
        label_6->setText(QCoreApplication::translate("GUI", "TITLE:", nullptr));
        label_7->setText(QCoreApplication::translate("GUI", "GENRE:", nullptr));
        label_8->setText(QCoreApplication::translate("GUI", "YEAR:", nullptr));
        label_9->setText(QCoreApplication::translate("GUI", "LIKES:", nullptr));
        label_10->setText(QCoreApplication::translate("GUI", "TRAILER:", nullptr));
        addWatchlist->setText(QCoreApplication::translate("GUI", "ADD TO WATCHLIST", nullptr));
        undoButton->setText(QCoreApplication::translate("GUI", "UNDO", nullptr));
        redoButton->setText(QCoreApplication::translate("GUI", "REDO", nullptr));
        user->setText(QCoreApplication::translate("GUI", "USER", nullptr));
        pushButton->setText(QCoreApplication::translate("GUI", "OPEN IN APP", nullptr));
        open->setText(QCoreApplication::translate("GUI", "TRAILER", nullptr));
        like->setText(QCoreApplication::translate("GUI", "LIKE", nullptr));
        removeWatchlist->setText(QCoreApplication::translate("GUI", "REMOVE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUI: public Ui_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
