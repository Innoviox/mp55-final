void autonomous() {
	pointTurnLeft(calc_time(90, 50), 50);
    forwards(2000, 50);
    takeTemperature();
    moveFlag();
    takeTemperature();
    takeSalinity();
    moveBack();
    pointTurnRight(calc_time(180, 50), 50);
    forwards(2000, 50);
    pointTurnLeft(calc_time(90, 50), 50);
}
