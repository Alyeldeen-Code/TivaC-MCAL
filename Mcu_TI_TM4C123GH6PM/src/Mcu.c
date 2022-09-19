/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Mcu.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Mcu.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define MCU_XTAL_CLOCK_FREQ_MHZ    16U

#define SYSTEM_RESET_REQ       (1U<<2U)

#define PWRDN 								 (1U<<13U)
#define BYPASS								 (1U<<11U)
#define MOSCDIS 							 (1U<<0U)

#define OSCSRC  							 4U
#define SYSDIV								 23U

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static const  Mcu_ConfigType* Mcu_ConfigPtr ;
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
uint32 GlobalSystemClock;

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
* \Syntax          : void Mcu_Init ( const Mcu_ConfigType* ConfigPtr )        
* \Description     : This service initializes the MCU driver.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr       Pointer to MCU driver configuration set.                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Mcu_Init ( const Mcu_ConfigType* ConfigPtr )
{

	Mcu_ConfigPtr =  ConfigPtr;
}

/******************************************************************************
* \Syntax          : void Mcu_PerformReset( void )        
* \Description     : Calling this function cause Reset for the system.                                                                                                                 
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                           
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Mcu_PerformReset(void)
{
	/* clear reset cause reester*/
	SYSCTL->RESC = 0x00;
	/* perform reset */
	APINT = (0x05FA0000 |SYSTEM_RESET_REQ);
	
}

/******************************************************************************
* \Syntax          : Mcu_RawResetType Mcu_GetResetRawValue( void )        
* \Description     : calling that function return  the reset type cause the reset.                                                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                            
* \Parameters (out): None                                                      
* \Return value:   : Mcu_RawResetType   Reset raw value
*******************************************************************************/
Mcu_RawResetType Mcu_GetResetRawValue(void)
{
	Mcu_RawResetType resetCause = SYSCTL->RESC;
	SYSCTL->RESC = 0x0;
	return resetCause;
}

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
Mcu_PllStatusType Mcu_GetPllStatus(void)
{
	return (Mcu_PllStatusType) SYSCTL->PLLSTAT;
}

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
Std_ReturnType Mcu_DistributePllClock( void)
{
	Std_ReturnType state = E_NOT_OK;
	/* check if PLL is enabled */
	if( (SYSCTL->RCC & PWRDN) == 0)
	{
			/* check if Pll is locked  */
			if(Mcu_GetPllStatus() == MCU_PLL_STATUS_LOCKED)
			{
				/* distribute PLL */
				SYSCTL->RCC |= BYPASS;
				state = E_OK;
			}
	}
	return state;

}

/******************************************************************************
* \Syntax          : void Mcu_Init ( const Mcu_ConfigType* ConfigPtr )        
* \Description     : This service initializes the PLL and other MCU specific clock options.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ClockSetting       ClockSetting.                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType 

*******************************************************************************/
Std_ReturnType Mcu_InitClock( Mcu_ClockType ClockSetting)
{
	Std_ReturnType state = E_NOT_OK;
	
	Mcu_ConfigType  ConfigPtr = Mcu_ConfigPtr[ClockSetting];

	Mcu_ClockSourceType clockSource = (ConfigPtr.ClockSource) & 0x03;
	Mcu_ClockGateType* ActevatedClockGatePtr =  Mcu_ConfigPtr[ClockSetting].Mcu_ActevatedClockGatePtr;
	uint32 divVal = 0;
	/*TODO: SUPPORT CLOCK GATE CONFIGRATION*/
	
	/*Config the sellected clock source*/
	SYSCTL->RCC |= (uint32) (clockSource << OSCSRC);
	
	
	if(ConfigPtr.PllEnable == ENABLE){
		/*Enable PLL if it setted*/
		SYSCTL->RCC &= ~PWRDN;
		divVal = ((200 / (ConfigPtr.Freq_KHz/1000)) );
		SYSCTL->RCC |= (divVal<< SYSDIV);
		
		state = E_OK;
	}else {
		uint32 SourceFreq_MHz ;
		
		/*Config the colock soure if Pll is desabled */ 
		if(ConfigPtr.ClockSource == MCU_CLOCK_SOURCE_MOSC){
			SYSCTL->RCC &= ~MOSCDIS;
			SourceFreq_MHz = MCU_XTAL_CLOCK_FREQ_MHZ;
		}else if(ConfigPtr.ClockSource == MCU_CLOCK_SOURCE_PIOSC){
			SYSCTL->RCC |= MOSCDIS;
			SourceFreq_MHz = 16;
		}else if(ConfigPtr.ClockSource == MCU_CLOCK_SOURCE_PIOSC){
			SYSCTL->RCC |= MOSCDIS;
			SourceFreq_MHz = 4;
		}
	
		divVal = ((SourceFreq_MHz / (ConfigPtr.Freq_KHz/1000)) );
		SYSCTL->RCC |= (divVal<< SYSDIV);
		state = E_OK;
	}
	
	/*Config the clock gate for prefrals*/
	 volatile uint8 i ;
	 for(i=0;i<MCU_ACTIVATED_CLOCK_GATES_SIZE;i++)
	    {
	    	volatile uint8 GateRegOffset = ((ActevatedClockGatePtr[i] >> 4U ) * WORD_LENGTH_BYTES) & 0x0FF ;
	    	volatile uint8 GateBitOffset = ActevatedClockGatePtr[i] & 0X00F ;
	    	GET_HWREG(SYSCTR_RCG_BASE,GateRegOffset ) |= (1<<GateBitOffset);	
	    }
	/*Global the system Clock*/
	GlobalSystemClock =  Mcu_ConfigPtr[ClockSetting].Freq_KHz *1000;
	
	return state;

}
/**********************************************************************************************************************
 *  END OF FILE: Mcu.c
 *********************************************************************************************************************/
