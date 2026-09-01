#include<red.h>
#include<stm32f4xx_gpio.h>
#include<Motor.h>
#include<delay.h>
void Red_Init(void)
{
	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOC , ENABLE);
	 GPIO_InitTypeDef G;
	G.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_8;
   G.GPIO_Mode = GPIO_Mode_IN; 
	G.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOC, &G);
}
void Red()
{
          int l = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_7);
          int r = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_8);
           if(r == 0 && l == 0)
          {
            car_go_on();//直行
          }
           else if(r == 1 && l == 0)
            {
           car_go_right();//右转
           	}
             else if(r == 0 && l == 1)
           {
            car_go_left();//左转
           }
            else 
           {
            car_go_stop();//停止
           }
}
void Red_Object()
{
	        int l = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_7);
          int r = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_8);
	         if(r == 1 && l == 1)
          {
            car_go_on(); //直行
						Mdelay_Lib(1000);
          }
           else if(r == 1 && l == 0)
            {
              car_go_right();//右转
							Mdelay_Lib(1000);
           	}
             else if(r == 0 && l == 1)
           {
            car_go_left();//左转
						 Mdelay_Lib(1000);
           }
            else 
           {
						 car_go_off();//先后退
						 Mdelay_Lib(1000);
						car_go_left();//再左转
						 Mdelay_Lib(1000);
				 }
			 }
