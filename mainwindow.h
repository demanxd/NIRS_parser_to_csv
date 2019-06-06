#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void File_saver(QString& );

public slots:
    void menuForThisWindow();
    void openAboProg();
    void openHelpProg();
    void debagMess();                           //use this when something is not working (output message about this)
    void importFile();

private:
    Ui::MainWindow *ui;
    QMenuBar*    mnuBar;
    QMenu*      pmnu;
    QAction*    addFile;
    QMenu*      pmnuSubMenu;
    QAction*    showAction;
    QAction*    minimizeAction;
    QAction*    helpButt;
    QAction*    aboProg;
    QMenu*      menu;
    QString*    str;
    QString*    CurrentPlaceProgram;
    QString*    fnm;
};


#endif
