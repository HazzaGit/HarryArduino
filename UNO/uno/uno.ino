void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*int val = analogRead(A0);  // A0 with nothing connected — picks up noise
  Serial.println(val);
  delay(500);*/
  digitalWrite(13, HIGH);
  Serial.println("light is on");
  delay(800);
  digitalWrite(13, LOW);
  Serial.println("light is off");
  delay(200);
  digitalWrite(13, HIGH);
  Serial.println("light is on");
  delay(200);
  digitalWrite(13, LOW);
  Serial.println("light is off");
  delay(200);
  digitalWrite(13, HIGH);
  Serial.println("light is on");
  delay(200);
  digitalWrite(13, LOW);
  Serial.println("light is off");
  delay(800);
}
