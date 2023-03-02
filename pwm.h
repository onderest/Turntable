#ifndef PWM_H_
#define PWM_H_

typedef struct PWM
{
    uint8_t GPIO;
    uint8_t slice;
    uint16_t wrap;
    uint8_t divider;
    uint8_t channel;

} PWM;

PWM new_PWM(const uint8_t GPIO, 
uint16_t wrap, uint8_t divider);
void set_pwm(PWM *self );

#endif