/**********************************************************************
版权所有：	喵呜创新科技，2017.
官		网：	http://www.miaowlabs.com
淘		宝：	https://shop275516297.taobao.com/
文 件 名: 	infrare.h
作    者:   喵呜实验室
版		本:   3.00
完成日期:   2017.03.01
概		要: 	




***********************************************************************/

#ifndef _INFRARE_H
#define _INFRARE_H


typedef enum _infrared_channel_t{
	infrared_channel_La = (0x01 << 0),
	infrared_channel_Lb = (0x01 << 1),
	infrared_channel_Lc = (0x01 << 2),
	infrared_channel_Ra = (0x01 << 4),
	infrared_channel_Rb = (0x01 << 5),
	infrared_channel_Rc = (0x01 << 6)
}infrared_channel_t;


void InfraredIOInit(void);
char InfraredDetect(void);
void InfrareSelfCheck(void);
int IsInfrareOK(void);

#endif

