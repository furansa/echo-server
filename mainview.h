#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainView; }
QT_END_NAMESPACE

class QTcpServer;
class QTcpSocket;

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    MainView(QWidget *parent = nullptr);
    ~MainView();

private slots:
    void on_buttonStartServer_clicked();
    void on_buttonStopServer_clicked();

private:
    Ui::MainView *ui;
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
    void ExchangeData();
    bool StartServer();
    void StopServer();
    void ReadData();
};
#endif // MAINVIEW_H
