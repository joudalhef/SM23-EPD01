int pushButton = 0;

void setup() 
{
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
}
void loop() 
{
  pushButton = digitalRead(2);
  if (pushButton == HIGH) {
    digitalWrite(13, HIGH);
  }
  else{
    digitalWrite(13, LOW);
  }
  delay(10);
}