#include <Servo.h>

Servo servo;  // create servo object to control a servo
int start_delay = 5000;
int minutes_to_steep = .5;
int servo_max_angle = 2; // max angle of the flag
int servo_min_angle = 85; // min angle of the flag

int flag_left = servo_max_angle + 5;
int flag_right = servo_max_angle - 5;

int a = 0;
int i = 0;
int j = 0;
int k = 0;
int starttime = 0;

void setup() {
  servo.attach(9);  // attaches the servo on pin 9 to the servo object
  servo.write(servo_max_angle); // set to min angle/lower tea bag.
  delay(start_delay);
}

void loop() {
  
//  lower 
    for(i = 0; servo.read() <= 85; i ++){
        servo.write(i);
        delay(75); 
    }
delay(5000);
//  dunk/steep
  for(a = 0; a <= minutes_to_steep * 2; a += 1){
    for(j = 0; j <= 20; j += 1){
        servo.write(servo_min_angle -= 1);
        delay(350);
    }
    for(k = 0; k <= 20; k += 1){
      servo.write(servo_min_angle += 1);
      delay(350);
    }
    delay(3000);
  }
//   rise up
servo.write(servo_max_angle);
//shake
delay(3000);
for(i = 0; i <= 3; i += 1){
    for(j = 0; j <= 5; j += 1){
        servo.write(flag_left);
        delay(50);
        servo.write(flag_right);
        delay(50);
    }
    delay(3000);
   }
   delay(160000);
}
