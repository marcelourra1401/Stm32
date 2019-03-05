
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "HardwareInit.h"
#include "Interrupts.h"
#include "Menu.h"

int main(void)
{
	HardwareInit();
	MenuSelect('0');
  while (1)
  {
  }
}


/*
 * Callback used by stm32f4_discovery_audio_codec.c.
 * Refer to stm32f4_discovery_audio_codec.h for more info.
 */
void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}