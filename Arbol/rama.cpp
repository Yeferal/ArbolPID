#include "rama.h"

Rama::Rama()
{

}

Rama::Rama(int numeroRama, int numHojas, pid_t miPid){
    this->numeroRama = numeroRama;
    this->numHojas = numHojas;
    this->miPid = miPid;
    crearHojas(numHojas);
}

void Rama::setUI(Ui::VentanaInicio * ventanaInicio){
    this->ventanaInicio = ventanaInicio;
}

void Rama::crearHojas(int hojas){
    int longHojas = listaHojas.size();
    if(hojas<11){
        if(longHojas<hojas){
            //int diferencia = ramas - longRamas;
            int padre = 1;
            cout<<"Total de  hojas: "<<hojas<<endl;
            if(miPid==0){
                for (int i = longHojas; i<hojas; i++) {
                    if (padre==1) {
                        pid_t hojaNueva;
                        if ((hojaNueva = fork())==0) {
                            Hoja* nuevaHoja = new Hoja(i+1,hojaNueva);
                            listaHojas.push_back(*nuevaHoja);
                            padre = 0;
                        }else{
                            padre = 1;
                        }
                    }
                }
            }
        }else{

        }
    }
}

void Rama::pintar(){
    label->setStyleSheet("QLabel { background-color : blue;}");
    label->setVisible(true);
    qApp->processEvents();
}

void Rama::setPadreInt(int padreInt){
    this->padreInt = padreInt;
}


void Rama::setMiPidInt(int miPidInt){
    this->miPidInt = miPidInt;
}


void Rama::setNumHojas(int numHojas){
    this->numHojas = numHojas;
}


void Rama::setNumeroRama(int numeroRama){
    this->numeroRama = numeroRama;
}


void Rama::setPadrePid(pid_t padrePid){
    this->padrePid = padrePid;
}


void Rama::setMiPid(pid_t miPid){
    this->miPid = miPid;
}


void Rama::setLabel(QLabel* label){
    this->label = label;
}

int Rama::getPadreInt(){
    return padreInt;
}


int Rama::getMiPidInt(){
    return miPidInt;
}


int Rama::getNumHojas(){
    return numHojas;
}


int Rama::getNumeroRama(){
    return numeroRama;
}


pid_t Rama::getPadrePid(){
    return padrePid;
}


pid_t Rama::getMiPid(){
    return miPid;
}


QLabel* Rama::getLabel(){
    return label;
}
