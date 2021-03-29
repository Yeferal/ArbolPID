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
    //crearRamas(numRamas,numHojas);
}

Planta::Planta(int numeroPlanta, int numRamas, int numHojas, pid_t pid, Ui::VentanaInicio * ventanaInicio){
    this->numeroPlanta = numeroPlanta;
    this->numRamas = numRamas;
    this->numHojas = numHojas;
    this->pid = pid;
    this->ventanaInicio = ventanaInicio;
    crearRamas(numRamas,numHojas);
}
void Planta::setUI(Ui::VentanaInicio * ventanaInicio){
    this->ventanaInicio = ventanaInicio;
}


void Planta::crearRamas(int ramas, int hojas){
    int longRamas = listaRamas.size();
    //ventanaInicio->labelRama2->setVisible(true);
    if(ramas<6){
        if(longRamas<ramas){
            //int diferencia = ramas - longRamas;
            int padre = 1;
            cout<<"Total de Ramas"<<ramas<<endl;
            //ventanaInicio->labelRama5->setVisible(true);
            //Ui_VentanaInicio* uiV = ventanaInicio;
            if(pid==0){
            //uiV->labelRama6->setVisible(true);
                for (int i = longRamas; i<ramas ; i++) {
                    //uiV->labelRama2->setVisible(true);
                    if (padre==1) {
                        pid_t ramaNueva;
                        //ventanaInicio->labelRama2->setVisible(true);
                        if ((ramaNueva = fork())==0) {
                            Rama* nuevaRama = new Rama(ramas,hojas,ramaNueva);
                            //ventanaInicio->labelRama1->setVisible(true);
                            nuevaRama->setUI(ventanaInicio);
                            //nuevaRama->setLabel(buscarLabel(i+1));
                            //nuevaRama->pintar();
                            listaRamas.push_back(*nuevaRama);
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

void Planta::pintar(){
    label->setStyleSheet("QLabel { background-color : red;}");
    label->setVisible(true);
    //ventanaInicio->labelRama1->setVisible(true);
    qApp->processEvents();
//    qApp->processEvents();


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

QLabel* Planta::buscarLabel(int id){
    switch (id) {
        case 1:
            //ventanaInicio->labelRama1->setVisible(true);
            return ventanaInicio->labelRama1;
        case 2:
            return ventanaInicio->labelRama2;
        case 3:
            return ventanaInicio->labelRama3;
        case 4:
            return ventanaInicio->labelRama4;
        case 5:
            return ventanaInicio->labelRama5;
        case 6:
            return ventanaInicio->labelRama6;
        case 7:
            return ventanaInicio->labelRama7;
        case 8:
            return ventanaInicio->labelRama8;
        case 9:
            return ventanaInicio->labelRama9;
        case 10:
            return ventanaInicio->labelRama10;
        default:
        //ventanaInicio->labelRama1->setVisible(true);
            return ventanaInicio->labelRama1;
    }
}



