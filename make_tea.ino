#include <Servo.h>

Servo servo;  // create servo object to control a servo
int minutes_to_steep = 1;
int flag_up = 10;
int flag_down = 90;
int flag_half = 45;
int flag_dunk_low = 65;
int flag_dunk_high = 30;
int raise_and_lower_duration = 8000;

// starting values for loops
int a = 0;
int b = 0;
int c = 0;
int d = 0;
int e = 0;
int i = 0;
int j = 0;
int k = 0;
int s = 0;

void slow_up() {
  for (c = 0; servo.read() > flag_up; c++) {
    servo.write(servo.read() - 1);
    delay(50);
  }
}
void slow_down() {
  for (d = 0; servo.read() < flag_down; d++) {
    servo.write(servo.read() + 1);
    delay(50);
  }
}

void dunk(int steep_duration) {
  double cycles = steep_duration / raise_and_lower_duration;
  // dunk/steep
  for (k = 0; k < cycles; k++) {
    //raise
    for (i = 0; servo.read() >= flag_dunk_high; i++) {
      servo.write(servo.read() - 1);
      delay(100);
    }
    delay(500);
    //lower
    for (j = 0; servo.read() <= flag_dunk_low; j++) {
      servo.write(servo.read() + 1);
      delay(100);
    }
  }
  delay(5000);
}

void soak() {
  for (e = 0; servo.read() <= flag_dunk_low; e++) {
    servo.write(servo.read() + 1);
    delay(100);
  }
}
  void shake() {
    for (s = 0; s <= 3; s++) {
      for (b = 0; b <= 5; b++) {
        servo.write(servo.read() - 10);
        delay(100);
        servo.write(servo.read() + 10);
        delay(100);
      }
      delay(2000);
    }
  }

  void setup() {
    servo.attach(9);  // attaches the servo on pin 9 to the servo object

    // setup() is probably not the proper place for this
    slow_up();
    delay(5000);
    soak();
    delay(5000);
    dunk(35000);
    slow_up();
    delay(5000);
    shake();
  }

  // master loop
  void loop() {
  }
