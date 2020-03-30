# Arduino Interrupcion

**Las interrupciones estan presentes en las comunicaciones**

* Transferencias de datos SPI
* Transferencias de datos I2C
* Transferencias de datos USART

No es posible utilizar el puerto serial durante una interrupcion porque cuando se utiliza una interrupcion detiene todas los procesos existente para atender uno especifico y las comunicaciones se ejecutan en otra una interrupcion.

**Como crear una buena interrupcion**
* Deben ser rapidas
* No debe tener funciones que relentizen el tiempo
* En una interrupcion solo pueden modificar variables cuando son volatile

Se define como volatile para modificar variables fuera de una interrupcion ya que indica al compilador que cargue la variable desde la ram y no desde un registro de almacenamiento.

Cuando se inicia una interrupcion el temporizador del arduino se detiene hasta que termine la interrupcion el tiempo de la interrupcion no sera incluido, las funciones ```delay();``` y ```millis();``` no funcionan dentro de una interrupcion porque trabaja atraves de una interrupcion la intruccion ```delayMicroseconds();``` es la unica que funciona correctamente.


Pines
PLACA	PINES INTERRUPCIONES

Uno, Nano, Mini	
* 2, 3

Mega, Mega2560, MegaADK	
* 2, 3, 18, 19, 20, 21

Micro, Leonardo
* 0, 1, 2, 3, 7

Zero
* Todos los pines digitales excepto el 4

MKR1000
* 0, 1, 4, 5, 6, 7, 8, 9, A1, A2

Due
* Todos los pines digitales

**Interrupcion**
* Inicia una interrupcion ```attachInterrupt()``` 
* Detiene una interrupcion ```detachInterrupt(pin)``` 
* Deshabilita todas las interrupciones ```NoInterrupts()```
* Habilita las interrupciones ```Interrupts()```

**Estados de inicio para una interrupcion**
* LOW, La interrupción inicia cuando el pin esta LOW.
* Existen 5 estados mas solo recomiendo LOW porque es el unico que funciona correctamente


code the final:

```c++
volatile int estado = 0;
const int led = 3;

void setup()
{
attachInterrupt(digitalPinToInterrupt(2),boton,LOW);
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

void boton()
{
  estado = 0;
}

```
