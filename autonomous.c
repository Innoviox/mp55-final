void autonomous() {
    takeWind();
    pointTurnLeft(calc_time(45, 50), 50);
    backwards(2000, 50);
    pointTurnRight(calc_time(180, 50), 50);
    backwards(1000, 50);
    wait1MSecs(1000);
    forwards(1000, 50);
    Sun sunValue;
    findSun(sunValue);
}
