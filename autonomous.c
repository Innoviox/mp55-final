void autonomous() {
	pointTurnLeft(calc_time(45, 50), 50);
	backwards(2000, 50);
	pointTurnRight(calc_time(180, 50), 50);
	forwards(1000, 50);
	moveFlag();
	retractFlag();
	takeTemperature();
	pointTurnRight(calc_time(90, 50), 50);
	forwards(500, 50);
	moveFlag();
	takeTemperature();
	takeSalinity();
	retractFlag();
	pointTurnRight(calc_time(135, 50), 50);
}
