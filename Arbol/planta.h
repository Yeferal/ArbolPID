#ifndef PLANTA_H
#define PLANTA_H

#include <QObject>
#include <QWidget>
#include <QLabel>

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#include "rama.h"
#include "ui_ventanainicio.h"
using namespace std;

class Planta
{
public:
    Planta();
    Planta(int, int, int);
    Planta(int, int, int, pid_t);
    Planta(int, int, int, pid_t, Ui::VentanaInicio*);
    void setUI(Ui::VentanaInicio*);
    void setLabel(QLabel*);
    void setNumeroPlanta(int);
    void setNumeroRamas(int);
    void setNumeroHojas(int);
    void setPid(pid_t);
    void pintar();
    QLabel* buscarLabel(int id);
    QLabel* getLabel();
    int getNumeroPlanta();
    int getNumeroRamas();
    int getNumeroHojas();
    void crearRamas(int ramas, int hojas);
    pid_t getPid();
    vector<Rama> listaRamas;
    Ui::VentanaInicio* ventanaInicio;

private:
    int plantaPID;
    int numeroPlanta;
    int numRamas;
    int numHojas;
    pid_t pid;
    QLabel* label;

};

#endif // PLANTA_H
