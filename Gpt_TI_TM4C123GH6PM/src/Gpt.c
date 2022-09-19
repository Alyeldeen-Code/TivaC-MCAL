/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Gpt.c
 *        \brief  Gpt Controller Driver
 *
 *      \details  The Driver Configure All Gpt Peripherals
									The Driver Only supported One-Shot/Periodic Timer Mode for Timer (A)
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Gpt.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
 #define GPT_AVAILABLE_NUMBER 							12
 
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
	static uint32 Prescale[GPT_AVAILABLE_NUMBER];
	
	static Gpt_NotificationType Gpt_NotificationFunctions [GPT_AVAILABLE_NUMBER];
	static Gpt_ConfigType Gpt_ConfigredTiemr[GPT_AVAILABLE_NUMBER];
	
	static uint32 Gpt_BaseAddr[GPT_AVAILABLE_NUMBER] = {
	TIMER0_BASE,
	TIMER1_BASE,
	TIMER2_BASE,
	TIMER3_BASE,
	TIMER4_BASE,
	TIMER5_BASE,
	TIMER6_BASE,
	TIMER7_BASE,
	TIMER8_BASE,
	TIMER9_BASE,
	TIMER10_BASE,
	TIMER11_BASE,
};
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern uint32 GlobalSystemClock;

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void TIMER0A_Handler(void);
void TIMER1A_Handler(void);
void TIMER2A_Handler(void);
void TIMER3A_Handler(void);
void TIMER4A_Handler(void);
void TIMER5A_Handler(void);
void WTIMER0A_Handler(void);
void WTIMER1A_Handler(void);
void WTIMER2A_Handler(void);
void WTIMER3A_Handler(void);
void WTIMER4A_Handler(void);
void WTIMER5A_Handler(void);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void Gpt_Init(const Gpt_ConfigType* ConfigPtr[i])                                     
* \Description     : Initializes the GPT driver                                
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr[i]                      
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_Init(const Gpt_ConfigType* ConfigPtr)
{
	/*TODO: Add Support For Predefine Timers*/
	
	
	volatile uint32 i;
	
	#if ( GPT_ACTEVATED_TIMERS_SIZE > GPT_AVAILABLE_NUMBER)
	#error "The Actevated Timer More Than Available!"
	#endif 
	
	for( i =0; i<GPT_ACTEVATED_TIMERS_SIZE; i++){
		uint8 ID = ConfigPtr[i].channelId;

		volatile TIMER_Type* Gpt_Addr = HW_TIMER_REG(Gpt_BaseAddr[ID]);

		Gpt_ConfigredTiemr[ID] = *ConfigPtr;


		
		Gpt_NotificationFunctions[ID] = ConfigPtr[i].gptNotification;
		
		Gpt_Addr->CTL &= (~(1U<<0U));						/*Desable Timer*/
		
		Gpt_Addr->TAMR |=  (ConfigPtr[i].countDir  == GPT_COUNT_UP)?(1<<4U):(0<<4U)  ;   /*set couter dirction*/
		

		/* The only Supported Configration is individual concatenated*/		
		Gpt_Addr->TAMR |=(0<<4U);
		if(ConfigPtr[i].timerMode == GPT_CONCATENATED){
			Gpt_Addr->CFG = 0x0; 
		}else if(ConfigPtr[i].timerMode == GPT_INDIVIDUAL){
			Gpt_Addr->CFG = 0x4; 
		}
		
		if(ConfigPtr[i].channelMode == GPT_MODE_ONESHOT){
			Gpt_Addr->TAMR = 0x1; 						     /* one shotmode*/
		}else{
			Gpt_Addr->TAMR |= (1<<1U);					/*Periodic Timer mode */
		}
		
		Gpt_DisableNotification(ID);
	}
}


/******************************************************************************
* \Syntax          : void Gpt_StartTimer( Gpt_ChannelType Channel, Gpt_ValueType Value );        
* \Description     : Starts a timer channel.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant(but not for the same timer channel)                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel. 
*										 Value		 Target time in number of ticks.
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Gpt_StartTimer( Gpt_ChannelType Channel, Gpt_ValueType Value )
{
	volatile Gpt_ValueType val = Value;
	Gpt_ConfigType gptConfig = Gpt_ConfigredTiemr[Channel];
	volatile TIMER_Type* Gpt_Addr = HW_TIMER_REG(Gpt_BaseAddr[Channel]);
	Gpt_ChannelTickFrequency tickFreq = gptConfig.channelTickFreq;

	uint32 tickMax = Gpt_ConfigredTiemr[Channel].channelTickMaxValue;

	uint32 i ;
	
	volatile uint32 prescale = GlobalSystemClock / tickFreq ;

	for(i=2;;i*=2){
		if(prescale/i == 1){
			
			if(prescale%i <= (i/2))
			{
				prescale = i;
			}
			else
			{
				prescale = i*2;
			}
			break;
		}
	}
	
	Prescale[Channel] = prescale;
	
	if(val > tickMax){
		val = tickMax;
	}
		
	Gpt_Addr->TAILR = val * prescale;
	Gpt_Addr->CTL |=(1<<0U);
	
}

/******************************************************************************
* \Syntax          : void Gpt_StopTimer( Gpt_ChannelType Channel )       
* \Description     : Stops a timer channel.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant (but not for the same timer channel)                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel.                     
* \Parameters (out): None                                                      
* \Return value:   : None                           
*******************************************************************************/
void Gpt_StopTimer( Gpt_ChannelType Channel )
{
	volatile TIMER_Type* Gpt_Addr = HW_TIMER_REG(Gpt_BaseAddr[Channel]);
	Gpt_Addr->CTL &= ~(1U<<0U); /*clear Timer Enable bit*/	

}

/******************************************************************************
* \Syntax          : void Gpt_EnableNotification( Gpt_ChannelType Channel )        
* \Description     : Enables the interrupt notification for a channel (relevant in normal mode).                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant (but not for the same timer channel)                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel.                    
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Gpt_EnableNotification( Gpt_ChannelType Channel )
{
	volatile TIMER_Type* Gpt_Addr = HW_TIMER_REG(Gpt_BaseAddr[Channel]);
	/* Only Support Time Out Interrupt Notification*/
	Gpt_Addr->IMR |= (1U<<0U);
	Gpt_Addr->ICR |= (1<<0U);
	
}



/******************************************************************************
* \Syntax          : void Gpt_DisableNotification( Gpt_ChannelType Channel )        
* \Description     : Reentrant (but not for the same timer channel)                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel.                     
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Gpt_DisableNotification( Gpt_ChannelType Channel )
{
	volatile TIMER_Type* Gpt_Addr = HW_TIMER_REG(Gpt_BaseAddr[Channel]);
	/* Only Support Time Out Interrupt Notification*/
	Gpt_Addr->IMR &= ~(1U<<0U);
}


/******************************************************************************
* \Syntax          : Gpt_GetTimeElapsed( Gpt_ChannelType Channel )        
* \Description     : Returns the time already elapsed.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel.                    
* \Parameters (out): Gpt_ValueType                                                      
* \Return value:   : Gpt_ValueType  uint32                                  
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeElapsed( Gpt_ChannelType Channel )
{
	Gpt_ValueType value = 0;
	
	volatile TIMER_Type* Gpt_Addr = HW_TIMER_REG(Gpt_BaseAddr[Channel]);
	Gpt_CoutDir countdir = Gpt_ConfigredTiemr[Channel].countDir;
	
	
	if(countdir == GPT_COUNT_DOWN){
		uint32 startTime = Gpt_Addr->TAILR;
		uint32 currentTime = Gpt_Addr->TAV ;
		value = (startTime - currentTime) / Prescale[Channel]  ;
	}

	
	return value;
}

/******************************************************************************
* \Syntax          : Gpt_ValueType Gpt_GetTimeRemaining( Gpt_ChannelType Channel )       
* \Description     : Returns the time remaining until the target time is reached.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel.                     
* \Parameters (out): None                                                      
* \Return value:   : Gpt_ValueType  uint32                                 
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining( Gpt_ChannelType Channel )
{
	Gpt_ValueType value = 0 ;
	volatile TIMER_Type* Gpt_Addr = HW_TIMER_REG(Gpt_BaseAddr[Channel]);
	Gpt_CoutDir countDir = Gpt_ConfigredTiemr[Channel].countDir;
	
	if(countDir == GPT_COUNT_DOWN){
		Gpt_ValueType currentValue = (Gpt_Addr->TAV / Prescale[Channel]);
		value = currentValue;
	}

	return value;

}


/*Handling Callback notifications*/

void TIMER0A_Handler(void)
{
	TIMER0->ICR |= (1<<0U); 
	Gpt_NotificationFunctions[0]();

}

void TIMER1A_Handler(void)
{
	TIMER1->ICR |= (1<<0U); 
	Gpt_NotificationFunctions[1]();
	
}

void TIMER2A_Handler(void)
{
	TIMER2->ICR |= (1<<0U); 
	Gpt_NotificationFunctions[2]();
}

void TIMER3A_Handler(void)
{
	TIMER3->ICR |= (1<<0U); 
	Gpt_NotificationFunctions[3]();
	
}

void TIMER4A_Handler(void)
{
	TIMER4->ICR |= (1<<0U); 
	Gpt_NotificationFunctions[4]();
}

void TIMER5A_Handler(void)
{
	TIMER5->ICR |= (1<<0U); 
	Gpt_NotificationFunctions[5]();
	
}

void WTIMER0A_Handler(void)
{
	TIMER6->ICR |= (1<<0U); 
	Gpt_NotificationFunctions[6]();
}

void WTIMER1A_Handler(void)
{
	TIMER7->ICR |= (1<<0U); 
	Gpt_NotificationFunctions[7]();
}

void WTIMER2A_Handler(void)
{
	TIMER8->ICR |= (1<<0U); 
	Gpt_NotificationFunctions[8]();
	
}

void WTIMER3A_Handler(void)
{
	TIMER9->ICR |= (1<<0U); 
	Gpt_NotificationFunctions[9]();
}

void WTIMER4A_Handler(void)
{
	TIMER10->ICR |= (1<<0U); 
	Gpt_NotificationFunctions[10]();
}

void WTIMER5A_Handler(void)
{
	TIMER11->ICR |= (1<<0U); 
	Gpt_NotificationFunctions[11]();
}


/**********************************************************************************************************************
 *  END OF FILE: Gpt.c
 *********************************************************************************************************************/
