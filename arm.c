void forwards(int speed) {
	motor[leftMotor] = speed;
	motor[rightMotor] = speed;
}

void turn(int speed) {
	motor[leftMotor] = -speed;
	motor[rightMotor] = speed;
}

int highArmTarget;

void moveBack(){
	while(SensorValue[quad1] > 1){
		motor[leftArmMotor] = 50;
		motor[rightArmMotor] = -50;
	}

		motor[leftArmMotor] = 0;
		motor[rightArmMotor] = 0;
}

void moveLowArm(int target){
	while(SensorValue[quad1] < target){
		writeDebugStreamLine("val : %d",SensorValue[quad1]);
		motor[leftArmMotor] = -50;
		motor[rightArmMotor] = 50;
	}
	int endValue = SensorValue[quad1];
	int stayValue = 30;
	bool stall = true;

	while(stall){
	//while(1==1){
		if(vexRT[Btn7R] == 1){
			stall = false;
			moveBack();
		}
		if(SensorValue[quad1] < endValue){
			motor[leftArmMotor] = -stayValue;
			motor[rightArmMotor] = stayValue;
		} else{
			motor[leftArmMotor] = stayValue;
			motor[rightArmMotor] = -stayValue;
		}
	}
}
/*
void moveHighArm(int target){
	while(-SensorValue[quad2] < target){
		writeDebugStreamLine("val : %d",-SensorValue[quad2]);
		motor[topArmMotor] = -50;
	}
	int endValue = -SensorValue[quad2];
	int stayValue = 15;
	//while(vexRT[Btn7U] == 1){
	while(1==1){
		if(-SensorValue[quad2] < endValue){
			motor[topArmMotor] = -stayValue;
			writeDebugStreamLine("chicken val : %d",-SensorValue[quad2]);
		} else{
			motor[topArmMotor] = stayValue;
			writeDebugStreamLine("noodle val : %d",SensorValue[quad2]);
		}
}
}
(*/

task moveHighArm() {
	int target = highArmTarget;
	while(-SensorValue[quad2] < target){
		writeDebugStreamLine("val : %d",-SensorValue[quad2]);
		motor[topArmMotor] = -40;
	}

	int endValue = -SensorValue[quad2];
	int stayValue = 30;
	bool stall = true;

	while(stall){
	//while(1==1){
		if(vexRT[Btn7R] == 1){
		stall = false;
		}
		if(-SensorValue[quad2] < endValue){
			motor[topArmMotor] = -stayValue;
			writeDebugStreamLine("chicken val : %d",-SensorValue[quad2]);
		} else{
			motor[topArmMotor] = stayValue;
			writeDebugStreamLine("noodle val : %d",SensorValue[quad2]);
		}
	}

}

void moveFlag(){
	highArmTarget = 100;
	startTask(moveHighArm);
	wait10Msec(15);
	moveLowArm(90);
}
