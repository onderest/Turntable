#include "header.h"
// https://www.digikey.se/en/maker/projects/raspberry-pi-pico-and-rp2040-cc-part-1-blink-and-vs-code/7102fb8bca95452e9df6150f39ae8422

// in build directory to build
// cmake -G "MinGW Makefiles" ..
// make
// gpiopinout

int main()
{
    setup();
    while(true)
    {       
        set_pwm(&pwm_motor);
        //printf("hello\n");
        //test_blink();
    }
}

