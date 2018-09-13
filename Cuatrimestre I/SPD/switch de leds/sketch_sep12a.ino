void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(3, INPUT);
}

void loop()
{
  digitalWrite(13, digitalRead(3));
  digitalWrite(12, 1 - digitalRead(3));
}
