/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbConnect;
    QPushButton *pbDisconnect;
    QPushButton *pbClear;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *leHost;
    QLineEdit *lePort;
    QPlainTextEdit *pteMessage;
    QHBoxLayout *horizontalLayout_3;
    QPlainTextEdit *pteSend;
    QCheckBox *pbConnectSSL;
    QPushButton *pbSend;
    QPushButton *pbSave;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(622, 522);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(90, 12, 444, 462));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pbConnect = new QPushButton(layoutWidget);
        pbConnect->setObjectName("pbConnect");

        horizontalLayout->addWidget(pbConnect);

        pbDisconnect = new QPushButton(layoutWidget);
        pbDisconnect->setObjectName("pbDisconnect");

        horizontalLayout->addWidget(pbDisconnect);

        pbClear = new QPushButton(layoutWidget);
        pbClear->setObjectName("pbClear");

        horizontalLayout->addWidget(pbClear);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        leHost = new QLineEdit(layoutWidget);
        leHost->setObjectName("leHost");

        horizontalLayout_2->addWidget(leHost);

        lePort = new QLineEdit(layoutWidget);
        lePort->setObjectName("lePort");

        horizontalLayout_2->addWidget(lePort);


        verticalLayout->addLayout(horizontalLayout_2);

        pteMessage = new QPlainTextEdit(layoutWidget);
        pteMessage->setObjectName("pteMessage");

        verticalLayout->addWidget(pteMessage);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pteSend = new QPlainTextEdit(layoutWidget);
        pteSend->setObjectName("pteSend");

        horizontalLayout_3->addWidget(pteSend);

        pbConnectSSL = new QCheckBox(layoutWidget);
        pbConnectSSL->setObjectName("pbConnectSSL");

        horizontalLayout_3->addWidget(pbConnectSSL);

        pbSend = new QPushButton(layoutWidget);
        pbSend->setObjectName("pbSend");

        horizontalLayout_3->addWidget(pbSend);


        verticalLayout->addLayout(horizontalLayout_3);

        pbSave = new QPushButton(Widget);
        pbSave->setObjectName("pbSave");
        pbSave->setGeometry(QRect(440, 480, 87, 26));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pbConnect->setText(QCoreApplication::translate("Widget", "Connect", nullptr));
        pbDisconnect->setText(QCoreApplication::translate("Widget", "Disconnect", nullptr));
        pbClear->setText(QCoreApplication::translate("Widget", "Clear", nullptr));
        leHost->setText(QCoreApplication::translate("Widget", "naver.com", nullptr));
        lePort->setText(QCoreApplication::translate("Widget", "0", nullptr));
        pteSend->setPlainText(QCoreApplication::translate("Widget", "GET / HTTP/1.1\n"
"Host: naver.com\n"
"\n"
"", nullptr));
        pbConnectSSL->setText(QCoreApplication::translate("Widget", "SSL", nullptr));
        pbSend->setText(QCoreApplication::translate("Widget", "Send", nullptr));
        pbSave->setText(QCoreApplication::translate("Widget", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
