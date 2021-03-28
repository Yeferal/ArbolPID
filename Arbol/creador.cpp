#include "creador.h"


Creador::Creador()
{

}


Creador::Creador(Ui::VentanaInicio* ventanaInicio){

    this->ventanaInicio = ventanaInicio;
}

void Creador::crear(vector<string> datos){
    int tamanio = datos.size();
    if(tamanio == 2){
        //
        //ventanaInicio->mostrarTronco();
    }else if(tamanio == 3){
        //ventanaInicio->mostrarTronco();
       // ventanaInicio->mostrarRamas(5);
    }else if(tamanio == 4){
       // ventanaInicio->mostrarTronco();
        //ventanaInicio->mostrarRamas(5);
    }
}

void Creador::insertarDatos(vector<string> datos){
    int tamanio = datos.size();
    if(tamanio == 2){
        textMsj = ""+ventanaInicio->textEditInfo->toPlainText().toStdString()+"\n";
        textMsj += "-------------------------------------------------\n";
        textMsj += "Crea la planta numero: "+datos.at(1);
        ventanaInicio->textEditInfo->setText(textMsj.c_str());
        //cout<<textMsj<<endl;
        int valued = atoi(datos.at(1).c_str());
        if(!buscarPlanta(valued)){
           crearPlanta(valued,0,0);
        }

    }else if(tamanio == 3){
        //cout<<"Crea la planta numero: "<<datos.at(1)<<", Ramas: "<<datos.at(2)<<endl;
        textMsj = ""+ventanaInicio->textEditInfo->toPlainText().toStdString()+"\n";
        textMsj += "-------------------------------------------------\n";
        textMsj += "Planta numero: "+datos.at(1)+"\n";
        textMsj += "Ramas: "+datos.at(2);
        ventanaInicio->textEditInfo->setText(textMsj.c_str());

        int valued = atoi(datos.at(1).c_str());
        int valued2 = atoi(datos.at(2).c_str());
        if(!buscarPlanta(valued)){
           crearPlanta(valued,valued2,0);
        }
    }else if(tamanio == 4){
        textMsj = ""+ventanaInicio->textEditInfo->toPlainText().toStdString()+"\n";
        textMsj += "-------------------------------------------------\n";
        textMsj += "Planta numero: "+datos.at(1)+"\n";
        textMsj += "Ramas: "+datos.at(2)+"\n";
        textMsj += "Hojas: "+datos.at(3);
        ventanaInicio->textEditInfo->setText(textMsj.c_str());

        int valued = atoi(datos.at(1).c_str());
        int valued2 = atoi(datos.at(2).c_str());
        int valued3 = atoi(datos.at(3).c_str());
        if(!buscarPlanta(valued)){
           crearPlanta(valued,valued2,valued3);
        }


    }
    cout<<textMsj<<endl;
}

void Creador::mostrarPlanta(vector<string> datos){
    int tamanio = datos.size();
    textMsj = ""+ventanaInicio->textEditInfo->toPlainText().toStdString()+"\n";
    textMsj += "-------------------------------------------------\n";
    if(tamanio == 2){
        textMsj += "Mostrar Planta: "+datos.at(1);
        int valued = atoi(datos.at(1).c_str());
        if(buscarPlanta(valued)){

        }else{
            textMsj += "La planta #"+datos.at(1)+"\nno existe";
        }
    }else{

        textMsj += "Para el comando \"M\" solo se permite un parametro";
    }
    ventanaInicio->textEditInfo->setText(textMsj.c_str());
}

bool Creador::buscarPlanta(int numPlanta){
    int longitud = plantas.size();
    for (int i = 0 ; i<longitud ; i++ ) {
        if(plantas.at(i).getNumeroPlanta()==numPlanta){
            index = i;
            return true;
        }
    }
    return false;
}


void Creador::crearPlanta(int numPlanta, int ramas, int hojas){
    cout<<"Planta: "<<numPlanta<<endl;
    if(numPlanta>0 && numPlanta<11){
        pid_t padreTronco = fork();
        Planta* nuevaPlanta = new Planta(numPlanta, ramas, hojas, padreTronco, ventanaInicio);
        //Planta* nuevaPlanta = new Planta(numPlanta, ramas, hojas, padreTronco);
        //nuevaPlanta->setUI(ventanaInicio);
        nuevaPlanta->setLabel(ventanaInicio->labelTronco);
        nuevaPlanta->pintar();
        //nuevaPlanta->crearRamas(ramas,hojas);
        //qApp->processEvents();
        /*int padre = 1;
        for (int i = 0; i<ramas ; i++) {
            if (padre==1) {
                pid_t ramaNueva;
                if ((ramaNueva = fork())==0) {
                    Rama* nuevaRama = new Rama(i+1,hojas,ramaNueva);
                    nuevaPlanta->listaRamas.push_back(*nuevaRama);
                    padre = 0;
                }
            }else{
                padre = 1;
                plantas.push_back(*nuevaPlanta);
            }
        }*/
        plantas.push_back(*nuevaPlanta);

    }else{
        textMsj = ""+ventanaInicio->textEditInfo->toPlainText().toStdString()+"\n";
        textMsj += "Imposible crea Planta";
        ventanaInicio->textEditInfo->setText(textMsj.c_str());
    }

}

void Creador::listarPlantas(){
    int longitud = plantas.size();
    for (int i = 0; i<longitud ; i++ ) {
        cout<<"Planta #"<<plantas.at(i).getNumeroPlanta();
        cout<<",\tPID: "<<plantas.at(i).getPid();
        cout<<" "<<endl;
    }
}

