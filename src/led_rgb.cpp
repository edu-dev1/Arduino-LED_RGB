#include <led_rgb.h>

Led_RGB::Led_RGB(int R_pin, int G_pin, int B_pin, bool common_cathode){
    __R_pin = R_pin;
    __G_pin = G_pin;
    __B_pin = B_pin;
    __common_cathode = common_cathode;
    pinMode(R_pin, OUTPUT);
    pinMode(G_pin, OUTPUT);
    pinMode(B_pin, OUTPUT);
    __state_on = common_cathode ? HIGH : LOW;
    __state_off = common_cathode ? LOW : HIGH;
    
}

void Led_RGB::red(){
    
    digitalWrite(__R_pin, __state_on);
    digitalWrite(__G_pin, __state_off);
    digitalWrite(__B_pin, __state_off);
}

void Led_RGB::green(){
    
    digitalWrite(__R_pin, __state_off);
    digitalWrite(__G_pin, __state_on);
    digitalWrite(__B_pin, __state_off);
}

void Led_RGB::blue(){
    
    digitalWrite(__R_pin, __state_off);
    digitalWrite(__G_pin, __state_off);
    digitalWrite(__B_pin, __state_on);
}

void Led_RGB::set_color(int r, int g, int b){

    analogWrite(__R_pin, __common_cathode ? r : (255 - r));
    analogWrite(__G_pin, __common_cathode ? g : (255 - g));
    analogWrite(__B_pin, __common_cathode ? b : (255 - b));
}

void Led_RGB::set_color(String color_name){
    if (color_name == "red"){
        Led_RGB::red();
    }
    else if (color_name == "green"){
        Led_RGB::green();
    }
    else if (color_name == "blue"){
        Led_RGB::blue();
    }
    else if (color_name == "white"){
        Led_RGB::white();
    }
    else{
        Led_RGB::off();
    }
    
}

void Led_RGB::white(){
    digitalWrite(__R_pin, __state_on);
    digitalWrite(__G_pin, __state_on);
    digitalWrite(__B_pin, __state_on);
}

void Led_RGB::off(){
    digitalWrite(__R_pin, __state_off);
    digitalWrite(__G_pin, __state_off);
    digitalWrite(__B_pin, __state_off);
}