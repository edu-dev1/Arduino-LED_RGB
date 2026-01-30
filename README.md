# Arduino-LED_RGB
LED RGB.

## Features:
- Easy to use.
- Compatible with Arduino.

## Example of usage:
```c++

#include <led_rgb.h>

Led_RGB my_led(6, 10, 11, false);
int r = 128, g = 0, b = 128;
String colors[] = {"red", "green", "blue", "white"};

void setup() {
  Serial.begin(9600);
}

void loop() {

  my_led.set_color(r, g, b);
  delay(1000);

  for (auto &color : colors){
    my_led.set_color(color);
    delay(1000);
  }

  my_led.off();
  delay(2000);

}
