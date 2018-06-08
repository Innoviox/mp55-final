int data[100];
string types[100];
int addData = 0, addType = 0;

/*
A sentinel value tells the program that
the array has no more data after this point.
*/
int SENTINEL_INT = 99999;
string SENTINEL_STR = "sentinel";

/*
Values for types of data.
*/
string t = "testing", wind="wind", sun="sun", sal="salinity", temp="temperature";

/*
This function sets a given LED to its digit number.
Any number not 1-5 sets status. (usually 0).
*/
void set(int number, int value) {
	switch (number) {
		case 1: SensorValue[one] = value; break;
		case 2: SensorValue[two] = value; break;
		case 3: SensorValue[three] = value; break;
		case 4: SensorValue[four] = value; break;
		case 5: SensorValue[five] = value; break;
		default: SensorValue[status] = value; break;
	}
}

void setAll(int value) {
	for (int i = 0; i <= 5; i++) {
		set(i, value);
	}
}
/*
Clears all of the LEDs.
*/
void clear() {
	setAll(0);
}

/*
Turn on all the LEDs for one second, then
turn them off.
*/
void test() {
	setAll(1);
	wait1Msec(100);
	clear();
}

/*
Display a value using the Compressed DSub Algorithm.

For each digit, if it is 1-5, flash the corresponding
LED. If it is 6-9, flash the corresponding LED to
the digit - 5 (1-4), as well as the status LED. Each
LED flashes for 400 milliseconds, and then the algorithm
pauses for 100 milliseconds.
*/
void displayInt(int value, bool shouldClear=true) {
	clear();
	string digits;
	sprintf(digits, "%d", value);
	for (int i = 0; i < strlen(digits); i++) {
		int disp = strIndex(digits, i) - 48;
		if (disp > 5) {
			set(disp-5, 1);
			set(0, 1);
		} else {
			set(disp, 1);
		}
		if (shouldClear) {
			wait1Msec(400);
			clear();
			wait1Msec(100);
		}
	}
}

void displayStr(string value) {
	switch (strIndex(value, 1)) {
		case 'i': displayInt(1, false); break; // wind
		case 'u': displayInt(2, false); break; // sun
		case 'a': displayInt(3, false); break; // salinity
		case 'e': displayInt(4, false); break; // temperature
		default: displayInt(0, false); break;
	}
}

void blinkStatus() {
	for (int i = 0; i < 10; i++) {
		set(0, 1);
		wait1Msec(50);
		set(0, 0);
		wait1Msec(50);
	}
}

bool displayData() {
	string previous, current;
	for (int i = 0; i < 100; i++) {
		if (data[i] == SENTINEL_INT) {
			return true;
		}

		current = types[i];
		if (current != previous) {
			displayStr(current);
			// wait1Msec(500);
			blinkStatus();
			clear();
			test();
		}
		previous = types[i];

		displayInt(data[i]);
		// wait1Msec(200);
		clear();
		test();
	}
	return false;
}

void addToList(string type, int value) {
	types[addType++] = type;
	data[addData++] = value;

	types[addType] = SENTINEL_STR;
	data[addData] = SENTINEL_INT;
}

void test_data_arr()
{
	data[0] = SENTINEL_INT;
	types[0] = SENTINEL_STR;


	test();
	addToList(sun, 5);
	addToList(sun, 10);
	addToList(sun, 19);
	// addToList(wind, 15);
	// addToList(wind, 516);
	// addToList(wind, 140);
	displayData();
}
