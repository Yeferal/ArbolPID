/********************************************************************************
** Form generated from reading UI file 'ventanainicio.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAINICIO_H
#define UI_VENTANAINICIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaInicio
{
public:
    QFrame *panel;
    QTextEdit *textEditComandos;
    QLabel *labelDibujo;
    QTextEdit *textEditInfo;
    QPushButton *buttonLeer;

    void setupUi(QWidget *VentanaInicio)
    {
        if (VentanaInicio->objectName().isEmpty())
            VentanaInicio->setObjectName(QString::fromUtf8("VentanaInicio"));
        VentanaInicio->resize(1109, 680);
        VentanaInicio->setLayoutDirection(Qt::LeftToRight);
        panel = new QFrame(VentanaInicio);
        panel->setObjectName(QString::fromUtf8("panel"));
        panel->setGeometry(QRect(0, 0, 1111, 681));
        panel->setFrameShape(QFrame::StyledPanel);
        panel->setFrameShadow(QFrame::Raised);
        textEditComandos = new QTextEdit(panel);
        textEditComandos->setObjectName(QString::fromUtf8("textEditComandos"));
        textEditComandos->setGeometry(QRect(0, 550, 871, 131));
        labelDibujo = new QLabel(panel);
        labelDibujo->setObjectName(QString::fromUtf8("labelDibujo"));
        labelDibujo->setGeometry(QRect(0, 0, 861, 541));
        labelDibujo->setStyleSheet(QString::fromUtf8(""));
        textEditInfo = new QTextEdit(panel);
        textEditInfo->setObjectName(QString::fromUtf8("textEditInfo"));
        textEditInfo->setEnabled(false);
        textEditInfo->setGeometry(QRect(870, 0, 241, 551));
        buttonLeer = new QPushButton(panel);
        buttonLeer->setObjectName(QString::fromUtf8("buttonLeer"));
        buttonLeer->setGeometry(QRect(880, 600, 88, 34));

        retranslateUi(VentanaInicio);

        QMetaObject::connectSlotsByName(VentanaInicio);
    } // setupUi

    void retranslateUi(QWidget *VentanaInicio)
    {
        VentanaInicio->setWindowTitle(QCoreApplication::translate("VentanaInicio", "VentanaInicio", nullptr));
        labelDibujo->setText(QString());
        buttonLeer->setText(QCoreApplication::translate("VentanaInicio", "Aplicar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VentanaInicio: public Ui_VentanaInicio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAINICIO_H
