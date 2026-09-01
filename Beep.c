#include"Beep.h"
#include"stm32f4xx_gpio.h"
void Beep_Init(void)
{
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOF , ENABLE);
	 GPIO_InitTypeDef G;
   G.GPIO_Pin = GPIO_Pin_8;
   G.GPIO_Mode = GPIO_Mode_OUT; 
   G.GPIO_Speed = GPIO_Speed_50MHz; 
   G.GPIO_OType = GPIO_OType_PP;
   GPIO_Init(GPIOF, &G);
}

