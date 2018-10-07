int enablePin = 11;
int in1Pin = 10;
int in2Pin = 9;
int butonPin = 7;
int potPin = 0;

void setup()
{
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(butonPin, INPUT);
}

void loop()
{
  int hiz = analogRead(potPin) / 4;
  boolean ters = digitalRead(butonPin);
  motorCalistir(hiz, ters);
}

void motorCalistir(int hiz, boolean ters)
{
  analogWrite(enablePin, hiz);
  digitalWrite(in1Pin, ! ters);
  digitalWrite(in2Pin, ters);
}
