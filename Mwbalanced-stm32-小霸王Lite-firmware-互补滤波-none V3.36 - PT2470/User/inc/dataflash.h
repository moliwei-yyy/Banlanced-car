/**********************************************************************
版权所有：	喵呜创新科技，2017.
官		网：	http://www.miaowlabs.com
淘		宝：	https://shop275516297.taobao.com/
文 件 名: 	dataflash.h
作    者:   喵呜实验室
版		本:   3.00
完成日期:   2017.03.01
概		要: 	




***********************************************************************/

#ifndef _DATAFLASH_H
#define _DATAFLASH_H


void ProgramFlash(unsigned int addr, char* data, unsigned short len);
void ReadFlash(unsigned int addr, char* data, unsigned short len);
void PIDInit(void);
void PIDWrite(char flag);
void PIDRead(void);
void PIDReset(char flag);


#endif

