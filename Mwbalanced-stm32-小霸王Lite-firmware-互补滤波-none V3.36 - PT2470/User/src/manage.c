/**********************************************************************
版权所有：	喵呜创新科技，2017.
官		网：	http://www.miaowlabs.com
淘		宝：	https://miaowlabs.taobao.com/
文 件 名: 	manage.c
作    者:   喵呜实验室
版		本:   3.00
完成日期:   2017.03.01
概		要: 	


***********************************************************************/

#include "manage.h"



const char FirmwareVer[] = "3.33";
const char EEPROMVer[]  = "2.00";
const char MCUVer[] = "STM32F103C8T6";

//系统运行时间计数，，开机后开始计数，每秒增1
unsigned short  g_RunTime = 0;

//电池电压，实际值*100
unsigned short  g_BatVolt=0;

//小车运行模式:遥控模式、红外寻迹模式，超声波避障、超声波跟随模式
unsigned char g_CarRunningMode = CONTROL_MODE;//默认为遥控模式

//以下定义在manage.h中
//#define CONTROL_MODE 			1   遥控模式
//#define INFRARED_TRACE_MODE 	2    红外寻迹模式
//#define ULTRA_FOLLOW_MODE		3       超声波跟随模式
//#define ULTRA_AVOID_MODE	   4      超声波避障模式
