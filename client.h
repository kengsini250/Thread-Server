#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>

class Client : public QTcpSocket
{
public:
    Client(qintptr id);
};

#endif // CLIENT_H
