#include <stm32f4xx_gpio.h>
#include <delay.h>
#include <main.h>
#include <led.h>
#include <uart.h>
#include <Motor.h>
#include <red.h>
	int main()
    {
			 Red_Init();  //初始化红外传感器
       Motor_Init(); //初始化电机
			 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//中断的分组
			 Uart1_Init(9600);//初始化串口
			while(1)
			{
			    Uart1_Ctrl_Motor();//控制小车进行活动
			}
		}