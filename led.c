#include"led.h"
#include"delay.h"
#include"stm32f4xx_gpio.h"
void LED_Init()
{
  	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOF , ENABLE);
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOE , ENABLE);
	GPIO_InitTypeDef G;
	G.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10;
	G.GPIO_Speed = GPIO_Speed_50MHz; //输出速率
	 G.GPIO_OType = GPIO_OType_PP; //推挽输出
	 //G.GPIO_PuPd = GPIO_PuPd_NOPULL; //输入浮空
	 GPIO_Init(GPIOF, &G);
	 G.GPIO_Pin = GPIO_Pin_13|GPIO_Pin_14;
	 GPIO_Init(GPIOE, &G);
}
void LED_Ctrl(int LED_NUM, int STA )
{  
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;
	
	switch(LED_NUM)
	{
		case LED1: 
			GPIOx = GPIOF;
			GPIO_Pin = GPIO_Pin_9;
		break;
		case LED2: 
			GPIOx = GPIOF;
			GPIO_Pin = GPIO_Pin_10;
		break;
		case LED3: 
			GPIOx = GPIOE;
			GPIO_Pin = GPIO_Pin_13;
			break;
		case LED4: 
			GPIOx = GPIOE;
			GPIO_Pin = GPIO_Pin_14;
			break;
	}	
	GPIO_WriteBit( GPIOx, GPIO_Pin,  (BitAction)STA);
}

  
