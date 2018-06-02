#include "anapencere.h"
#include "ui_anapencere.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QLabel>
#include <QProcess>

AnaPencere::AnaPencere(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnaPencere)

{
    ui->setupUi(this);

}



AnaPencere::~AnaPencere()
{

    delete ui;
}

void AnaPencere::on_pushButton_clicked()
{
    QString filename =  QFileDialog::getOpenFileName(
          this,
          "Qemu ile Başlatmak İstediğiniz ISO Kalıbını Seçiniz",
          QDir::currentPath(),
          "ISO Kalıbı (*.iso);; Tüm Dosyalar (*.*)");

    if( !filename.isNull() )
    {
      ui->label->setText(filename.toUtf8());
      qDebug() << "Seçilen Dosya Yolu: " << filename.toUtf8();
    }
};

void AnaPencere::on_commandLinkButton_2_clicked()
{
    QMessageBox::information(this, "Ay-Qemu","    Qemu için basit bir arayüz \nCihan Alkan Tarafından Hazırlanmıştır.");
}

void AnaPencere::on_commandLinkButton_clicked()
{
    QFile kurulumu("/usr/bin/qemu-system-x86_64");

    if(!kurulumu.exists())
    {
    QMessageBox::information(this, "Ay-Qemu"," Qemu uygulaması kurulu değil. Öncelikle Qemu kurulmalıdır. \n (sudo pacman -S qemu)");
    }
else
    {
     QString ram = ui->comboBox->currentText();
     QProcess::execute("qemu-system-x86_64 -m "+ ram + " --enable-kvm " + ui->label->text());
    }

}
