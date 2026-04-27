#include <Wire.h>
#include "Adafruit_TCS34725.h"

#define tcs_led_pin A1

Adafruit_TCS34725 tcs = Adafruit_TCS34725(
  TCS34725_INTEGRATIONTIME_50MS,
  TCS34725_GAIN_4X
);

void setup() {
  Serial.begin(9600);

  pinMode(tcs_led_pin, OUTPUT);
  digitalWrite(tcs_led_pin, HIGH); 

  if (tcs.begin()) {
    Serial.println("TCS34725 bulundu!");
  } else {
    Serial.println("Sensör bulunamadı!");
    while (1);
  }
}

void loop() {
  uint16_t r, g, b, c;

  tcs.getRawData(&r, &g, &b, &c);

  Serial.print("R: "); Serial.print(r);
  Serial.print(" G: "); Serial.print(g);
  Serial.print(" B: "); Serial.print(b);
  Serial.print(" C: "); Serial.println(c);

  delay(500);
}
