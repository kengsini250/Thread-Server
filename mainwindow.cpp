#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->cclean, &QAbstractButton::clicked, [=]() {
        ui->textBrowser->clear();
    });

    myServer=new MyServer(this);
    ui->textBrowser->append("Max Users : "+QString::number(myServer->maxPendingConnections())+"\n");

    connect(myServer,&MyServer::newClient,[=]() {
        ui->textBrowser->append("--new  client---");
        ui->textBrowser->append("now : "+QString::number(myServer->getConnectingClient())+"\n");
    });
    connect(myServer,&MyServer::setText,[&](QString&msg){
        ui->textBrowser->append(msg);
    });
    connect(myServer,&MyServer::disconnectClient,[=](qintptr id){
        ui->textBrowser->append("\n---"+QString::number(id)+" disconnect");
        ui->textBrowser->append("now : "+QString::number(myServer->getConnectingClient())+"---\n");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

