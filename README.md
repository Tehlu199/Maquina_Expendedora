

En este repositorio se encuentran todos los archivos del prototipo del software de una máquina expendedora, como parte de la tarea de diseño final del curso de Sistemas Incrustados de la Escuela de Ingeniería Eléctrica de la Universidad de Costa Rica.

El software consiste en una interfaz gráfica de usuario para la compra y reabastecimiento de los productos a través de una pantalla táctil LCD ubicado en el lateral derecho de la máquina. Además, el software se encarga de monitorear el estado de la máquina: envía un mensaje cuando se compra un producto y también cuando se agota. Este prototipo se implementó en el lenguaje de programación C++, usando la IDE multiplataforma llamada QT Creator, mediante el uso de bibliotecas QT para la interfaz y el uso del protocolo MQTT para el trasiego de mensajes. 

NOTAS IMPORTANTES: 

-En el siguiente link se encuentra un video donde se explica con detalle el funcionamiento del prototipo: https://youtu.be/EWj1rU2oqBI

-Cuando ejecute el programa por primera vez, se asume que la maquina expendedora esta vacia y que entonces no hay ni un solo producto disponible. Por lo tanto, tiene que proceder a llenar la maquina expendedora de nuevos productos, tal y como en el video. 

-La clave para acceder a la interfaz de rebastecimiento de productos es "Password", tal y como en el video.

-Los mensajes se publican en el topico general/maquina_expendedora_sebas_santi, a traves del servirdor de mosquitto 64.227.111.82, con puerto 1884. Entonces, se usa la siguiente linea para publicar: 

                 -> mosquitto_pub -h 64.227.111.82 -p 1884 -t general/maquina_expendedora_sebas_santi -m "Mensaje"
 
 y se puede utilizar la siguiente linea para subscreibirse y recibir los mensajes: 

                 -> mosquitto_sub -h 64.227.111.82 -p 1884 -t general/maquina_expendedora_sebas_santi



 
