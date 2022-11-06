/**********************************************************************
版权所有：	喵呜创新科技，2017.
官		网：	http://www.miaowlabs.com
淘		宝：	https://shop275516297.taobao.com/
文 件 名: 	systick.h
作    者:   喵呜实验室
版		本:   3.00
完成日期:   2017.03.01
概		要: 	




***********************************************************************/

#ifndef __SYSTICK_H
#define __SYSTICK_H

#include "stm32f10x.h"


extern unsigned short SoftTimer[5];

void SoftTimerCountDown(void);
void SysTick_Init(void);


#endif /* __SYSTICK_H */

