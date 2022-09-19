/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu.h
 *       Module:  
 *
 *  Description:     
 *  
 *********************************************************************************************************************/
#ifndef MCU_H
#define MCU_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Cfg.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*actevated clock gate ids*/

#define MCU_ACTIVATE_TIMER0_CLOCK 					0X010
#define MCU_ACTIVATE_TIMER1_CLOCK 					0X011
#define MCU_ACTIVATE_TIMER2_CLOCK 					0X012
#define MCU_ACTIVATE_TIMER3_CLOCK 					0X013
#define MCU_ACTIVATE_TIMER4_CLOCK 					0X014
#define MCU_ACTIVATE_TIMER5_CLOCK 					0X015



#define MCU_ACTIVATE_GPIOA_CLOCK 					0X020
#define MCU_ACTIVATE_GPIOB_CLOCK 					0X021
#define MCU_ACTIVATE_GPIOC_CLOCK 					0X022
#define MCU_ACTIVATE_GPIOD_CLOCK 					0X023
#define MCU_ACTIVATE_GPIOE_CLOCK 					0X024
#define MCU_ACTIVATE_GPIOF_CLOCK 					0X025

#define MCU_ACTIVATE_WTIMER0_CLOCK 					0X170
#define MCU_ACTIVATE_WTIMER1_CLOCK 					0X171
#define MCU_ACTIVATE_WTIMER2_CLOCK 					0X172
#define MCU_ACTIVATE_WTIMER3_CLOCK 					0X173
#define MCU_ACTIVATE_WTIMER4_CLOCK 					0X174
#define MCU_ACTIVATE_WTIMER5_CLOCK 					0X175



typedef enum
{
	MCU_CLOCK_SOURCE_MOSC,
	MCU_CLOCK_SOURCE_PIOSC,
	MCU_CLOCK_SOURCE_PIOSC_DIV4,
	MCU_CLOCK_SOURCE_LFIOSC,
}Mcu_ClockSourceType;

typedef uint32 Mcu_FreqSourceType;

typedef enum {
	MCU_EXTERNAL_RESET          = 1u,
	MCU_POWER_ON_RESET          = 2u,
	MCU_BROWN_OUT_RESET         = 4u,
	MCU_WDT0_RESET		          =	8u,
	MCU_SOFTWARE_RESET	        =	16u,
	MCU_WDT1_RESET              =	32u,
	MCU_MOSC_FAILURE_RESET      = 0x10000uL

}Mcu_RawResetType;

typedef enum
{
	MCU_PLL_STATUS_UNLOCKED,
	MCU_PLL_STATUS_LOCKED
}Mcu_PllStatusType;

typedef uint8 Mcu_ClockType;

typedef uint16 Mcu_ClockGateType;

typedef struct
{
	Mcu_ClockSourceType ClockSource;
	boolean PllEnable;
	Mcu_FreqSourceType Freq_KHz;
	Mcu_ClockGateType *Mcu_ActevatedClockGatePtr;
}Mcu_ConfigType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void Mcu_Init ( const Mcu_ConfigType* ConfigPtr )        
* \Description     : This service initializes the MCU driver.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr       Pointer to MCU driver configuration set.                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Mcu_Init ( const Mcu_ConfigType* ConfigPtr );

/******************************************************************************
* \Syntax          : void Mcu_PerformReset( void )        
* \Description     : Calling this function cause Reset for the system.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                           
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Mcu_PerformReset(void);


/******************************************************************************
* \Syntax          : Mcu_RawResetType Mcu_GetResetRawValue( void )        
* \Description     : calling that function return  the reset type cause the reset.                                                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                            
* \Parameters (out): None                                                      
* \Return value:   : Mcu_RawResetType   Reset raw value
*******************************************************************************/
Mcu_RawResetType Mcu_GetResetRawValue(void);

/******************************************************************************
* \Syntax          : Mcu_PllStatusType Mcu_GetPllStatus        
* \Description     : Calling this function return the state of PLL.
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : Mcu_PllStatusType  PLL Status
																				MCU_PLL_STATUS_UNLOCKED
																				MCU_PLL_STATUS_LOCKED
*******************************************************************************/
Mcu_PllStatusType Mcu_GetPllStatus(void);

/******************************************************************************
* \Syntax          : Std_ReturnType Mcu_DistributePllClock( void )        
* \Description     : This service activates the PLL clock to the MCU clock distribution.                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                            
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType 
*                    E_OK: Command has been accepted
*                    E_NOT_OK: Command has not been accepted
*******************************************************************************/
Std_ReturnType Mcu_DistributePllClock( void);


/******************************************************************************
* \Syntax          : void Mcu_Init ( const Mcu_ConfigType* ConfigPtr )        
* \Description     : This service initializes the PLL and other MCU specific clock options.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ClockSetting       ClockSetting.                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType 

*******************************************************************************/
Std_ReturnType Mcu_InitClock( Mcu_ClockType ClockSetting);

#endif  /* MCU_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu.h
 *********************************************************************************************************************/
