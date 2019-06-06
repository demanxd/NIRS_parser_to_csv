#ifndef WRITENEW_H
#define WRITENEW_H

#include <QString>
#include <QFile>
#include <QTextStream>


class WriteNew
{
    //Q_OBJECT

public:
    explicit WriteNew(QString &, QString &, QString &);
    ~WriteNew();
    void write();
    void read();
    bool isEnd();                                               //true - if not End, false - if End
    void missUpper(int);

private:
    QFile fileIn;
    QFile fileOut;
    QTextStream readStream;
    QTextStream writeStream;
    QString oldFileName;
    QString newFileName;
    QString saveDirectory;
    QString FW;
    QString data;
    long long int numPos;
    long long int fileEnd;


/*
    QString StrFN;
    QString StrFW;
    QString SStrFW;
    QString readStream;
    long int numPos;
    */
};



#endif // WRITENEW_H

