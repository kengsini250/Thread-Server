#include "clientthread.h"

ClientThread::ClientThread(QObject *parent, qintptr socketID) : QObject(parent)
{
    this->socketID = socketID;
}

void ClientThread::run()
{
    Client *currentClient = new Client(socketID);
    //-------------------new Client------------------------------
    emit newClient(socketID,currentClient);

    //-------------------new Message------------------------------
    connect(currentClient,&QTcpSocket::readyRead,[=](){
        QString msg = currentClient->readAll();
        emit setText(msg);
    });

    //-------------------Client disconnect------------------------
    connect(currentClient,&QTcpSocket::disconnected,[=]{
        emit setDisconnect(socketID);
    });
}
