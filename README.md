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

En la interrupcion si quieremos modificar una variable debe estar declarada como Volatile esto significa que esta variable puede cambiar de valor en cualquier momento lo que pasa que el arduino busca esta variable en el registro de memoria temporal y cuando es declarada como volatile le dice que se revisa directamente desde la memoria ram.

Específicamente, indica al compilador que cargue la variable desde la RAM y no desde un registro de almacenamiento, que es una ubicación de memoria temporal donde se almacenan y manipulan las variables del programa. Bajo ciertas condiciones, el valor de una variable almacenada en registros puede ser inexacto.

Una variable debe declararse volátil siempre que su valor pueda ser cambiado por algo más allá del control de la sección de código en la que aparece, como un subproceso que se ejecuta simultáneamente. En Arduino, el único lugar en el que es probable que esto ocurra es en las secciones de código asociadas con las interrupciones, lo que se denomina rutina de servicio de interrupción.
