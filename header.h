#ifndef HEADER_H_
#define HEADER_H_
#include "definitions.h"
#include "pwm.h"

#define motor_pin 25
#define encoder_a_pin 18
#define encoder_b_pin 19
#define ENC_SW 15

#define pwm_period 10000
#define clkdiv 125

#define timer_delay 2000




//#define encoder_pin 17

#define LED_TEST 4



extern PWM pwm_motor;


void setup(void);
void test_blink(void);
void on_pwm_wrap();
int64_t alarm_callback(alarm_id_t id, void *user_data);
bool repeating_timer_callback(struct repeating_timer *t); 
void encoder_callback(uint gpio, uint32_t events);
#endif