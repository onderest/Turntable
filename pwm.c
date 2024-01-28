#include "header.h"
#include "pwm.h"

PWM new_PWM(const uint8_t GPIO, uint16_t wrap, uint8_t divider)
{
    PWM self;
    //gpio_init(GPIO);
    //gpio_set_dir(GPIO, GPIO_OUT);
    gpio_set_function(GPIO, GPIO_FUNC_PWM);
    self.slice = pwm_gpio_to_slice_num(GPIO);
    self.channel = pwm_gpio_to_channel(GPIO);

    self.wrap = wrap;
    pwm_set_wrap(self.slice, self.wrap);

    self.divider = divider;
    pwm_set_clkdiv(self.slice, (float)self.divider);

    pwm_set_enabled(self.slice, true);
    
    return self;
}

//set pwm to a value from 0-65000
void set_pwm(PWM *self)
{
    static int pwm = 9500;
    
    pwm_set_chan_level(self->slice, self->channel, pwm);
}
/*
void set_pwm(PWM *self)
{
    static int fade = 0;
    static bool going_up = true;
    if (going_up) {
        ++fade;
        if (fade > 255) {
            fade = 255;
            
            going_up = false;
        }
    } else {
        --fade;
        if (fade < 0) {
            fade = 0;
            
            going_up = true;
        }
    }
    sleep_ms(5);
    pwm_set_chan_level(self->slice, self->channel, fade * fade);
}
*/


