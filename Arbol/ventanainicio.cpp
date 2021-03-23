#include "ventanainicio.h"
#include "ui_ventanainicio.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

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

vector<string> VentanaInicio::split(string str, char pattern) {

    int posInit = 0;
    int posFound = 0;
    string splitted;
    vector<string> resultados;

    while(posFound >= 0){
        posFound = str.find(pattern, posInit);
        splitted = str.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        resultados.push_back(splitted);
    }

    return resultados;
}

void VentanaInicio::on_buttonLeer_clicked()
{
    string texto = ui->textEditComandos->toPlainText().toStdString();   //obtenemos le texto el textEditComandos
    texto.replace(texto.length()-1,1,"");                               //eleminamos el ultmio parentesis
    texto.replace(0,1,"");                                              //eleminamos el segundo parentesis
    ui->textEditInfo->setText(texto.c_str());                           //mostramos el texto
    vector<string> resultados;

    resultados = split(texto,',');
    int longitud = resultados.size();
    texto = texto + "\nTamanio: "+std::to_string(longitud)+"\n";
    ui->textEditInfo->setText(texto.c_str());
    for (int i =0; i<longitud ;i++ ) {
        ui->textEditInfo->setText(ui->textEditInfo->toPlainText()+resultados[i].c_str()+"\n");                           //mostramos el texto
    }
}



