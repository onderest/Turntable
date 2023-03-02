#include "header.h"
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

