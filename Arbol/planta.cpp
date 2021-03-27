#include "planta.h"

Planta::Planta(){

}

Planta::Planta(int numeroPlanta, int numRamas, int numHojas){
    this->numeroPlanta = numeroPlanta;
    this->numRamas = numRamas;
    this->numHojas = numHojas;
    //crearRamas(numRamas,numHojas);
}

Planta::Planta(int numeroPlanta, int numRamas, int numHojas, pid_t pid){
    this->numeroPlanta = numeroPlanta;
    this->numRamas = numRamas;
    this->numHojas = numHojas;
    this->pid = pid;
    crearRamas(numRamas,numHojas);
}


void Planta::crearRamas(int ramas, int hojas){
    int longRamas = listaRamas.size();
    if(ramas<10){
        if(longRamas<ramas){
            //int diferencia = ramas - longRamas;
            int padre = 1;
            cout<<"Total de Ramas"<<ramas<<endl;
            for (int i = longRamas; i<ramas ; i++) {
                if (padre==1) {
                    pid_t ramaNueva;
                    if ((ramaNueva = fork())==0) {
                        Rama* nuevaRama = new Rama(ramas,hojas,ramaNueva);
                        listaRamas.push_back(*nuevaRama);
                        padre = 0;
                    }else{
                        padre = 1;
                    }
                }
            }
        }else{

        }
    }
}


void Planta::setLabel(QLabel* label){
    this->label = label;
}

void  Planta::setNumeroPlanta(int numeroPlanta){
    this->numeroPlanta = numeroPlanta;
}

void  Planta::setNumeroRamas(int numRamas){
    this->numRamas = numRamas;
}

void  Planta::setNumeroHojas(int numHojas){
    this->numHojas = numHojas;
}

void  Planta::setPid(pid_t pid){
    this->pid = pid;
}

QLabel* Planta::getLabel(){
    return label;
}

int Planta::getNumeroPlanta(){
    return numeroPlanta;
}

int Planta::getNumeroRamas(){
    return numRamas;
}

int Planta::getNumeroHojas(){
    return numHojas;
}

pid_t Planta::getPid(){
    return pid;
}

