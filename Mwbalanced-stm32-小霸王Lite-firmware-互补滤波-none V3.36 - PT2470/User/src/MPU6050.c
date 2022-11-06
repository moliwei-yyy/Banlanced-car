/**********************************************************************
��Ȩ���У�	���ش��¿Ƽ���2017.
��		����	http://www.miaowlabs.com
��		����	https://miaowlabs.taobao.com/
�� �� ��: 	MPU6050.c
��    ��:   ����ʵ����
��		��:   3.00
�������:   2017.03.01
��		Ҫ: 	


***********************************************************************/

#include "I2C.h"

/*
* ����MPU6050�ڲ���ַ
*/
#define MPU6050_ADDR  0x68
#define	SMPLRT_DIV		0x19	//�����ǲ����ʣ�����ֵ��0x07(125Hz)
#define	CONFIG				0x1A	//��ͨ�˲�Ƶ�ʣ�����ֵ��0x06(5Hz)
#define	GYRO_CONFIG		0x1B	//�������Լ켰������Χ������ֵ��0x18(���Լ죬2000deg/s)
#define	ACCEL_CONFIG	0x1C	//���ټ��Լ졢������Χ����ͨ�˲�Ƶ�ʣ�����ֵ��0x01(���Լ죬2G��5Hz)
#define	ACCEL_XOUT_H	0x3B
#define	ACCEL_XOUT_L	0x3C
#define	ACCEL_YOUT_H	0x3D
#define	ACCEL_YOUT_L	0x3E
#define	ACCEL_ZOUT_H	0x3F
#define	ACCEL_ZOUT_L	0x40
#define	TEMP_OUT_H		0x41
#define	TEMP_OUT_L		0x42
#define	GYRO_XOUT_H		0x43
#define	GYRO_XOUT_L		0x44	
#define	GYRO_YOUT_H		0x45
#define	GYRO_YOUT_L		0x46
#define	GYRO_ZOUT_H		0x47
#define	GYRO_ZOUT_L		0x48
#define	PWR_MGMT_1		0x6B	//��Դ��������ֵ��0x00(��������)
#define	WHO_AM_I		0x75	//IIC��ַ�Ĵ���(Ĭ����ֵ0x68��ֻ��)


typedef enum _axis_t{x_Axis, y_Axis, z_Axis}axis_t;

short g_fGyro_x,g_fAccel_y,g_fAccel_z;

void MPU6050_Init(void)
{
	unsigned char buff[5] = {0x00,0x07,0x04,0x18,0x01};
	i2cwrite(MPU6050_ADDR,PWR_MGMT_1, 1,&buff[0]);   //�������״̬
	i2cwrite(MPU6050_ADDR,SMPLRT_DIV, 1,&buff[1])  ; //������125hz
	i2cwrite(MPU6050_ADDR,CONFIG, 1,&buff[2])      ; //Accelerometer:21hz 8.5ms ; Gyroscope:20hz 8.3ms
	i2cwrite(MPU6050_ADDR,GYRO_CONFIG, 1,&buff[3]) ; //��2000��/s  
	i2cwrite(MPU6050_ADDR,ACCEL_CONFIG, 1,&buff[4]); //��2g
}

/*
* ��ȡһ��16λ����
*/
short DataSynthesis(unsigned char REG_Address)	
{
	unsigned char  uByte[2]; 

	i2cread(MPU6050_ADDR,REG_Address,2,uByte)  ;

	return ((uByte[0] << 8) + uByte[1]);   /*���غϳ�����*/
}

/*
* ��ȡ���ٶ�����
*/
short ReadAcceData(axis_t  axis)
{
	short temp = 0;
	
	if(axis == x_Axis)
		temp = DataSynthesis(ACCEL_XOUT_H); 
	else if(axis == y_Axis)
		temp = DataSynthesis(ACCEL_YOUT_H); 
	else if(axis == z_Axis)
		temp = DataSynthesis(ACCEL_ZOUT_H); 

	return temp;
}

/*
* ��ȡ�����ǽ��ٶ�����
*/
short ReadGyroData(axis_t  axis)
{
	short temp = 0;
	
	if(axis == x_Axis)
		temp = DataSynthesis(GYRO_XOUT_H); 
	else if(axis == y_Axis)
		temp = DataSynthesis(GYRO_YOUT_H); 
	else if(axis == z_Axis)
		temp = DataSynthesis(GYRO_ZOUT_H);
	
	return temp;
}

void MPU6050_Pose(void)
{	
	g_fGyro_x = ReadGyroData(x_Axis); //������x��
	g_fAccel_y = ReadAcceData(y_Axis); //���ٶ�y�� 
		g_fAccel_z = ReadAcceData(z_Axis); //���ٶ�z��
}


