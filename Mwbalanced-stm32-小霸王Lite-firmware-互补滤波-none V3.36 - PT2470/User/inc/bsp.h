/**********************************************************************
版权所有：	喵呜创新科技，2017.
官		网：	http://www.miaowlabs.com
淘		宝：	https://shop275516297.taobao.com/
文 件 名: 	bsp.h
作    者:   喵呜实验室
版		本:   3.00
完成日期:   2017.03.01
概		要: 	



***********************************************************************/
#ifndef _BSP_H
#define _BSP_H

#include "stm32f10x_gpio.h"






#define LED1On		GPIO_ResetBits(GPIOA,GPIO_Pin_3)
#define LED1Off		GPIO_SetBits(GPIOA,GPIO_Pin_3)

#define LED2On		GPIO_ResetBits(GPIOA,GPIO_Pin_12)
#define LED2Off		GPIO_SetBits(GPIOA,GPIO_Pin_12)




void LEDToggle(void);

void BspInit(void);




#endif

