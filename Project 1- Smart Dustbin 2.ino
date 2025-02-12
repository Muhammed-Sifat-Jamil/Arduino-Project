#include <Servo.h>

int distance_Function(int echo, int trig);

Servo myservo;
int echo = 4, trig = 5;

void setup() {
  Serial.begin(9600);         
  myservo.attach(8);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
}

void loop() {
  int distance = distance_Function(echo, trig); 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 30) {
    myservo.write(90);
    delay(2000);
  } else {
    myservo.write(0);
  }

  delay(500);  
}

int distance_Function(int echo, int trig) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH); 
 
  

  float distance = (0.034 * duration) / 2;
  return distance;
}