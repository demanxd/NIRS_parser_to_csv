#include "mainwindow.h"
#include <QString>
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include "writenew.h"
#include <QDebug>


void MainWindow::File_saver(QString &filename){

    QFileInfo qnf(filename);

    QString fileWay = qnf.canonicalPath();
    QString fileN = qnf.fileName();

    QString newFileName = "csv"+qnf.fileName() + ".csv";
    WriteNew exF(fileN,newFileName,fileWay);

    if (exF.isEnd())
        QMessageBox::information(0,"kek","End");

    exF.missUpper(24);

    while (!exF.isEnd()){
        exF.read();
        exF.write();
    }
    QMessageBox::information(this,"kek","chekaj");
}

