/*
 ================================================================================================
 Name        : PWM.c
 Author      : Mazen khaled
 Description : Motor header file
 Date        : 5/28/2022
 ================================================================================================
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	clockWise,antiClockWise,stop
}DcMotor_State;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * for setup the direction for the two motor pins through the GPIO driver & stop the motor at the beginning.
 */
void DcMotor_Init(void);

/*
 * Description :
 * send the direction of the motor and it's speed 0 -> 100.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* MOTOR_H_ */
