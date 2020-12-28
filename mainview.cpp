#include <QMessageBox>
#include <QTcpServer>
#include <QTcpSocket>
#include "mainview.h"
#include "ui_mainview.h"

const static int PORT_NUMBER = 7777;
const static int WAIT_FOR_DATA_MS = 200;

MainView::MainView(QWidget *parent):QMainWindow(parent), ui(new Ui::MainView),
    tcpServer(new QTcpServer(this)), tcpSocket(nullptr) {

    ui->setupUi(this);
    ui->buttonStopServer->setEnabled(false);

    // Connect the newConnection signal from the server to the ExchangeData slot
    connect(tcpServer, &QTcpServer::newConnection, this, &MainView::ExchangeData);
}

MainView::~MainView() {
    delete ui;
}

void MainView::on_buttonStartServer_clicked() {
    if(StartServer()) {
        ui->buttonStartServer->setEnabled(false);
        ui->buttonStopServer->setEnabled(true);
    }
}

void MainView::on_buttonStopServer_clicked() {
    StopServer();
    ui->buttonStartServer->setEnabled(true);
    ui->buttonStopServer->setEnabled(false);
}

void MainView::ExchangeData() {
    // Ask the server for next pending connection socket
    tcpSocket = tcpServer->nextPendingConnection();

    if(tcpSocket->isOpen()) {
        // Connect the readyRead signal from the socket to the ReadData slot
        connect(tcpSocket, &QTcpSocket::readyRead, this, &MainView::ReadData);
    }
}

void MainView::ReadData() {
    QString message;

    tcpSocket->write("<echo>\n");

    while(!tcpSocket->atEnd()) {
        message.append(tcpSocket->readAll());
        tcpSocket->waitForReadyRead(WAIT_FOR_DATA_MS);
    }

    tcpSocket->write(qPrintable(message));
    tcpSocket->write("</echo>\n");
}

bool MainView::StartServer() {
    const bool hasStarted = tcpServer->listen(QHostAddress::Any, PORT_NUMBER);

    if(!hasStarted) {
        QMessageBox::critical(this, "Echo Server",
                              tr("Unable to start the server: %1").arg(tcpServer->errorString()));

        return false;
    }

    return true;
}

void MainView::StopServer() {
    tcpServer->close();
    if((tcpSocket != nullptr) && (tcpSocket->isOpen())) tcpSocket->close();
}
