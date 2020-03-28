#include <SoftwareSerial.h>
#include <Wire.h>
#include <JY901.h>
#include "control.h"
#define SER1_BAUD 115200
void Motor_Forward(char motor,char pwm);
void Motor_Back(char motor,char pwm);
void Motor_Left(char motor,char pwm);
void Motor_Right(char motor,char pwm);
void Motor_Turn_Left(char motor,char pwm);
void Motor_Turn_Right(char motor,char pwm);
void Motor_Stop(char motor);
char datain;

SoftwareSerial ESP01(10, 13);

void setup() {
     Serial.begin(9600);
     ESP01.begin(115200); 
}

void loop() {
  //print received data. Data was received in serialEvent;
  Serial.print("Time:20");Serial.print(JY901.stcTime.ucYear);Serial.print("-");Serial.print(JY901.stcTime.ucMonth);Serial.print("-");Serial.print(JY901.stcTime.ucDay);
 
  Serial.print("Acc:");Serial.print((float)JY901.stcAcc.a[0]/32768*16);Serial.print(" ");Serial.print((float)JY901.stcAcc.a[1]/32768*16);Serial.print(" ");Serial.println((float)JY901.stcAcc.a[2]/32768*16);
  
  Serial.print("Gyro:");Serial.print((float)JY901.stcGyro.w[0]/32768*2000);Serial.print(" ");Serial.print((float)JY901.stcGyro.w[1]/32768*2000);Serial.print(" ");Serial.println((float)JY901.stcGyro.w[2]/32768*2000);
  
  Serial.print("Angle:");Serial.print((float)JY901.stcAngle.Angle[0]/32768*180);Serial.print(" ");Serial.print((float)JY901.stcAngle.Angle[1]/32768*180);Serial.print(" ");Serial.println((float)JY901.stcAngle.Angle[2]/32768*180);
  
  Serial.println("");
  
     if (ESP01.available() > 0){
      datain = ESP01.read(); 
     }
     switch (datain)
  {
    case 'U':
       Serial.println("up"); Motor_Forward(1,50);Motor_Forward(2,50);delay(1000);
       Motor_Stop(1);Motor_Stop(2); break; 

    case 'D':
      Serial.println("down");Motor_Back(1,100);Motor_Back(2,100);delay(5000);
      Motor_Stop(1);Motor_Stop(2); break; 
    case 'L':
      Serial.println("left");  Motor_Turn_Left(1,100);Motor_Turn_Left(2,100);delay(1000);
      Motor_Stop(1);Motor_Stop(2); break; 
    case 'R':
      Serial.println("right"); Motor_Turn_Right(1,100);Motor_Turn_Right(2,100);delay(1000);
      Motor_Stop(1);Motor_Stop(2); break; 
    case 'S':
      Serial.println("stop"); Motor_Stop(1);Motor_Stop(2); break;  
    case 'z':
      Serial.println("zigzag");
               for (int i=1; i<=4;i++)
               {
               zigzag(100);
               }
               Motor_Stop(1);Motor_Stop(2);break;
    case 'c':
      Serial.println("turning right"); Motor_Forward(1,150);Motor_Forward(2,150);delay(6000);Motor_Stop(1);Motor_Stop(2); break; 
    case 'r':
      Serial.println("random"); Motor_Forward(1,random(1,255));Motor_Forward(2,random(1,255));delay(6000);Motor_Stop(1);Motor_Stop(2); break;  
defalt:
      break;

  }

}

void serialEvent() 
{
  while (Serial.available()) 
  {
    JY901.CopeSerialData(Serial.read()); //Call JY901 data cope function
  }
}
