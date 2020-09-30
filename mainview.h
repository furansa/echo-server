#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainView; }
QT_END_NAMESPACE

class QTcpServer;

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
    bool StartServer();
    void StopServer();
};
#endif // MAINVIEW_H
