#include"Key.h"
#include"stm32f4xx_gpio.h"
void Key_Init(void)
{
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOA , ENABLE);
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOE , ENABLE);
	GPIO_InitTypeDef G;
	G.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;
   G.GPIO_Mode = GPIO_Mode_IN; 
   G.GPIO_Speed = GPIO_Speed_50MHz; 
  G.GPIO_OType = GPIO_OType_PP;
	G.GPIO_PuPd = GPIO_PuPd_NOPULL;
   GPIO_Init(GPIOE, &G);
	G.GPIO_Pin = GPIO_Pin_0;
	GPIO_Init(GPIOA, &G);
}
int Get_Key_State(int Key_Num)
{
    GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;
	switch(Key_Num)
	{
		case Key1:
			GPIOx=GPIOA;
			GPIO_Pin=GPIO_Pin_0;
		break;
		case Key2:
			GPIOx=GPIOE;
		  GPIO_Pin=GPIO_Pin_2;
		break;
		case Key3:
			GPIOx=GPIOE;
		  GPIO_Pin=GPIO_Pin_3;
		break;
		case Key4:
			GPIOx=GPIOE;
		  GPIO_Pin=GPIO_Pin_4;
		break;
     }
	if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin)==0)
	{
		return 0;
	}
	else {
	return 1;
	}
}
