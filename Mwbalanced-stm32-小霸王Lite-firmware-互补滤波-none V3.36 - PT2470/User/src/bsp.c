/**********************************************************************
版权所有：	喵呜创新科技，2017.
官		网：	http://www.miaowlabs.com
淘		宝：	https://miaowlabs.taobao.com/
文 件 名: 	bsp.c
作    者:   喵呜实验室
版		本:   3.00
完成日期:   2017.03.01
概		要: 	


***********************************************************************/

#include "stdio.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_tim.h"
#include "common.h"
#include "MPU6050.h"
#include "oled.h"
#include "bsp.h"
#include "ADC.h"
#include "usart.h"
#include "motor.h"
#include "I2C.h"
#include "ultrasonic.h"
#include "infrare.h"


/* 
	使能SWD， 失能JTAG
	PB3,PB4,PA15做普通IO使用（必须失能JTAG） 
*/
void SWDConfig(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);	
}



void LEDInit(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

  /* GPIOB clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); 

  /*GPIOB Configuration*/
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_12;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		    // 复用推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
}
void LEDToggle(void)
{
	static char flag=0;
	if(flag==0)
	{
		flag = 1;
		GPIO_SetBits(GPIOB, GPIO_Pin_12);
	}
	else{
		flag = 0;
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);
	}
}
/*
	读取单片机12字节 ID
*/
#define UniqueID_Addr 0x1FFFF7E8U
void GetUniqueID(char* ID)
{
	char i;
	char *p = (char*)UniqueID_Addr; 
	for(i=0; i<12; i++){
		*ID++ = *p++;
	}
}


/*
	设置蓝牙名称
*/
void SetBlueToothName(void)
{
	char temp[32];
	char check;
	GetUniqueID(temp);
	check = XOR_Get(temp, 12);
	sprintf(temp, "AT+NAMEMiaowLabs-%04X\r\n",(int)check);
	Uart3SendStr(temp);
	delay_ms(100);
}


/*
	bsp初始化
*/
void BspInit(void)
{
	SWDConfig();
	
	ADCInit();				//ADC初始化

	USART1Init();			//串口1初始化-底板预留下载及调试用
	USART3Init(0);			//串口3初始化-用于蓝牙

	TIM1_Cap_Init();		//TIM1初始化-用于超声波跟随功能
	TIM3_PWM_Init(); 		//PWM初始化
	TIM2_Encoder_Init();	//TIM2正交解码初始化-用于测速
	TIM4_Encoder_Init();	//TIM4正交解码初始化-用于测速
	
	i2cInit();	 			//I2C初始化
	
	InfraredIOInit();		//红外IO口初始化

	OLED_Init();			//OLED初始化
	delay_ms(20);
	MPU6050_Init();		    //MPU6050初始化
	
	LEDInit();				//指示灯初始化
	
	UltraSelfCheck();							//	超声模块开机自检
	InfrareSelfCheck();						//  红外模块开机自检
	
	delay_ms(500);			//延时0.5s，等待蓝牙模块启动
	Uart3SendStr("AT+BAUD8\r\n"); //配置蓝牙串口波特率为115200 ( 原波特率9600 ) 
	delay_ms(20);
	Uart3SendStr("AT+RESET\r\n");  //蓝牙复位
	USART3Init(1);					//更改UART3波特率为115200
	delay_ms(20);
	SetBlueToothName();		//配置蓝牙模块名称
	Uart3SendStr("AT+RESET\r\n");  //蓝牙复位
}

