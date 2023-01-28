// Servo library is imported
#include<Servo.h>

Servo servo;
int const trigerlid = 6;
int const untrigelid = 5;
void setup(){
{
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
    servo.attach(3);
}
void loop()
{       double duration, distance;
digitalWrite(trigerlid, HIGH);
delay(0.9);
digitalWrite(trigerlid, LOW);
// Measure the pulse input in echo pin
duration = pulseIn(untrigelid, HIGH);
// Distance is half the duration divided by 30
    // 30 has been chosen as an estimation from documentation
distance = (duration/2) / 30;
// if distance less than 0.6 meter and more than 0
if (distance <= 55 && distance >= 0) {
    servo.write(55);
    delay(3000);
} 
else {
    
    servo.write(160);
}

delay(60);
}
{
    when servo.write(55) is called, the servo will move to the position of 55 degrees.
when servo.write(160) is called, the servo will move to the position of 160 degrees.
print(open);
} 
else {
    print(closed);
}
}
