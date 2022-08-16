/*
 ================================================================================================
 Name        : PWM.c
 Author      : Mazen khaled
 Description : pulse width modulation header file
 Date        : 5/28/2022
 ================================================================================================
 */

#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * The function responsible for trigger the Timer0 with the PWM Mode.
 */
void Timer0_PWM_Init(uint8 set_duty_cycle);

#endif /* PWM_H_ */
