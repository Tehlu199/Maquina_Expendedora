#include "Producto.h"
#include <iostream>
#include <string>
#include <cstring>
#include <QString>
#include <QDebug>
#include <QProcess>

using namespace std;


void Producto::comprar(){

    cantidad = cantidad - 1;

    if(cantidad_de_pilas == 1){

    QString mosquitto = "mosquitto_pub -h 64.227.111.82 -p 1884 -t general/maquina_expendedora_sebas_santi -m \"Se vendio una unidad del producto llamado: ";
    QString mensaje = nombre;
    QString enviar_mensaje = mosquitto + mensaje + tr("\"");
    QProcess sh;
    sh.start("sh", QStringList() << "-c" << enviar_mensaje);
    sh.waitForFinished();
    QByteArray output = sh.readAll();
    sh.close();
    }


    //Se verifica si un producto no repetido se agoto (la pila con ese producto se vacio)
    if(cantidad==0 && producto_repetido == 0 && cantidad_de_pilas == 1){

        emit senal_producto_agotado();

        QString mosquitto = "mosquitto_pub -h 64.227.111.82 -p 1884 -t general/maquina_expendedora_sebas_santi -m \"Se agoto el producto llamado: ";
        QString mensaje = nombre;
        QString enviar_mensaje = mosquitto + mensaje + tr("\"");
        QProcess sh;
        sh.start("sh", QStringList() << "-c" << enviar_mensaje);
        sh.waitForFinished();
        QByteArray output = sh.readAll();
        sh.close();

    }

    //Se verifica si un producto repetido se agoto (todas las pilas que tenian ese producto estan vacias)
    if(cantidad==0 && cantidad_de_pilas > 1){

        producto_agotado=0;
        emit senal_producto_agotado();

        QString mosquitto = "mosquitto_pub -h 64.227.111.82 -p 1884 -t general/maquina_expendedora_sebas_santi -m \"Se agoto el producto llamado: ";
        QString mensaje = nombre;
        QString enviar_mensaje = mosquitto + mensaje + tr("\"");
        QProcess sh;
        sh.start("sh", QStringList() << "-c" << enviar_mensaje);
        sh.waitForFinished();
        QByteArray output = sh.readAll();
        sh.close();
    }
}



