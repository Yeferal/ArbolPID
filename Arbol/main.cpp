#include "ventanainicio.h"

#include <QApplication>
#include <QStyle>
#include <QDesktopWidget>

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VentanaInicio w;

    w.show();

    cout<<"Padre: "<<getpid()<<endl;
/*
    for (int i = 1; i<11 ;i++ ) {
        for (int j = 1;j<11 ;j++ ) {
            cout<<"ui->label_R"<<i<<"_h"<<j<<"->setVisible(false);"<<endl;
        }
    }*/
    /*
    int nHOjas = 10;
    int nRamas = 10;
    cout<<"\tswitch (rama) {"<<endl;
    for (int i = 1; i< nHOjas+1 ;i++ ) {
        cout<<"\t\tcase "<<i<<":"<<endl;
        cout<<"\t\t\t\tswitch (hoja) {"<<endl;
        for (int j = 1; j<nRamas+1 ;j++ ) {
            cout<<"\t\t\t\tcase "<<j<<":"<<endl;
            cout<<"\t\t\t\t\treturn ventanaInicio->label_R"<<i<<"_h"<<j<<";"<<endl;
        }
        cout<<"\t\t\t\t}"<<endl;
        cout<<"\t\t\t\tbreak;"<<endl;
    }
    cout<<"\t}"<<endl;
    */

    return a.exec();
}
