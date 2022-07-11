/********************************************************************************
** Form generated from reading UI file 'csv_html_gui.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSV_HTML_GUI_H
#define UI_CSV_HTML_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_csv_html_gui
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *csvButton;
    QPushButton *htmlButton;

    void setupUi(QWidget *csv_html_gui)
    {
        if (csv_html_gui->objectName().isEmpty())
            csv_html_gui->setObjectName(QString::fromUtf8("csv_html_gui"));
        csv_html_gui->resize(581, 216);
        widget = new QWidget(csv_html_gui);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 50, 545, 102));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Tempus Sans ITC")});
        font.setPointSize(20);
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        csvButton = new QPushButton(widget);
        csvButton->setObjectName(QString::fromUtf8("csvButton"));
        QFont font1;
        font1.setPointSize(16);
        csvButton->setFont(font1);

        horizontalLayout->addWidget(csvButton);

        htmlButton = new QPushButton(widget);
        htmlButton->setObjectName(QString::fromUtf8("htmlButton"));
        htmlButton->setFont(font1);

        horizontalLayout->addWidget(htmlButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(csv_html_gui);

        QMetaObject::connectSlotsByName(csv_html_gui);
    } // setupUi

    void retranslateUi(QWidget *csv_html_gui)
    {
        csv_html_gui->setWindowTitle(QCoreApplication::translate("csv_html_gui", "csv_html_gui", nullptr));
        label->setText(QCoreApplication::translate("csv_html_gui", " CHOOSE THE FILE TYPE:", nullptr));
        csvButton->setText(QCoreApplication::translate("csv_html_gui", "CSV", nullptr));
        htmlButton->setText(QCoreApplication::translate("csv_html_gui", "HTML", nullptr));
    } // retranslateUi

};

namespace Ui {
    class csv_html_gui: public Ui_csv_html_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSV_HTML_GUI_H
