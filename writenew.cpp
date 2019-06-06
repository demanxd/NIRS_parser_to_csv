#include "writenew.h"
#include <QDir>
#include <QMessageBox>
#include <QApplication>
#include <QFileInfo>




WriteNew::WriteNew(QString &oldFN, QString &newFN, QString &FW){

    QDir direct;
    direct.setCurrent(FW);

    fileIn.setFileName(oldFN);

    saveDirectory = QApplication::applicationDirPath() + "/controlFolders/";
    fileOut.setFileName(newFN);
    fileOut.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append);

    fileIn.open(QIODevice::ReadOnly|QIODevice::Text|QIODevice::Append);
    if(!fileIn.isOpen())
        QMessageBox::information(0,"upss","wrong in working directory\n"+QDir::currentPath());

    fileEnd = fileIn.pos();
    fileIn.seek(0);
    readStream.setDevice(&fileIn);
    readStream.seek(0);
    numPos = readStream.pos();
    writeStream.setDevice(&fileOut);

}

WriteNew::~WriteNew()
{
    fileIn.close();
    fileOut.close();
}

void WriteNew::read()
{
    data = readStream.readLine();
}

void WriteNew::write()
{
    writeStream<<data<<"\n";
}

bool WriteNew::isEnd(){
    if (readStream.pos() == fileEnd)
        return true;
    else
        return false;
}

void WriteNew::missUpper(int n)
{
    for (int i = 0; i < n; ++i)
        data = readStream.readLine();
}
