typedef int Sun[2];

void findSun(Sun &values) {
	int min = 4100;
	int backIterate = 0;
	for(int i = 0; i < 40; i++){
		swingTurnLeft(100, 50);
		if(SensorValue[light] < min){
			min = SensorValue[light];
			backIterate = 0;
		}
		backIterate++;
	}

	for(int i = 0; i < backIterate; i++){
		swingTurnRight(105, 50);
	}

	values[0] = min;
	values[1] = backIterate;

	addToList(sun, values[1]);
}

void takeTemperature() {
	int value = SensorValue[tempsensor];
	addToList(temp, 50.5686 - 0.052071 * value);
}

void takeSalinity() {
	int value = SensorValue[tempsensor];
	int ret = 0;
	if (value > 3000) ret = 1111;
	addToList(sal, ret);
}

void takeWind() {
	float seconds = 0, speed, meters;
	int sensorData, prevSensorData;
	SensorValue[animometer] = 0;

	for (int i = 0; i < 20; i++) {
		wait1Msec(100);
		seconds += .1;
		prevSensorData = sensorData;
		sensorData = SensorValue[animometer];

		if (seconds > .1) {
			meters = (sensorData - prevSensorData) / 720.0;
		} else {
			meters = 0;
		}

		speed = meters / .1;
	}

	addToList(wind, speed);
}
