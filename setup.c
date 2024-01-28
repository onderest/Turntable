#include "header.h"
PWM pwm_motor; 
volatile bool timer_fired = false;
struct repeating_timer timer;
uint16_t executed_interrupts;
void setup()
{
    stdio_init_all();
    gpio_init(LED_TEST);
    gpio_set_dir(LED_TEST, GPIO_OUT);
    
    gpio_init(ENC_SW);					//Initialise a GPIO for (enabled I/O and set func to GPIO_FUNC_SIO)
    gpio_set_dir(ENC_SW,GPIO_IN);
	gpio_disable_pulls(ENC_SW);

    gpio_init(encoder_a_pin);
    gpio_set_dir(encoder_a_pin, GPIO_IN);
    gpio_disable_pulls(encoder_a_pin);

    gpio_init(encoder_b_pin);
    gpio_set_dir(encoder_b_pin, GPIO_IN);
    gpio_disable_pulls(encoder_b_pin);

    gpio_set_irq_enabled_with_callback(ENC_SW, GPIO_IRQ_EDGE_FALL, true, &encoder_callback);
    gpio_set_irq_enabled(encoder_a_pin, GPIO_IRQ_EDGE_FALL, true);
	gpio_set_irq_enabled(encoder_b_pin, GPIO_IRQ_EDGE_FALL, true);
    pwm_motor = new_PWM(motor_pin, pwm_period, clkdiv); //PIN, wrap, divider
    
    
    
    //add_repeating_timer_ms(40, repeating_timer_callback, NULL, &timer);
    
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
    //gpio_put(LED_TEST, 1);
    add_alarm_in_ms(20, alarm_callback, NULL, false);
    //printf("timer fired");
    return true;
}

int64_t alarm_callback(alarm_id_t id, void *user_data) 
{
    //printf("Timer %d fired!\n", (int) id);
    //timer_fired = true;
    //gpio_put(LED_TEST, 0);
    // Can return a value here in us to fire in the future
    return 0;
}