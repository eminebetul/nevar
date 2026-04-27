#include <Servo.h>

#define mod_pin A0
#define kirmizi_led A2
#define mavi_led A3

#define servo1_pin 12
#define servo2_pin 13
#define servo3_pin 4

Servo servo1;
Servo servo2;
Servo servo3;

bool kirmizi_takim = false;

void setup() {
  pinMode(mod_pin, INPUT);

  pinMode(kirmizi_led, OUTPUT);
  pinMode(mavi_led, OUTPUT);

  servo1.attach(servo1_pin);
  servo2.attach(servo2_pin);
  servo3.attach(servo3_pin);

  servo1.write(90);
  servo2.write(0);
  servo3.write(0);

  int mod_deger = digitalRead(mod_pin);

  kirmizi_takim = (mod_deger == HIGH);

  digitalWrite(kirmizi_led, kirmizi_takim ? HIGH : LOW);
  digitalWrite(mavi_led, kirmizi_takim ? LOW : HIGH);
}

void loop() {
  servo1.write(0);
  delay(1000);
  servo1.write(90);
  delay(1000);
  servo1.write(180);
  delay(1000);

  servo2.write(0);
  delay(1000);
  servo2.write(90);
  delay(1000);
  servo2.write(180);
  delay(1000);

  servo3.write(0);
  delay(1000);
  servo3.write(90);
  delay(1000);
  servo3.write(180);
  delay(1000);
}
