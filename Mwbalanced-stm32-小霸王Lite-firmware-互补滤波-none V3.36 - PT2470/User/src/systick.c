/**********************************************************************
版权所有：	喵呜创新科技，2017.
官		网：	http://www.miaowlabs.com
淘		宝：	https://miaowlabs.taobao.com/
文 件 名: 	systick.c
作    者:   喵呜实验室
版		本:   3.00
完成日期:   2017.03.01
概		要: 	


***********************************************************************/
#include "stm32f10x.h"

#include "SysTick.h"

// 系统软件定时器，分辨率为1ms，递减计数
unsigned short SoftTimer[5] = {0, 0, 0, 0, 0};

void SoftTimerCountDown(void)
{
	char i;
	for(i = 0;  i < 5; i++){
		if(SoftTimer[i] > 0)SoftTimer[i]--;
	}
}

/*
 * 函数名：SysTick_Init
 * 描述  ：启动系统滴答定时器 SysTick
 * 输入  ：无
 * 输出  ：无
 * 调用  ：外部调用 
 */
void SysTick_Init(void)
{
	/* SystemFrequency / 100     10ms中断一次
	   SystemFrequency / 1000    1ms中断一次
	 * SystemFrequency / 100000	 10us中断一次
	 * SystemFrequency / 1000000 1us中断一次
	 */
	SystemCoreClockUpdate();

	if (SysTick_Config(SystemCoreClock / 1000))	// ST3.5.0库版本
	{ 
		/* Capture error */ 
		while (1);
	}
	// 开启滴答定时器  
	SysTick->CTRL |=  SysTick_CTRL_ENABLE_Msk;
}


