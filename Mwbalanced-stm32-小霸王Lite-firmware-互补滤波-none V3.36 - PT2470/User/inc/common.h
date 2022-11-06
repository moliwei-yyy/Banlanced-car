/**********************************************************************
版权所有：	喵呜创新科技，2017.
官		网：	http://www.miaowlabs.com
淘		宝：	https://shop275516297.taobao.com/
文 件 名: 	common.h
作    者:   喵呜实验室
版		本:   3.00
完成日期:   2017.03.01
概		要: 	


***********************************************************************/

#ifndef _COMMON_H
#define _COMMON_H

void delay_us(unsigned int n);
void delay_ms(unsigned int n);
void get_ms(unsigned long *time);


unsigned char XOR_Get(char * str, unsigned char  len);
unsigned char XOR_Check(char * str, unsigned char  len,unsigned char checksum);
unsigned char Sum_Get(char *dat,char len);
unsigned short CRC16Calculate(unsigned char *buff, unsigned char len);




#endif
