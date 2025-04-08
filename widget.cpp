#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QTextStream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //socket_.commected();
    QObject::connect(&socket_, &QAbstractSocket::connected, this, &Widget::doConnected );
    QObject::connect(&socket_, &QAbstractSocket::disconnected, this, &Widget::doDisConnected );
    QObject::connect(&socket_, &QIODevice::readyRead, this, &Widget::doReadyRead );
    QObject::connect(&socket_, &QAbstractSocket::stateChanged, this, &Widget::updateUI);
    loadSettings(); // 프로그램 시작 시 설정 불러오기

}

Widget::~Widget()
{
    saveSettings(); // 프로그램 종료 시 설정 저장
    delete ui;
    //socket_.connected();
}

void Widget::doConnected(){
    QString msg="connected\r\n";
    ui->pteMessage->insertPlainText(msg);
    updateUI(socket_.state());

}

void Widget::doDisConnected(){
    QString msg="disconnected\r\n";
    ui->pteMessage->insertPlainText(msg);
    updateUI(socket_.state());
}

void Widget::doReadyRead(){
    QString msg=socket_.readAll();
    ui->pteMessage->insertPlainText(msg);

}


void Widget::on_pbConnect_clicked()
{
    //socket_.connectToHost(ui->leHost->text(), ui->lePort->text().toUShort());
    //socket_.connectToHostEncrypted(ui->leHost->text(), ui->lePort->text().toUShort());
    if (ui->pbConnectSSL->isChecked()) {
        socket_.connectToHostEncrypted(ui->leHost->text(), ui->lePort->text().toUShort());
    } else {
        socket_.connectToHost(ui->leHost->text(), ui->lePort->text().toUShort());
    }

}


void Widget::on_pbDisconnect_clicked()
{
    socket_.disconnectFromHost();
}


void Widget::on_pbSend_clicked()
{
    socket_.write(ui->pteSend->toPlainText().toUtf8());

}


void Widget::on_pbClear_clicked()
{
    ui->pteMessage->clear();
}




void Widget::on_pbConnectSSL_clicked()
{

    if (ui->pbConnectSSL->isChecked()) {
        ui->lePort->setText("443");
    } else {
        ui->lePort->setText("80");
    }
}
void Widget::updateUI(QAbstractSocket::SocketState state)
{
    bool connected = (state == QAbstractSocket::ConnectedState);
    ui->pbConnect->setEnabled(!connected);
    ui->pbDisconnect->setEnabled(connected);
    ui->pbSend->setEnabled(connected);
}

void Widget::loadSettings() {
    QFile file("settings.txt");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        QString host = in.readLine();
        QString port = in.readLine();
        bool sslChecked = in.readLine().toInt();

        ui->leHost->setText(host);
        ui->lePort->setText(port);
        ui->pbConnectSSL->setChecked(sslChecked);

        file.close();
    }
}

void Widget::saveSettings() {
    QFile file("settings.txt");
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);

        out << ui->leHost->text() << "\n";
        out << ui->lePort->text() << "\n";
        out << (ui->pbConnectSSL->isChecked() ? 1 : 0) << "\n";

        file.close();
    }
}
