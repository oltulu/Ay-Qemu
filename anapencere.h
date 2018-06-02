#ifndef ANAPENCERE_H
#define ANAPENCERE_H

#include <QMainWindow>

namespace Ui {
class AnaPencere;
}

class AnaPencere : public QMainWindow
{
    Q_OBJECT

public:
    explicit AnaPencere(QWidget *parent = 0);
    ~AnaPencere();

private slots:
    void on_pushButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_clicked();

private:
    Ui::AnaPencere *ui;

};

#endif // ANAPENCERE_H
