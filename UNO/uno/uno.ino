void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(LED_BUILTIN, HIGH);
  
  delay(500);

  digitalWrite(LED_BUILTIN, LOW);
  
  delay(500);
  
  /*digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("light is on");
  delay(800);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("light is off");
  delay(200);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("light is on");
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("light is off");
  delay(200);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("light is on");
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("light is off");
  delay(800);*/
}
