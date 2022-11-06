/**********************************************************************
版权所有：	喵呜创新科技，2017.
官		网：	http://www.miaowlabs.com
淘		宝：	https://shop275516297.taobao.com/
文 件 名: 	mpu6050.h
作    者:   喵呜实验室
版		本:   3.00
完成日期:   2017.03.01
概		要: 	




***********************************************************************/
#ifndef __MPU6050_H__
#define __MPU6050_H__

extern short g_fGyro_x,g_fAccel_y,g_fAccel_z;

void MPU6050_Init(void);
void MPU6050_Pose(void);


#endif

