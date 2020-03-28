#include <Arduino.h>
#define PWMA_IN1 3        //定义IN3引脚
#define PWMA_IN2 5        //定义IN4引脚
#define PWMB_IN1 6        //定义IN3引脚
#define PWMB_IN2 9        //定义IN4引脚

void Motor_Forward(char motor,char pwm) //电机正转
{
  if(motor==1)
  {
     analogWrite(PWMA_IN1,pwm);
     analogWrite(PWMA_IN2,255);
  }
  else if(motor==2)
  {
     analogWrite(PWMB_IN1,pwm);
     analogWrite(PWMB_IN2,255); 
  }
}

void Motor_Back(char motor,char pwm)//电机反转
{
  if(motor==1)
  {
     analogWrite(PWMA_IN1,255);
     analogWrite(PWMA_IN2,pwm);
  }
  else if(motor==2)
  {
     analogWrite(PWMB_IN1,255);
     analogWrite(PWMB_IN2,pwm); 
  }
}


void Motor_Turn_Left(char motor,char pwm) //差速左转-1正2反
{
    if(motor==1)
  {
     analogWrite(PWMA_IN1,pwm);
     analogWrite(PWMA_IN2,255);
  }
  else if(motor==2)
  {
     analogWrite(PWMB_IN1,255);
     analogWrite(PWMB_IN2,255); 
  }
}

void Motor_Turn_Right(char motor,char pwm) //差速右转-1反2正
{
    if(motor==1)
  {
     analogWrite(PWMA_IN1,255);
     analogWrite(PWMA_IN2,255);
  }
  else if(motor==2)
  {
     analogWrite(PWMB_IN1,pwm);
     analogWrite(PWMB_IN2,255); 
  }
}

void Motor_Stop(char motor)
{
    if(motor==1)
  {
     analogWrite(PWMA_IN1,255);
     analogWrite(PWMA_IN2,255);
  }
  else if(motor==2)
  {
     analogWrite(PWMB_IN1,255);
     analogWrite(PWMB_IN2,255); 
  }
}

void zigzag(char speedvalue)
{
    Motor_Turn_Right(1,speedvalue);
    Motor_Turn_Right(2,speedvalue);
    delay(800); 

    Motor_Turn_Left(1,speedvalue);
    Motor_Turn_Left(2,speedvalue);
    delay(800); 
}
