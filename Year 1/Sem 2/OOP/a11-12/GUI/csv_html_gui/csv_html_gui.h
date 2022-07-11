//

//

#ifndef A11_12_914_MARTI_NICOLAE_VLAD_CSV_HTML_GUI_H
#define A11_12_914_MARTI_NICOLAE_VLAD_CSV_HTML_GUI_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class csv_html_gui; }
QT_END_NAMESPACE

class csv_html_gui : public QWidget {
Q_OBJECT
private:
    bool csv;

public:
    explicit csv_html_gui(QWidget *parent = nullptr);

    ~csv_html_gui() override;
    bool csvOrHtml();

private:
    Ui::csv_html_gui *ui;

    void connectSignals();
    void pushCSV();
    void pushHTML();
};


#endif //A11_12_914_MARTI_NICOLAE_VLAD_CSV_HTML_GUI_H
