#include <Servo.h>


//blue cable
const int trigpin = 9;

const int echopin = 10;

long duration;
int distance;

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

const int servopin = 8;

int pos = 0;

int ultrasonicproc() {

  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  //read echopin, returning the sound wave travel time in microseconds
  duration = pulseIn(echopin, HIGH);

  //calculate the distance (speed of sound is 0.034 cm/us)
  distance = duration * 0.034 / 2;
  return distance;
}

void setup() {
  // put your setup code here, to run once:
  //this will be motionsensor sketch
  Serial.begin(9600);

  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  myservo.attach(servopin);
  myservo.write(pos);
}

void loop() {

  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    delay(15);
    distance = ultrasonicproc();
    //print distance to the serial monitor
    Serial.print("Degrees: ");
    Serial.print(pos);
    Serial.print(",");
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print("cm");
    Serial.print(".");
    Serial.println();
  }

  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(15);
    distance = ultrasonicproc();
    //print distance to the serial monitor
    Serial.print("Degrees: ");
    Serial.print(pos);
    Serial.print(",");
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print("cm");
    Serial.print(".");
    Serial.println();
  }

  //print distance to the serial monitor
  Serial.print("Degrees: ");
  Serial.print(pos);
  Serial.print(",");
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("cm");
  Serial.print(".");
  Serial.println();

  //delay(500);
  
  }
