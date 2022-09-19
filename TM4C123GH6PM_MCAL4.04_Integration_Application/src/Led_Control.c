/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Led_Control.c
 *        \brief  
 *
 *      \details  that Module provide HAL to Controll the Led on board  
 *	
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Led_Control.h"
#include "Led_Control_Cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define TIMER0A_CLOCK_IN_KHz 1000UL 


/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static volatile uint8 led_state = STD_HIGH;
static volatile uint8 update = STD_ACTIVE;

static volatile uint8 OnTime_Togle = LED_ON_TIME_INIT;
static volatile uint8 OffTime_Togle = LED_OFF_TIME_INIT;


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern const Gpt_ConfigType Gpt_Config[GPT_ACTEVATED_TIMERS_SIZE];
extern const Port_ConfigType Port_Config[PORT_ACTIVATED_CHANNELS_SIZE];

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Timer1A_Notification(void);
void PortF_Notification(void);

void Togle_Led (uint8 OnTime, uint8 OffTime);


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void Init_Led (void)      
* \Description     : Initializing the timer and gpio needed for led                                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None 
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void Led_Control_Init (void)
{
	IntCrtl_Init();
		
	Port_Init(Port_Config);
	
	Gpt_Init(Gpt_Config);
	Gpt_EnableNotification(GPT_TIMER0);
	
}

/******************************************************************************
* \Syntax          : Togle_Led_Run (void)      
* \Description     : callint That function in will main loop to run the led Togle App                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : None                               
*******************************************************************************/
void Led_Control_TogleRun (void){
	
	Togle_Led (OnTime_Togle, OffTime_Togle);

}

/******************************************************************************
* \Syntax          : void Togle_Led (uint8 OnTime, uint8 OffTime)      
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : OnTime   (Led On time in second)  
										 OffTime   (Led Off time in second)
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void Togle_Led (uint8 OnTime, uint8 OffTime)
{	
		if(update == STD_ACTIVE){
	
			if(led_state == STD_LOW){
			Dio_WriteChannel(ACTIVE_LED,HIGH);
			Gpt_StartTimer(GPT_TIMER0,OnTime*TIMER0A_CLOCK_IN_KHz*1000);   /*To convert the tick to sec (mul by TIMER_CLOCK_1MZ)*/
			}else if(led_state == STD_HIGH){
			Dio_WriteChannel(ACTIVE_LED,LOW);
			Gpt_StartTimer(GPT_TIMER0,OffTime*TIMER0A_CLOCK_IN_KHz*1000);
			
			}
			update = STD_IDLE;
	}
}



void Timer1A_Notification(){
	update = STD_ACTIVE;
	if(led_state == STD_HIGH){
		led_state = STD_LOW;
	}else if (led_state == STD_LOW){
		led_state = STD_HIGH;
	} 
		
}


void PortF_Notification(void)
{
	if(Port_GetNotificationState(PORTF,PIN0)){
		volatile uint8 time = (OnTime_Togle % MAX_ON_OFF_SEC)== 0 ? 1 : OnTime_Togle+1;
		Port_ClearNotification(PORTF, PIN0);
		OnTime_Togle = time  ;
		//OnTime_Togle = 5;
	}
	if(GPIOF->MIS & (1U<<4U)){
		Port_ClearNotification(PORTF, PIN4);
		OffTime_Togle = ((OffTime_Togle % MAX_ON_OFF_SEC)==0)? 1 : OffTime_Togle+1 ;
	}
}

/**********************************************************************************************************************
 *  END OF FILE: Led.c
 *********************************************************************************************************************/
