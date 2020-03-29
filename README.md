# Arduino Interrupcion

**Las interrupciones estan presentes en las comunicaciones**

* Transferencias de datos SPI
* Transferencias de datos I2C
* Transferencias de datos USART

No es posible utilizar el puerto serial durante una interrupcion porque cuando se utiliza una interrupcion detiene todas los procesos existente para atender uno especifico y las comunicaciones se ejecutan en otra una interrupcion.

**Como crear una buena interrupcion**
* Deben ser rapidas
* No debe tener funciones que relentizen el tiempo como ```delay();```
* Cuando cambias una variable fuera de una interrupcion debe estar declarada como volatile

Se debe usar identificar como volatile para modificar variables fuera de una interrupcion ya que indica al compilador que cargue la variable desde la ram y no desde un registro de almacenamiento.

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

NO VERIFICADA.... SOLO COPIADA
* LOW, La interrupción se dispara cuando el pin es LOW.
* CHANGE, Se dispara cuando pase de HIGH a LOW o viceversa.
* RISING, Dispara en el flanco de subida (Cuando pasa de LOW a HIGH).
* FALLING, Dispara en el flanco de bajada (Cuando pasa de HIGH a LOW).
* HIGH, se dispara cuando el pin esta HIGH solo para el modelo due.

chiste... VAYA ESTO ES SOLO UNA COPIA DE UNA PUBLICACION EN INGLES Y MAS ENCIMA CON UNA PESIMA TRADUCCION JAJA FLANCO JAJAJA ESO NO TIENE SENTIDO NO SIGNFICA NADA EN ESPAÑOL LOS QUE HICIERON ESTO TODOS LOS DEMAS LO COPIARON Y HICIERON UN PESIMO TRABAJO JAJAJAJAJA


code the testing:

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
 digitalWrite(led,HIGH);
}

}

void boton()
{
  digitalWrite(led,HIGH);
}
``` 
este codigo no funciono en nada de lo abosulto el digitalwrite(); no cambia el valor de la variable yo pienso que solo declare digitalwrite(); yo le tenia que aver declarado como volatile int estado = digitalwrite(); esto se debe probar ...


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
}
```
este codigo en cambio si funciono en todo codigo la variable para modificarla en la interrupcion la escribi como volatile a lo mejor el codigo anterior no funciono porque toda variable independinte que sea funcion nativa como digitalWrite(); debe estar como una variable modifcable como volatile int cambiar = digitalwrite(); 

No se pueden utilizar variables de librerias porque las variables de la libreria no estan declaradas como volatile y digitalWrite(); 

prueba??? curiosida sin documentacion y que pasa si llamos codigo de una libreria pero en un funcion declarada como volatile como 

```c++
//volatile int estado = 0;
const int led = 3;

void setup()
{
  attachInterrupt(digitalPinToInterrupt(2), boton, LOW);
  pinMode(led, OUTPUT);
}

void loop()
{
  while (true)
  {
    digitalWrite(led, HIGH);
  }

}


void boton()
{
  funcion();
}

volatile funcion()
{
  digitalWrite(led, HIGH);
}


```
