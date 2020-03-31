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
