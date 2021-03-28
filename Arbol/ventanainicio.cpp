#include "ventanainicio.h"
#include "ui_ventanainicio.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>


#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


VentanaInicio::VentanaInicio(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VentanaInicio)
{
    //this->setLocale(NULL);

    ui->setupUi(this);
    ocultarPlanta();
    ui->labelTronco->setAutoFillBackground(true);
    //ui;
    creador = Creador(ui);

}

VentanaInicio::~VentanaInicio()
{
    delete ui;
}

vector<string> VentanaInicio::split(string str, char pattern) {

    int posInit = 0;
    int posFound = 0;
    string splitted;
    vector<string> resultados;

    while(posFound >= 0){
        posFound = str.find(pattern, posInit);
        splitted = str.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        resultados.push_back(splitted);
    }

    return resultados;
}


void VentanaInicio::ocultarPlanta(){
    ui->labelRama1->setVisible(false);
    ui->labelRama2->setVisible(false);
    ui->labelRama3->setVisible(false);
    ui->labelRama4->setVisible(false);
    ui->labelRama5->setVisible(false);
    ui->labelRama6->setVisible(false);
    ui->labelRama7->setVisible(false);
    ui->labelRama8->setVisible(false);
    ui->labelRama9->setVisible(false);
    ui->labelRama10->setVisible(false);
    ui->labelTronco->setVisible(false);
    ui->label_R1_h1->setVisible(false);
    ui->label_R1_h1->setVisible(false);
    ui->label_R1_h2->setVisible(false);
    ui->label_R1_h3->setVisible(false);
    ui->label_R1_h4->setVisible(false);
    ui->label_R1_h5->setVisible(false);
    ui->label_R1_h6->setVisible(false);
    ui->label_R1_h7->setVisible(false);
    ui->label_R1_h8->setVisible(false);
    ui->label_R1_h9->setVisible(false);
    ui->label_R1_h10->setVisible(false);
    ui->label_R2_h1->setVisible(false);
    ui->label_R2_h2->setVisible(false);
    ui->label_R2_h3->setVisible(false);
    ui->label_R2_h4->setVisible(false);
    ui->label_R2_h5->setVisible(false);
    ui->label_R2_h6->setVisible(false);
    ui->label_R2_h7->setVisible(false);
    ui->label_R2_h8->setVisible(false);
    ui->label_R2_h9->setVisible(false);
    ui->label_R2_h10->setVisible(false);
    ui->label_R3_h1->setVisible(false);
    ui->label_R3_h2->setVisible(false);
    ui->label_R3_h3->setVisible(false);
    ui->label_R3_h4->setVisible(false);
    ui->label_R3_h5->setVisible(false);
    ui->label_R3_h6->setVisible(false);
    ui->label_R3_h7->setVisible(false);
    ui->label_R3_h8->setVisible(false);
    ui->label_R3_h9->setVisible(false);
    ui->label_R3_h10->setVisible(false);
    ui->label_R4_h1->setVisible(false);
    ui->label_R4_h2->setVisible(false);
    ui->label_R4_h3->setVisible(false);
    ui->label_R4_h4->setVisible(false);
    ui->label_R4_h5->setVisible(false);
    ui->label_R4_h6->setVisible(false);
    ui->label_R4_h7->setVisible(false);
    ui->label_R4_h8->setVisible(false);
    ui->label_R4_h9->setVisible(false);
    ui->label_R4_h10->setVisible(false);
    ui->label_R5_h1->setVisible(false);
    ui->label_R5_h2->setVisible(false);
    ui->label_R5_h3->setVisible(false);
    ui->label_R5_h4->setVisible(false);
    ui->label_R5_h5->setVisible(false);
    ui->label_R5_h6->setVisible(false);
    ui->label_R5_h7->setVisible(false);
    ui->label_R5_h8->setVisible(false);
    ui->label_R5_h9->setVisible(false);
    ui->label_R5_h10->setVisible(false);
    ui->label_R6_h1->setVisible(false);
    ui->label_R6_h2->setVisible(false);
    ui->label_R6_h3->setVisible(false);
    ui->label_R6_h4->setVisible(false);
    ui->label_R6_h5->setVisible(false);
    ui->label_R6_h6->setVisible(false);
    ui->label_R6_h7->setVisible(false);
    ui->label_R6_h8->setVisible(false);
    ui->label_R6_h9->setVisible(false);
    ui->label_R6_h10->setVisible(false);
    ui->label_R7_h1->setVisible(false);
    ui->label_R7_h2->setVisible(false);
    ui->label_R7_h3->setVisible(false);
    ui->label_R7_h4->setVisible(false);
    ui->label_R7_h5->setVisible(false);
    ui->label_R7_h6->setVisible(false);
    ui->label_R7_h7->setVisible(false);
    ui->label_R7_h8->setVisible(false);
    ui->label_R7_h9->setVisible(false);
    ui->label_R7_h10->setVisible(false);
    ui->label_R8_h1->setVisible(false);
    ui->label_R8_h2->setVisible(false);
    ui->label_R8_h3->setVisible(false);
    ui->label_R8_h4->setVisible(false);
    ui->label_R8_h5->setVisible(false);
    ui->label_R8_h6->setVisible(false);
    ui->label_R8_h7->setVisible(false);
    ui->label_R8_h8->setVisible(false);
    ui->label_R8_h9->setVisible(false);
    ui->label_R8_h10->setVisible(false);
    ui->label_R9_h1->setVisible(false);
    ui->label_R9_h2->setVisible(false);
    ui->label_R9_h3->setVisible(false);
    ui->label_R9_h4->setVisible(false);
    ui->label_R9_h5->setVisible(false);
    ui->label_R9_h6->setVisible(false);
    ui->label_R9_h7->setVisible(false);
    ui->label_R9_h8->setVisible(false);
    ui->label_R9_h9->setVisible(false);
    ui->label_R9_h10->setVisible(false);
    ui->label_R10_h1->setVisible(false);
    ui->label_R10_h2->setVisible(false);
    ui->label_R10_h3->setVisible(false);
    ui->label_R10_h4->setVisible(false);
    ui->label_R10_h5->setVisible(false);
    ui->label_R10_h6->setVisible(false);
    ui->label_R10_h7->setVisible(false);
    ui->label_R10_h8->setVisible(false);
    ui->label_R10_h9->setVisible(false);
    ui->label_R10_h10->setVisible(false);

}

void VentanaInicio::mostrarTronco(){
    ui->labelTronco->setVisible(true);

}

void VentanaInicio::mostrarRamas(int num){
    for (int i = 1; i<num+1 ;i++ ) {
        switch (i) {
            case 1:
                ui->labelRama1->setVisible(true);
                break;
            case 2:
                ui->labelRama2->setVisible(true);
                break;
            case 3:
                ui->labelRama3->setVisible(true);
                break;
            case 4:
                ui->labelRama4->setVisible(true);
                break;
            case 5:
                ui->labelRama5->setVisible(true);
                break;
            case 6:
                ui->labelRama6->setVisible(true);
                break;
            case 7:
                ui->labelRama7->setVisible(true);
                break;
            case 8:
                ui->labelRama8->setVisible(true);
                break;
            case 9:
                ui->labelRama9->setVisible(true);
                break;
            case 10:
                ui->labelRama10->setVisible(true);
                break;
        }
    }


}

void VentanaInicio::verificarTipo(vector<string> datos){
    if(datos[0]=="P"){
        cout<<"P"<<endl;
    }else if(datos[0]=="M"){
        cout<<"M"<<endl;
    }else{
        cout<<"Error"<<endl;
    }
}



void VentanaInicio::on_buttonLeer_clicked()
{
    string texto = ui->textEditComandos->toPlainText().toStdString();   //obtenemos le texto el textEditComandos
    if(!texto.empty()){
        texto.replace(texto.length()-1,1,"");                               //eleminamos el ultmio parentesis
        texto.replace(0,1,"");                                              //eleminamos el segundo parentesis
        //ui->textEditInfo->setText(texto.c_str());                           //mostramos el texto
        vector<string> resultados;

        resultados = split(texto,',');
        verificarTipo(resultados);
        int longitud = resultados.size();
        if(longitud>1 && longitud<5){
            if(resultados.at(0)=="P"){
                creador.insertarDatos(resultados);
            }else if(resultados.at(0)=="M"){
                creador.mostrarPlanta(resultados);
            }else{
                text = ""+ui->textEditInfo->toPlainText().toStdString()+"\n";
                text += "-------------------------------------------------\n";
                text += "Comando no admitido: "+ui->textEditComandos->toPlainText().toStdString()+"\n";
                ui->textEditInfo->setText(text.c_str());
            }
        }else{
            text = ""+ui->textEditInfo->toPlainText().toStdString()+"\n";
            text += "-------------------------------------------------\n";
            text += "Comando no admitido: "+ui->textEditComandos->toPlainText().toStdString()+"\n";
            ui->textEditInfo->setText(text.c_str());
        }

    }else{
        //Rama rama = new Rama();
        /*int pid1=fork();
        if(pid1==0){
            for (int i = 0; i<3 ;i++ ) {
                if(pid1==0){
                    //fork();
                }
            }
        }else{

        }*/

        QPalette palette = ui->labelTronco->palette();
         palette.setColor(ui->labelTronco->backgroundRole(), Qt::yellow);
mostrarTronco();
//usleep(5 * 1000000);


/*
         for (int i =0; i<10 ;i++ ) {

             ui->labelTronco->setStyleSheet("QLabel { background-color : red;}");
             qApp->processEvents();
             cout<<"Pinta red"<<endl;
             //usleep(1 * 1000000);
             sleep(2);
             cout<<"pausa"<<endl;

             ui->labelTronco->setStyleSheet("QLabel { background-color : blue;}");
             qApp->processEvents();
            cout<<"Pinta blue"<<endl;
            sleep(2);
         }*/

        int i;
        int padre;
        padre = 1;
        pid_t padreR = fork();
        cout<<"Éste es el proceso hijo: "<<getpid();
        cout<<",\tpadre: "<<getppid()<<"\t primer fork: "<<padreR<<endl;
        //fork();
        if(padreR==0){
            for (i=0; i < 3; i++){
                if (padre == 1){
                    if (fork() == 0){ /* Proceso hijo */
                        //fprintf(stdout, "Éste es el proceso hijo con padre %ld\n",(long)getppid());
                        cout<<"Éste es el proceso hijo: "<<getpid();
                        cout<<",\tpadre: "<<getppid()<<"\t  phijo"<<endl;
                        padre = 0;

                    }else{ /* Proceso padre */
                        //fprintf(stdout, "Éste es el proceso padre con ID %ld\n",(long)getpid());
                        padre = 1;
                        cout<<"Éste es el proceso hijo: "<<getpid();
                        cout<<",\tpadre: "<<getppid()<<"\t  ppadre"<<endl;
                        //break;
                    }
                    /*if(getppid()==padreR){
                        i=4;
                        cout<<"PADRE"<<endl;
                    }*/
                }
            }
        }
        qApp->processEvents();

    }
}


void VentanaInicio::on_pushButton_clicked(){
    creador.listarPlantas();
}



