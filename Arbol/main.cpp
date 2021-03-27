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

    return a.exec();
}
