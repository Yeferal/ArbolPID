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

    return a.exec();
}
