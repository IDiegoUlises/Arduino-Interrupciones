# Arduino Interrupciones
Cuando se esta realizando un proceso y sucede un imprevisto se debe atender con una interrupcion para detener el proceso actual para saltar a otro.

**Las interrupcion estan presentes en las comunicaciones**

* Transferencias de datos SPI
* Transferencias de datos I2C
* Transferencias de datos USART

No es posible utilizar el puerto serial durante una interrupcion porque cuando se utiliza una interrupcion detiene todas los procesos existente para atender uno especifico y las comunicaciones se ejecutan con una interrupcion.


**Como crear una buena interrupcion**
* Deben ser rapidas
* NO debe usar funciones que relentizen como delay();
* En caso que cambia una variable debe estar asignada como Volatile

Se debe usar la palabra Volatile para modificar variables en una interrupcion ya que indica al compilador que cargue la variable desde la RAM y no desde un registro de almacenamiento, que es una ubicación de memoria temporal donde se almacenan y manipulan las variables del programa.


--Agregar fuentes o sera eliminada en caso que no tenga utilidad.
Proriedad de interrupcion: Pueden ocurrir muchas interrupciones y las interrupcion solo se ejecuta 1 la vez por eso existen las proriedades para elegir que interrupcion se ejecuta primero que la otra debido a su importancia.  
