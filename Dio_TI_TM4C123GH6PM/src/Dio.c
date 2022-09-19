/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
 *        \brief  
 *
 *      \details  
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
#define NUM_CHANNELS_AVILABLE 							8

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static uint32 ports_PaseAddress[] = {
	GPIOB_BASE,
	GPIOA_BASE,
	GPIOC_BASE,
	GPIOD_BASE,
	GPIOE_BASE,
	GPIOF_BASE
};
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/



/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel ( Dio_ChannelType ChannelId )        
* \Description     : Reads channel value
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId   ID of DIO channel                     
* \Parameters (out): Dio_LevelType                                                      
* \Return value:   : Dio_LevelType  STD_LOW,
																		 STD_HIGH                                  
*******************************************************************************/
Dio_LevelType Dio_ReadChannel ( Dio_ChannelType ChannelId )
{
	volatile Dio_LevelType level ;
	
	uint8 portId = ChannelId / NUM_CHANNELS_AVILABLE;
	volatile uint8 pin = ChannelId % NUM_CHANNELS_AVILABLE;
	
	volatile GPIO_Type * port_Addr = HW_GPIO_REG(ports_PaseAddress[portId]);
	
	level = (Dio_LevelType) ((port_Addr->DATA_Bits[(1<<pin)])>>pin);
	
	return level;
}   

/******************************************************************************
* \Syntax          : void Dio_WriteChannel ( Dio_ChannelType ChannelId, Dio_LevelType Level )        
* \Description     : Writes channel value
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId   ID of DIO channel                     
* \Parameters (out): None                                                      
* \Return value:   : None                                  
*******************************************************************************/
void Dio_WriteChannel ( Dio_ChannelType ChannelId, Dio_LevelType Level )
{
	
	
	uint8 portId = ChannelId / NUM_CHANNELS_AVILABLE;
	volatile uint8 pin = ChannelId % NUM_CHANNELS_AVILABLE;
	
	volatile GPIO_Type * port_Addr = HW_GPIO_REG(ports_PaseAddress[portId]);
	port_Addr->DATA_Bits[(1<<pin)] = (uint32)(Level <<pin);
}


/******************************************************************************
* \Syntax          : Dio_PortLevelType Dio_ReadPort ( Dio_PortType PortId )       
* \Description     : Reads Port value
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : portId   ID of DIO port                    
* \Parameters (out): Dio_PortLevelType                                                      
* \Return value:   : Dio_PortLevelType   uint8                                  
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort ( Dio_PortType portId )
{
	Dio_PortLevelType pLevels;
	
	volatile GPIO_Type * port_Addr = HW_GPIO_REG(ports_PaseAddress[portId]);
	
	pLevels = (uint8) port_Addr->DATA;
	
	return pLevels;
}

/******************************************************************************
* \Syntax          : void Dio_WritePort ( Dio_PortType PortId, Dio_PortLevelType Level );       
* \Description     : writes Port value
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : portId   ID of DIO port
										 Level  	Value to be written                    
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Dio_WritePort ( Dio_PortType portId, Dio_PortLevelType Level )
{
	
	volatile GPIO_Type * port_Addr = HW_GPIO_REG(ports_PaseAddress[portId]);
	
	port_Addr->DATA =  Level;

}

/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
