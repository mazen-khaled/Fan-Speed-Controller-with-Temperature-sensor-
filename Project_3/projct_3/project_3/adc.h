/*
 ================================================================================================
 Name        : adc.h
 Author      : Mazen khaled
 Description : ADC header file
 Date        : 5/28/2022
 ================================================================================================
 */

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	AREF,AVCC=0x40,Reserved=0x80,int_ref_volt=0xC0
}ADC_ReferenceVolatge;

typedef enum
{
	prescaler_22,prescaler_2,prescaler_4,prescaler_8,prescaler_16,prescaler_32,prescaler_64,prescaler_128
}ADC_Prescaler;

typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
