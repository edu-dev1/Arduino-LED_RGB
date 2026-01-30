# Arduino-LED_RGB
LED RGB.

## Features:
- Easy to use.
- Compatible with Arduino.

## Example of usage:
```c++

#include <led_rgb.h>

/*---Creating the object my_led---*/
int r_pin = 6, g_pin = 10, b_pin = 11;
bool commom_cathode = false;
Led_RGB my_led(r_pin, g_pin, b_pin, common_cathode);

/*---Variables to use later---*/
int r = 255, g = 255, b = 0;//yellow color
String colors[] = {"red", "green", "blue", "white"};

void setup() {
  Serial.begin(9600);
}

void loop() {

  my_led.set_color(r, g, b);//yelow
  delay(1000);

  for (auto &color : colors){
    my_led.set_color(color);//all colors from the colors array
    delay(1000);
  }

  my_led.off();//off led
  delay(2000);

}
