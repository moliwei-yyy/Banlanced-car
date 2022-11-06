/**********************************************************************
��Ȩ���У�	���ش��¿Ƽ���2017.
��		����	http://www.miaowlabs.com
��		����	https://shop275516297.taobao.com/
�� �� ��: 	common.c
��    ��:   ����ʵ����
��		��:   3.00
�������:   2017.03.01
��		Ҫ: 	


***********************************************************************/

#include "stdio.h"
#include "common.h"
#include "usart.h"


/*
	��ʱ����
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
	���������
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
	����������Ƿ���ȷ
*/
unsigned char XOR_Check(char * str, unsigned char  len,unsigned char checksum)
{
	unsigned char 	sum=0;
	sum = XOR_Get(str, len);
	if(sum == checksum) return 1;
	else	return 0; 
}

/*
	�����ۼӺ�
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
	 16λcrc����
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


