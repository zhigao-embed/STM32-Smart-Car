#include<Motor.h>
#include"stm32f4xx_gpio.h"
void Motor_Init(void)
{
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOB , ENABLE);
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOA , ENABLE);
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOD , ENABLE);
	 GPIO_InitTypeDef G;
   G.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;
   G.GPIO_Mode = GPIO_Mode_OUT; 
   G.GPIO_Speed = GPIO_Speed_50MHz; 
   G.GPIO_OType = GPIO_OType_PP;
   GPIO_Init(GPIOD, &G);
	 G.GPIO_Pin = GPIO_Pin_7;
	GPIO_Init(GPIOB, &G);
	G.GPIO_Pin = GPIO_Pin_4;
	GPIO_Init(GPIOA, &G);
}
void Set_Left_A(int sta) //?????????????
    {
        GPIO_WriteBit(GPIOB,  GPIO_Pin_7 , (BitAction)sta);
    }

	void Set_Left_B(int sta) 
    {
        GPIO_WriteBit(GPIOA,  GPIO_Pin_4, (BitAction)sta);
    }	

	void Set_Right_A(int sta) 
    {  
        GPIO_WriteBit(GPIOD,  GPIO_Pin_6 , (BitAction)sta);
    }

	void Set_Right_B(int sta) 
    {
        GPIO_WriteBit(GPIOD,  GPIO_Pin_7, (BitAction)sta);
    }	
void car_go_on(void)
    {
       	Set_Left_A(1);// <- 1
        Set_Left_B(0);// <- 0
        Set_Right_A(1); // <- 1
        Set_Right_B(0);// <- 0
    }
void car_go_off(void)
    {
       	Set_Left_A(0);// <- 0
        Set_Left_B(1);// <- 1
        Set_Right_A(0); // <- 0
        Set_Right_B(1);// <- 1
    }
	//?? 
	void car_go_stop(void)
    {
       	Set_Left_A(0);
        Set_Left_B(0);
        Set_Right_A(0);
        Set_Right_B(0);
    }
	
	//?? (????,????)
	void car_go_left(void)
    {
			  Set_Left_A(0);
        Set_Left_B(1);
        Set_Right_A(1);
        Set_Right_B(0);
		}

	//?? (????,????)
	void car_go_right(void)
    {
			Set_Left_A(1);
        Set_Left_B(0);
        Set_Right_A(0);
        Set_Right_B(1);
		}

