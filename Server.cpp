#include "Server.h"

MyServer::MyServer(QMainWindow* parent):QTcpServer(parent)
{
    listen(QHostAddress::Any, 55555);
}

int MyServer::getConnectingClient() noexcept
{
    return allClient.size();
}

void MyServer::incomingConnection(qintptr socketDescriptor)
{
    ClientThread *client = new ClientThread(0,socketDescriptor);
    thread = new QThread;
    client->moveToThread(thread);
    thread->start();

    connect(thread,&QThread::finished,client,&QObject::deleteLater);
    connect(thread,&QThread::started,client,&ClientThread::run);

    connect(client,&ClientThread::newClient,[=](qintptr id,QTcpSocket* socket){
        allClient.insert(id,socket);
    });
    connect(client,&ClientThread::setDisconnect,[=](qintptr id){
        allClient.remove(id);
        emit disconnectClient(id);
    });
    connect(client,&ClientThread::setText,[&](QString&msg){
        emit setText(msg);
    });
}
