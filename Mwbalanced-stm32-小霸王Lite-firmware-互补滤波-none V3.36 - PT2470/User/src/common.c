/**********************************************************************
版权所有：	喵呜创新科技，2017.
官		网：	http://www.miaowlabs.com
淘		宝：	https://shop275516297.taobao.com/
文 件 名: 	common.c
作    者:   喵呜实验室
版		本:   3.00
完成日期:   2017.03.01
概		要: 	


***********************************************************************/

#include "stdio.h"
#include "common.h"
#include "usart.h"


/*
	延时函数
*/
void delay_us(unsigned int n)
{
	unsigned char j;
	while(n--)
	for(j=0;j<10;j++);
}
void delay_ms(unsigned int n)
{
	while(n--)
	delay_us(1000);
}
void get_ms(unsigned long *time)
{
}


/*
	计算异或结果
*/
unsigned char XOR_Get(char * str, unsigned char  len)
{
	unsigned char	i=0;
	unsigned char 	sum=0;
	for(i=0; i<len; i++)
	{
		sum ^= *str++;
	}
	return sum;
}

/*
	检验异或结果是否正确
*/
unsigned char XOR_Check(char * str, unsigned char  len,unsigned char checksum)
{
	unsigned char 	sum=0;
	sum = XOR_Get(str, len);
	if(sum == checksum) return 1;
	else	return 0; 
}

/*
	计算累加和
*/
unsigned char Sum_Get(char *dat,char len)
{
	char i,sum=0;
	for(i=0; i<len;i++)
	{
		sum += *dat++;
	}
	return sum;
}

 /*
	 16位crc计算
 */
 unsigned short CRC16Calculate(unsigned char *buff, unsigned char len)
{
    unsigned short CRC_Temp;
    unsigned char i,j;
    CRC_Temp = 0xffff;

    for (i=0;i<len; i++){      
        CRC_Temp ^= buff[i];
        for (j=0;j<8;j++) {
            if (CRC_Temp & 0x01)
                CRC_Temp = (CRC_Temp >>1 ) ^ 0xa001;
            else
                CRC_Temp = CRC_Temp >> 1;
        }
    }
    return(CRC_Temp);
}


