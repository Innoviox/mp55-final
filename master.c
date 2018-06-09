while (1==1) {
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
        if(vexRT[Btn5D] == 1){
            moveLowArm(90);
        }else if(vexRT[Btn5U] == 1){
            moveLowArm(145);
        }else if(vexRT[Btn6D] == 1){
            moveFlag();
        }else if(vexRT[Btn6U] == 1){
            //moveHighArm(145);
        }
        motor[topArmMotor] = vexRT[Ch1] / 3;
        motor[leftArmMotor] = vexRT[Ch3] / 2;
        motor[rightArmMotor] = -vexRT[Ch3] / 2;
    }
    
    if (vexRT[Btn7L] == 1) {
        isDrive = !isDrive;
    }
}
