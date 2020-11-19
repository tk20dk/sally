#include "adc.h"
#include "si7021.h"
#include "bh1750.h"
#include "si4432.h"
#include "application.h"


uint32_t volatile SysTick;

static void CLK_Config( void );
static void RTC_Config( void );
static void TIM4_Config( void );
static void UART_Config( void );
static void GPIO_Config( void );


void main(void)
{
  CLK_Config();
  RTC_Config();
  TIM4_Config();
  UART_Config();
  GPIO_Config();

  AppInit();
  while( true )
  {
    AppLoop();
  }
}

int getchar( void )
{
  while( USART_GetFlagStatus( USART1, USART_FLAG_RXNE ) == RESET )
  {
  }

  return USART_ReceiveData8( USART1 );
}

int putchar( int const Ch )
{
  USART_SendData8( USART1, Ch );

  while( USART_GetFlagStatus( USART1, USART_FLAG_TXE ) == RESET )
  {
  }
  while( USART_GetFlagStatus( USART1, USART_FLAG_TC ) == RESET )
  {
  }
  return 0;
}

void HAL_MsDelay( uint16_t const Delay )
{
  uint32_t const Timeout = SysTick + Delay;
  while( SysTick != Timeout )
  {
    wfi();
  }
}

void RTC_CSSLSE_IRQHandler( void ) __interrupt( 4 )
{
  AppInterruptRTC();
  RTC_ClearITPendingBit( RTC_IT_WUT );
}

void EXTI0_IRQHandler( void ) __interrupt( 8 )
{
  Si4432Interrupt();
  EXTI_ClearITPendingBit( EXTI_IT_Pin0 );
}

void TIM4_UPD_OVF_TRG_IRQHandler( void ) __interrupt( 25 )
{
  SysTick++;
  AppInterruptSysTick();
  I2cInterruptSysTick();
  TIM4_ClearITPendingBit( TIM4_IT_Update );
}

static void CLK_Config( void )
{
  CLK_SYSCLKDivConfig( CLK_SYSCLKDiv_1 );
}

static void RTC_Config( void )
{
  CLK_RTCClockConfig( CLK_RTCCLKSource_LSI, CLK_RTCCLKDiv_4 );
  while( CLK_GetFlagStatus( CLK_FLAG_LSIRDY ) == RESET )
  {
  }

  CLK_PeripheralClockConfig( CLK_Peripheral_RTC, ENABLE );

  RTC_WakeUpClockConfig( RTC_WakeUpClock_RTCCLK_Div16 );
  RTC_ITConfig( RTC_IT_WUT, ENABLE );
}

static void TIM4_Config(void)
{
  /* TIM4 configuration:
   - TIM4CLK is set to 16 MHz, the TIM4 Prescaler is equal to 128 so the TIM1 counter
   clock used is 16 MHz / 128 = 125 000 Hz
  - With 125 000 Hz we can generate time base:
      max time base is 2.048 ms if TIM4_PERIOD = 255 --> (255 + 1) / 125000 = 2.048 ms
      min time base is 0.016 ms if TIM4_PERIOD = 1   --> (  1 + 1) / 125000 = 0.016 ms
  - In this example we need to generate a time base equal to 1 ms
   so TIM4_PERIOD = (0.001 * 125000 - 1) = 124 */

  CLK_PeripheralClockConfig( CLK_Peripheral_TIM4, ENABLE );

  TIM4_TimeBaseInit( TIM4_Prescaler_128, 124 );
  TIM4_ClearFlag( TIM4_FLAG_Update );
  TIM4_ITConfig( TIM4_IT_Update, ENABLE );
  TIM4_Cmd( ENABLE );
}

static void UART_Config( void )
{
  CLK_PeripheralClockConfig( CLK_Peripheral_USART1, ENABLE );

  GPIO_Init( UART_PORT_RX, UART_PIN_RX, GPIO_Mode_In_PU_No_IT );
  GPIO_Init( UART_PORT_TX, UART_PIN_TX, GPIO_Mode_Out_PP_High_Slow );

  SYSCFG_REMAPPinConfig( REMAP_Pin_USART1TxRxPortC, ENABLE );

  USART_Init( USART1, 115200, USART_WordLength_8b, USART_StopBits_1, USART_Parity_No, USART_Mode_Rx | USART_Mode_Tx );
  USART_Cmd( USART1, ENABLE );
}

static void GPIO_Config( void )
{
  GPIO_Init( HMI_PORT_LED, HMI_PIN_LED, GPIO_Mode_Out_PP_Low_Slow );
  GPIO_Init( HMI_PORT_ERROR, HMI_PIN_ERROR, GPIO_Mode_Out_PP_Low_Slow );
  GPIO_Init( HMI_PORT_BUZZER, HMI_PIN_BUZZER, GPIO_Mode_Out_PP_Low_Slow );
}


