/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio.h
 *       Module:  Dio
 *
 *  Description:  header file for Dio Module    
 *  
 *********************************************************************************************************************/
#ifndef Dio_H
#define Dio_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Platform_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef uint8 Dio_ChannelType;
typedef enum {
	DIO_CHANNEL_A0,
	DIO_CHANNEL_A1,
	DIO_CHANNEL_A2,
	DIO_CHANNEL_A3,
	DIO_CHANNEL_A4,
	DIO_CHANNEL_A5,
	DIO_CHANNEL_A6,
	DIO_CHANNEL_A7,
	
	DIO_CHANNEL_B0,
	DIO_CHANNEL_B1,
	DIO_CHANNEL_B2,
	DIO_CHANNEL_B3,
	DIO_CHANNEL_B4,
	DIO_CHANNEL_B5,
	DIO_CHANNEL_B6,
	DIO_CHANNEL_B7,
	
	DIO_CHANNEL_C0,
	DIO_CHANNEL_C1,
	DIO_CHANNEL_C2,
	DIO_CHANNEL_C3,
	DIO_CHANNEL_C4,
	DIO_CHANNEL_C5,
	DIO_CHANNEL_C6,
	DIO_CHANNEL_C7,
	
	DIO_CHANNEL_D0,
	DIO_CHANNEL_D1,
	DIO_CHANNEL_D2,
	DIO_CHANNEL_D3,
	DIO_CHANNEL_D4,
	DIO_CHANNEL_D5,
	DIO_CHANNEL_D6,
	DIO_CHANNEL_D7,
	
	DIO_CHANNEL_E0,
	DIO_CHANNEL_E1,
	DIO_CHANNEL_E2,
	DIO_CHANNEL_E3,
	DIO_CHANNEL_E4,
	DIO_CHANNEL_E5,
	DIO_CHANNEL_E6,
	DIO_CHANNEL_E7,
	
	DIO_CHANNEL_F0,
  DIO_CHANNEL_F1,
	DIO_CHANNEL_F2,
	DIO_CHANNEL_F3,
	DIO_CHANNEL_F4,
	DIO_CHANNEL_F5,
	DIO_CHANNEL_F6,
	DIO_CHANNEL_F7,

}CHANNELS;

typedef uint8 Dio_PortLevelType;

typedef uint8 Dio_PortType;

typedef enum {
	DIO_PORTA =0 , 
	DIO_PORTB, 
	DIO_PORTC, 
	DIO_PORTD, 
	DIO_PORTE, 
	DIO_PORTF
}DIO_PORTS;

typedef enum{
	LOW =0 ,
	HIGH
}Dio_LevelType;



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
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
Dio_LevelType Dio_ReadChannel ( Dio_ChannelType ChannelId );

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
void Dio_WriteChannel ( Dio_ChannelType ChannelId, Dio_LevelType Level );
 

/******************************************************************************
* \Syntax          : Dio_PortLevelType Dio_ReadPort ( Dio_PortType PortId )       
* \Description     : Reads Port value
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortId   ID of DIO port                    
* \Parameters (out): Dio_PortLevelType                                                      
* \Return value:   : Dio_PortLevelType   uint8                                  
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort ( Dio_PortType PortId );

/******************************************************************************
* \Syntax          : void Dio_WritePort ( Dio_PortType PortId, Dio_PortLevelType Level );       
* \Description     : writes Port value
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortId   ID of DIO port
										 Level  	Value to be written                    
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Dio_WritePort ( Dio_PortType PortId, Dio_PortLevelType Level );
#endif  /* Dio_H */

/**********************************************************************************************************************
 *  END OF FILE: Dio.h
 *********************************************************************************************************************/
