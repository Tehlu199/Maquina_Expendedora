#include "mainwindow.h"
#include "Producto.h"
#include <QSignalMapper>
#include <QString>
#include <QIcon>
#include <QPixmap>
#include <QDesktopWidget>
#include <QScreen>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //---------------------------------------------------------
    //--------------------------COMPRAR-----------------------
    //---------------------------------------------------------
    
    //Se crea y se configura la interfaz de compra y sus ventanas.
    crear_y_configurar_la_interfaz_de_compra();
    crear_y_configurar_la_ventana_de_la_frase_gracias();
    crear_y_configurar_la_ventana_de_la_frase_retirar();
    
    //---------------------------------------------------------
    //--------------------------REBASTECER---------------------
    //---------------------------------------------------------
    
    //Se crea y se configura la interfaz para rebastecer y sus ventanas.
    crear_y_configurar_la_interfaz_de_rebastecimiento();
    crear_y_configurar_la_ventana_ingresar_nombre();
    crear_y_configurar_la_ventana_ingresar_cantidad();
    crear_y_configurar_la_ventana_ingresar_contrasena();
    crear_y_configurar_la_ventana_contrasena_incorrecta();
    
    //---------------------------------------------------------
    //-----------------------CONECTAR------------------------
    //---------------------------------------------------------
    
    conectar_la_interfaz_de_compra_y_sus_ventanas();
    conectar_la_interfaz_para_rebastecer_y_sus_ventanas();
    
    //---------------------------------------------------------
    //-------------------------------------------------------
    //---------------------------------------------------------
    
    //Se muestran la ventana inicial
    d_comprar->show();
}



//--------------------------------------------------------------------------------------------------------------
//----------------------SE DEFINEN LAS FUNCIONES PARA CREAR LA INTERFAZ GRAFICA--------------------------------
//--------------------------------------------------------------------------------------------------------------


//---------------------------------------------------------
//--------------------------COMPRAR------------------------
//---------------------------------------------------------


void MainWindow::crear_y_configurar_la_interfaz_de_compra(){
    
    //---------Variables locales----------
    int i,j;
    QFont font;
    
    //-------------Se inicializan todas las variables y objetos relacionados con la interfaz de compra------------
    
    //Widgets
    d_comprar = new QWidget;
    
    //Layouts
    d_comprar_main_layout = new QVBoxLayout;
    d_comprar_titulo_layout = new QHBoxLayout;
    d_comprar_boton_layout = new QGridLayout;
    d_comprar_boton_refill_layout = new QGridLayout;
    
    //Titulo
    d_comprar_titulo = new QLabel("Seleccione el producto que desea comprar");
    
    //Botones
    d_comprar_boton_refill = new QPushButton("Rebastecer");
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            d_comprar_boton[i][j] = new QPushButton;
        }
    }
    
    //-----------------------Se configuran los atributos de los objetos (widgets)----------------------
    //Los atributos pueden ser: tamano de letra, tipo de letra, negrita o no, tamano minimo y maximo del objeto, nombre, ocultarlo o no, etc
    
    
    //Se configuran los atributos del titulo.
    font = d_comprar_titulo->font();
    font.setPointSize(15);
    font.setBold(true);
    d_comprar_titulo->setFont(font);
    d_comprar_titulo->setAlignment(Qt::AlignCenter);
    d_comprar_titulo->setMinimumSize(1000,50);
    d_comprar_titulo->setMaximumSize(1000,50);
    
    //Se configuran los atributos de los botones.
    //Botones para comprar los productos disponibles:
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            d_comprar_boton[i][j]->hide();
            
            d_comprar_boton[i][j]->setMinimumSize(QSize(180, 100));
            d_comprar_boton[i][j]->setMaximumSize(QSize(180, 100));
            
            font = d_comprar_boton[i][j]->font();
            font.setPointSize(10);
            font.setBold(true);
            d_comprar_boton[i][j]->setFont(font);
        }
    }
    
    //Boton para dirigirse a la ventana para rebastecer productos
    font =  d_comprar_boton_refill->font();
    font.setPointSize(11);
    font.setBold(true);
    d_comprar_boton_refill->setFont(font);
    d_comprar_boton_refill->setMinimumSize(QSize(250, 70));
    d_comprar_boton_refill->setMaximumSize(QSize(250, 70));
    
    
    //--------------------Se anaden los widgets anteriores a sus respectivas capas----------------------
    
    //Titulos
    d_comprar_titulo_layout->addWidget(d_comprar_titulo);
    
    //Botones
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            d_comprar_boton_layout->addWidget(d_comprar_boton[i][j], i, j);
        }
    }
    d_comprar_boton_refill_layout->addWidget(d_comprar_boton_refill);
    
    
    //--------------------Se establece el espacio entre widgets en las capas--------------------
    d_comprar_titulo_layout->setSpacing(20);
    d_comprar_main_layout->setSpacing(20);
    d_comprar_boton_layout->setSpacing(20);
    d_comprar_boton_refill_layout->setSpacing(20);
    
    
    //--------------------Se establece el tamano de la ventana de compra--------------------
    d_comprar->setMinimumSize(QSize(1000, 850));
    d_comprar->setMaximumSize(QSize(1000, 850));
    d_comprar->adjustSize();
    d_comprar->move(QApplication::desktop()->rect().center()-d_comprar->rect().center());

    
    
    //--------------------Se insertan las capas en la ventana de compra--------------------
    d_comprar_main_layout->addLayout(d_comprar_titulo_layout);
    d_comprar_main_layout->addLayout(d_comprar_boton_layout);
    d_comprar_main_layout->addLayout(d_comprar_boton_refill_layout);
    d_comprar->setLayout(d_comprar_main_layout);
}


void MainWindow::crear_y_configurar_la_ventana_de_la_frase_gracias(){
    
    //---------Variables locales----------
    QFont font;
    
    
    //-------------Se inicializan todas las variables y objetos relacionados a la ventana de gracias------------
    
    //Widget
    d_comprar_frase1 = new QWidget; //d_frase1
    
    //Layout
    d_comprar_frase1_layout = new QVBoxLayout;
    
    //Frase
    d_comprar_frase1_frase = new QLabel("Gracias por su compra");
    
    //Temporizador
    d_comprar_temporizador1 = new QTimer;
    
    //-----------------------Se configuran los atributos de los objetos (widgets)----------------------
    //Los atributos pueden ser: tamano de letra, tipo de letra, negrita o no, tamano minimo y maximo del objeto, nombre, ocultarlo o no, entre otros
    
    //Frase
    font = d_comprar_frase1_frase->font();
    font.setPointSize(16);
    font.setBold(true);
    d_comprar_frase1_frase->setFont(font);
    d_comprar_frase1_frase->setAlignment(Qt::AlignCenter);
    
    //Temporizador
    d_comprar_temporizador1->start(2000);
    d_comprar_temporizador1->stop();
    d_comprar_temporizador1->setSingleShot(true);
    
    //--------------------Se anaden los widgets anteriores a sus respectivas capas---------------
    d_comprar_frase1_layout->addWidget(d_comprar_frase1_frase);
    
    
    //--------------------Se establece el tamano de la ventana de compra--------------------
    d_comprar_frase1->setMinimumSize(QSize(1000, 850));
    d_comprar_frase1->setMaximumSize(QSize(1000, 850));
    d_comprar_frase1->adjustSize();
    d_comprar_frase1->move(QApplication::desktop()->rect().center()-d_comprar_frase1->rect().center());
    
    
    //--------------------Se insertan las capas en la ventana de gracias--------------------
    d_comprar_frase1->setLayout(d_comprar_frase1_layout);
    
}


void MainWindow::crear_y_configurar_la_ventana_de_la_frase_retirar(){
    
    //---------Variables locales----------
    QFont font;
    
    
    //-------------Se inicializan todas las variables y objetos relacionados con la ventana retirar--------------
    
    //Widget
    d_comprar_frase2 = new QWidget; //d_frase2
    
    //Layout
    d_comprar_frase2_layout = new QVBoxLayout;
    
    //Frase
    d_comprar_frase2_frase = new QLabel("Puede retirar su producto");
    
    //Temporizador
    d_comprar_temporizador2 = new QTimer;
    
    
    //-----------------------Se configuran los atributos de los objetos (widgets)----------------------
    //Los atributos pueden ser: tamano de letra, tipo de letra, negrita o no, tamano minimo y maximo del objeto, nombre, ocultarlo o no, etc
    
    //Frase
    font = d_comprar_frase2_frase->font();
    font.setPointSize(16);
    font.setBold(true);
    d_comprar_frase2_frase->setFont(font);
    d_comprar_frase2_frase->setAlignment(Qt::AlignCenter);
    
    //Temporizador
    d_comprar_temporizador2->start(2000);
    d_comprar_temporizador2->stop();
    d_comprar_temporizador2->setSingleShot(true);
    
    //--------------------Se anaden los widgets anteriores a sus respectivas capas----------------------
    d_comprar_frase2_layout->addWidget(d_comprar_frase2_frase);
    
    //--------------------Se establece el tamano de la ventana de compra--------------------
    d_comprar_frase2->setMinimumSize(QSize(1000, 850));
    d_comprar_frase2->setMaximumSize(QSize(1000, 850));
    d_comprar_frase2->adjustSize();
    d_comprar_frase2->move(QApplication::desktop()->rect().center()-d_comprar_frase2->rect().center());
    
    
    //--------------------Se insertan las capas en la ventana de compra--------------------
    d_comprar_frase2->setLayout(d_comprar_frase2_layout);
    
}



//---------------------------------------------------------
//--------------------------REBASTECER---------------------
//---------------------------------------------------------



void MainWindow::crear_y_configurar_la_interfaz_de_rebastecimiento(){
    
    //---------Variables locales----------
    int i,j;
    QFont font;
    QString nombre;
    
    
    //------------Se inicializan todas las variables y objetos relacionados con la interfaz para rebastecer-----------
    
    //Widget
    d_refill = new QWidget;
    
    //Layouts
    d_refill_main_layout = new QVBoxLayout;
    d_refill_title_layout = new QHBoxLayout;
    d_refill_boton_layout = new QGridLayout;
    d_refill_boton_finalizar_layout = new QGridLayout;
    
    //Titulo
    d_refill_title1 = new QLabel("Rebastecer maquina expendedora");
    
    //Botones
    d_refill_boton_finalizar = new QPushButton("Finalizar");
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            d_refill_button[i][j] = new QPushButton;
        }
    }
    
    //Productos
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            lista_de_productos[i][j] = new Producto;
        }
    }
    for(i=0;i<25;i++){
        lista_de_productos_repetidos[i] = new Producto;
    }
    
    //-----------------------Se configuran los atributos de los objetos (widgets)----------------------
    //Los atributos pueden ser: tamano de letra, tipo de letra, negrita o no, tamano minimo y maximo del objeto, nombre, ocultarlo o no, etc
    
    //Se configuran los atributos del titulo.
    font = d_refill_title1->font();
    font.setPointSize(16);
    font.setBold(true);
    d_refill_title1->setFont(font);
    d_refill_title1->setAlignment(Qt::AlignCenter);
    d_refill_title1->setMinimumSize(1000,50);
    d_refill_title1->setMaximumSize(1000,50);
    
    //Se configuran los atributos de los botones
    //Botones que representan las pilas de la maquina expendedora, para rebastecer productos
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            
            if(i==0){nombre = QString("A%1").arg(j);}
            if(i==1){nombre = QString("B%1").arg(j);}
            if(i==2){nombre = QString("C%1").arg(j);}
            if(i==3){nombre = QString("D%1").arg(j);}
            if(i==4){nombre = QString("E%1").arg(j);}
            
            d_refill_button[i][j] = new QPushButton(nombre);
            d_refill_boton_fila_columna[i][j] = nombre;
            d_refill_button[i][j]->setMinimumSize(QSize(180, 100));
            d_refill_button[i][j]->setMaximumSize(QSize(180, 100));
            
            font =  d_refill_button[i][j]->font();
            font.setPointSize(10);
            font.setBold(true);
            d_refill_button[i][j]->setFont(font);
            
            d_refill_boton_layout->addWidget(d_refill_button[i][j], i, j);
        }
    }
    
    //Boton para finalizar el proceso de rebastecimiento e ir a la interfaz de compra.
    font =  d_refill_boton_finalizar->font();
    font.setPointSize(11);
    font.setBold(true);
    d_refill_boton_finalizar->setFont(font);
    d_refill_boton_finalizar->setMinimumSize(QSize(250, 70));
    d_refill_boton_finalizar->setMaximumSize(QSize(250, 70));
    
    
    //--------------------Se anaden los widgets anteriores a sus respectivas capas---------------
    
    //Titulo
    d_refill_title_layout->addWidget(d_refill_title1);
    
    //Botones
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            d_refill_boton_layout->addWidget(d_refill_button[i][j], i, j);
        }
    }
    d_refill_boton_finalizar_layout->addWidget(d_refill_boton_finalizar);
    
    
    //--------------------Se establece el espacio entre widgets en las capas--------------------
    d_refill_title_layout->setSpacing(20);
    d_refill_main_layout->setSpacing(20);
    d_refill_boton_layout->setSpacing(20);
    d_refill_boton_finalizar_layout->setSpacing(20);
    
    
    //--------------------Se establece el tamano de la ventana para rebastecer---------------------
    d_refill->setMinimumSize(QSize(1000, 850));
    d_refill->setMaximumSize(QSize(1000, 850));
    d_refill->adjustSize();
    d_refill->move(QApplication::desktop()->rect().center()-d_refill->rect().center());
    
    
    //--------------------Se insertan las capas en la ventana para rebastecer----------------------
    d_refill_main_layout->addLayout(d_refill_title_layout);
    d_refill_main_layout->addLayout(d_refill_boton_layout);
    d_refill_main_layout->addLayout(d_refill_boton_finalizar_layout);
    d_refill->setLayout(d_refill_main_layout);
}


void MainWindow::crear_y_configurar_la_ventana_ingresar_nombre(){
    
    //---------Variables locales----------
    QFont font;
    
    //------------Se inicializan todas las variables y objetos relacionados con la ventana para ingresar el nombre del producto-----------
    
    //Widget
    d_refill_nombre = new QWidget;
    
    //Layouts
    d_refill_nombre_main_layout = new QVBoxLayout;
    d_refill_nombre_title_layout = new QHBoxLayout;
    d_refill_nombre_input_layout = new QGridLayout;
    
    //Titulo
    d_refill_nombre_title = new QLabel("Ingrese el nombre del producto y presione enter");
    
    //Editor de texto
    d_refill_nombre_input = new QLineEdit;
    
    //-----------------------Se configuran los atributos de los objetos (widgets)----------------------
    //Los atributos pueden ser: tamano de letra, tipo de letra, negrita o no, tamano minimo y maximo del objeto, nombre, ocultarlo o no, etc
    
    //Titulo
    font = d_refill_nombre_title->font();
    font.setPointSize(16);
    font.setBold(true);
    d_refill_nombre_title->setFont(font);
    d_refill_nombre_title->setAlignment(Qt::AlignCenter);
    d_refill_nombre_title->setMinimumSize(1000,50);
    d_refill_nombre_title->setMaximumSize(1000,50);
    
    //Editor de texto
    d_refill_nombre_input->setPlaceholderText("Nombre (cualquiera)");
    d_refill_nombre_input->setFocus();
    font = d_refill_nombre_input->font();
    font.setPointSize(11);
    d_refill_nombre_input->setFont(font);
    d_refill_nombre_input->setMinimumSize(QSize(600, 40));
    d_refill_nombre_input->setMaximumSize(QSize(600, 40));
    
    //--------------------Se anaden los widgets anteriores a sus respectivas capas---------------
    
    //Titulo
    d_refill_nombre_title_layout->addWidget(d_refill_nombre_title);
    
    //Editor de texto
    d_refill_nombre_input_layout->addWidget(d_refill_nombre_input);
    
    
    //--------------------Se establece el espacio entre widgets en las capas--------------------
    d_refill_nombre_title_layout->setSpacing(20);
    d_refill_nombre_main_layout->setSpacing(20);
    d_refill_nombre_input_layout->setSpacing(20);
    
    //--------------------Se establece el tamano de la ventana para ingresar nombre---------------------
    d_refill_nombre->setMinimumSize(QSize(1000, 850));
    d_refill_nombre->setMaximumSize(QSize(1000, 850));
    d_refill_nombre->adjustSize();
    d_refill_nombre->move(QApplication::desktop()->rect().center()-d_refill_nombre->rect().center());
    
    //--------------------Se insertan las capas en la ventana para ingresar nombre----------------------
    d_refill_nombre_main_layout->addLayout(d_refill_nombre_title_layout);
    d_refill_nombre_main_layout->addLayout(d_refill_nombre_input_layout);
    d_refill_nombre->setLayout(d_refill_nombre_main_layout);
    
}


void MainWindow::crear_y_configurar_la_ventana_ingresar_cantidad(){
    
    //---------Variables locales----------
    QFont font;
    
    
    //------------Se inicializan todas las variables y objetos relacionados con la ventana para ingresar la cantidad del producto-----------
    
    //Widget
    d_refill_cantidad = new QWidget;
    
    //Layout
    d_refill_cantidad_main_layout = new QVBoxLayout;
    d_refill_cantidad_title_layout = new QHBoxLayout;
    d_refill_cantidad_input_layout = new QGridLayout;
    
    //Titulo
    d_refill_cantidad_title = new QLabel("Ingrese la cantidad del producto y presione enter");
    
    //Editor de texto
    d_refill_cantidad_input = new QLineEdit;
    
    
    //-----------------------Se configuran los atributos de los objetos (widgets)----------------------
    //Los atributos pueden ser: tamano de letra, tipo de letra, negrita o no, tamano minimo y maximo del objeto, nombre, ocultarlo o no, etc
    
    //Titulo
    font = d_refill_cantidad_title->font();
    font.setPointSize(16);
    font.setBold(true);
    d_refill_cantidad_title->setFont(font);
    d_refill_cantidad_title->setAlignment(Qt::AlignCenter);
    d_refill_cantidad_title->setMinimumSize(1000,50);
    d_refill_cantidad_title->setMaximumSize(1000,50);
    
    //Editor de texto
    d_refill_cantidad_input->setPlaceholderText("Cantidad (entre 0 y 5)");
    d_refill_cantidad_input->setFocus();
    d_refill_cantidad_input->setValidator( new QIntValidator(0, 5, d_refill_nombre) );
    font = d_refill_cantidad_input->font();
    font.setPointSize(11);
    d_refill_cantidad_input->setFont(font);
    d_refill_cantidad_input->setMinimumSize(QSize(600, 40));
    d_refill_cantidad_input->setMaximumSize(QSize(600, 40));
    
    
    //--------------------Se anaden los widgets anteriores a sus respectivas capas---------------
    
    //Titulo
    d_refill_cantidad_title_layout->addWidget(d_refill_cantidad_title);
    
    //Editor de texto
    d_refill_cantidad_input_layout->addWidget(d_refill_cantidad_input);
    
    
    //--------------------Se establece el espacio entre widgets en las capas--------------------
    d_refill_cantidad_title_layout->setSpacing(20);
    d_refill_cantidad_main_layout->setSpacing(20);
    d_refill_cantidad_input_layout->setSpacing(20);
    
    
    //--------------------Se establece el tamano de la ventana para ingresar cantidad---------------------
    d_refill_cantidad->setMinimumSize(QSize(1000, 850));
    d_refill_cantidad->setMaximumSize(QSize(1000, 850));
    d_refill_cantidad->adjustSize();
    d_refill_cantidad->move(QApplication::desktop()->rect().center()-d_refill_cantidad->rect().center());
    
    //--------------------Se insertan las capas en la ventana para ingresar cantidad----------------------
    d_refill_cantidad_main_layout->addLayout(d_refill_cantidad_title_layout);
    d_refill_cantidad_main_layout->addLayout(d_refill_cantidad_input_layout);
    d_refill_cantidad->setLayout(d_refill_cantidad_main_layout);
    
    
}


void MainWindow::crear_y_configurar_la_ventana_ingresar_contrasena(){
    
    //---------Variables locales----------
    QFont font;
    
    //------------Se inicializan todas las variables y objetos relacionados con la ventana pare ingresar contrasena-----------
    
    //Widget
    d_refill_contrasena = new QWidget;
    
    //Layouts
    d_refill_contrasena_main_layout = new QVBoxLayout;
    d_refill_contrasena_titulo_layout = new QHBoxLayout;
    d_refill_contrasena_input_layout = new QGridLayout;
    d_refill_contrasena_boton_atras_layout = new QGridLayout;
    
    //Titulo
    d_refill_contrasena_titulo = new QLabel("Ingrese la contraseña y presione enter");
    
    //Editor de texto
    d_refill_contrasena_input = new QLineEdit;
    
    //Boton
    d_refill_contrasena_boton_atras = new QPushButton("< Atras");
    
    
    //-----------------------Se configuran los atributos de los objetos (widgets)----------------------
    //Los atributos pueden ser: tamano de letra, tipo de letra, negrita o no, tamano minimo y maximo del objeto, nombre, ocultarlo o no, etc
    
    
    //Titulo
    font = d_refill_contrasena_titulo->font();
    font.setPointSize(16);
    font.setBold(true);
    d_refill_contrasena_titulo->setFont(font);
    d_refill_contrasena_titulo->setAlignment(Qt::AlignCenter);
    d_refill_contrasena_titulo->setMinimumSize(1000,50);
    d_refill_contrasena_titulo->setMaximumSize(1000,50);
    
    //Editor de texto
    font = d_refill_contrasena_input->font();
    font.setPointSize(11);
    d_refill_contrasena_input->setFont(font);
    d_refill_contrasena_input->setPlaceholderText("Contraseña");
    d_refill_contrasena_input->setFocus();
    d_refill_contrasena_input->setMinimumSize(QSize(600, 40));
    d_refill_contrasena_input->setMaximumSize(QSize(600, 40));
    
    //Boton
    font =  d_refill_contrasena_boton_atras->font();
    font.setPointSize(11);
    font.setBold(true);
    d_refill_contrasena_boton_atras->setFont(font);
    d_refill_contrasena_boton_atras->setMinimumSize(QSize(250, 70));
    d_refill_contrasena_boton_atras->setMaximumSize(QSize(250, 70));
    
    
    //--------------------Se anaden los widgets anteriores a sus respectivas capas---------------
    
    //Titulo
    d_refill_contrasena_titulo_layout->addWidget(d_refill_contrasena_titulo);
    
    //Editor de texto
    d_refill_contrasena_input_layout->addWidget(d_refill_contrasena_input);
    
    //Boton
    d_refill_contrasena_boton_atras_layout->addWidget(d_refill_contrasena_boton_atras);
    
    
    //--------------------Se establece el espacio entre widgets en las capas--------------------
    d_refill_contrasena_titulo_layout->setSpacing(20);
    d_refill_contrasena_main_layout->setSpacing(20);
    d_refill_contrasena_input_layout->setSpacing(20);
    d_refill_contrasena_boton_atras_layout->setSpacing(20);
    
    
    //--------------------Se establece el tamano de la ventana para ingresar contrasena---------------------
    d_refill_contrasena->setMinimumSize(QSize(1000, 850));
    d_refill_contrasena->setMaximumSize(QSize(1000, 850));
    d_refill_contrasena->adjustSize();
    d_refill_contrasena->move(QApplication::desktop()->rect().center()-d_refill_contrasena->rect().center());
    
    
    //--------------------Se insertan las capas en la ventana para ingresar contrasena----------------------
    d_refill_contrasena_main_layout->addLayout(d_refill_contrasena_titulo_layout);
    d_refill_contrasena_main_layout->addLayout(d_refill_contrasena_input_layout);
    d_refill_contrasena_main_layout->addLayout(d_refill_contrasena_boton_atras_layout);
    d_refill_contrasena->setLayout(d_refill_contrasena_main_layout);
    
}


void MainWindow::crear_y_configurar_la_ventana_contrasena_incorrecta(){
    
    //---------Variables locales----------
    QFont font;
    
    //------------Se inicializan todas las variables y objetos relacionados con la ventana de contrasena incorrecta-----------
    
    //Widget
    d_refill_contrasena_incorrecta = new QWidget;
    
    //Layout
    d_refill_contrasena_incorrecta_layout = new QVBoxLayout;
    
    //Frase
    d_refill_contrasena_incorrecta_frase = new QLabel("La contraseña que ingreso es incorrecta\n Vuelva a intentarlo");
    
    //Temporizador
    d_refill_temporizador1 = new QTimer;
    
    
    //-----------------------Se configuran los atributos de los objetos (widgets)----------------------
    //Los atributos pueden ser: tamano de letra, tipo de letra, negrita o no, tamano minimo y maximo del objeto, nombre, ocultarlo o no, etc
    
    //Editor de texto
    font = d_refill_contrasena_incorrecta_frase->font();
    font.setPointSize(16);
    font.setBold(true);
    d_refill_contrasena_incorrecta_frase->setFont(font);
    d_refill_contrasena_incorrecta_frase->setAlignment(Qt::AlignCenter);
    
    //Temporizador
    d_refill_temporizador1->start(2000);
    d_refill_temporizador1->stop();
    d_refill_temporizador1->setSingleShot(true);
    
    
    //--------------------Se anaden los widgets anteriores a sus respectivas capas---------------
    d_refill_contrasena_incorrecta_layout->addWidget(d_refill_contrasena_incorrecta_frase);
    
    
    //--------------------Se establece el tamano de la ventana de contrasena incorrecta---------------------
    d_refill_contrasena_incorrecta->setMinimumSize(QSize(1000, 850));
    d_refill_contrasena_incorrecta->setMaximumSize(QSize(1000, 850));
    d_refill_contrasena_incorrecta->adjustSize();
    d_refill_contrasena_incorrecta->move(QApplication::desktop()->rect().center()-d_refill_contrasena_incorrecta->rect().center());
    
    
    //--------------------Se insertan las capas en la ventana de contrasena incorrecta----------------------
    d_refill_contrasena_incorrecta->setLayout(d_refill_contrasena_incorrecta_layout);
    
}





//--------------------------------------------------------------------------------------------------------------
//----------------------SE DEFINEN LAS FUNCIONES PARA CONECTAR VENTANAS E INTERFACES ENTRE SI-------------------
//--------------------------------------------------------------------------------------------------------------


void MainWindow::conectar_la_interfaz_de_compra_y_sus_ventanas(){
    
    //------Variables Globales------
    int i,j;
    
    //--------Conecciones----------
    
    //Se conectan los botones y la lista de productos;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            
            //Se conectan los botones que representan los productos disponibles en la maquina expendedora, con la funcion que se encarga de dispensar el producto
            //comprado y actualizar la cantidad disponible de este.
            //El evento que tiene que suceder es que se presione el respectivo boton
            QObject::connect(d_comprar_boton[i][j], SIGNAL(clicked()), this, SLOT(d_comprar_slot_dispensar_producto_comprado_y_actualizar_cantidades()));
            
            //Se conectan los productos que estan en la maquina expendedora con la funcion que se encarga de actualizar la interfaz de compra o la ventana de compra,
            //en la que solo se debe de mostrar los porductos disponibles.
            //El evento que tiene que suceder es que el producto se agote.
            QObject::connect(lista_de_productos[i][j], SIGNAL(senal_producto_agotado()), this, SLOT(d_comprar_slot_actualizar_ventana_de_productos_disponibles()));
        }
    }
    
    for(i=0;i<25;i++){
        //Se conectan los productos repetidos como un conjunto que estan en la maquina expendedora con la funcion que se encarga de actualizar la interfaz de compra o la ventana de compra,
        //en la que solo se debe de mostrar los porductos disponibles.
        //El evento que tiene que suceder es que el total del producto repetido se agote.
        QObject::connect(lista_de_productos_repetidos[i], SIGNAL(senal_producto_agotado()), this, SLOT(d_comprar_slot_actualizar_ventana_de_productos_disponibles()));
    }
    
    
    //Se conecta el temporizador1 para la ventana de gracias por su compra con tres cosas: la funcion que esconde la ventana de la frase1 (gracias), la
    //funcion que muestra la ventana de la frase2 (retirar) y la funcion que inicia el temporizador2 para la ventana retirar.
    //El evento que tiene que suceder es que el intervalo de 2s se acabe, que el temporizador llegue a cero.
    QObject::connect(d_comprar_temporizador1, SIGNAL(timeout()), d_comprar_frase1, SLOT(hide()));
    QObject::connect(d_comprar_temporizador1, SIGNAL(timeout()), d_comprar_frase2, SLOT(show()));
    QObject::connect(d_comprar_temporizador1, SIGNAL(timeout()), d_comprar_temporizador2, SLOT(start()));
    
    //Se conecta el temporizador2 para la ventana de retire su producto con dos cosas: la funcion que esconde la ventana de la frase2 (retirar) y la
    //funcion que muestra la ventana de compra.
    //El evento que tiene que suceder es que el intervalo de 2s se acabe, que el temporizador llegue a cero.
    QObject::connect(d_comprar_temporizador2, SIGNAL(timeout()), d_comprar_frase2, SLOT(hide()));
    QObject::connect(d_comprar_temporizador2, SIGNAL(timeout()), d_comprar, SLOT(show()));
    
    //Se conecta el boton "Rebastecer" con dos cosas: la funcion que esconde la ventana de compra y la funcion que muestra la ventana que me pide
    //una contrasena.
    //El evento que tiene que suceder es que se aprete el respectivo boton.
    QObject::connect(d_comprar_boton_refill, SIGNAL(clicked()), d_comprar, SLOT(hide()));
    QObject::connect(d_comprar_boton_refill, SIGNAL(clicked()), d_refill_contrasena, SLOT(show()));
}


void MainWindow::conectar_la_interfaz_para_rebastecer_y_sus_ventanas(){
    
    //------Variables Globales------
    int i,j;
    
    //--------Conecciones----------
    
    
    //Se conectan los botones que representan las pilas o slots de la maquina expendedora con la funcion que se encarga de identificar la pila
    //que se esta selecionando, ya que las ventanas de ingresas nombre e ingresar cantidad tienen que saber quien las "llamo", cual pila.
    //El evento que tiene que suceder es que se presione el respectivo boton,
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            
            QObject::connect(d_refill_button[i][j], SIGNAL(clicked()), this, SLOT(d_refill_slot_identificar_la_pila_seleccionada()));
        }
    }
    
    //Se conecta el boton "Finalizar" de la ventana rebastecer con la funcion que se encarga de agrupar los productos repetidos que tiene la maquina expendedora y ademas que
    //cierra la ventana de rebastecer y abre la ventana de compra con los productos disponibles.
    //El evento que tiene que suceder es que se presione el respectivo boton.
    QObject::connect(d_refill_boton_finalizar, SIGNAL(clicked()), this, SLOT(d_refill_slot_agrupar_productos_repetidos()));
    
    //Se conecta el editor de texto para ingresar el nombre del producto con la funcion que se encarga de guardar el respectivo nombre en la pila
    //que es, es decir, se asocia la pila con el producto.
    //El evento que tiene que suceder es que se presione enter en el teclado.
    QObject::connect(d_refill_nombre_input, SIGNAL(returnPressed()), this, SLOT(d_refill_slot_guardar_nombre_de_producto_rebastecido()));
    
    //Se conecta el editor de texto para ingresar la cantidad del producto con la funcion que se encarga de guardar la respectiva cantidad
    //en la pila, es decir, se asocia la pila con el producto.
    //El evento que tiene que suceder es que se presione enter en el teclado.
    QObject::connect(d_refill_cantidad_input, SIGNAL(returnPressed()), this, SLOT(d_refill_slot_guardar_cantidad_de_producto_rebastecido()));
    
    //Se conecta el editor de texto para ingresar la contrasena para acceder a la ventana para rebastecer productos con la funcion
    //que se encarga de verificar si dicha contrasena fue la correcta o no.
    //El evento que tiene que suceder es que se presione enter en el teclado.
    QObject::connect(d_refill_contrasena_input, SIGNAL(returnPressed()), this, SLOT(d_refill_slot_verificar_contrasena()));
    
    //Se conecta el temporizador1 para la ventana de contrasena incorrecta con tres funciones: la funcion que esconde la ventana de contrasena
    //incorrecta, la funcion que muestra la ventana de contrasena y la funcion que limpia el editor de texto asociado.
    //El evento que tiene que suceder es que el intervalo de 2s se acabe, que el temporizador llegue a cero.
    QObject::connect(d_refill_temporizador1, SIGNAL(timeout()), d_refill_contrasena, SLOT(show()));
    QObject::connect(d_refill_temporizador1, SIGNAL(timeout()), d_refill_contrasena_incorrecta, SLOT(hide()));
    QObject::connect(d_refill_temporizador1, SIGNAL(timeout()), d_refill_contrasena_input, SLOT(clear()));
    
    //Se conecta el boton "Atras" de la ventana de contrasena con dos funciones: la funcion que se encarga de ocultar la ventana
    //de contrasena y la muestra la ventana de compra.
    //El evento que tiene que suceder es que se presione el respectivo boton.
    QObject::connect(d_refill_contrasena_boton_atras, SIGNAL(clicked()), d_refill_contrasena, SLOT(hide()));
    QObject::connect(d_refill_contrasena_boton_atras, SIGNAL(clicked()), d_comprar, SLOT(show()));
}


void MainWindow::liberar_variables(){
    
    int i,j;
    
    delete d_refill;
    delete d_refill_nombre;
    delete d_refill_cantidad;
    delete d_refill_contrasena;
    delete d_refill_contrasena_incorrecta;
    
    delete d_comprar;
    delete d_comprar_frase1;
    delete d_comprar_frase2;
    
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            delete lista_de_productos[i][j];
        }
    }
    
    for(i=0; i<25; i++){
        delete lista_de_productos_repetidos[i];
    }
    
}






//--------------------------------------------------------------------------------------------------------------
//----------------------------SE DEFINEN LOS SLOTS Y LAS FUNCIONES QUE ESTOS USAN-------------------------------
//--------------------------------------------------------------------------------------------------------------
//Los slots son funciones que se ejecutan cuando ocurre algun evento como apretar un boton por ejemplo.



//---------------------------------------------------------
//--------------------------COMPRAR-----------------------
//---------------------------------------------------------


//-----------Funcion que se ejecuta luego de que se presiona el boton Finalizar y cuando un producto se agota--------------

void MainWindow::d_comprar_slot_actualizar_ventana_de_productos_disponibles(){
    
    int i,j,a,b;
    a=0;
    b=0;
    
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            d_comprar_boton[i][j]->hide();
            
            if(lista_de_productos[i][j]->cantidad == 0 || QString::compare(lista_de_productos[i][j]->nombre, tr(" "), Qt::CaseInsensitive) == 0){
                if(lista_de_productos[i][j]->producto_repetido == 0){
                    lista_de_productos[i][j]->producto_agotado = 1;
                }
            }
            else {
                lista_de_productos[i][j]->producto_agotado = 0;
            }
        }
    }
    
    
    for(i=0; i<25; i++){
        for(j=0; j<lista_de_productos_repetidos[i]->cantidad_de_pilas; j++){
            
            if(lista_de_productos_repetidos[i]->cantidad==0){
                lista_de_productos_repetidos[i]->puntero_a_pilas[j]->producto_agotado = 1;
            }
            else{
                lista_de_productos_repetidos[i]->puntero_a_pilas[j]->producto_agotado = 0;
            }
        }
    }
    
    
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(lista_de_productos[i][j]->producto_agotado == 0 && lista_de_productos[i][j]->mostrar_producto == 1){
                d_comprar_boton[a][b]->setText(lista_de_productos[i][j]->nombre);
                d_comprar_boton[a][b]->show();
                b++;
                if(b==5){
                    b=0;
                    a++;
                    if(a==5){
                        a=0;
                    }
                }
            }
            
        }
    }
}


//-----------Funcion que se ejecuta cada vez que se realiza una compra--------------

void MainWindow::d_comprar_slot_dispensar_producto_comprado_y_actualizar_cantidades(){
    
    d_comprar->hide();
    d_comprar_frase1->show();
    d_comprar_temporizador1->start();
    
    int i,j,k,l,m,n,r;
    QString boton;
    QString producto;
    int cantidad_anterior, cantidad;
    cantidad_anterior = 30;
    int r_min = -1;
    int flag =0;
    
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            
            if(sender() == d_comprar_boton[i][j]){
                
                boton = d_comprar_boton[i][j]->text();
                
                for(k=0; k<5; k++){
                    for(l=0; l<5; l++){
                        
                        producto = lista_de_productos[k][l]->nombre;
                        if(QString::compare(boton, producto, Qt::CaseInsensitive) == 0 && flag==0){
                            
                            if(lista_de_productos[k][l]->producto_repetido==1){
                                
                                for(m=0; m<25; m++){
                                    
                                    if(QString::compare(lista_de_productos_repetidos[m]->nombre, producto, Qt::CaseInsensitive) == 0){
                                        
                                        r = m;
                                    }
                                }
                                
                                for(n=0; n<lista_de_productos_repetidos[r]->cantidad_de_pilas; n++){
                                    
                                    cantidad = lista_de_productos_repetidos[r]->puntero_a_pilas[n]->cantidad;
                                    
                                    if(0<cantidad && cantidad<=cantidad_anterior){
                                        r_min = n;
                                        cantidad_anterior=cantidad;
                                    }
                                }
                                lista_de_productos_repetidos[r]->comprar();
                                lista_de_productos_repetidos[r]->puntero_a_pilas[r_min]->comprar();
                                
                            }
                            else{
                                lista_de_productos[k][l]->comprar();
                            }
                            flag=1;
                        }
                    }
                }
            }
        }
    }
}



//---------------------------------------------------------
//--------------------------REBASTECER---------------------
//---------------------------------------------------------


//-----------Funciones que se ejecutan luego de que se presiona algun boton de la ventana restablecer------------------

void MainWindow::d_refill_slot_identificar_la_pila_seleccionada(){
    
    d_refill_nombre->show();
    d_refill->hide();
    
    int i,j;
    
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if(sender() == d_refill_button[i][j]){
                
                fila_boton_refill = i;
                columna_boton_refill = j;
                
                d_refill_mostrar_nombre_de_producto_en_editor_de_texto();
                
                break;
            }
        }
    }
}

void MainWindow::d_refill_mostrar_nombre_de_producto_en_editor_de_texto(){
    
    int i = fila_boton_refill;
    int j = columna_boton_refill;
    
    if(QString::compare(lista_de_productos[i][j]->nombre, tr(" "), Qt::CaseInsensitive) != 0){
        d_refill_nombre_input->setText(lista_de_productos[i][j]->nombre);
    }
    else {
        d_refill_nombre_input->clear();
    }
}



//-----------Funcion que se ejecunta luego de que se ingresa el nombre del producto--------------

void MainWindow::d_refill_slot_guardar_nombre_de_producto_rebastecido(){
    
    d_refill_nombre->hide();
    d_refill_cantidad->show();
    
    int i = fila_boton_refill;
    int j = columna_boton_refill;
    
    lista_de_productos[i][j]->nombre = d_refill_nombre_input->text();
}



//-----------Funciones que se ejecutan luego de que se ingresa la cantidad del producto--------------


void MainWindow::d_refill_slot_guardar_cantidad_de_producto_rebastecido(){
    
    d_refill_cantidad->hide();
    d_refill->show();
    
    int i = fila_boton_refill;
    int j = columna_boton_refill;
    
    lista_de_productos[i][j]->cantidad = d_refill_cantidad_input->text().toInt();
    
    d_refill_cantidad_input->clear();
    
    d_refill_slot_mostrar_atributos_de_producto_rebastecido();
}

void MainWindow::d_refill_slot_mostrar_atributos_de_producto_rebastecido(){
    
    int i = fila_boton_refill;
    int j = columna_boton_refill;
    
    if(QString::compare(lista_de_productos[i][j]->nombre, tr(" "), Qt::CaseInsensitive) == 0){
        d_refill_button[i][j]->setText(d_refill_boton_fila_columna[i][j]);
    }
    else{
        QString refill_boton_nuevo_nombre = d_refill_boton_fila_columna[i][j] + tr("\n") + lista_de_productos[i][j]->nombre + tr("\n") + QString::number(lista_de_productos[i][j]->cantidad) +tr(" unidades");
        d_refill_button[i][j]->setText(refill_boton_nuevo_nombre);
    }
    
}



//-----------Funcion que se ejecuta luego de que se presiona el boton de Finalizar--------------


void MainWindow::d_refill_slot_agrupar_productos_repetidos(){
    
    d_refill->hide();
    d_comprar->show();
    
    int i,j,k,l;
    int repetidos=0;
    int iguales=0;
    int flag1=0;
    int flag2=0;
    int temp=0;
    int temp2=0;
    QString producto1;
    QString producto2;
    
    
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            lista_de_productos[i][j]->producto_repetido = 0;
            lista_de_productos[i][j]->mostrar_producto= 1;
        }
    }
    
    for(i=0; i<25; i++){
        lista_de_productos_repetidos[i]->cantidad_de_pilas=1;
        lista_de_productos_repetidos[i]->cantidad = 0;
        lista_de_productos_repetidos[i]->nombre = tr(" ");
        lista_de_productos_repetidos[i]->producto_repetido = 1;
        
        for(j=0; j<25; j++){
            lista_de_productos_repetidos[i]->puntero_a_pilas[j] = new Producto;
        }
    }
    
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            
            producto1 = lista_de_productos[i][j]->nombre;
            iguales = 0;
            flag2=1;
            flag1=0;
            temp =0;
            temp2=0;
            
            if(lista_de_productos[i][j]->producto_repetido == 0  && QString::compare(producto1, tr(" "), Qt::CaseInsensitive) != 0){
                
                for(k=0; k<5; k++){
                    for(l=0; l<5; l++){
                        
                        if(k!=i || l!=j){
                            
                            producto2 = lista_de_productos[k][l]->nombre;
                            
                            if(QString::compare(producto1, producto2, Qt::CaseInsensitive) == 0 && lista_de_productos[k][l]->producto_repetido == 0){
                                
                                lista_de_productos_repetidos[repetidos]->puntero_a_pilas[iguales+1] = lista_de_productos[k][l];
                                
                                lista_de_productos[k][l]->mostrar_producto = 0;
                                lista_de_productos[k][l]->producto_repetido = 1;
                                
                                temp2 = temp2 +1;
                                
                                lista_de_productos_repetidos[repetidos]->nombre = lista_de_productos[k][l]->nombre;
                                
                                iguales++;
                                flag1=1;
                            }
                            
                            if(flag1==1 &&  flag2==1){
                                lista_de_productos_repetidos[repetidos]->puntero_a_pilas[0] = lista_de_productos[i][j];
                                flag2=0;
                            }
                        }
                    }
                }
                
                if(flag1==1 && flag2==0){
                    lista_de_productos_repetidos[repetidos]->cantidad_de_pilas = temp2+1;
                    repetidos++;
                }
            }
            
            if(iguales==0){
                lista_de_productos[i][j]->producto_repetido = 0;
            }
            else{
                lista_de_productos[i][j]->producto_repetido = 1;
            }
        }
    }
    
    for(i=0;i<25;i++){
        temp = 0;
        for(j=0;j<25;j++){
            temp = temp + lista_de_productos_repetidos[i]->puntero_a_pilas[j]->cantidad;
            lista_de_productos_repetidos[i]->puntero_a_pilas[j]->producto_repetido=1;
        }
        lista_de_productos_repetidos[i]->cantidad = temp;
    }
    
    d_comprar_slot_actualizar_ventana_de_productos_disponibles();
}



//-----------Funciones que se ejecutan luego deingresar correctamente la clave para acceder a la interfaz para rebastecer--------------


void MainWindow::d_refill_slot_verificar_contrasena(){
    QString contrasena = d_refill_contrasena_input->text();
    
    if(QString::compare(contrasena, tr("Password"), Qt::CaseInsensitive) == 0){
        d_refill_actualizar_cantidades_en_ventana_rebastecer();
    }
    else {
        
        d_refill_temporizador1->start();
        d_refill_contrasena->hide();
        d_refill_contrasena_incorrecta->show();
    }
}

void MainWindow::d_refill_actualizar_cantidades_en_ventana_rebastecer(){
    
    d_refill_contrasena->hide();
    d_refill->show();
    d_refill_contrasena_input->clear();
    
    int i,j;
    
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(QString::compare(lista_de_productos[i][j]->nombre, tr(" "), Qt::CaseInsensitive) != 0){
                QString refill_boton_nuevo_nombre = d_refill_boton_fila_columna[i][j] + tr("\n") + lista_de_productos[i][j]->nombre + tr("\n") + QString::number(lista_de_productos[i][j]->cantidad) +tr(" unidades");
                d_refill_button[i][j]->setText(refill_boton_nuevo_nombre);
                d_refill_button[i][j]->show();
            }
        }
    }
}







