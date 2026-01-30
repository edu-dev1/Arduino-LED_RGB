#ifndef led_rgb_h
#define led_rgb_h

#include <Arduino.h>
#include <string.h>

class Led_RGB{
    private:
        //Attributes
        int __R_pin;
        int __G_pin;
        int __B_pin;
        bool __common_cathode;
        int __state_on, __state_off;
    
    public:
        //methods
        Led_RGB(int, int, int, bool);
        void red();//The LED lights up red.
        void green();//The LED lights up green.
        void blue();//The LED lights up blue.
        void set_color(int, int, int);//The LED lights up on rgb mode (0-255).
        void set_color(String);//Like "red", "green", "blue" or "white".
        void white();//The LED lights up white.
        void off();//Turns off the LED.
};

#endif