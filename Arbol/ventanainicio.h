#ifndef VENTANAINICIO_H
#define VENTANAINICIO_H

#include <QWidget>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
//#include <ifstr>
#include <fstream>
#include "rama.h"
#include "creador.h"

#define COMANDOPSTREE "pstree -c | grep Arbol"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class VentanaInicio; }
QT_END_NAMESPACE

class VentanaInicio : public QWidget
{
    Q_OBJECT

public:
    VentanaInicio(QWidget *parent = nullptr);
    ~VentanaInicio();
    vector<string> split(string str, char pattern);
    void ocultarPlanta();
    void mostrarTronco();
    void mostrarRamas(int num);
    void verificarTipo(vector<string>);
    char* readOutput(char comando[]);
    void escribir(char* textAr);

private slots:
    void on_buttonLeer_clicked();
    void on_pushButton_clicked();

private:
    Ui::VentanaInicio *ui;
    Creador creador;
    string text;

};
#endif // VENTANAINICIO_H
