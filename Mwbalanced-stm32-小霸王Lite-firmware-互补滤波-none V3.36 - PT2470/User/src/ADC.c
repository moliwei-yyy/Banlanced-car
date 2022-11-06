/**********************************************************************
版权所有：	喵呜创新科技，2017.
官		网：	http://www.miaowlabs.com
淘		宝：	https://shop275516297.taobao.com/
文 件 名: 	ADC.c
作    者:   喵呜实验室
版		本:   3.00
完成日期:   2017.03.01
概		要: 	


***********************************************************************/

#include "stm32f10x_adc.h"
#include "ADC.h"




/*
	ADC 初始化(用于电池电压采集)
*/
void ADCInit(void)
{
  ADC_InitTypeDef ADC_InitStructure;
  GPIO_InitTypeDef GPIO_InitStructure;

  /* Enable ADC1 and GPIOA clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 | RCC_APB2Periph_GPIOA, ENABLE);
  RCC_ADCCLKConfig(RCC_PCLK2_Div6); //12MHZ 
    
  /* Configure PA.4 (ADC Channel) as analog input -------------------------*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
     
  /* ADC1 configuration ------------------------------------------------------*/
  ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
  ADC_InitStructure.ADC_ScanConvMode = DISABLE;
  ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
  ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
  ADC_InitStructure.ADC_NbrOfChannel = 5;
  ADC_Init(ADC1, &ADC_InitStructure);
 
	ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 1, ADC_SampleTime_55Cycles5);

  ADC_Cmd(ADC1, ENABLE);

  /* Enable ADC1 reset calibration register */   
  ADC_ResetCalibration(ADC1);
  /* Check the end of ADC1 reset calibration register */
  while(ADC_GetResetCalibrationStatus(ADC1));
  /* Start ADC1 calibration */
  ADC_StartCalibration(ADC1);
  /* Check the end of ADC1 calibration */
  while(ADC_GetCalibrationStatus(ADC1));
  ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}

/*
	读取电池电压,返回值为实际值x100
*/
unsigned short GetBatVoltage(void)
{
	float fTemp = 0;
	unsigned short sTemp=0;
	sTemp = ADC_GetConversionValue(ADC1);
	fTemp = sTemp*0.4834; // 0.4834= ((3.3/4096)/(2/(10+2))) * 100
	return (unsigned short)fTemp; // 返回值为实际值的100倍
}

