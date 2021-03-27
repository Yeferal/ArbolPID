#ifndef CREADOR_H
#define CREADOR_H

#include <QWidget>
#include <QLabel>

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <stdbool.h>
//#include "ventanainicio.h"
#include "ui_ventanainicio.h"
#include "planta.h"
//#include <ventanainicio.cpp>
using namespace std;


class Creador
{
public:
    //VentanaInicio* ventanaInicio;
    Creador();
    Creador(Ui::VentanaInicio*);
    //Creador(VentanaInicio ventanaInicil);
    void crear(vector<string>);
    void visualizar(vector<string>);
    void insertarDatos(vector<string>);
    void mostrarPlanta(vector<string>);
    bool buscarPlanta(int numPlanta);
    void crearPlanta(int numPlanta, int ramas, int hojas);
    void listarPlantas();

    string textMsj;
    vector<Planta> plantas;

private:
    Ui::VentanaInicio* ventanaInicio;
    int index;
};

#endif // CREADOR_H
