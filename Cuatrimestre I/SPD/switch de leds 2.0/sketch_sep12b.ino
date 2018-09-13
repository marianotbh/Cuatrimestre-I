#define STATE_ON 1
#define STATE_OFF 2

int state = STATE_OFF;
int lecturaAnterior = 0;

void setup()
{
  Serial.begin(9600);
  
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(3, INPUT);
}

void loop()
{
  int lectura = digitalRead(3);
  
  if(lectura == HIGH && lecturaAnterior == 0)
  {
    if(state == STATE_OFF) 
      state = STATE_ON;
    else 
      state = STATE_OFF;
  }

  lecturaAnterior = lectura;

  switch(state)
  {
    case STATE_ON: 
    on();
    break;
    case STATE_OFF:
    off();
    break;
  }
}

void on() 
{
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  Serial.print("Enciendo la placa \n");
}

void off() 
{
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  Serial.print("Apago la placa \n");
}

