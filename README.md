# Arduino Interrupcion

**Las interrupciones estan presentes en las comunicaciones**

* Transferencias de datos SPI
* Transferencias de datos I2C
* Transferencias de datos USART

No es posible utilizar el puerto serial durante una interrupcion porque cuando se utiliza una interrupcion detiene todas los procesos existente para atender uno especifico y las comunicaciones se ejecutan en otra una interrupcion.

**Como crear una buena interrupcion**
* Deben ser rapidas
* No debe usar funciones que relentizen el tiempo como delay();
* Cuando cambia una variable esta debe estar declarada como Volatile

Se debe usar la palabra Volatile para modificar variables fuera de una interrupcion ya que indica al compilador que cargue la variable desde la ram y no desde un registro de almacenamiento.

Cuando se inicia una interrupcion el temporizador del arduino se detiene hasta que termine la interrupcion esta puede afectar si usted intenta medir el tiempo ya que ese tiempo de la interrupcion no sera incluido.


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

NO VERIFICADA.... SOLO COPIADA
* LOW, La interrupción se dispara cuando el pin es LOW.
* CHANGE, Se dispara cuando pase de HIGH a LOW o viceversa.
* RISING, Dispara en el flanco de subida (Cuando pasa de LOW a HIGH).
* FALLING, Dispara en el flanco de bajada (Cuando pasa de HIGH a LOW).
* HIGH, se dispara cuando el pin esta HIGH solo para el modelo due.


code:

```c++
//volatile int estado = 0;
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
 //se queda sin hacer nada infinitamente
}

}

void boton()
{
  digitalWrite(led,HIGH);
}
``` 
