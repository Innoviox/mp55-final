#pragma config(Sensor, in1,    light,          sensorReflection)
#pragma config(Sensor, in2,    tempsensor,     sensorReflection)
#pragma config(Sensor, dgtl1,  quad1,          sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  quad2,          sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  animometer,     sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  status,         sensorLEDtoVCC)
#pragma config(Sensor, dgtl8,  one,            sensorLEDtoVCC)
#pragma config(Sensor, dgtl9,  two,            sensorLEDtoVCC)
#pragma config(Sensor, dgtl10, three,          sensorLEDtoVCC)
#pragma config(Sensor, dgtl11, four,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl12, five,           sensorLEDtoVCC)
#pragma config(Motor,  port2,           leftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftArmMotor,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           topArmMotor,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightArmMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           rightMotor,    tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "drive.c"
#include "data-export.c"
#include "data-take.c"
#include "arm.c"
#include "autonomous.c"

bool isDrive = true;
Sun sunValues;

task main()
{
    int count = 0;
    while (1==1) {
        bool stay = true;
        
        if (vexRT[Btn8L] == 1) {
            findSun(sunValues);
            isData = false;
        } else if (vexRT[Btn8U] == 1) {
            takeWind();
            isData = false;
        } else if (vexRT[Btn8R] == 1) {
            takeSalinity();
            isData = false;
        } else if (vexRT[Btn8D] == 1) {
            takeTemperature();
            isData = false;
        }
        if (isDrive) {
            turn(vexRT[Ch1] / -2);
            forwards(vexRT[Ch3] / -2);
            if (vexRT[Btn7U] == 1) {
                autonomous();
            } else if (vexRT[Btn8R] == 1) {
                displayData();
            }
        } else {
            if (vexRT[Btn5D] == 1) {
                moveHighArm(50);
            } else if (vexRT[Btn5U] == 1) {
                moveHighArm(90);
            } else if (vexRT[Btn6D] == 1) {
                moveFlag();
            } else if (vexRT[Btn6U] == 1) {
                //moveHighArm(145);
            }
            
            ---
            int stayValue = 30;
            if (vexRT[Ch1] == 0) {
                if(stay){
                        motor[topArmMotor] = -stayValue;
                    } else{
                        motor[topArmMotor] = stayValue;
                    }
            } else {
                motor[topArmMotor] = vexRT[Ch1] / 3;
            }

            if (vexRT[Ch3] == 0){
                if(stay){
                        motor[leftArmMotor] = -stayValue;
                        motor[rightArmMotor] = stayValue;
                    } else{
                        motor[leftArmMotor] = stayValue;
                        motor[rightArmMotor] = -stayValue;
                    }
            } else {
                motor[leftArmMotor] = vexRT[Ch3] / 2;
                motor[rightArmMotor] = -vexRT[Ch3] / 2;
            }
            
            count = count + 1;
            if(count > 20){
                count = 0;
                if(stay){
                    stay = false;
                }else{
                    stay = true;
                }
            }
            ---
        }
        
        if (vexRT[Btn7L] == 1) {
            isDrive = !isDrive;
        }
    }
}