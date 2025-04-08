#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QTextStream>
#include <QSettings>

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
    QObject::connect(ui->pbSave, &QPushButton::clicked, this, &Widget::on_pbSave_clicked);
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
    QSettings settings("SocketApp", "Settings");

    // 창 위치 불러오기
    if (settings.contains("geometry")) {
        setGeometry(settings.value("geometry").toRect());
    }

    // 텍스트 필드 내용 불러오기
    ui->leHost->setText(settings.value("host", "naver.com").toString());
    ui->lePort->setText(settings.value("port", "80").toString());
    ui->pbConnectSSL->setChecked(settings.value("ssl", false).toBool());
    ui->pteSend->setPlainText(settings.value("sendContent", "GET / HTTP/1.1\nHost: naver.com\n").toString());
    ui->pteMessage->setPlainText(settings.value("messageContent", "").toString());

    // SSL이 체크되어 있으면 포트를 443으로 설정
    if (ui->pbConnectSSL->isChecked()) {
        ui->lePort->setText("443");
    }
}

void Widget::saveSettings() {
    QSettings settings("SocketApp", "Settings");

    // 창 위치 저장
    settings.setValue("geometry", geometry());

    // 텍스트 필드 내용 저장
    settings.setValue("host", ui->leHost->text());
    settings.setValue("port", ui->lePort->text());
    settings.setValue("ssl", ui->pbConnectSSL->isChecked());
    settings.setValue("sendContent", ui->pteSend->toPlainText());
    settings.setValue("messageContent", ui->pteMessage->toPlainText());

    settings.sync(); // 설정을 즉시 디스크에 기록
}

void Widget::on_pbSave_clicked()
{
    saveSettings();
    ui->pteMessage->appendPlainText("Settings saved.\n");
}

