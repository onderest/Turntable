#include "header.h"
PWM pwm_motor; 
volatile bool timer_fired = false;
struct repeating_timer timer;
uint32_t executed_interrupts;
void setup()
{
    gpio_init(LED_TEST);
    gpio_set_dir(LED_TEST, GPIO_OUT);
    
    gpio_init(ENCODER);
    gpio_set_dir(ENCODER, GPIO_IN);

    pwm_motor = new_PWM(motor_pin, pwm_period, clkdiv); //PIN, wrap, divider
    
    stdio_init_all();
    
    add_repeating_timer_ms(40, repeating_timer_callback, NULL, &timer);
    
}

void test_blink()
{
    gpio_put(LED_TEST, 1);
    sleep_ms(10);
    gpio_put(LED_TEST, 0);
    sleep_ms(10);
}

bool repeating_timer_callback(struct repeating_timer *t) 
{

    printf("Repeat at %lld\n", time_us_64());
    executed_interrupts++;
    printf("executed_interruts = %d\n", executed_interrupts);
    if(executed_interrupts >= 10000)
        {
            executed_interrupts = 0x00;
        }
    gpio_put(LED_TEST, 1);
    add_alarm_in_ms(20, alarm_callback, NULL, false);
    printf("timer fired");
    return true;
}

int64_t alarm_callback(alarm_id_t id, void *user_data) 
{
    printf("Timer %d fired!\n", (int) id);
    //timer_fired = true;
    gpio_put(LED_TEST, 0);
    // Can return a value here in us to fire in the future
    return 0;
}