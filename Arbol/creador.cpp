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
//            for (int i =0;i<plantas.at(index).listaRamas.size() ;i++ ) {

//            }
            cout<<"planta #"<<plantas.at(index).getNumeroPlanta()<<endl;
            cout<<"ramas: "<<plantas.at(index).getNumeroRamas()<<endl;
            cout<<"hojas: "<<plantas.at(index).getNumeroHojas()<<endl;
            pintarPlanta();
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
        Planta* nuevaPlanta;
        pid_t padreTronco = fork();
        nuevaPlanta = new Planta(numPlanta, ramas, hojas, padreTronco, ventanaInicio);
        //Planta* nuevaPlanta = new Planta(numPlanta, ramas, hojas, padreTronco);
        //nuevaPlanta->setUI(ventanaInicio);
        nuevaPlanta->setLabel(ventanaInicio->labelTronco);
        //nuevaPlanta->pintar();
        //nuevaPlanta->crearRamas(ramas,hojas);
//        if(ramas<11){
//            int longRamas = nuevaPlanta->listaRamas.size();
//            if(longRamas<ramas){
//                int padre = 1;
//                if(nuevaPlanta->getPid()==0){
//                    for (int i = longRamas; i<ramas ; i++) {
//                        if (padre==1) {
//                            pid_t ramaNueva;
//                            if ((ramaNueva = fork())==0) {
//                                padre = 0;
//                            }else{
//                                padre = 1;
//                            }
//                        }
//                    }
//                }
//            }
//        }
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

void Creador::pintarPlanta(){
    ventanaInicio->labelTronco->setStyleSheet("QLabel { background-color : grey;}");
    ventanaInicio->labelTronco->setVisible(true);
    qApp->processEvents();
    sleep(1);
    mostrarRamas(plantas.at(index).getNumeroRamas());
    pintarHojas();

}

void Creador::mostrarRamas(int num){
    for (int i = 1; i<num+1 ;i++ ) {
        switch (i) {
            case 1:
                ventanaInicio->labelRama1->setVisible(true);
                ventanaInicio->labelRama1->setStyleSheet("QLabel { background-color : red;}");
                //qApp->processEvents();
                break;
            case 2:
                ventanaInicio->labelRama2->setVisible(true);
                ventanaInicio->labelRama2->setStyleSheet("QLabel { background-color : red;}");
                //qApp->processEvents();
                break;
            case 3:
                ventanaInicio->labelRama3->setVisible(true);
                ventanaInicio->labelRama3->setStyleSheet("QLabel { background-color : red;}");
                break;
            case 4:
                ventanaInicio->labelRama4->setVisible(true);
                ventanaInicio->labelRama4->setStyleSheet("QLabel { background-color : red;}");
                break;
            case 5:
                ventanaInicio->labelRama5->setVisible(true);
                ventanaInicio->labelRama5->setStyleSheet("QLabel { background-color : red;}");
                break;
            case 6:
                ventanaInicio->labelRama6->setVisible(true);
                ventanaInicio->labelRama6->setStyleSheet("QLabel { background-color : red;}");
                break;
            case 7:
                ventanaInicio->labelRama7->setVisible(true);
                ventanaInicio->labelRama7->setStyleSheet("QLabel { background-color : red;}");
                break;
            case 8:
                ventanaInicio->labelRama8->setVisible(true);
                ventanaInicio->labelRama8->setStyleSheet("QLabel { background-color : red;}");
                break;
            case 9:
                ventanaInicio->labelRama9->setVisible(true);
                ventanaInicio->labelRama9->setStyleSheet("QLabel { background-color : red;}");
                break;
            case 10:
                ventanaInicio->labelRama10->setVisible(true);
                ventanaInicio->labelRama10->setStyleSheet("QLabel { background-color : red;}");
                break;
        }
        qApp->processEvents();
        sleep(1);
    }

}

void Creador::pintarHojas(){
    int nHOjas = plantas.at(index).getNumeroHojas();
    int nRamas = plantas.at(index).getNumeroRamas();
    for (int i = 1; i< nHOjas+1 ;i++ ) {
        sleep(1);
        for (int j = 1; j<nRamas+1 ;j++ ) {
            QLabel* labelAux = getHoja(i,j);
            labelAux->setStyleSheet("QLabel { background-color : green;}");
            labelAux->setVisible(true);
            qApp->processEvents();
            sleep(1);
        }

    }
}

QLabel* Creador::getHoja(int hoja, int rama){
    switch (rama) {
            case 1:
                    switch (hoja) {
                    case 1:
                        return ventanaInicio->label_R1_h1;
                    case 2:
                        return ventanaInicio->label_R1_h2;
                    case 3:
                        return ventanaInicio->label_R1_h3;
                    case 4:
                        return ventanaInicio->label_R1_h4;
                    case 5:
                        return ventanaInicio->label_R1_h5;
                    case 6:
                        return ventanaInicio->label_R1_h6;
                    case 7:
                        return ventanaInicio->label_R1_h7;
                    case 8:
                        return ventanaInicio->label_R1_h8;
                    case 9:
                        return ventanaInicio->label_R1_h9;
                    case 10:
                        return ventanaInicio->label_R1_h10;
                    }
                    break;
            case 2:
                    switch (hoja) {
                    case 1:
                        return ventanaInicio->label_R2_h1;
                    case 2:
                        return ventanaInicio->label_R2_h2;
                    case 3:
                        return ventanaInicio->label_R2_h3;
                    case 4:
                        return ventanaInicio->label_R2_h4;
                    case 5:
                        return ventanaInicio->label_R2_h5;
                    case 6:
                        return ventanaInicio->label_R2_h6;
                    case 7:
                        return ventanaInicio->label_R2_h7;
                    case 8:
                        return ventanaInicio->label_R2_h8;
                    case 9:
                        return ventanaInicio->label_R2_h9;
                    case 10:
                        return ventanaInicio->label_R2_h10;
                    }
                    break;
            case 3:
                    switch (hoja) {
                    case 1:
                        return ventanaInicio->label_R3_h1;
                    case 2:
                        return ventanaInicio->label_R3_h2;
                    case 3:
                        return ventanaInicio->label_R3_h3;
                    case 4:
                        return ventanaInicio->label_R3_h4;
                    case 5:
                        return ventanaInicio->label_R3_h5;
                    case 6:
                        return ventanaInicio->label_R3_h6;
                    case 7:
                        return ventanaInicio->label_R3_h7;
                    case 8:
                        return ventanaInicio->label_R3_h8;
                    case 9:
                        return ventanaInicio->label_R3_h9;
                    case 10:
                        return ventanaInicio->label_R3_h10;
                    }
                    break;
            case 4:
                    switch (hoja) {
                    case 1:
                        return ventanaInicio->label_R4_h1;
                    case 2:
                        return ventanaInicio->label_R4_h2;
                    case 3:
                        return ventanaInicio->label_R4_h3;
                    case 4:
                        return ventanaInicio->label_R4_h4;
                    case 5:
                        return ventanaInicio->label_R4_h5;
                    case 6:
                        return ventanaInicio->label_R4_h6;
                    case 7:
                        return ventanaInicio->label_R4_h7;
                    case 8:
                        return ventanaInicio->label_R4_h8;
                    case 9:
                        return ventanaInicio->label_R4_h9;
                    case 10:
                        return ventanaInicio->label_R4_h10;
                    }
                    break;
            case 5:
                    switch (hoja) {
                    case 1:
                        return ventanaInicio->label_R5_h1;
                    case 2:
                        return ventanaInicio->label_R5_h2;
                    case 3:
                        return ventanaInicio->label_R5_h3;
                    case 4:
                        return ventanaInicio->label_R5_h4;
                    case 5:
                        return ventanaInicio->label_R5_h5;
                    case 6:
                        return ventanaInicio->label_R5_h6;
                    case 7:
                        return ventanaInicio->label_R5_h7;
                    case 8:
                        return ventanaInicio->label_R5_h8;
                    case 9:
                        return ventanaInicio->label_R5_h9;
                    case 10:
                        return ventanaInicio->label_R5_h10;
                    }
                    break;
            case 6:
                    switch (hoja) {
                    case 1:
                        return ventanaInicio->label_R6_h1;
                    case 2:
                        return ventanaInicio->label_R6_h2;
                    case 3:
                        return ventanaInicio->label_R6_h3;
                    case 4:
                        return ventanaInicio->label_R6_h4;
                    case 5:
                        return ventanaInicio->label_R6_h5;
                    case 6:
                        return ventanaInicio->label_R6_h6;
                    case 7:
                        return ventanaInicio->label_R6_h7;
                    case 8:
                        return ventanaInicio->label_R6_h8;
                    case 9:
                        return ventanaInicio->label_R6_h9;
                    case 10:
                        return ventanaInicio->label_R6_h10;
                    }
                    break;
            case 7:
                    switch (hoja) {
                    case 1:
                        return ventanaInicio->label_R7_h1;
                    case 2:
                        return ventanaInicio->label_R7_h2;
                    case 3:
                        return ventanaInicio->label_R7_h3;
                    case 4:
                        return ventanaInicio->label_R7_h4;
                    case 5:
                        return ventanaInicio->label_R7_h5;
                    case 6:
                        return ventanaInicio->label_R7_h6;
                    case 7:
                        return ventanaInicio->label_R7_h7;
                    case 8:
                        return ventanaInicio->label_R7_h8;
                    case 9:
                        return ventanaInicio->label_R7_h9;
                    case 10:
                        return ventanaInicio->label_R7_h10;
                    }
                    break;
            case 8:
                    switch (hoja) {
                    case 1:
                        return ventanaInicio->label_R8_h1;
                    case 2:
                        return ventanaInicio->label_R8_h2;
                    case 3:
                        return ventanaInicio->label_R8_h3;
                    case 4:
                        return ventanaInicio->label_R8_h4;
                    case 5:
                        return ventanaInicio->label_R8_h5;
                    case 6:
                        return ventanaInicio->label_R8_h6;
                    case 7:
                        return ventanaInicio->label_R8_h7;
                    case 8:
                        return ventanaInicio->label_R8_h8;
                    case 9:
                        return ventanaInicio->label_R8_h9;
                    case 10:
                        return ventanaInicio->label_R8_h10;
                    }
                    break;
            case 9:
                    switch (hoja) {
                    case 1:
                        return ventanaInicio->label_R9_h1;
                    case 2:
                        return ventanaInicio->label_R9_h2;
                    case 3:
                        return ventanaInicio->label_R9_h3;
                    case 4:
                        return ventanaInicio->label_R9_h4;
                    case 5:
                        return ventanaInicio->label_R9_h5;
                    case 6:
                        return ventanaInicio->label_R9_h6;
                    case 7:
                        return ventanaInicio->label_R9_h7;
                    case 8:
                        return ventanaInicio->label_R9_h8;
                    case 9:
                        return ventanaInicio->label_R9_h9;
                    case 10:
                        return ventanaInicio->label_R9_h10;
                    }
                    break;
            case 10:
                    switch (hoja) {
                    case 1:
                        return ventanaInicio->label_R10_h1;
                    case 2:
                        return ventanaInicio->label_R10_h2;
                    case 3:
                        return ventanaInicio->label_R10_h3;
                    case 4:
                        return ventanaInicio->label_R10_h4;
                    case 5:
                        return ventanaInicio->label_R10_h5;
                    case 6:
                        return ventanaInicio->label_R10_h6;
                    case 7:
                        return ventanaInicio->label_R10_h7;
                    case 8:
                        return ventanaInicio->label_R10_h8;
                    case 9:
                        return ventanaInicio->label_R10_h9;
                    case 10:
                        return ventanaInicio->label_R10_h10;
                    }
                    break;
        }
    return NULL;
}


