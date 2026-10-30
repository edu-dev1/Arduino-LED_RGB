#include "rgbLED.h"

rgb_LED::rgb_LED(uint8_t r, uint8_t g, uint8_t b, bool common_cathode) : __r(r), __g(g), __b(b), __common_cathode(common_cathode){
    pinMode(__r, OUTPUT);
    pinMode(__g, OUTPUT);
    pinMode(__b, OUTPUT);
}
rgb_LED::rgb_LED(const uint8_t pins[3], bool common_cathode) : rgb_LED(pins[0], pins[1], pins[2], common_cathode) {}

void rgb_LED::red(void){
    set_color(255, 0, 0);
}

void rgb_LED::green(void){
    set_color(0, 255, 0);
}

void rgb_LED::blue(void){
    set_color(0, 0, 255);
}

void rgb_LED::white(void){
    analogWrite(__r, __common_cathode ? 255 : 0);
    analogWrite(__g, __common_cathode ? 255 : 0);
    analogWrite(__b, __common_cathode ? 255 : 0);
}

void rgb_LED::set_color(const uint8_t &r, const uint8_t &g, const uint8_t &b){
    analogWrite(__r, __common_cathode ? r : (255 - r));
    analogWrite(__g, __common_cathode ? g : (255 - g));
    analogWrite(__b, __common_cathode ? b : (255 - b));
}

void rgb_LED::set_color(const char* color){
    static const __COLORS COLORS[] = {{"red", &rgb_LED::red}, {"green", &rgb_LED::green}, {"blue", &rgb_LED::blue}, {"white", &rgb_LED::white}};
    void(rgb_LED::*func_ptr)(void) = nullptr;
    for(int c = 0; c < C; c++){
        if(strcmp(color, COLORS[c]._color) == 0){
            func_ptr = COLORS[c].func_ptr;
            break;
        }
    }
    if(func_ptr != nullptr){
        (this->*func_ptr)();

    }
}

void rgb_LED::on(void){
    set_color(255, 255, 255);
}
void rgb_LED::off(void){
    set_color(0, 0, 0);
}
