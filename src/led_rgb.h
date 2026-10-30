#ifndef rgbLED
#define rgbLED

#include <Arduino.h>
#define C 4

class rgb_LED{
    private:
        struct __COLORS{
            const char* _color;
            void (rgb_LED::*func_ptr)(void);
        };
        uint8_t __r, __g, __b;
        bool __common_cathode;
    public:
        rgb_LED(uint8_t r, uint8_t g, uint8_t b, bool common_cathode);
        rgb_LED(const uint8_t pins[3], bool common_cathode);
        void red(void);
        void green(void);
        void blue(void);
        void white(void);
        void set_color(const uint8_t &r, const uint8_t &g, const uint8_t &b);
        void set_color(const char* color);
        void on(void);
        void off(void);
};
#endif
