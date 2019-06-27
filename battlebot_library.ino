int ultraSonicTrigPin = 9;    // Ultrasonic Trigger
int ultraSonicEchoPin = 12;    // Ultrasonic Echo
long ultraSonicDuration, mm;  // Ultrasonic Saved measurements
int infraRedSensorPin = 13; // Line sensor 
int leftSpeedPin = 6;
int rightSpeedPin = 5;
int leftDirectionPin = 7;
int rightDirectionPin = 4;
int leftSpeed = 255;
int rightSpeed = 255;
bool leftDirection = true;
bool rightDirection = true;

void setup() {
 Serial.begin (9600);
 pinMode(ultraSonicTrigPin, OUTPUT);
 pinMode(ultraSonicEchoPin, INPUT);
 pinMode(4, OUTPUT);
 pinMode(leftSpeedPin, OUTPUT);
 pinMode(rightSpeedPin, OUTPUT);
 pinMode(7, OUTPUT);
 pinMode(13, INPUT);
}

void ultraSonicSensorFunction () {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(ultraSonicTrigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(ultraSonicTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultraSonicTrigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(ultraSonicEchoPin, INPUT);
  ultraSonicDuration = pulseIn(ultraSonicEchoPin, HIGH);
 
  // Convert the time into a distance
  mm = (ultraSonicDuration/2) / 2.91;     // Divide by 2.91 to find distance in mm
  Serial.print(mm);
  Serial.print("mm");
  Serial.println();
}

void outOfBounds () {
leftSpeed = 0;
rightSpeed = 0;
motorFunction ();
}

void motorFunction () {
 digitalWrite(leftDirectionPin, leftDirection);
 digitalWrite(rightDirectionPin, rightDirection);
 analogWrite(leftSpeedPin, leftSpeed);
 analogWrite(rightSpeedPin, rightSpeed);
}

void motorAttack () {
leftSpeed = 255;
rightSpeed = 255;
leftDirection = false;
rightDirection = false;
motorFunction ();  
}

void loop() {

ultraSonicSensorFunction ();

 
}
