#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "HardwareInit.h"
uint8_t menumode = 0;
uint8_t mainmenu[150]="Main menu-----Press the number to select the item\r\n0-Return Main menu\r\n1-Turn on LED list\r\n2-Turn Off LED list\r\n\r\n\r\n";
uint8_t submenu1[180]="Turn on LED list-----Press the number to select the item\r\n\r\n0-Return Main menu\r\n1-Turn on LED 1\r\n2-Turn on LED 2\r\n3-Turn on LED 3\r\n4-Turn on LED 4\r\n\r\n\r\n";
uint8_t submenu2[180]="Turn off LED list-----Press the number to select the item\r\n\r\n0-Return Main menu\r\n1-Turn off LED 1\r\n2-Turn off LED 2\r\n3-Turn off LED 3\r\n4-Turn off LED 4\r\n\r\n\r\n";


void MenuSelect(uint8_t charin){

	  switch (menumode){
	  	  case 0:
	  		  switch (charin){
	  		  	  case '0':
	  		  		  USART_puts(USART2,mainmenu);
	  		  		  menumode = 0;
	  		  		  break;
	  		  	  case '1':
	  		  		  USART_puts(USART2,submenu1);
	  		  		  menumode = 1;
	  		  		  break;
	  		  	  case '2':
	  		  		  USART_puts(USART2,submenu2);
	  		  		  menumode = 2;
	  		  		  break;
	  		  	  default:
	  		  		  USART_puts(USART2,"Ingreso incorrecto\r\n");
	  		  		  menumode = 0;
	  		  		  USART_puts(USART2,mainmenu);
	  		  		  break;
	  		  }
	  		  break;
	  	  case 1:
	  		  switch (charin){
	  		  	  case '0':
	  		  		  USART_puts(USART2,mainmenu);
	  		  		  menumode = 0;
	  		  		  break;
	  		  	  case '1':
	  		  		  GPIO_SetBits(GPIOD, GPIO_Pin_12);
	  		  		  break;
	  		  	  case '2':
	  		  		  GPIO_SetBits(GPIOD, GPIO_Pin_13);
	  		  		  break;
	  		  	  case '3':
	  		  		  GPIO_SetBits(GPIOD, GPIO_Pin_14);
	  		  		  break;
	  		  	  case '4':
	  		  		  GPIO_SetBits(GPIOD, GPIO_Pin_15);
	  		  		  break;
	  		  	  default:
	  		  		  USART_puts(USART2,"Ingreso incorrecto\r\n");
	  		  		  menumode = 1;
	  		  		  break;
	  		  }
	  		  break;
	  	  case 2:
	  		  switch (charin){
	  		  	  case '0':
	  		  		  USART_puts(USART2,mainmenu);
	  		  		  menumode = 0;
	  		  		  break;
	  		  	  case '1':
	  		  		  GPIO_ResetBits(GPIOD, GPIO_Pin_12);
	  		  		  break;
	  		  	  case '2':
	  		  		  GPIO_ResetBits(GPIOD, GPIO_Pin_13);
	  		  		  break;
	  		  	  case '3':
	  		  		  GPIO_ResetBits(GPIOD, GPIO_Pin_14);
	  		  		  break;
	  		  	  case '4':
	  		  		  GPIO_ResetBits(GPIOD, GPIO_Pin_15);
	  		  		  break;
	  		  	  default:
	  		  		  USART_puts(USART2,"Ingreso incorrecto\r\n");
	  		  		  menumode = 2;
	  		  		  break;
	  		  }
	  		  break;
	  }
}


