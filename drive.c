#define LOW 20;
#define MED 50;
#define HIGH 100;

/*
Move the robot in the given direction
on the motors for a period of time at a speed.
*/
void move(int msec, int speed, int m1, int m2) {
	motor[leftMotor] = speed * m1;
	motor[rightMotor] = speed * m2;
	wait1Msec(msec);
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
}

void backwards(int msec, int speed){
	move(msec, speed, 1, 1);
}

void swingTurnLeft(int msec, int speed) {
	move(msec, speed, -1, 1);
}

void swingTurnRight(int msec, int speed) {
	move(msec, speed, 1, -1);
}

void pointTurnLeft(int msec, int speed) {
	move(msec, speed, 0, 1);
}

void pointTurnRight(int msec, int speed) {
	move(msec, speed, 1, 0);
}

void forwards(int msec, int speed) {
	move(msec, speed, -1, -1);
}

int calc_time(int angle, int speed) {
	return (90/angle) * speed * 14.11;
}
