/**********************************************************************
��Ȩ���У�	���ش��¿Ƽ���2017.
��		����	http://www.miaowlabs.com
��		����	https://shop275516297.taobao.com/
�� �� ��: 	dataflash.h
��    ��:   ����ʵ����
��		��:   3.00
�������:   2017.03.01
��		Ҫ: 	




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

