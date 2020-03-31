# Arduino Interrupcion

**Las interrupciones estan presentes en las comunicaciones**

* Transferencias de datos SPI
* Transferencias de datos I2C
* Transferencias de datos USART

No es posible utilizar el puerto serial durante una interrupcion porque cuando se utiliza una interrupcion detiene todas los procesos existente para atender uno especifico y las comunicaciones se ejecutan en otra una interrupcion.

**Recomendacion para crear una interrupcion**
* Deben ser rapidas
* No deben tener funciones que relentizen el tiempo
* En una interrupcion solo pueden modificar variables cuando estan definidas como volatile

Se define como volatile para modificar variables en una interrupcion ya que indica al compilador que cargue la variable desde la ram y no desde un registro de almacenamiento.

Cuando se inicia una interrupcion el temporizador del arduino se detiene hasta que termine la interrupcion el tiempo de la interrupcion no sera incluido, las funciones ```delay();``` y ```millis();``` no funcionan dentro de una interrupcion porque trabajan atraves de una interrupcion la funcion ```delayMicroseconds();``` es la unica que funciona correctamente.

**Pins disponibles para una interrupcion**

<img src="https://github.com/IDiegoUlises/Arduino-Interrupciones/blob/master/images/pines-para-interrupciones.png" />

**Interrupcion**
* Inicia una interrupcion ```attachInterrupt()``` 
* Detiene una interrupcion ```detachInterrupt(pin)``` 
* Deshabilita todas las interrupciones ```NoInterrupts()```
* Habilita las interrupciones ```Interrupts()```

**Estados de inicio para una interrupcion**
* LOW, la interrupcion inicia cuando el pin esta LOW.
* Existen 5 estados mas recomiendo LOW porque es el unico que funciona correctamente


**Iniciando una Interrupcion**

```c++
volatile int estado = 0;
int led = 13;

void setup()
{
attachInterrupt(digitalPinToInterrupt(2),interrupcion,LOW);
pinMode(led,OUTPUT);
}

void loop()
{
while(true)
{
 digitalWrite(led,estado);
 estado = 1;
}

}

void interrupcion()
{
  estado = 0;
}
```

## Conexion
<img src="https://github.com/IDiegoUlises/Arduino-Interrupciones/blob/master/images/Boton-con-resistencia-externa.png" width="400" height="600" />

## Funcionamiento
![](https://github.com/IDiegoUlises/Arduino-Interrupciones/blob/master/images/Circuito-Interrupcion.gif)
