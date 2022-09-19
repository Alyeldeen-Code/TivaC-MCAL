/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :3;
    uint32          :4;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;
typedef union 
{
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;

typedef struct {                                    /*!< SYSCTL Structure                                                      */
  volatile uint32  DID0;                              /*!< Device Identification 0                                               */
  volatile uint32  DID1;                              /*!< Device Identification 1                                               */
  volatile uint32  DC0;                               /*!< Device Capabilities 0                                                 */
  volatile uint32  RESERVED;
  volatile uint32  DC1;                               /*!< Device Capabilities 1                                                 */
  volatile uint32  DC2;                               /*!< Device Capabilities 2                                                 */
  volatile uint32  DC3;                               /*!< Device Capabilities 3                                                 */
  volatile uint32  DC4;                               /*!< Device Capabilities 4                                                 */
  volatile uint32  DC5;                               /*!< Device Capabilities 5                                                 */
  volatile uint32  DC6;                               /*!< Device Capabilities 6                                                 */
  volatile uint32  DC7;                               /*!< Device Capabilities 7                                                 */
  volatile uint32  DC8;                               /*!< Device Capabilities 8                                                 */
  volatile uint32  PBORCTL;                           /*!< Brown-Out Reset Control                                               */
  volatile uint32  RESERVED1[3];
  volatile uint32  SRCR0;                             /*!< Software Reset Control 0                                              */
  volatile uint32  SRCR1;                             /*!< Software Reset Control 1                                              */
  volatile uint32  SRCR2;                             /*!< Software Reset Control 2                                              */
  volatile uint32  RESERVED2;
  volatile uint32  RIS;                               /*!< Raw Interrupt Status                                                  */
  volatile uint32  IMC;                               /*!< Interrupt Mask Control                                                */
  volatile uint32  MISC;                              /*!< Masked Interrupt Status and Clear                                     */
  volatile uint32  RESC;                              /*!< Reset Cause                                                           */
  volatile uint32  RCC;                               /*!< Run-Mode Clock Configuration                                          */
  volatile uint32  RESERVED3[2];
  volatile uint32  GPIOHBCTL;                         /*!< GPIO High-Performance Bus Control                                     */
  volatile uint32  RCC2;                              /*!< Run-Mode Clock Configuration 2                                        */
  volatile uint32  RESERVED4[2];
  volatile uint32  MOSCCTL;                           /*!< Main Oscillator Control                                               */
  volatile uint32  RESERVED5[32];
  volatile uint32  RCGC0;                             /*!< Run Mode Clock Gating Control Register 0                              */
  volatile uint32  RCGC1;                             /*!< Run Mode Clock Gating Control Register 1                              */
  volatile uint32  RCGC2;                             /*!< Run Mode Clock Gating Control Register 2                              */
  volatile uint32  RESERVED6;
  volatile uint32  SCGC0;                             /*!< Sleep Mode Clock Gating Control Register 0                            */
  volatile uint32  SCGC1;                             /*!< Sleep Mode Clock Gating Control Register 1                            */
  volatile uint32  SCGC2;                             /*!< Sleep Mode Clock Gating Control Register 2                            */
  volatile uint32  RESERVED7;
  volatile uint32  DCGC0;                             /*!< Deep Sleep Mode Clock Gating Control Register 0                       */
  volatile uint32  DCGC1;                             /*!< Deep-Sleep Mode Clock Gating Control Register 1                       */
  volatile uint32  DCGC2;                             /*!< Deep Sleep Mode Clock Gating Control Register 2                       */
  volatile uint32  RESERVED8[6];
  volatile uint32  DSLPCLKCFG;                        /*!< Deep Sleep Clock Configuration                                        */
  volatile uint32  RESERVED9;
  volatile uint32  SYSPROP;                           /*!< System Properties                                                     */
  volatile uint32  PIOSCCAL;                          /*!< Precision Internal Oscillator Calibration                             */
  volatile uint32  PIOSCSTAT;                         /*!< Precision Internal Oscillator Statistics                              */
  volatile uint32  RESERVED10[2];
  volatile uint32  PLLFREQ0;                          /*!< PLL Frequency 0                                                       */
  volatile uint32  PLLFREQ1;                          /*!< PLL Frequency 1                                                       */
  volatile uint32  PLLSTAT;                           /*!< PLL Status                                                            */
  volatile uint32  RESERVED11[7];
  volatile uint32  SLPPWRCFG;                         /*!< Sleep Power Configuration                                             */
  volatile uint32  DSLPPWRCFG;                        /*!< Deep-Sleep Power Configuration                                        */
  volatile uint32  DC9;                               /*!< Device Capabilities 9                                                 */
  volatile uint32  RESERVED12[3];
  volatile uint32  NVMSTAT;                           /*!< Non-Volatile Memory Information                                       */
  volatile uint32  RESERVED13[4];
  volatile uint32  LDOSPCTL;                          /*!< LDO Sleep Power Control                                               */
  volatile uint32  RESERVED14;
  volatile uint32  LDODPCTL;                          /*!< LDO Deep-Sleep Power Control                                          */
  volatile uint32  RESERVED15[80];
  volatile uint32  PPWD;                              /*!< Watchdog Timer Peripheral Present                                     */
  volatile uint32  PPTIMER;                           /*!< 16/32-Bit General-Purpose Timer Peripheral Present                    */
  volatile uint32  PPGPIO;                            /*!< General-Purpose Input/Output Peripheral Present                       */
  volatile uint32  PPDMA;                             /*!< Micro Direct Memory Access Peripheral Present                         */
  volatile uint32  RESERVED16;
  volatile uint32  PPHIB;                             /*!< Hibernation Peripheral Present                                        */
  volatile uint32  PPUART;                            /*!< Universal Asynchronous Receiver/Transmitter Peripheral Present        */
  volatile uint32  PPSSI;                             /*!< Synchronous Serial Interface Peripheral Present                       */
  volatile uint32  PPI2C;                             /*!< Inter-Integrated Circuit Peripheral Present                           */
  volatile uint32  RESERVED17;
  volatile uint32  PPUSB;                             /*!< Universal Serial Bus Peripheral Present                               */
  volatile uint32  RESERVED18[2];
  volatile uint32  PPCAN;                             /*!< Controller Area Network Peripheral Present                            */
  volatile uint32  PPADC;                             /*!< Analog-to-Digital Converter Peripheral Present                        */
  volatile uint32  PPACMP;                            /*!< Analog Comparator Peripheral Present                                  */
  volatile uint32  PPPWM;                             /*!< Pulse Width Modulator Peripheral Present                              */
  volatile uint32  PPQEI;                             /*!< Quadrature Encoder Interface Peripheral Present                       */
  volatile uint32  RESERVED19[4];
  volatile uint32  PPEEPROM;                          /*!< EEPROM Peripheral Present                                             */
  volatile uint32  PPWTIMER;                          /*!< 32/64-Bit Wide General-Purpose Timer Peripheral Present               */
  volatile uint32  RESERVED20[104];
  volatile uint32  SRWD;                              /*!< Watchdog Timer Software Reset                                         */
  volatile uint32  SRTIMER;                           /*!< 16/32-Bit General-Purpose Timer Software Reset                        */
  volatile uint32  SRGPIO;                            /*!< General-Purpose Input/Output Software Reset                           */
  volatile uint32  SRDMA;                             /*!< Micro Direct Memory Access Software Reset                             */
  volatile uint32  RESERVED21;
  volatile uint32  SRHIB;                             /*!< Hibernation Software Reset                                            */
  volatile uint32  SRUART;                            /*!< Universal Asynchronous Receiver/Transmitter Software Reset            */
  volatile uint32  SRSSI;                             /*!< Synchronous Serial Interface Software Reset                           */
  volatile uint32  SRI2C;                             /*!< Inter-Integrated Circuit Software Reset                               */
  volatile uint32  RESERVED22;
  volatile uint32  SRUSB;                             /*!< Universal Serial Bus Software Reset                                   */
  volatile uint32  RESERVED23[2];
  volatile uint32  SRCAN;                             /*!< Controller Area Network Software Reset                                */
  volatile uint32  SRADC;                             /*!< Analog-to-Digital Converter Software Reset                            */
  volatile uint32  SRACMP;                            /*!< Analog Comparator Software Reset                                      */
  volatile uint32  SRPWM;                             /*!< Pulse Width Modulator Software Reset                                  */
  volatile uint32  SRQEI;                             /*!< Quadrature Encoder Interface Software Reset                           */
  volatile uint32  RESERVED24[4];
  volatile uint32  SREEPROM;                          /*!< EEPROM Software Reset                                                 */
  volatile uint32  SRWTIMER;                          /*!< 32/64-Bit Wide General-Purpose Timer Software Reset                   */
  volatile uint32  RESERVED25[40];
  volatile uint32  RCGCWD;                            /*!< Watchdog Timer Run Mode Clock Gating Control                          */
  volatile uint32  RCGCTIMER;                         /*!< 16/32-Bit General-Purpose Timer Run Mode Clock Gating Control         */
  volatile uint32  RCGCGPIO;                          /*!< General-Purpose Input/Output Run Mode Clock Gating Control            */
  volatile uint32  RCGCDMA;                           /*!< Micro Direct Memory Access Run Mode Clock Gating Control              */
  volatile uint32  RESERVED26;
  volatile uint32  RCGCHIB;                           /*!< Hibernation Run Mode Clock Gating Control                             */
  volatile uint32  RCGCUART;                          /*!< Universal Asynchronous Receiver/Transmitter Run Mode Clock Gating
                                                         Control                                                               */
  volatile uint32  RCGCSSI;                           /*!< Synchronous Serial Interface Run Mode Clock Gating Control            */
  volatile uint32  RCGCI2C;                           /*!< Inter-Integrated Circuit Run Mode Clock Gating Control                */
  volatile uint32  RESERVED27;
  volatile uint32  RCGCUSB;                           /*!< Universal Serial Bus Run Mode Clock Gating Control                    */
  volatile uint32  RESERVED28[2];
  volatile uint32  RCGCCAN;                           /*!< Controller Area Network Run Mode Clock Gating Control                 */
  volatile uint32  RCGCADC;                           /*!< Analog-to-Digital Converter Run Mode Clock Gating Control             */
  volatile uint32  RCGCACMP;                          /*!< Analog Comparator Run Mode Clock Gating Control                       */
  volatile uint32  RCGCPWM;                           /*!< Pulse Width Modulator Run Mode Clock Gating Control                   */
  volatile uint32  RCGCQEI;                           /*!< Quadrature Encoder Interface Run Mode Clock Gating Control            */
  volatile uint32  RESERVED29[4];
  volatile uint32  RCGCEEPROM;                        /*!< EEPROM Run Mode Clock Gating Control                                  */
  volatile uint32  RCGCWTIMER;                        /*!< 32/64-Bit Wide General-Purpose Timer Run Mode Clock Gating Control    */
  volatile uint32  RESERVED30[40];
  volatile uint32  SCGCWD;                            /*!< Watchdog Timer Sleep Mode Clock Gating Control                        */
  volatile uint32  SCGCTIMER;                         /*!< 16/32-Bit General-Purpose Timer Sleep Mode Clock Gating Control       */
  volatile uint32  SCGCGPIO;                          /*!< General-Purpose Input/Output Sleep Mode Clock Gating Control          */
  volatile uint32  SCGCDMA;                           /*!< Micro Direct Memory Access Sleep Mode Clock Gating Control            */
  volatile uint32  RESERVED31;
  volatile uint32  SCGCHIB;                           /*!< Hibernation Sleep Mode Clock Gating Control                           */
  volatile uint32  SCGCUART;                          /*!< Universal Asynchronous Receiver/Transmitter Sleep Mode Clock
                                                         Gating Control                                                        */
  volatile uint32  SCGCSSI;                           /*!< Synchronous Serial Interface Sleep Mode Clock Gating Control          */
  volatile uint32  SCGCI2C;                           /*!< Inter-Integrated Circuit Sleep Mode Clock Gating Control              */
  volatile uint32  RESERVED32;
  volatile uint32  SCGCUSB;                           /*!< Universal Serial Bus Sleep Mode Clock Gating Control                  */
  volatile uint32  RESERVED33[2];
  volatile uint32  SCGCCAN;                           /*!< Controller Area Network Sleep Mode Clock Gating Control               */
  volatile uint32  SCGCADC;                           /*!< Analog-to-Digital Converter Sleep Mode Clock Gating Control           */
  volatile uint32  SCGCACMP;                          /*!< Analog Comparator Sleep Mode Clock Gating Control                     */
  volatile uint32  SCGCPWM;                           /*!< Pulse Width Modulator Sleep Mode Clock Gating Control                 */
  volatile uint32  SCGCQEI;                           /*!< Quadrature Encoder Interface Sleep Mode Clock Gating Control          */
  volatile uint32  RESERVED34[4];
  volatile uint32  SCGCEEPROM;                        /*!< EEPROM Sleep Mode Clock Gating Control                                */
  volatile uint32  SCGCWTIMER;                        /*!< 32/64-Bit Wide General-Purpose Timer Sleep Mode Clock Gating
                                                         Control                                                               */
  volatile uint32  RESERVED35[40];
  volatile uint32  DCGCWD;                            /*!< Watchdog Timer Deep-Sleep Mode Clock Gating Control                   */
  volatile uint32  DCGCTIMER;                         /*!< 16/32-Bit General-Purpose Timer Deep-Sleep Mode Clock Gating
                                                         Control                                                               */
  volatile uint32  DCGCGPIO;                          /*!< General-Purpose Input/Output Deep-Sleep Mode Clock Gating Control     */
  volatile uint32  DCGCDMA;                           /*!< Micro Direct Memory Access Deep-Sleep Mode Clock Gating Control       */
  volatile uint32  RESERVED36;
  volatile uint32  DCGCHIB;                           /*!< Hibernation Deep-Sleep Mode Clock Gating Control                      */
  volatile uint32  DCGCUART;                          /*!< Universal Asynchronous Receiver/Transmitter Deep-Sleep Mode
                                                         Clock Gating Control                                                  */
  volatile uint32  DCGCSSI;                           /*!< Synchronous Serial Interface Deep-Sleep Mode Clock Gating Control     */
  volatile uint32  DCGCI2C;                           /*!< Inter-Integrated Circuit Deep-Sleep Mode Clock Gating Control         */
  volatile uint32  RESERVED37;
  volatile uint32  DCGCUSB;                           /*!< Universal Serial Bus Deep-Sleep Mode Clock Gating Control             */
  volatile uint32  RESERVED38[2];
  volatile uint32  DCGCCAN;                           /*!< Controller Area Network Deep-Sleep Mode Clock Gating Control          */
  volatile uint32  DCGCADC;                           /*!< Analog-to-Digital Converter Deep-Sleep Mode Clock Gating Control      */
  volatile uint32  DCGCACMP;                          /*!< Analog Comparator Deep-Sleep Mode Clock Gating Control                */
  volatile uint32  DCGCPWM;                           /*!< Pulse Width Modulator Deep-Sleep Mode Clock Gating Control            */
  volatile uint32  DCGCQEI;                           /*!< Quadrature Encoder Interface Deep-Sleep Mode Clock Gating Control     */
  volatile uint32  RESERVED39[4];
  volatile uint32  DCGCEEPROM;                        /*!< EEPROM Deep-Sleep Mode Clock Gating Control                           */
  volatile uint32  DCGCWTIMER;                        /*!< 32/64-Bit Wide General-Purpose Timer Deep-Sleep Mode Clock Gating
                                                         Control                                                               */
  volatile uint32  RESERVED40[104];
  volatile uint32  PRWD;                              /*!< Watchdog Timer Peripheral Ready                                       */
  volatile uint32  PRTIMER;                           /*!< 16/32-Bit General-Purpose Timer Peripheral Ready                      */
  volatile uint32  PRGPIO;                            /*!< General-Purpose Input/Output Peripheral Ready                         */
  volatile uint32  PRDMA;                             /*!< Micro Direct Memory Access Peripheral Ready                           */
  volatile uint32  RESERVED41;
  volatile uint32  PRHIB;                             /*!< Hibernation Peripheral Ready                                          */
  volatile uint32  PRUART;                            /*!< Universal Asynchronous Receiver/Transmitter Peripheral Ready          */
  volatile uint32  PRSSI;                             /*!< Synchronous Serial Interface Peripheral Ready                         */
  volatile uint32  PRI2C;                             /*!< Inter-Integrated Circuit Peripheral Ready                             */
  volatile uint32  RESERVED42;
  volatile uint32  PRUSB;                             /*!< Universal Serial Bus Peripheral Ready                                 */
  volatile uint32  RESERVED43[2];
  volatile uint32  PRCAN;                             /*!< Controller Area Network Peripheral Ready                              */
  volatile uint32  PRADC;                             /*!< Analog-to-Digital Converter Peripheral Ready                          */
  volatile uint32  PRACMP;                            /*!< Analog Comparator Peripheral Ready                                    */
  volatile uint32  PRPWM;                             /*!< Pulse Width Modulator Peripheral Ready                                */
  volatile uint32  PRQEI;                             /*!< Quadrature Encoder Interface Peripheral Ready                         */
  volatile uint32  RESERVED44[4];
  volatile uint32  PREEPROM;                          /*!< EEPROM Peripheral Ready                                               */
  volatile uint32  PRWTIMER;                          /*!< 32/64-Bit Wide General-Purpose Timer Peripheral Ready                 */
} SYSCTL_Type;

typedef struct {                                    /*!< GPIOA Structure                                                       */
  volatile uint32  DATA_Bits[255];
  volatile uint32  DATA;                              /*!< GPIO Data                                                             */
  volatile uint32  DIR;                               /*!< GPIO Direction                                                        */
  volatile uint32  IS;                                /*!< GPIO Interrupt Sense                                                  */
  volatile uint32  IBE;                               /*!< GPIO Interrupt Both Edges                                             */
  volatile uint32  IEV;                               /*!< GPIO Interrupt Event                                                  */
  volatile uint32  IM;                                /*!< GPIO Interrupt Mask                                                   */
  volatile uint32  RIS;                               /*!< GPIO Raw Interrupt Status                                             */
  volatile uint32  MIS;                               /*!< GPIO Masked Interrupt Status                                          */
  volatile uint32  ICR;                               /*!< GPIO Interrupt Clear                                                  */
  volatile uint32  AFSEL;                             /*!< GPIO Alternate Function Select                                        */
  volatile uint32  RESERVED1[55];  // 220 ???
  volatile uint32  DR2R;                              /*!< GPIO 2-mA Drive Select                                                */
  volatile uint32  DR4R;                              /*!< GPIO 4-mA Drive Select                                                */
  volatile uint32  DR8R;                              /*!< GPIO 8-mA Drive Select                                                */
  volatile uint32  ODR;                               /*!< GPIO Open Drain Select                                                */
  volatile uint32  PUR;                               /*!< GPIO Pull-Up Select                                                   */
  volatile uint32  PDR;                               /*!< GPIO Pull-Down Select                                                 */
  volatile uint32  SLR;                               /*!< GPIO Slew Rate Control Select                                         */
  volatile uint32  DEN;                               /*!< GPIO Digital Enable                                                   */
  volatile uint32  LOCK;                              /*!< GPIO Lock                                                             */
  volatile uint32  CR;                                /*!< GPIO Commit                                                           */
  volatile uint32  AMSEL;                             /*!< GPIO Analog Mode Select                                               */
  volatile uint32  PCTL;                              /*!< GPIO Port Control                                                     */
  volatile uint32  ADCCTL;                            /*!< GPIO ADC Control                                                      */
  volatile uint32  DMACTL;                            /*!< GPIO DMA Control                                                      */
} GPIO_Type;

typedef struct {                                    /*!< TIMER0 Structure                                                      */
  volatile uint32  CFG;                               /*!< GPTM Configuration                                                    */
  volatile uint32  TAMR;                              /*!< GPTM Timer A Mode                                                     */
  volatile uint32  TBMR;                              /*!< GPTM Timer B Mode                                                     */
  volatile uint32  CTL;                               /*!< GPTM Control                                                          */
  volatile uint32  SYNC;                              /*!< GPTM Synchronize                                                      */
  volatile uint32  RESERVED;
  volatile uint32  IMR;                               /*!< GPTM Interrupt Mask                                                   */
  volatile uint32  RIS;                               /*!< GPTM Raw Interrupt Status                                             */
  volatile uint32  MIS;                               /*!< GPTM Masked Interrupt Status                                          */
  volatile uint32  ICR;                               /*!< GPTM Interrupt Clear                                                  */
  volatile uint32  TAILR;                             /*!< GPTM Timer A Interval Load                                            */
  volatile uint32  TBILR;                             /*!< GPTM Timer B Interval Load                                            */
  volatile uint32  TAMATCHR;                          /*!< GPTM Timer A Match                                                    */
  volatile uint32  TBMATCHR;                          /*!< GPTM Timer B Match                                                    */
  volatile uint32  TAPR;                              /*!< GPTM Timer A Prescale                                                 */
  volatile uint32  TBPR;                              /*!< GPTM Timer B Prescale                                                 */
  volatile uint32  TAPMR;                             /*!< GPTM TimerA Prescale Match                                            */
  volatile uint32  TBPMR;                             /*!< GPTM TimerB Prescale Match                                            */
  volatile uint32  TAR;                               /*!< GPTM Timer A                                                          */
  volatile uint32  TBR;                               /*!< GPTM Timer B                                                          */
  volatile uint32  TAV;                               /*!< GPTM Timer A Value                                                    */
  volatile uint32  TBV;                               /*!< GPTM Timer B Value                                                    */
  volatile uint32  RTCPD;                             /*!< GPTM RTC Predivide                                                    */
  volatile uint32  TAPS;                              /*!< GPTM Timer A Prescale Snapshot                                        */
  volatile uint32  TBPS;                              /*!< GPTM Timer B Prescale Snapshot                                        */
  volatile uint32  TAPV;                              /*!< GPTM Timer A Prescale Value                                           */
  volatile uint32  TBPV;                              /*!< GPTM Timer B Prescale Value                                           */
  volatile uint32  RESERVED1[981];
  volatile uint32  PP;                                /*!< GPTM Peripheral Properties                                            */
} TIMER_Type;

typedef struct
{
  volatile uint32 ISER[8U];               /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
           uint32 RESERVED0[24U];
  volatile uint32 ICER[8U];               /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
           uint32 RESERVED1[24U];
  volatile uint32 ISPR[8U];               /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
           uint32 RESERVED2[24U];
  volatile uint32 ICPR[8U];               /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
           uint32 RESERVED3[24U];
  volatile uint32 IABR[8U];               /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
           uint32 RESERVED4[56U];
  volatile uint8 IP[240U];               /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
					 uint32 RESERVED5[644U];
  volatile uint32 STIR;                   /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register */
}  NVIC_Type;


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define APINT                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define INTCTRL                                *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))

//NVIC
#define NVIC_BASE     0xE000E100UL
#define NVIC                ((NVIC_Type*)NVIC_BASE)
#define HW_NVIC_REG(Reg_base)      						((NVIC_Type*) Reg_base)


//SYSCTL REG
#define SYSCTL_BASE                     0x400FE000UL
#define SYSCTR_RCG_BASE      						0x400FE600						
#define SYSCTL                          ((SYSCTL_Type*) SYSCTL_BASE)


//Gpio REG
#define GPIOA_BASE                      0x40004000UL
#define GPIOB_BASE                      0x40005000UL
#define GPIOC_BASE                      0x40006000UL
#define GPIOD_BASE                      0x40007000UL
#define GPIOE_BASE                      0x40024000UL
#define GPIOF_BASE                      0x40025000UL

#define HW_GPIO_REG(Reg_base)      						((GPIO_Type*) Reg_base)

#define GPIOA                           ((GPIO_Type*) GPIOA_BASE)
#define GPIOB                           ((GPIO_Type*) GPIOB_BASE)
#define GPIOC                           ((GPIO_Type*) GPIOC_BASE)
#define GPIOD                           ((GPIO_Type*) GPIOD_BASE)
#define GPIOE		                        ((GPIO_Type*) GPIOE_BASE)
#define GPIOF			                      ((GPIO_Type*) GPIOF_BASE)

//Timer REG

#define TIMER0_BASE                     0x40030000UL
#define TIMER1_BASE                     0x40031000UL
#define TIMER2_BASE                     0x40032000UL
#define TIMER3_BASE                     0x40033000UL
#define TIMER4_BASE                     0x40034000UL
#define TIMER5_BASE                     0x40035000UL
#define TIMER6_BASE                     0x40036000UL
#define TIMER7_BASE                     0x40037000UL
#define TIMER8_BASE                     0x4004C000UL
#define TIMER9_BASE                     0x4004D000UL
#define TIMER10_BASE                    0x4004E000UL
#define TIMER11_BASE                    0x4004F000UL

#define HW_TIMER_REG(Reg_base)      						((TIMER_Type*) Reg_base)

#define TIMER0                          ((TIMER_Type*) TIMER0_BASE)
#define TIMER1                          ((TIMER_Type*) TIMER1_BASE)
#define TIMER2                          ((TIMER_Type*) TIMER2_BASE)
#define TIMER3                          ((TIMER_Type*) TIMER3_BASE)
#define TIMER4                          ((TIMER_Type*) TIMER4_BASE)
#define TIMER5                          ((TIMER_Type*) TIMER5_BASE)
#define TIMER6                          ((TIMER_Type*) TIMER6_BASE)
#define TIMER7                          ((TIMER_Type*) TIMER7_BASE)
#define TIMER8                          ((TIMER_Type*) TIMER8_BASE)
#define TIMER9                          ((TIMER_Type*) TIMER9_BASE)
#define TIMER10                         ((TIMER_Type*) TIMER10_BASE)
#define TIMER11                         ((TIMER_Type*) TIMER11_BASE)

#define GET_HWREG(BaseAddress,RegOffset)		*((volatile uint32*)(BaseAddress+RegOffset))

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
