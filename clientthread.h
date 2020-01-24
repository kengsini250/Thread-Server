#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H

#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <QMap>
#include <QDebug>

#include "client.h"

class ClientThread : public QObject
{
    Q_OBJECT
public:
    explicit ClientThread(QObject *parent = nullptr, qintptr socketID = -1);
public slots:
    void run();
private:
    qintptr socketID;
signals:
    void setDisconnect(qintptr id);
    void setText(QString&);
    void newClient(qintptr id,QTcpSocket*);

};

#endif // CLIENTTHREAD_H
