/**********************************************************************
��Ȩ���У�	���ش��¿Ƽ���2017.
��		����	http://www.miaowlabs.com
��		����	https://shop275516297.taobao.com/
�� �� ��: 	common.h
��    ��:   ����ʵ����
��		��:   3.00
�������:   2017.03.01
��		Ҫ: 	


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
