/**********************************************************************
版权所有：	喵呜创新科技，2017.
官		网：	http://www.miaowlabs.com
淘		宝：	https://miaowlabs.taobao.com/
文 件 名: 	display.c
作    者:   喵呜实验室
版		本:   3.00
完成日期:   2017.03.01
概		要: 	


***********************************************************************/

#include "stdio.h"
#include "oled.h"
#include "bmp.h"
#include "control.h"
#include "ultrasonic.h"
#include "mpu6050.h"
#include "common.h"
#include "manage.h"
#include "bsp.h"

extern unsigned short BatVol;



/*
	显示logo
*/
void ShowHomePageInit(void)
{
	OLED_DrawBMP(0,0,128,8,LOGO);  //图片显示
	delay_ms(1000);
	OLED_Clear();
}


/*
	oled主页刷新函数
	分六步刷新，避免一次刷新时间过长
*/

void ShowHomePage(void)
{
	unsigned char buff[32]={0};
	static char step = 0;

	step++;
	if(step >= 6)step = 0;

	//分步执行，缩短单次刷屏时间
	if(step == 0){
		OLED_ShowString(0, 0, "Mode: Complementary  ");
	}

	if(step == 1){
		if(IsUltraOK())
			snprintf((char*)buff, 21,  "Distance:  %d(cm)       ", Distance);
		else
			snprintf((char*)buff, 21,  "Distance:  %s(cm)       ", "xx");
		
		OLED_ShowString(0, 1, buff);
	}

	if(step == 2){
		snprintf((char*)buff, 21,  "EncoLeft:  %d         ",g_s16LeftMotorPulse);
		OLED_ShowString(0, 2, buff);
	}
	if(step == 3){
		snprintf((char*)buff, 21, "EncoRight: %d         ",g_s16RightMotorPulse);
		OLED_ShowString(0, 3, buff);
	}
	
	if(step == 4){
		snprintf((char*)buff, 21, "Angle:     %0.1f      ", g_fCarAngle);
		OLED_ShowString(0, 4, buff);
	}
	if(step == 5){
		snprintf((char*)buff, 21, "Battery:   %0.1f(V)      ", g_BatVolt/100.0);
		OLED_ShowString(0, 5, buff);		
		}
}


