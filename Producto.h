#ifndef Producto_H
#define Producto_H

#include <QObject>
#include <QWidget>
#include <string>
#include <iostream>
#include <cstring>
#include <QString>

using namespace std;


//La clase Producto es una clase que engloba todo lo que tiene que ver con los productos que se encuentran
//en las pilas de una maquina expendedora: su cantidad, nombre, si esta repetido, si se agoto, si se le muestra
//o no al comprador, etc.

class Producto : public QObject
{
    Q_OBJECT

public:

    //-----------------------------------
    //-----Se Declaran las Variables----
    //-----------------------------------

    int cantidad=0;             //cantidad de producto en una pila (0 a 5 para productos no repetidos) o cantidad de producto total (0 a 125 para productos repetidos)
    int producto_agotado;       //esta variable toma un valor de 1 si el producto total esta agotado y 0 si no lo esta
    int producto_repetido=0;    //esta variable toma un valor de 0 si el producto esta en una sola pila y 1 si esta en mas de una pila
    int cantidad_de_pilas = 1;  //esta asociado con la cantidad de pilas que ocupa el producto (por defecto es 1, produto no repetido).
    int mostrar_producto = 1;   //si esta variable tiene un valor de 1, entonces el prducto se le muestra al usuario, si tiene un valor de 0 no

    QString nombre = tr(" ");   //es el nombre dle producto

    Producto *puntero_a_pilas[25]; //cada pila tiene un producto asociado, cuando hay un producto repetido este puntero va a apuntar a las
                                   //cuyo producto sea igual a este.

public slots:

    //-----------------------------------
    //-----Se Declaran los Slots---------
    //-----------------------------------

    //Cada vez que se compra un producto de la maquina expendedora, se llama a esta funcion. Se encarga de disminuir la cantidad
    //del producto en una y de verificar si el producto se agoto, hay dos casos: cuando el producto no esta repetido y cuando
    //el producto esta repetido. En ambos casos se emite una senal llamada senal_producto_agotado, para avisarle al algoritmo que
    //ya no hay mas de este producto y que se tienen que tomar acciones. Ademas, esta funcion es la que se encarga del trasiego
    //de mensajes mediante el uso de un servidor de mosquitto y el protocolo MQTT.
    void comprar();

signals:

    //-----------------------------------
    //-----Se Declaran las Senales-------
    //-----------------------------------

    void senal_producto_agotado();

private:
};


#endif //Producto_H
