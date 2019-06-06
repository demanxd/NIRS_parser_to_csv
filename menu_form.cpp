#include "mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QString>


void MainWindow::menuForThisWindow(){
    //it is alive!!!
    QMenuBar * mnu = new QMenuBar(this);
        QMenu * pMnu = new QMenu("File");

        helpButt = new QAction("Help", this);
        aboProg = new QAction("About program", this);
        addFile = new QAction("Open file", this);

        connect(aboProg, SIGNAL(triggered()), this, SLOT(openAboProg()));
        connect(helpButt, SIGNAL(triggered()), this, SLOT(openHelpProg()));
        connect(addFile, SIGNAL(triggered()), this, SLOT(importFile()));

        pMnu->addAction(aboProg);
        pMnu->addAction(helpButt);
        pMnu->addAction(addFile);


        mnu->addMenu(pMnu);

        mnu->show();
}




//slot's
//----
void MainWindow::openAboProg(){
    QMessageBox::information(this, "About this program",
                                       "Kill the hat!");
}
//----
void MainWindow::openHelpProg(){
    QMessageBox::information(this, "Help",
                                       "This program is lasy");
}
//----
void MainWindow::debagMess(){
    QMessageBox::information(this, "Sorry, but..","This part still don't work");
}
//----
void MainWindow::importFile(){
    QString str = QFileDialog::getOpenFileName(this,"Open dial", "", "*.txt");
    File_saver(str);
}
