#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "HardwareInit.h"
#include "Interrupts.h"
uint8_t HardwareInit(void){

	Init_RCC();
	Init_GPIO_Misc();
	Init_USART2(9600);
	Init_Interrupts();
	Init_Systick(1000);// 100 = 10ms , 1000 = 1ms, 1000000 = 1us
	InterruptsEnable();
	return 1;
}
void Init_RCC(void){

	/* Advanced High Speed Bus */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOE , ENABLE);

	/* Advanced Peripheral Bus 1 */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
}
void Init_GPIO_Misc(void){
	GPIO_InitTypeDef GPIO_InitStruct;
	/* - LED_GREEN     on PD12
	   - LED_ORANGE    on PD13
	   - LED_RED       on PD14
	   - LED_BLUE      on PD15*/
	GPIO_StructInit(&GPIO_InitStruct);
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	//Initialize pins
	GPIO_Init(GPIOD, &GPIO_InitStruct);

    /* Init GPIO pins */
    GPIO_StructInit(&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* Set alternate functions */
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2); //Tx
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);//Rx

}
void Init_USART2(uint32_t baudrate){

		USART_InitTypeDef USART_InitStruct;

	    /* Configure UART setup */
	    USART_StructInit(&USART_InitStruct);
	    USART_InitStruct.USART_BaudRate = baudrate;
	    USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	    USART_InitStruct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	    USART_InitStruct.USART_Parity = USART_Parity_No;
	    USART_InitStruct.USART_StopBits = USART_StopBits_1;
	    USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	    USART_Init(USART2, &USART_InitStruct);
	    USART_Cmd(USART2, ENABLE);
}

void Init_Systick(uint32_t clock){
	while(SysTick_Config(SystemCoreClock/clock)==!0);
}

void Init_Interrupts(void){

NVIC_InitTypeDef NVIC_InitStructure;
/* Enable global interrupts for USART */
NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
NVIC_Init(&NVIC_InitStructure);
}

void InterruptsEnable(void){
    /* Enable transfer complete interrupt */
    USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
    USART_Cmd(USART2, ENABLE);
}

void USART_puts(USART_TypeDef* USARTx, volatile char *s){

	while(*s){
		// wait until data register is empty
		while( !(USARTx->SR & 0x00000040) );
		USART_SendData(USARTx, *s);
		*s++;
	}
}

