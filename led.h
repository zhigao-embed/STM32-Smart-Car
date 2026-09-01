#ifndef _LED_H_
#define _LED_H_


#define LED1 1
#define LED2 2
#define LED3 3
#define LED4 4

#define LED_ON 0
#define LED_OFF 1
void LED_Init(void);
void LED_Ctrl(int LED_NUM, int STA);
#endif

