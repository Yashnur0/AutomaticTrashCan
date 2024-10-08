#include <Servo.h> 

Servo servo;  // Create a Servo object
int const trigerlid = 6;  // Pin for trigger
int const untrigelid = 5;  // Pin for echo

void setup() {
  pinMode(trigerlid, OUTPUT);  // Setting trigger pin as output
  pinMode(untrigelid, INPUT);  // Setting echo pin as input
  servo.attach(3);  // Attaching the servo to pin 3
  
  //initiallizing the serial communication
  Serial.begin(9600);  
}

void loop() {
  double duration, distance;

  // Triggering the ultrasonic sensor
  digitalWrite(trigerlid, HIGH);  
  delayMicroseconds(10);  // Triggering pulse for 10 microseconds
  digitalWrite(trigerlid, LOW);

  // Measuring the duration of the pulse returned
  duration = pulseIn(untrigelid, HIGH, 38000); // 38ms = 38,000 microseconds

  // Calculating the distance in cm
  distance = (duration / 2) / 30;

  // If the distance is less than or equal to 55 cm, open the lid
  if (distance <= 55 && distance >= 0) {
    servo.write(90);  // Moving the servo to 90 degrees (open)
    delay(4000);  // Keeping the lid open for 4 seconds

    Serial.println("Lid is open");  // Printing the state to the serial monitor
  } else {
    servo.write(160);  // Moving the servo to 160 degrees (closed)
    Serial.println("Lid is closed");  // Print the state to the serial monitor
  }

  delay(60);  // Short delay before taking the next reading
}
