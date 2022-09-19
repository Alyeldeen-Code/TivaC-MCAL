/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  port.h
 *       Module:  prot
 *
 *  Description:  header file for port Module    
 *  
 *********************************************************************************************************************/
#ifndef port_H
#define port_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Port_Cfg.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define Port_PinMode_X_DIO					0
#define Port_PinMode_PA0_U0RX				1
#define Port_PinMode_PA1_U0TX				1
#define Port_PinMode_PA0_CAN1Rx			8
#define Port_PinMode_PA1_CAN1Tx			8
#define Port_PinMode_PA2_SSI0Clk		2
#define Port_PinMode_PA3_SSI0Fss		2
#define Port_PinMode_PA4_SSI0Rx			2
#define Port_PinMode_PA5_SSI0Tx			2
#define Port_PinMode_PA6_I2C1SCL		3
#define Port_PinMode_PA7_I2C1SDA		3
#define Port_PinMode_PA6_M1PWM2			5
#define Port_PinMode_PA7_M1PWM3			5

#define Port_PinMode_PB0_U1Rx				1
#define Port_PinMode_PB1_U1Tx				1
#define Port_PinMode_PB2_I2C0SCL		3
#define Port_PinMode_PB3_I2C0SDA		3
#define Port_PinMode_PB4_SSI2Clk		2
#define Port_PinMode_PB5_SSI2Fss		2
#define Port_PinMode_PB6_SSI2Rx			2
#define Port_PinMode_PB7_SSI2Tx			2
#define Port_PinMode_PB4_M0PWM2			4
#define Port_PinMode_PB5_M0PWM3			4
#define Port_PinMode_PB6_M0PWM0			4
#define Port_PinMode_PB7_M0PWM1			4
#define Port_PinMode_PB4_CAN0Rx			8
#define Port_PinMode_PB5_CAN0Tx			8
#define Port_PinMode_PB0_T2CCP0			7
#define Port_PinMode_PB1_T2CCP1			7
#define Port_PinMode_PB2_T3CCP0			7
#define Port_PinMode_PB3_T3CCP1			7
#define Port_PinMode_PB4_T1CCP0			7
#define Port_PinMode_PB5_T1CCP1			7
#define Port_PinMode_PB6_T0CCP0			7
#define Port_PinMode_PB7_T0CCP1			7

#define Port_PinMode_PC0_TCK_SWCLK	1
#define Port_PinMode_PC1_TMS_SWDIO	1
#define Port_PinMode_PC2_TDI				1
#define Port_PinMode_PC3_TDO_SWO		1	
#define Port_PinMode_PC4_U4Rx				1
#define Port_PinMode_PC5_U4Tx				1
#define Port_PinMode_PC6_U3Rx				1
#define Port_PinMode_PC7_U3Tx				1
#define Port_PinMode_PC4_M0PWM2			4
#define Port_PinMode_PC5_M0PWM3			4
#define Port_PinMode_PC6_M0PWM0			4
#define Port_PinMode_PC7_M0PWM1			4
#define Port_PinMode_PC4_IDX1				6
#define Port_PinMode_PC5_PhA1				6
#define Port_PinMode_PC6_PhB1				6
#define Port_PinMode_PC4_U1RTS			8
#define Port_PinMode_PC5_U1CTS			8
#define Port_PinMode_PC6_USB0EPEN		8
#define Port_PinMode_PC7_USB0PFLT		8
#define Port_PinMode_PC0_T4CCP0			7
#define Port_PinMode_PC1_T4CCP1			7
#define Port_PinMode_PC2_T5CCP0			7
#define Port_PinMode_PC3_T5CCP1			7	
#define Port_PinMode_PC4_WT0CCP0		7
#define Port_PinMode_PC5_WT0CCP1		7
#define Port_PinMode_PC6_WT1CCP0		7
#define Port_PinMode_PC7_WT1CCP1		7

#define Port_PinMode_PD0_SSI3Clk		1
#define Port_PinMode_PD1_SSI3Fss		1
#define Port_PinMode_PD2_SSI3Rx			1
#define Port_PinMode_PD3_SSI3Tx			1
#define Port_PinMode_PD4_U6Rx				1
#define Port_PinMode_PD5_U6Tx				1
#define Port_PinMode_PD6_U2Rx				1
#define Port_PinMode_PD7_U2Tx				1
#define Port_PinMode_PD0_SSI1Clk		2
#define Port_PinMode_PD1_SSI1Fss		2
#define Port_PinMode_PD2_SSI1Rx			2
#define Port_PinMode_PD3_SSI1Tx			2
#define Port_PinMode_PD0_I2C3SCL		3
#define Port_PinMode_PD1_I2C3SDA		3
#define Port_PinMode_PD0_M0PWM6			4
#define Port_PinMode_PD1_M0PWM7			4
#define Port_PinMode_PD2_M0FAULT0		4
#define Port_PinMode_PD0_M1PWM0			5
#define Port_PinMode_PD1_M1PWM1			5
#define Port_PinMode_PD2_USB0EPEN		8
#define Port_PinMode_PD3_USB0PFLT		8
#define Port_PinMode_PD3_IDX0				6
#define Port_PinMode_PD6_PhA0 			6
#define Port_PinMode_PD7_PhB0				6
#define Port_PinMode_PD7_NMI 				8
#define Port_PinMode_PD0_WT2CCP0		7
#define Port_PinMode_PD1_WT2CCP1		7
#define Port_PinMode_PD2_WT3CCP0		7
#define Port_PinMode_PD3_WT3CCP1		7
#define Port_PinMode_PD4_WT4CCP0		7
#define Port_PinMode_PD5_WT4CCP1		7
#define Port_PinMode_PD6_WT5CCP0		7
#define Port_PinMode_PD7_WT5CCP1		7

#define Port_PinMode_PE0_U7Rx				1
#define Port_PinMode_PE1_U7Tx				1
#define Port_PinMode_PE4_U5Rx				1
#define Port_PinMode_PE5_U5Tx				1
#define Port_PinMode_PE4_I2C2SCL		3
#define Port_PinMode_PE5_I2C2SDA		3
#define Port_PinMode_PE4_M0PWM4			4
#define Port_PinMode_PE5_M0PWM5			4
#define Port_PinMode_PE4_M1PWM2			5
#define Port_PinMode_PE5_M1PWM3			5
#define Port_PinMode_PE4_CAN0Rx			8
#define Port_PinMode_PE5_CAN0Tx			8

#define Port_PinMode_PF0_U1RTS		1
#define Port_PinMode_PF1_U1CTS		1
#define Port_PinMode_PF0_SSI1Rx		2
#define Port_PinMode_PF1_SSI1Tx		2
#define Port_PinMode_PF2_SSI1Clk	2
#define Port_PinMode_PF3_SSI1Fss	2
#define Port_PinMode_PF0_CAN0Rx		3
#define Port_PinMode_PF3_CAN0Tx		3
#define Port_PinMode_PF2_M0FAULT0	4
#define Port_PinMode_PF0_M1PWM4		5
#define Port_PinMode_PF1_M1PWM5		5
#define Port_PinMode_PF2_M1PWM6		5
#define Port_PinMode_PF3_M1PWM7		5
#define Port_PinMode_PF4_M1FAULT0	5
#define Port_PinMode_PF0_PhA0			6
#define Port_PinMode_PF1_PhB0			6
#define Port_PinMode_PF4_IDX0			6
#define Port_PinMode_PF0_T0CCP0		7
#define Port_PinMode_PF1_T0CCP1		7
#define Port_PinMode_PF2_T1CCP0		7
#define Port_PinMode_PF3_T1CCP1		7
#define Port_PinMode_PF4_T2CCP0		7
#define Port_PinMode_PF0_NMI			8
#define Port_PinMode_PF4_USB0EPEN	8
#define Port_PinMode_PF0_C0o			9
#define Port_PinMode_PF1_C1o			9
#define Port_PinMode_PF1_TRD1			14
#define Port_PinMode_PF2_TRD0			14
#define Port_PinMode_PF3_TRCLK		14


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum {
	PIN_CURRENT_DEFULT,
	PIN_CURRENT_2m,
	PIN_CURRENT_4m,
	PIN_CURRENT_8m
}Port_PinOutCourrentType;

typedef enum {
	PORTA, 
	PORTB, 
	PORTC, 
	PORTD, 
	PORTE, 
	PORTF
}Port_PortType;

typedef uint8 Port_PinType;

typedef enum {
	PIN0 =0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}PINS;

typedef uint8 Port_PinModeType;


typedef enum {
	PORT_PIN_IN = 0,
	PORT_PIN_OUT = 1
} Port_PinDirectionType;

typedef enum
{
	DEFAULT,
	PULLUP,
	PULLDOWN,
	OPENDRAIN
}Port_PinAttachType;

typedef enum {
	PORT_PIN_LOW,
	PORT_PIN_HIGH
}Port_PinLevelValue;

typedef enum {
	PORT_CLEAR,
	PORT_SET
}Port_NotificationStateType;

typedef enum
{
	PORT_EXT_INT_DISABLE,
	PORT_EXT_INT_RISING,
	PORT_EXT_INT_FALLING,
	PORT_EXT_INT_BOTH,
}Port_PinExternalIntType;

typedef void (*Port_NotificationType)(void);


typedef struct {
	Port_PortType port;
	Port_PinType pin;
	Port_PinLevelValue pinLevel;
	Port_PinDirectionType dir;
	Port_PinModeType mode;
	Port_PinOutCourrentType  outCurrent; 
	Port_PinAttachType pinAttach;
	Port_PinExternalIntType externalInterrupt;
	Port_NotificationType portNotification;
}Port_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
/******************************************************************************
* \Syntax          : void Port_Init(const Port_ConfigType* ConfigPtr)                                      
* \Description     : initialize port Module by parsing the Configuration 
*                    into port registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr  (Pointer to configuration set).
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr);
 
/******************************************************************************
* \Syntax          : void Port_EnableNotification(const Port_PortType port)                                      
* \Description     : Enable port handeler 
*                                                 
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : port  (port number).
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Port_EnableNotification(const Port_PortType port, const Port_PinType pin);

/******************************************************************************
* \Syntax          : void Port_DisableNotification(const Port_PortType port)                                      
* \Description     : Disable port handeler 
*                                                 
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : port  (port number).
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Port_DisableNotification(const Port_PortType port,const Port_PinType pin); 

/******************************************************************************
* \Syntax          : void Port_ClearNotification(const Port_PortType port, const Port_PinType pin)                                      
* \Description     : Clear interrupt flag. 
*                                                 
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : port  (port number)
										 pin   ( pin number)
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Port_ClearNotification(const Port_PortType port, const Port_PinType pin);

/******************************************************************************
* \Syntax          : void Port_GetNotificationState (const Port_PortType port, const Port_PinType pin)                                      
* \Description     : get interrupt state for any pin pin
*                                                 
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : port  (port number)
										 pin   ( pin number)
* \Parameters (out): None                                                      
* \Return value:   : Port_NotificationStateType  PORT_SET
																								 PORT_CLEAR
*******************************************************************************/
Port_NotificationStateType Port_GetNotificationState (const Port_PortType port, const Port_PinType pin);

#endif  /* port_H */

/**********************************************************************************************************************
 *  END OF FILE: port.h
 *********************************************************************************************************************/
