#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "Interrupts.h"
#include "HardwareInit.h"
#include "Menu.h"

static __IO uint32_t TimingDelay;
void USART2_IRQHandler(void) {

	char rData;

	  if ( USART_GetITStatus(USART2, USART_IT_RXNE)) {
		  rData= USART2->DR;
		  MenuSelect(rData);
	  }
	    USART_ClearITPendingBit(USART2, USART_IT_RXNE);
}
void SysTick_Handler(void){
if (TimingDelay == 0xFFFFFFFF){
	TimingDelay = 0;
}
else{
	TimingDelay++;
}
}
uint32_t millis(void){
	return TimingDelay;
}
