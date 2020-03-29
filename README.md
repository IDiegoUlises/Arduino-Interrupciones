# Arduino Interrupcion

**Las interrupciones estan presentes en las comunicaciones**

* Transferencias de datos SPI
* Transferencias de datos I2C
* Transferencias de datos USART

No es posible utilizar el puerto serial durante una interrupcion porque cuando se utiliza una interrupcion detiene todas los procesos existente para atender uno especifico y las comunicaciones se ejecutan en otra una interrupcion.

**Como crear una buena interrupcion**
* Deben ser rapidas
* No debe tener funciones que relentizen el tiempo como ```delay();```
* En una interrupcion solo pueden modificar variables cuando son volatile

Se define como volatile para modificar variables fuera de una interrupcion ya que indica al compilador que cargue la variable desde la ram y no desde un registro de almacenamiento.

Cuando se inicia una interrupcion el temporizador del arduino se detiene hasta que termine la interrupcion esto afecta si usted intenta medir el tiempo porque el tiempo de la interrupcion no sera incluido.


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

attachInterrupt() para iniciar una interrupcion 

detachInterrupt(pin) detiene una interrupcion

NoInterrupts(), desactiva todas las interrupciones

Interrupts(), reactiva las interrupciones

**Estados de inicio para una interrupcion**
* LOW, La interrupción inicia cuando el pin esta LOW.
* CHANGE, cuando pase de HIGH a LOW o viceversa.
* RISING, cuando pasa de LOW a HIGH.
* FALLING, cuando pasa de HIGH a LOW.
* HIGH, cuando el pin esta en HIGH solo para el modelo due.

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
Durante una inter
