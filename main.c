#include "header.h"
// https://www.digikey.se/en/maker/projects/raspberry-pi-pico-and-rp2040-cc-part-1-blink-and-vs-code/7102fb8bca95452e9df6150f39ae8422

// in build directory to build
// cmake -G "MinGW Makefiles" ..
// make
// gpiopinout
/* Encoder Callback*/
/*
        "LEVEL_LOW",  // 0x1
        "LEVEL_HIGH", // 0x2
        "EDGE_FALL",  // 0x4
        "EDGE_RISE"   // 0x8
*/

void encoder_callback(uint gpio, uint32_t events) 
{
	
	uint32_t gpio_state = 0;

	//gpio_state = (gpio_get_all() >> 10) & 0b0111;  	// get all GPIO them mask out all but bits 10, 11, 12
													// This will need to change to match which GPIO pins are being used.
    gpio_state = (gpio_get_all() & (1<<18 | 1<<19 | 1<<15)) >> 18;
	
	static bool ccw_fall = 0;  //bool used when falling edge is triggered
	static bool cw_fall = 0;
	
	uint8_t enc_value = 0;
	enc_value = (gpio_state & 0x03);

	
	if (gpio == encoder_a_pin) 
	{
		if ((!cw_fall) && (enc_value == 0b10)) // cw_fall is set to TRUE when phase A interrupt is triggered
			cw_fall = 1; 

		if ((ccw_fall) && (enc_value == 0b00)) // if ccw_fall is already set to true from a previous B phase trigger, the ccw event will be triggered 
		{
			cw_fall = 0;
			ccw_fall = 0;
			//do something here,  for now it is just printing out CW or CCW
			printf("CCW \r\n");
		}

	}	


	if (gpio == encoder_b_pin) 
	{
		if ((!ccw_fall) && (enc_value == 0b01)) //ccw leading edge is true
			ccw_fall = 1;

		if ((cw_fall) && (enc_value == 0b00)) //cw trigger
		{
			cw_fall = 0;
			ccw_fall = 0;
			//do something here,  for now it is just printing out CW or CCW
			printf("CW \r\n");
		}

	}
	
}

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

