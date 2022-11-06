#ifndef __CONTROL_H
#define __CONTROL_H


typedef struct _PID_t{
	float P;
	float I;
	float D;
}PID_t;

#define ACCEL_SENSITIVITY  16384.0
#define GYRO_SENSITIVITY 16.4
#define M_PI 3.14159265359
#define    GYRO_OFFSET      0          //陀螺仪零点偏移值
//#define 	 GRAVITY_OFFSET   (g_iGravity_Offset)      			//
#define    CAR_ZERO_ANGLE   (2)
#define CAR_ANGLE_SET 0
#define CAR_ANGLE_SPEED_SET 0
/******速度控制相关宏定义******/
#define CAR_POSITION_SET      0
#define CAR_SPEED_SET         g_iCarSpeedSet
#define MOTOR_LEFT_SPEED_POSITIVE  (g_fLeftMotorOut >0)
#define MOTOR_RIGHT_SPEED_POSITIVE (g_fRightMotorOut>0)
#define SPEED_CONTROL_PERIOD	 25	    //速度环控制周期
#define CAR_SPEED_CONSTANT		(1000.0/(float)SPEED_CONTROL_PERIOD/(float)OPTICAL_ENCODE_CONSTANT)
#define CAR_POSITION_MAX	700
#define CAR_POSITION_MIN	(-900)
/******电机控制相关宏定义******/
#define MOTOR_OUT_DEAD_VAL       0	   //死区值8
#define MOTOR_OUT_MAX           999	   //占空比正最大值
#define MOTOR_OUT_MIN         (-999)   //占空比负最大值


extern short  g_s16LeftMotorPulse;
extern short  g_s16RightMotorPulse;

extern int  g_s32LeftMotorPulseSigma;
extern int  g_s32RightMotorPulseSigma;

extern int  g_iGravity_Offset;

extern float g_fCarAngle;         		
extern float g_fGyroAngleSpeed;		   			
extern float g_fGravityAngle;			

extern PID_t g_tCarAnglePID;
extern PID_t g_tCarSpeedPID;

extern float g_fBluetoothSpeed;
extern float g_fBluetoothDirection;
extern unsigned char g_u8MainEventCount;
extern unsigned char g_u8SpeedControlCount;
extern unsigned char g_u8SpeedControlPeriod;
extern unsigned char g_u8DirectionControlPeriod;
extern unsigned char g_u8DirectionControlCount;


void CarUpstandInit(void);
void MotorManage(void);
void AngleControl(void)	 ;
void MotorOutput(void);
void SpeedControl(void);
void BluetoothControl(void)	;
void GetMotorPulse(void);
void AngleCalculate(void);
void SpeedControlOutput(void);
void DirectionControlOutput(void);
void DirectionControl(void); 
void Steer(float direct, float speed);
void UltraControl(int mode);

void TailingControl(void);


#endif
