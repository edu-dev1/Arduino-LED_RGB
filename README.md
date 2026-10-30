# Arduino-LED_RGB
LED RGB.

## Features:
- Easy to use.
- Compatible with Arduino.

## Example of use:
```c++
#include <rgbLED.h>

uint8_t led_pins[] = {11, 9, 3};
bool common_cathode = false;
rgb_LED led(11, 9, 3, common_cathode);

void setup() {}

void loop() {
  led.on();
  delay(1000);
  led.off();
  delay(1000);
}
```
