#ifndef HARDWAREINIT_H_
#define HARDWAREINIT_H_
#include "stm32f4xx.h"
uint8_t  HardwareInit(void);
void Init_RCC(void);
void Init_GPIO_Misc(void);
void Init_USART2(uint32_t baudrate);
void Init_Systick(uint32_t clock);
void Init_Interrupts(void);
void InterruptsEnable(void);
void USART_puts(USART_TypeDef* USARTx, volatile char *s);

#endif /* HARDWAREINIT_H_ */
