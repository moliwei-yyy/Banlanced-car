/**********************************************************************
版权所有：	喵呜创新科技，2017.
官		网：	http://www.miaowlabs.com
淘		宝：	https://shop275516297.taobao.com/
文 件 名: 	OLED.h
作    者:   喵呜实验室
版		本:   3.00
完成日期:   2017.03.01
概		要: 	




***********************************************************************/


#ifndef __OLED_H
#define __OLED_H			  	 


#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据
#define OLED_MODE 0


//OLED模式设置
//0:4线串行模式
//1:并行8080模式
#define SIZE 8
#define XLevelL		0x02
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define Brightness	0xFF 
#define X_WIDTH 	128
#define Y_WIDTH 	64	    						  

 		     

//OLED控制用函数
void OLED_WR_Byte(unsigned char dat,unsigned char cmd);	    
void OLED_Display_On(void);
void OLED_Display_Off(void);	   							   		    
void OLED_Init(void);
void OLED_Clear(void);
void OLED_DrawPoint(unsigned char x,unsigned char y,unsigned char t);
void OLED_Fill(unsigned char x1,unsigned char y1,unsigned char x2,unsigned char y2,unsigned char dot);
void OLED_ShowChar(unsigned char x,unsigned char y,unsigned char chr);
void OLED_ShowNum(unsigned char x,unsigned char y,unsigned int num,unsigned char len,unsigned char size2);
void OLED_ShowString(unsigned char x,unsigned char y, unsigned char *p);	 
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_ShowCHinese(unsigned char x,unsigned char y,unsigned char no);
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[]);
void OLED_DrawConvertBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP [ ]);

#endif  
	 



