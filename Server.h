#ifndef SERVER_H
#define SERVER_H

#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QMainWindow>
#include <QString>
#include <QByteArray>
#include <QMap>

#include <QThread>
#include "clientthread.h"

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
	explicit MyServer(QMainWindow* parent = nullptr);

    int getConnectingClient() noexcept;
protected:
    void incomingConnection(qintptr socketDescriptor);
private:
    QMap<qintptr,QTcpSocket*> allClient;
    QMap<qintptr,QTcpSocket*>::iterator i;

    QString msg;
    QThread* thread;
signals:
    void newClient();
    void setText(QString&str);
    void disconnectClient(qintptr);
};

#endif
