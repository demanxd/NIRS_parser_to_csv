#include <QApplication>
#include <QMenu>
#include <QMenuBar>
#include "mainwindow.h"
#include "writenew.h"



class WriteNew;

int main(int argc,char** Argv)
{
    QApplication  app(argc, Argv);


    MainWindow w;
    w.show();

    return app.exec();
}
