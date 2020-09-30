#include "mainview.h"
#include "ui_mainview.h"
#include <QTcpServer>

MainView::MainView(QWidget *parent):QMainWindow(parent), ui(new Ui::MainView),
    tcpServer(new QTcpServer(this)) {

    ui->setupUi(this);
}

MainView::~MainView() {
    delete ui;
}

void MainView::on_buttonStartServer_clicked() {
    StartServer();
    ui->buttonStartServer->setEnabled(false);
    ui->buttonStopServer->setEnabled(true);
}

void MainView::on_buttonStopServer_clicked() {
    StopServer();
    ui->buttonStartServer->setEnabled(true);
    ui->buttonStopServer->setEnabled(false);
}

void MainView::StartServer() {

}

void MainView::StopServer() {

}
