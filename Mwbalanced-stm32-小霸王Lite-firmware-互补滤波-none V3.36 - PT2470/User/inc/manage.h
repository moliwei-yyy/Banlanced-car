/**********************************************************************
版权所有：	喵呜创新科技，2017.
官		网：	http://www.miaowlabs.com
淘		宝：	https://shop275516297.taobao.com/
文 件 名: 	manage.h
作    者:   喵呜实验室
版		本:   3.00
完成日期:   2017.03.01
概		要: 	




***********************************************************************/


#ifndef _MANAGE_H
#define _MANAGE_H



#define CONTROL_MODE 			1
#define INFRARED_TRACE_MODE 	2
#define ULTRA_FOLLOW_MODE		3
#define ULTRA_AVOID_MODE	   4

extern const char FirmwareVer[];
extern const char EEPROMVer[];
extern const char MCUVer[];

extern unsigned short  g_RunTime;
extern unsigned short g_BatVolt;
extern unsigned char   g_CarRunningMode;




#endif

