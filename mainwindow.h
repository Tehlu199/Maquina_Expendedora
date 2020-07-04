#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <iostream>
#include <QObject>
#include <QtCore>
#include <QLabel>
#include <string>
#include <QGridLayout>
#include <QTimer>
#include <QFont>
#include <QLocale>
#include <QSignalMapper>
#include <QString>
#include <QtGui>
#include <QCoreApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QInputDialog>
#include <QIcon>
#include <QPixmap>

#include"Producto.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);


    //--------------------------------------
    //--------Variables y Objetos-----------
    //--------------------------------------


    //--------------Producto-------------

    //Estas variables son de la clase Producto.

    Producto *lista_de_productos[5][5];          //Es una matriz de Productos, que representa la matriz fisica 5x5 de pilas de la maquina expendedora.
    Producto *lista_de_productos_repetidos[25];  //Es un vector de Productos, que representa una lista de productos repetidos solamente, es decir, contiene
                                                 //solamente aquellos productos de la matriz anterior que se repitan (su nombre seria el mismo pero la cantidad es el total).

    //--------------Rebastecer------------

    //Estos objetos y variables estan relaciones con la interfaz de rebastecimientos de productos, es decir,son necesarios para llevar a
    //cabo la logica y la interfaz grafica de el rebastecimiento de la maquina expendedora.

    QWidget *d_refill;                                    //Widget que representa la ventana en la cual se muestra la interfaz para rebastecer los productos.
    QWidget *d_refill_nombre;                             //Widget que representa la ventana en la cual se introduce el nombre del producto que se esta rebasteciendo.
    QWidget *d_refill_cantidad;                           //Widget que representa la ventana en la cual se introduce la cantidad del producto que se esta rebasteciendo.
    QWidget *d_refill_contrasena;                         //Widget que representa la ventana en la cual se tiene que introducir la contrasena para acceder a la interfaz de rebastecimiento
    QWidget *d_refill_contrasena_incorrecta;              //Widget que representa la ventana en la cual se muestra el mensaje de: contrasena incorrecta, vuelva a intentarlo.

    //Capas principales de los respectivos widgets, la capa principal es donde se "insertan" otras capas secundarias que contienen botones, editores de texto, mensajes, titulos, etc
    //Entonces en realidad, son estas capas las que se muestran en las respecticas ventanas anteriores, es decir, un widget sin layout no muestra nada.
    QVBoxLayout *d_refill_main_layout;
    QVBoxLayout *d_refill_nombre_main_layout;
    QVBoxLayout *d_refill_cantidad_main_layout;
    QVBoxLayout *d_refill_contrasena_main_layout;
    QVBoxLayout *d_refill_contrasena_incorrecta_layout;

    //Capas de los titulos de los respectivos widgets, en estas capas se "insertan" los titulos de las ventanas.
    QHBoxLayout *d_refill_title_layout;
    QHBoxLayout *d_refill_nombre_title_layout;
    QHBoxLayout *d_refill_cantidad_title_layout;
    QHBoxLayout *d_refill_contrasena_titulo_layout;

    //Capas de los inputs los respectivos widgets, en estas capas se "insertan" los editores de texto para establecer el nombre del producto y su cantidad
    //y tambien para la contrasena de la interfaz rebastecer.
    QGridLayout *d_refill_nombre_input_layout;
    QGridLayout *d_refill_cantidad_input_layout;
    QGridLayout *d_refill_contrasena_input_layout;

    //Capas de los botones de los respectivos widgets, en estas capas "insertan" los botones de los respectivos widgets.
    QGridLayout *d_refill_boton_layout;
    QGridLayout *d_refill_boton_finalizar_layout;
    QGridLayout *d_refill_contrasena_boton_atras_layout;

    //Se definen los objetos tipo QLabel (para mostrar texto), es decir, los titulos y frases que se muestran en las respectivas ventanas
    QLabel *d_refill_title1;                //titulo
    QLabel *d_refill_nombre_title;          //""
    QLabel *d_refill_cantidad_title;        //""
    QLabel *d_refill_contrasena_titulo;     //""
    QLabel *d_refill_contrasena_incorrecta_frase; //frase que se muestra en la ventana que aparecere cuando digta mal la contrasena

    //Se definen los objetos tipo QLineEdit (para ingresar texto), es decir, los editores de texto que se utilizan en las respectivas ventanas
    QLineEdit *d_refill_cantidad_input;     //para ingresar la cantidad del producto (0 a 5)
    QLineEdit *d_refill_nombre_input;       //para ingresar el nombre del producto (cualquiera)
    QLineEdit *d_refill_contrasena_input;   //para ingresar la contrasena para acceder a la ventana para rebastecer productos

    //Se definen los objetos tipo QPushButton, es decir, los botones que se utilizan en las respectivas ventanas.
    QPushButton *d_refill_boton_finalizar;         //boton que va en la ventana de rebastecimiento, cuando se apreta se cierra la ventana de rebastecer y se abre la de compra
    QPushButton *d_refill_contrasena_boton_atras;  //boton que va en la ventana para ingrear la contrasena, si se apreta se devuelve a la ventana de compra
    QPushButton *d_refill_button[5][5];            //matriz de botones 5x5 que se muestran en la ventana de rebastecer, son las pilas de la maquina expendedora

    QString d_refill_boton_fila_columna[5][5];     //Es una matriz de objetos tipo QSring que contiene los nombres de las pilas (Nombre de pila = Fila_Columna -> A1, B1, C2, etc)

    QTimer *d_refill_temporizador1;                //Es un objeto tipo QTimer para temporizar la ventana de la contrasena incorrecta, que solo se muestre por unos segundos.

    int fila_boton_refill;        //son variables para guardar la fila y la columna del boton que se presione en la ventana de rebastecer
    int columna_boton_refill;


    //--------------Comprar-------------

    //Estos objetos y variables estan relaciones con la interfaz para comprar productos, es decir,son necesarios para llevar a
    //cabo la logica y la interfaz grafica de la compra de un producto en la maquina expendedora.

    QWidget *d_comprar;                           //Widget que representa la ventana en la cual se muestra la interfaz para comprar productos
    QWidget *d_comprar_frase1;                    //Widget que representa la ventana en la cual se muestra el mensaje de: gracias por su compra
    QWidget *d_comprar_frase2;                    //Widget que representa la ventana en la cual se muestra el mensaje de: puede retirar su producto


    //Capas principales de los respectivos widgets.
    QVBoxLayout *d_comprar_main_layout;
    QVBoxLayout *d_comprar_frase1_layout;
    QVBoxLayout *d_comprar_frase2_layout;

    //Titulo de la ventana para comprar productos
    QHBoxLayout *d_comprar_titulo_layout;

    //Capas de los botones de los respectivos widgets
    QGridLayout *d_comprar_boton_layout;
    QGridLayout *d_comprar_boton_refill_layout;

    //Se definen los objetos tipo QLabel (para mostrar texto), es decir, los titulos y frases que se muestran en las respectivas ventanas
    QLabel *d_comprar_frase1_frase;  //frase de puede retirar su producto
    QLabel *d_comprar_frase2_frase;  //frase de gracias por su compra
    QLabel *d_comprar_titulo;        //titulo

    //Se definen los objetos tipo QPushButton, es decir, los botones que se utilizan en las respectivas ventanas.
    QPushButton *d_comprar_boton[5][5];   //matriz de botones 5x5 que se van a mostrar dinamicamente en la ventana de compra, es decir, solo se muestran los botones de productos disponibles.
    QPushButton *d_comprar_boton_refill;  //boton que se presiona en la ventana de compra para ir a la ventana de rebastecer

    //Se definen los objetos tipo QTimer para temporizar la ventanas
    QTimer *d_comprar_temporizador1;  //para temporizar la ventana de gracias por la compra
    QTimer *d_comprar_temporizador2;  //para temporizar la ventana de puede retir su producto



    //------------------------------------
    //--------------Funciones--------------
    //-------------------------------------


    //--------------Comprar-----------

    //Esta funcion se utiliza para crear y configuar la ventana principal de la interzas de compra que es utilizada por el usuario para comprar
    //cualquier producto que este disponible en la maquina expendedora de 5 filas y 5 columnas. Esta ventana consiste de tres elementos. El primer
    //elemento es el titulo de la ventana que es "Seleccione el producto que desea comprar". El segundo elemento es una matriz de botones de 5x5 que representan
    //los productos disponibles, en la ventana solo se muestran los disponibles y nada mas, por lo tanto, esta ventana es dinamica. El tercer elemento
    //es un boton que se utiliza para rebastecer la maquina de producto nuevos. Adicionalmente, los botones tienen el nombre del producto que representan.
     void crear_y_configurar_la_interfaz_de_compra();

    //Esta funcion se utiliza para crear y configurar la ventana que muestra la frase "gracias por su compra". Esta ventana se muestra justo luego de que
    //se compra un producto. Solo tiene un elemento que es el texto de la frase.
    void crear_y_configurar_la_ventana_de_la_frase_gracias();

    //Esta funcion se utiliza para crear y configurar la ventana que muestra la frase "puede retirar su producto". Esta ventana se muestra justo luego
    //de que se compra un producto. Solo tiene un elemento que es el texto de la frase.
    void crear_y_configurar_la_ventana_de_la_frase_retirar();


    //--------------Rebastecer-----------

    //Esta funcion se utiliza para crear y configuar la ventana principal de la interzas para rebastecer que es utilizada por el usuario para rebastecer
    //cualquier producto que se encuentre agotado o que queden pocos de este.Esta ventana consiste de tres elementos. El primer elemento
    //es el titulo de la ventana que es "Rebastecer maquina expendedora". El segundo elemento es una matriz de botones de 5x5 que representan las pilas
    //o slots fisicos de la maquina expendedora, esta ventana es estatica porque esos botones simpre se muestran. El tercer elemento es un boton
    //que se utiliza para finalizar el proceo de rebastecimiento de la maquina. Adicionalmente, los botones tienen la fila y columna de la pila
    //que representan.
    void crear_y_configurar_la_interfaz_de_rebastecimiento();

    //Esta funcion se utiliza para crear y configurar  la ventana en la cual se ingrea el nombre del producto que se esta rebasteciendo. Tiene dos elementos.
    //El primer elemento es el titulo "Ingrese el nombre del producto y presione enter y el segundo elemento es un editor de texto para ingresar con
    //el teclado el nombre.
    void crear_y_configurar_la_ventana_ingresar_nombre();

    //Esta funcion se utiliza para crear y configurar  la ventana en la cual se ingresa la cantidad del producto que se esta rebasteciendo. Tiene dos elementos.
    //El primer elemento es el titulo "Ingrese la cantidad del producto y presione enter y el segundo elemento es un editor de texto para ingresar con
    //el teclado la cantidad.
    void crear_y_configurar_la_ventana_ingresar_cantidad();

    //Esta funcion se utiliza para crear y configurar la ventana en la cual se ingresa la contrasena para acceder a la ventana de rebastecimiento. Tiene
    //tres elementos. El primer elemento es el titulo de la ventana "Ingrese la contrasena y presione enter". El segundo elemento es el editor de
    //texto para ingresar la contrasena. El tecer elemento es un boton llamado "Atras" para devolverse a la ventana de compra.
    void crear_y_configurar_la_ventana_ingresar_contrasena();

    //Esta funcion se utiliza para crear y configurar la ventana que muestra la frase "contrasena incorrecta". Esta ventana se muestra justo luego
    //de que se ingresa una contrasena incorrecta. Solo tiene un elemento que es el texto de la frase.
    void crear_y_configurar_la_ventana_contrasena_incorrecta();


    //--------------Conectar------------

    //En esta funcion se establecen todas las conecciones que existen entre ventanas de la interfaz comprar: botones, editores de texto,
    //temporizadores, etc. En la funcion en si se explican todas las conneciones.
    void conectar_la_interfaz_de_compra_y_sus_ventanas();

    //En esta funcion se establecen todas las conecciones que existen entre ventanas de la interfaz rebastecer: botones, editores de texto,
    //temporizadores, etc. En la funcion en si se explican todas las conneciones.
    void conectar_la_interfaz_para_rebastecer_y_sus_ventanas();


    //--------------Liberar----------
    //Es para liberar todas las variables que estan ocupando memoria, se ejecuta luego de que la aplicacion termina.
    void liberar_variables();


    //--------------Funciones usadas por slots-----------

    //Esta funcion es utilizada por el slot llamado "d_refill_slot_identificar_la_pila_seleccionada()". Lo que hace es simplemente mostrar en el editor
    //de texto de la ventana ingresar nmombre, el nombre del producto que tenia o que tiene esa pila, del forma que el usuario no tenga que volver
    //a escribir el nombre.
    void d_refill_mostrar_nombre_de_producto_en_editor_de_texto();

    //Esta funcion es utilizada por el slot llamado "void d_refill_slot_agrupar_productos_repetidos()". Lo que hace es simplemente mostrar en el boton que representa
    //la pila que se esta rebasteciendo, los atributos del producto (el nombre y la cantidad presente).
    void d_refill_slot_mostrar_atributos_de_producto_rebastecido();

    //Esta funcion es utilizada por el slot llamado "d_refill_slot_verificar_contrasena()". Lo que hace es actualizar la cantidad de producto en cada
    //pila de la maquina expendendora, de tal forma que en cada boton se muestre el nombre del producto la cantidad actual, luego de X compras.
    void d_refill_actualizar_cantidades_en_ventana_rebastecer();

public slots:


    //--------------Rebastecer-----------

    //Como su nombre lo dice, esta funcion lo que hace es identificar cual pila es la que se esta rebasteciendo. Siempre que se aprete el boton
    //de una pila se abrira la ventana de ingresar nombre y luego la de ingresar cantidad, pero estas ventanas tienen que saber quien las "invoco"
    //para poder guar el nombre y la cantidad en el elmento de la lista de productos correspondiente y correcto. Ademas, cuando esta funcion
    //se ejecuta se muestra la ventana de ingresar nombre y se oculta la de rebastecer.

    //Se llama a esta funcion cuando se presiona un boton de pila de la ventana rebastecer.

    //En esta funcion se utiliza la funcion llamada "d_refill_mostrar_nombre_de_producto_en_editor_de_texto()" que se explica antes.
    void d_refill_slot_identificar_la_pila_seleccionada();

    //Como su nombre lo dice, esta funcion lo que hace es guardar el nombre del producto que se esta rebasteciendo, el cual
    //se ingreso en la ventana respectiva de ingresar nombre. Se guarda en el elemento de la lista de productos que corresponde a
    //la pila que llamo a esta ventana. Ademas, esconde la ventana de ingresar nombre y muestra la de ingresar cantidad.
    //Se llama a esta funcion cuando se presiona enter en la ventana de ingresar nombre.
    void d_refill_slot_guardar_nombre_de_producto_rebastecido();

    //Como su nombre lo dice, esta funcion lo que hace es guardar la cantidad del producto que se esta rebasteciendo, el cual
    //se ingreso en la ventana respectiva de ingresar cantidad. Se guarda en el elemento de la lista de productos que corresponde a
    //la pila que llamo a esta ventana.Ademas, esconde la ventana de ingresar cantidad y muestra la de rebastecer.
    //Se llama a esta funcion cuando se presiona enter en la ventana de ingresar cantidad.
    //En esta funcion se utiliza la funcion llamada "d_refill_slot_mostrar_atributos_de_producto_rebastecido()" que se explica antes.
    void d_refill_slot_guardar_cantidad_de_producto_rebastecido();

    //Esta funcion lo que hace es agrupar todos los productos repetidos de la maquina expendedora en un solo producto, con el nombre del producto que
    //se repite y con la cantidad total (Si hay un producto llamado Galleta que esta en 3 pilas y cada una llena, el producto repetido seria Galleta
    //con una cantidad de 15). Ademas, se establece la variable mostrar_producto para asegurarse de que en la ventana de compra no se muestren
    //productos repetidos mas de una vez y la varible repetir para saber si un producto esta repetido o no. Ademas, cuando se ejecuta esconde
    //la la ventana de rebastecer y muestra la ventana de compra.
    //Se llama a esta funcion cuando se clickea el boton finalizar de la ventana rebastecer. Tambien es llamada por la senal producto_agotado.
    //En esta funcion se utiliza la funcion llamada "d_comprar_slot_actualizar_ventana_de_productos_disponibles()" mas adelante.
    void d_refill_slot_agrupar_productos_repetidos();

    //Esta funcion lo que hace es simplemente verificar si la contrasena que se ingresa en la ventana de ingresar contrasena, es la correcta o no.
    //En caso de que sea la incorrecta se llama a la funcion "d_refill_actualizar_cantidades_en_ventana_rebastecer()" que se explica antes y en caso de que sea incorrecta
    //se esconde la ventana de ingresar contrasena y se muestra la de contrasena incorrecta por 2 segundos.
    //Se llama a esta funcion cuando se clickea el boton de "Rebastecer" en la ventana de compra.
    void d_refill_slot_verificar_contrasena();


    //--------------Comprar------------

    //Esta funcion lo que hace es dispensar el producto comprado. Si el producto no esta repetido pues solamente se llama a la funcion comprar y listo.
    //Se decrementa la cantidad en 1 y si agota se genera la senal.
    //Pero si el producto esta repetido se tiene que determinar cual pila con ese producto es la que tiene la menor cantidad para dispensar y se compra o se
    //dispensa el producto de esa pila nada mas. Si la cantidad total de producto repetido es 0, el producto esta agotado y se general la senal.
    //La senal producto agotado lo que hace es actualizar la ventana de compra, no se mostraria mas ese producto.
    //Esconde la ventana de compra y muestra la ventana de gracias por su compra.
    //Esta funcion es llamada cuando se presiona algun producto y se compra.
    void d_comprar_slot_dispensar_producto_comprado_y_actualizar_cantidades();

    //Esta funcion lo que hace es detemrinar cuales productos se deben de mostrar en la ventana de compra y cuales no (los agotados no y los
    //repetidos solamente uno).
    //Esta funcion es llamada por la funcion "d_refill_slot_agrupar_productos_repetidos();" y por la senal de producto_agotado.
    void d_comprar_slot_actualizar_ventana_de_productos_disponibles();

};

#endif // MAINWINDOW_H
