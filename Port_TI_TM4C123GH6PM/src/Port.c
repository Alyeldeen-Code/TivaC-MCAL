/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief  Port Configration and Initialzation Driver
 *
 *      \details  The Driver Configure All MCU Ports 
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Port.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
#define GPIO_COMMIT_UNLOCKING_KEY			 0x4C4F434B
#define GPIOPCTL_PIN_FIELD_SIZE 			 4
#define PORTS_AVILABLE_SIZE 					 6
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

static Port_NotificationType Port_NotificationFunction [PORTS_AVILABLE_SIZE];


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
void GPIOA_Handler(void);
void GPIOB_Handler(void);
void GPIOC_Handler(void);
void GPIOD_Handler(void);
void GPIOE_Handler(void);
void GPIOF_Handler(void);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
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
void Port_Init(const Port_ConfigType* ConfigPtr)
{
	
	volatile uint16 i;
	
	for (i=0;i<PORT_ACTIVATED_CHANNELS_SIZE;i++){
		volatile Port_PortType port = ConfigPtr[i].port;
		volatile GPIO_Type* Port_Addr = HW_GPIO_REG(ports_PaseAddress[port]);
	
		volatile Port_PinType pin = ConfigPtr[i].pin;
		volatile Port_PinDirectionType dir = ConfigPtr[i].dir;
		Port_PinModeType pinMode = ConfigPtr[i].mode;
		Port_PinOutCourrentType outCurrent = ConfigPtr[i].outCurrent;
		Port_PinAttachType pinAttach = ConfigPtr[i].pinAttach;
		Port_PinLevelValue pinLevel = ConfigPtr[i].pinLevel;
		Port_PinExternalIntType externalInterrupt = ConfigPtr[i].externalInterrupt;
		
		/*set port Callback function*/
		if(Port_NotificationFunction[port] == ((Port_NotificationType)0) ){
			Port_NotificationFunction[port]  = ConfigPtr[i].portNotification;
		}
		
		if(dir==PORT_PIN_OUT){
			Port_Addr->DIR |= (1<<pin);
			
		}else{
			Port_Addr->DIR &= ~(1<<pin);
		}
		
		
		
		if(pinMode == Port_PinMode_X_DIO){
			Port_Addr->LOCK = GPIO_COMMIT_UNLOCKING_KEY;
			Port_Addr->AFSEL &= ~(1<<pin);
			Port_Addr->DEN |= (1<<pin);
		}else{
			Port_Addr->LOCK =GPIO_COMMIT_UNLOCKING_KEY;
			Port_Addr->CR |= (1<<pin);
			Port_Addr->PCTL |= (unsigned long)(pinMode << (pin * GPIOPCTL_PIN_FIELD_SIZE));
		}
		
		if(outCurrent == PIN_CURRENT_2m){
			Port_Addr->DR2R =(1<<pin);
		}else if(outCurrent == PIN_CURRENT_4m){
			Port_Addr->DR4R =(1<<pin);
		}else if(outCurrent == PIN_CURRENT_8m){
			Port_Addr->DR8R =(1<<pin);
		}
			
		/*setting pin attachment (pullup pulldown opendrain)*/
		if(pinAttach == PULLUP){
			Port_Addr->LOCK = GPIO_COMMIT_UNLOCKING_KEY;
			Port_Addr->CR = (1<<pin);
			Port_Addr->PUR = (1<<pin);
		}else if (pinAttach == PULLDOWN){
			Port_Addr->LOCK = GPIO_COMMIT_UNLOCKING_KEY;
			Port_Addr->CR = (1<<pin);
			Port_Addr->PDR = (1<<pin);
		}
		else if (pinAttach == OPENDRAIN){
			Port_Addr->LOCK = GPIO_COMMIT_UNLOCKING_KEY;
			Port_Addr->CR = (1<<pin);
			Port_Addr->DEN |= (1<<pin);
			Port_Addr->ODR = (1<<pin);
		}
		
		if(pinLevel == PORT_PIN_HIGH ){
				Port_Addr->DATA_Bits[(1<<pin)] = 0xff;
			}else{
				Port_Addr->DATA_Bits[(1<<pin)] = (0U<<pin);
			}
			
	/*External Enterrupt Configration*/
		if(externalInterrupt == PORT_EXT_INT_DISABLE){
			Port_Addr->IM &= ~(1U << pin); 
		}else if(externalInterrupt == PORT_EXT_INT_FALLING){
			Port_Addr->IEV &= ~(1U << pin);
			Port_Addr->IS  &= ~(1U << pin);
			Port_Addr->IBE &= ~(1U << pin);
			Port_Addr->IM  |=  (1U << pin);

		}else if(externalInterrupt == PORT_EXT_INT_RISING){
			Port_Addr->IEV |= (1U << pin);
			Port_Addr->IS  &= ~(1U << pin);
			Port_Addr->IBE &= ~(1U << pin);
			Port_Addr->IM  |=  (1U << pin);


		}else if(externalInterrupt == PORT_EXT_INT_BOTH){
			Port_Addr->IEV &= ~(1U << pin);
			Port_Addr->IS  &= ~(1U << pin);
			Port_Addr->IBE |=  (1U << pin);
			Port_Addr->IM  |=  (1U << pin);

		}
			
		
	}
	
}

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
void Port_EnableNotification(const Port_PortType port, const Port_PinType pin)
{
	volatile GPIO_Type* Port_Addr = HW_GPIO_REG(ports_PaseAddress[port]);
	Port_Addr->IM  |=  (1U << pin);

}

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
void Port_DisableNotification(const Port_PortType port, const Port_PinType pin)
{
	volatile GPIO_Type* Port_Addr = HW_GPIO_REG(ports_PaseAddress[port]);
	Port_Addr->IM  &=  ~(1U << pin);

}

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
void Port_ClearNotification(const Port_PortType port, const Port_PinType pin)
{
	volatile GPIO_Type* Port_Addr = HW_GPIO_REG(ports_PaseAddress[port]);
	Port_Addr->ICR |= (1U<<pin);
}
	
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
Port_NotificationStateType Port_GetNotificationState (const Port_PortType port, const Port_PinType pin)
{
	volatile Port_NotificationStateType state;
	volatile GPIO_Type* Port_Addr = HW_GPIO_REG(ports_PaseAddress[port]);
	state = (Port_NotificationStateType) Port_Addr->MIS & (1<< pin);
	
	return state;
}
	
	
/* PORT handller function */
void GPIOA_Handler(void)
{
	Port_NotificationFunction[0]();
}

void GPIOB_Handler(void)
{
	Port_NotificationFunction[1]();
}

void GPIOC_Handler(void)
{
	Port_NotificationFunction[2]();	
}

void GPIOD_Handler(void)
{
	Port_NotificationFunction[3]();	
}

void GPIOE_Handler(void)
{
	Port_NotificationFunction[4]();
}

void GPIOF_Handler(void)
{
	Port_NotificationFunction[5]();
}


/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/
