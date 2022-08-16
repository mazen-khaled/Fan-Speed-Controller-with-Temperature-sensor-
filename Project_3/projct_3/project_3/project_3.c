/*
 ================================================================================================
 Name        : project_3.c
 Author      : Mazen khaled
 Description : Test the ADC driver designed with polling technique using LM35 Temperature Sensor
 Date        : 5/28/2022
 ================================================================================================
 */

#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "Motor.h"

int main(void)
{
	const ADC_ConfigType Config = {int_ref_volt,prescaler_8};
	uint8 temp;
	LCD_init(); /* initialize LCD driver */

	ADC_init(&Config); /* initialize ADC driver */
	DcMotor_Init(); /* initialize ADC driver */

	/* Display this string "Temp =   C" only once on LCD at the first row */
	LCD_displayString("Temp =    C");

	while(1)
	{
		temp = LM35_getTemperature();
		/* Display the temperature value every time at same position */
		LCD_moveCursor(0,7);
/*-------------------------------------------LCD DISPLAY-------------------------------------------*/
		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
/*--------------------------------------------motor actions----------------------------------------*/
		if (temp < 30 ){
			DcMotor_Rotate(stop,0);//stop the motor
		}
		else if(temp>=30 && temp<60){
			DcMotor_Rotate(clockWise,25);//the motor work with 25% of it's speed
		}
		else if(temp>=60 && temp<90){
			DcMotor_Rotate(clockWise,50);//the motor work with 50% of it's speed
		}
		else if(temp>=90 && temp<120){
			DcMotor_Rotate(clockWise,75);//the motor work with 75% of it's speed
		}
		else if(temp>=120){
			DcMotor_Rotate(clockWise,100);//the motor work with it's full speed
		}
	}
}
