/**********************************************************************
版权所有：	喵呜创新科技，2017.
官		网：	http://www.miaowlabs.com
淘		宝：	https://shop275516297.taobao.com/
文 件 名: 	communicate.h
作    者:   喵呜实验室
版		本:   3.00
完成日期:   2017.03.01
概		要: 	




***********************************************************************/
#ifndef _COMMUNICATE_H
#define _COMMUNICATE_H


typedef enum _PIDType{AnglePID, SpeedPID,}PIDType;


extern char StatusFlag;

void Parse(char *dataInput);
void ResponseIMU(void);
void ResponsePID(PIDType type);
void ResponseStatus(void);


#endif

