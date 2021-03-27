#ifndef HOJA_H
#define HOJA_H

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

using namespace std;

class Hoja
{
public:
    Hoja();
    Hoja(int numeroHoja, pid_t miPid);
    void setPadreInt(int);
    void setMiPidInt(int);
    void setNumeroHoja(int);
    void setPadrePid(pid_t);
    void setMiPid(pid_t);
    void setLabel(QLabel*);
    int getPadreInt();
    int getMiPidInt();
    int getNumeroHoja();
    pid_t getPadrePid();
    pid_t getMiPid();
    QLabel* getLabel();

    //vector<Hoja> listaHojas;

private:
    int padreInt;
    int miPidInt;
    int numeroHoja;
    pid_t padrePid;
    pid_t miPid;
    QLabel* label;
};

#endif // HOJA_H
