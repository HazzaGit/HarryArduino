//blue cable
const int trigpin = 9;

//green cable
const int echopin = 10;


long duration;
int distance;


void setup() {
  // put your setup code here, to run once:
  //this will be motionsensor sketch
  Serial.begin(9600);

  pinMode(trigpin, OUTPUT);

  pinMode(echopin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  //clear trigpin by setting it to LOW for a clean pulse
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);

  //set trigpin high for 10 microseconds
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);


  //read echopin, returning the sound wave travel time in microseconds
  duration = pulseIn(echopin, HIGH);

  //calculate the distance (speed of sound is 0.034 cm/us)
  distance = duration * 0.034 / 2;

  //print distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("cm");
  Serial.println();

  delay(500);

}
