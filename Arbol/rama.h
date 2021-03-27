#ifndef RAMA_H
#define RAMA_H

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

#include "hoja.h"
using namespace std;

class Rama
{
public:
    Rama();
    Rama(int numeroRama, int numHojas, pid_t padrePid, pid_t miPid);
    Rama(int numeroRama, int numHojas, pid_t miPid);
    void setPadreInt(int);
    void setMiPidInt(int);
    void setNumHojas(int);
    void setNumeroRama(int);
    void setPadrePid(pid_t);
    void setMiPid(pid_t);
    void setLabel(QLabel*);
    void crearHojas(int hojas);
    int getPadreInt();
    int getMiPidInt();
    int getNumHojas();
    int getNumeroRama();
    pid_t getPadrePid();
    pid_t getMiPid();
    QLabel* getLabel();

    vector<Hoja> listaHojas;

private:
    int padreInt;
    int miPidInt;
    int numHojas;
    int numeroRama;
    pid_t padrePid;
    pid_t miPid;
    QLabel* label;

};

#endif // RAMA_H
