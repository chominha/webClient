#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QSslSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //QTcpSocket socket_;
    QSslSocket socket_;



public slots:
    void doConnected();
    void doDisConnected();
    void doReadyRead();


//git

private slots:
    void on_pbConnect_clicked();

    void on_pbDisconnect_clicked();

    void on_pbSend_clicked();

    void on_pbClear_clicked();

    void on_pbConnectSSL_clicked();

    void on_pbSave_clicked();

    void updateUI(QAbstractSocket::SocketState state);


private:
    void loadSettings();
    void saveSettings();

    Ui::Widget *ui;
};
#endif // WIDGET_H
