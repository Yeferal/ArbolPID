#ifndef VENTANAINICIO_H
#define VENTANAINICIO_H

#include <QWidget>
#include<iostream>
#include <cstdlib>
#include <vector>
#include<string>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class VentanaInicio; }
QT_END_NAMESPACE

class VentanaInicio : public QWidget
{
    Q_OBJECT

public:
    VentanaInicio(QWidget *parent = nullptr);
    ~VentanaInicio();
    string*  split(string *texto);

private slots:
    void on_buttonLeer_clicked();

private:
    Ui::VentanaInicio *ui;
};
#endif // VENTANAINICIO_H
