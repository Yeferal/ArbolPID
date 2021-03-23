#include "ventanainicio.h"
#include "ui_ventanainicio.h"

VentanaInicio::VentanaInicio(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VentanaInicio)
{
    //this->setLocale(NULL);
    ui->setupUi(this);
}

VentanaInicio::~VentanaInicio()
{
    delete ui;
}


void VentanaInicio::on_buttonLeer_clicked()
{
    //printf("Hola mundo");
    ui->textEditInfo->setText(ui->textEditInfo->toPlainText()+ui->textEditComandos->toPlainText()+"\n");
}
