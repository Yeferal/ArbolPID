#include "hoja.h"

Hoja::Hoja()
{

}

Hoja::Hoja(int numeroHoja, pid_t miPid){
    this->numeroHoja = numeroHoja;
    this->miPid = miPid;
}


void Hoja::setPadreInt(int padreInt){
    this->padreInt = padreInt;
}


void Hoja::setMiPidInt(int miPidInt){
    this->miPidInt = miPidInt;
}


void Hoja::setNumeroHoja(int numeroHoja){
    this->numeroHoja = numeroHoja;
}

void Hoja::setPadrePid(pid_t padrePid){
    this->padrePid = padrePid;
}


void Hoja::setMiPid(pid_t miPid){
    this->miPid = miPid;
}


void Hoja::setLabel(QLabel* label){
    this->label = label;
}

int Hoja::getPadreInt(){
    return padreInt;
}


int Hoja::getMiPidInt(){
    return miPidInt;
}


int Hoja::getNumeroHoja(){
    return numeroHoja;
}

pid_t Hoja::getPadrePid(){
    return padrePid;
}


pid_t Hoja::getMiPid(){
    return miPid;
}


QLabel* Hoja::getLabel(){
    return label;
}
