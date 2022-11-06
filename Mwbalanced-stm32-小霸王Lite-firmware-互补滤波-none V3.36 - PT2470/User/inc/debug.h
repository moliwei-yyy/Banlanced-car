/**********************************************************************
版权所有：	喵呜创新科技，2017.
官		网：	http://www.miaowlabs.com
淘		宝：	https://shop275516297.taobao.com/
文 件 名: 	debug.h
作    者:   喵呜实验室
版		本:   3.00
完成日期:   2017.03.01
概		要: 	




***********************************************************************/
#ifndef _DEBUG_H
#define _DEBUG_H

#include "usart.h"

#define DEBUG_EN				1


#define IMU_SCOPE_EN						0	// 使能输出模拟示波器调试信息
#define IMU_FOURAXISMONITOR_EN	1	// 使能输出四轴模拟器调试信息

#define COMMUNICATE_DEBUG_EN		0	// 使能输出蓝牙通信信调试信息
#define INFRARE_DEBUG_EN				1	// 使能输出红外寻迹调试信息


#if DEBUG_EN
#define DebugOutByte(byte)	Uart1SendByte(byte)
#define DebugOutBuff(buff, len)	Uart1SendBuff(buff, len)
#define DebugOutStr(str)		Uart1SendStr(str)
#else
#define DebugOutByte(byte)
#define DebugOutBuff(buff,len)
#define DebugOutStr(str)
#endif


void DebugService(void);




#endif 
