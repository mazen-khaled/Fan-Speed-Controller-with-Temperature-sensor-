/*
 ================================================================================================
 Name        : Motor.c
 Author      : Mazen khaled
 Description : Motor driver
 Date        : 5/28/2022
 ================================================================================================
 */

#include "Motor.h"
#include "gpio.h"
#include "PWM.h"
#include "std_types.h"

void DcMotor_Init(void){
	/* configure pin PC0 and PC1 as output pins */
	GPIO_setupPinDirection(PORTB_ID, PIN0_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN1_ID, PIN_OUTPUT);

	/* Motor is stop at the beginning */
	GPIO_writePort(PORTB_ID, LOGIC_HIGH);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	/*speed should be from 0 to 100*/
	/*mapping the % value to 8-bit value*/
	uint8 Con_speed = ((uint16)speed*255)/100;

	Timer0_PWM_Init(Con_speed);

	if(state==clockWise)
	{
		// Rotate the motor --> clock wise
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_HIGH);
	}
	else if(state==antiClockWise)
	{
		// Rotate the motor --> anti-clock wise
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_HIGH);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
	}
	else if(state==stop)
	{
		// Stop the motor
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
	}
}
