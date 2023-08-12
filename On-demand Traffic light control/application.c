/*
 * main.c
 *
 * Created: 8/5/2022 10:22:38 PM
 *  Author: DABOUR
 */

#include "application.h"

volatile trafic_sign_t traffic_car_state = RED_SIGN;

volatile trafic_sign_t traffic_pedestrians_state = RED_SIGN ;

volatile sequance_t sequance;

volatile traffic_mode_t traffic_mode = TRAFFIC_CAR_MODE;

volatile flag_t flag_250ms = FLAG_CLEAR;


void btn_press_func(void)
{
	traffic_mode = TRAFFIC_PEDESTRIANS_MODE;

	if (traffic_car_state == RED_SIGN)
	{
		traffic_pedestrians_state = GREEN_SIGN;
		sequance = SEQUANCE_UPWARD;
		timer_control_sign_reset();
	}
	else if (traffic_car_state == YELLOW_SIGN)
	{
		traffic_pedestrians_state = YELLOW_SIGN;
		sequance = SEQUANCE_DOWNWARD;
	//	timer_control_sign_reset();
	}
	else if (traffic_car_state == GREEN_SIGN)
	{
		traffic_pedestrians_state = YELLOW_SIGN;
		sequance = SEQUANCE_DOWNWARD;
	}
}

void interrrupt_each_5sec (void)
{
	
	if(traffic_mode == TRAFFIC_CAR_MODE)
	{
		if(sequance == SEQUANCE_DOWNWARD)
		{
			traffic_car_state++;
			if(traffic_car_state == GREEN_SIGN) sequance = SEQUANCE_UPWARD;
		}
		else
		{
			traffic_car_state--;
			if(traffic_car_state == RED_SIGN)
			{
				sequance = SEQUANCE_DOWNWARD;
			}
		}
	}
	else if(traffic_mode == TRAFFIC_PEDESTRIANS_MODE)
	{	
		if(sequance == SEQUANCE_DOWNWARD)
		{
			traffic_pedestrians_state++;
			if(traffic_pedestrians_state == GREEN_SIGN) sequance = SEQUANCE_UPWARD;
		}
		else
		{
			traffic_pedestrians_state--;
			if(traffic_pedestrians_state == RED_SIGN)
			{
				sequance = SEQUANCE_DOWNWARD;
			}
		}
	}
	timer_control_sign_reset();
}

void interrrupt_each_250msec (void)
{
	flag_250ms ^= (1 << 0);
	
	fast_timer_reset();
}

int main(void)
{
	application_intialize();
    while(1)
    {
		if(traffic_mode == TRAFFIC_CAR_MODE)
		{
			pedestrians_red_sign();
			switch(traffic_car_state)
			{
				case RED_SIGN:
					car_red_sign();
					while (traffic_car_state == RED_SIGN && traffic_mode == TRAFFIC_CAR_MODE );		
					break;
					
				case YELLOW_SIGN:
					fast_timer_enable();
					while (traffic_car_state == YELLOW_SIGN && traffic_mode == TRAFFIC_CAR_MODE){
						car_yellow_sign();
					}
					fast_timer_disable();
					break;
					
				case GREEN_SIGN:
					car_green_sign();
					while (traffic_car_state == GREEN_SIGN && traffic_mode == TRAFFIC_CAR_MODE);
					break;
			}
		}
		else if(traffic_mode == TRAFFIC_PEDESTRIANS_MODE)
		{
			push_button_interrupted_disable();
			switch(traffic_pedestrians_state)
			{
				case GREEN_SIGN:
					
					pedestrians_green_sign();
					car_red_sign();
					while (traffic_pedestrians_state == GREEN_SIGN && traffic_mode == TRAFFIC_PEDESTRIANS_MODE);		// wait to interrupt
					
					break;
					
				case YELLOW_SIGN:
					fast_timer_enable();
					while (traffic_pedestrians_state == YELLOW_SIGN ){												// wait to interrupt and blinking yellow led every 250ms
						pedestrians_yellow_sign();																
						car_yellow_sign();
					}
					fast_timer_disable();
					break;
				
				case RED_SIGN:
					pedestrians_red_sign();																		
					car_green_sign();
					traffic_mode = TRAFFIC_CAR_MODE;
					sequance = SEQUANCE_UPWARD;
					traffic_car_state = GREEN_SIGN;
					
					/* end of pedestrian mode */
					push_button_interrupted_enable();
					
					break;
			}
		}
	}
}

void application_intialize(void)
{	
	/* car's traffic light LEDs initializations */
	traffic_car_signs_initialization();
	
	/* pedestrians request button initialization */
	pedestrians_button_initialization();
	
	/* pedestrians traffic light LEDs initializations */
	traffic_pedestrians_signs_initialization();
	
	/* Set functions happen when interrupt evens */
	ext0_set_call_back (btn_press_func);
	int_timer1_set_call_back (interrrupt_each_5sec);
	int_timer0_set_call_back (interrrupt_each_250msec);
	
	/* enable global interrupt to  make the system sensitive to any interrupt request */
	global_interrupt_enable();
	
	/* make pedestrians button in interrupt case */
	push_button_interrupted_enable();
	
	/* enable timer interrupt each 5sec to control the traffic */
	timer_control_sign_enable();
}
