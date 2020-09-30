#include <QMessageBox>
#include <QTcpServer>
#include "mainview.h"
#include "ui_mainview.h"

static int PORT_NUMBER = 7777;

MainView::MainView(QWidget *parent):QMainWindow(parent), ui(new Ui::MainView),
    tcpServer(new QTcpServer(this)) {

    ui->setupUi(this);
}

MainView::~MainView() {
    delete ui;
}

void MainView::on_buttonStartServer_clicked() {
    if (StartServer()) {
        ui->buttonStartServer->setEnabled(false);
        ui->buttonStopServer->setEnabled(true);
    }
}

void MainView::on_buttonStopServer_clicked() {
    StopServer();
    ui->buttonStartServer->setEnabled(true);
    ui->buttonStopServer->setEnabled(false);
}

bool MainView::StartServer() {
    bool hasStarted = tcpServer->listen(QHostAddress::Any, PORT_NUMBER);

    if (!hasStarted) {
        QMessageBox::critical(this, "Echo Server",
                              tr("Unable to start the server: %1").arg(tcpServer->errorString()));

        return false;
    }

    return true;
}

void MainView::StopServer() {
    tcpServer->close();
}
