/**********************************************************************
版权所有：	喵呜创新科技，2017.
官		网：	http://www.miaowlabs.com
淘		宝：	https://shop275516297.taobao.com/
文 件 名: 	.h
作    者:   喵呜实验室
版		本:   3.00
完成日期:   2017.03.01
概		要: 	




***********************************************************************/

#ifndef __USART_H
#define __USART_H



#define Uart3BufferSize 128

extern char Uart3Buffer[];			//蓝牙通信串口接收缓冲区
extern unsigned char Uart3Index;

void USART1Init(void);
void USART3Init(char baudrate);


void Uart1SendByte(char byte) ;
void Uart1SendBuff(char *buf, unsigned short len);
void Uart1SendStr(char * str);
	
void Uart3SendByte(char byte)  ;
void Uart3SendBuff(char *buf, unsigned short len);
void Uart3SendStr(char *str);

#define BluetoothOut(str) Uart3SendStr(str)



#endif /* __USART1_H */

