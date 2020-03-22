# Arduino Interrupciones
Cuando el arduino esta realizando una accion infinita esta no permite que se ejecute otra acciones podemos usar una interrupcion para salir de una accion infinita para realizar otra accion.

Las interrupciones deben ser lo mas cortas posibles ya que todo el arduino se detiene para atender una sola funcion

se puede utilizar la intruccion  parar delay(); dentro de una interrupcion pero es recomendable no utilizarla 

Una interrupcion afecta el temporizador interno del arduino es decir cuando sucede una excepcion este temporizador interno dentro del arduino se congela vuelve a contar cuando termina la interrupcion.

Las interrupcion estan presentes en las comunicaciones

* Transferencias de datos SPI
* Transferencias de datos I2C
* Transferencias de datos USART

Por esta razon nose puede utilizar el puerto serial en una interrupcion porque cuando se utiliza una interrupcion bloquea todas las demas interrupciones y la comunicacion serial es una interrupcion.

