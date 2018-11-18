const int MOTORCON = 15;
const int BASEPOWER = 10;

float degreesToMM(int degrees)
{
	return ((float)degrees/15);
}

float rad(float deg)
{
    return deg*PI/180.0;
}

void drawDiag(bool north, int angle, bool east, float dist)
{
		nMotorEncoder[motorA]=0;
		nMotorEncoder[motorB]=0;
		nMotorEncoder[motorC]=0;
    int dirX, dirY;
    float Xdist, Ydist, powerX, powerY;

    if(north)
        dirX = 1;
    else
        dirX = -1;
    if(east)
        dirY = 1;
    else
        dirY = -1;

    Xdist = dirX * dist * cos(rad(angle));
    Ydist = dirY * dist * sin(rad(angle));

    powerX = dirX * BASEPOWER*cos(rad(angle));
    powerY = dirY * BASEPOWER*sin(rad(angle));

    /*
    displayBigTextLine(0, "Xdist %d", Xdist);
    displayBigTextLine(2, "Ydist %d", Ydist);
    displayBigTextLine(4, "powerX %d", powerX);
    displayBigTextLine(6, "powerY %d", powerY);
    wait1Msec(4000);
    */

    motor[motorA] = powerX;
    motor[motorB] = powerY;

    while((pow((degreesToMM(nMotorEncoder[motorA])),2) + pow((degreesToMM(nMotorEncoder[motorB])),2)) < dist*dist)
    {
    	//float aSquared = pow((degreesToMM(nMotorEncoder[motorA])),2);
			//float bSquared = pow((degreesToMM(nMotorEncoder[motorB])),2);
    }

	motor[motorA] = motor[motorB] = 0;
}

void inkOn (bool inkMotor)
{
	if (inkMotor == true)
		motor[motorC]= MOTORCON;
	else
		motor[motorC]= 0;
	wait1Msec(50);
}

//This code writes Uoftrash

void go_straight(tMotor sideMotor, int sideLen)
{
	if (sideLen > 0)
		motor[sideMotor] = BASEPOWER;
	else
		motor[sideMotor] = -BASEPOWER;

	int sideDegrees = sideLen * 15;
	int currentEncoderVal = nMotorEncoder[sideMotor];

	while (abs(nMotorEncoder[sideMotor] - currentEncoderVal) < abs(sideDegrees))
	{}
	motor[sideMotor] = 0;
}

void drawU()
{
	motor[motorA]=motor[motorB]=motor[motorC]=0;
	inkOn(true);
	draw(false, 0, false, 10);
	draw(true, 90, true, 5);
	draw(true, 0, false, 10);
	inkOn(false);
	draw(true, 90, true, 5);
}

void drawO()
{
	motor[motorA]=motor[motorB]=motor[motorC]=0;
	inkOn(true);
	draw(false, 0, false, 10);
	draw(true, 90, true, 5);
	draw(true, 0, false, 10);
	draw(true, 90, false, 5);
	inkOn(false);
	draw(true, 90, true, 7.5);

}

void drawF()
{
	inkOn(true);
	go_straight(motorB,-20);
	inkOn(false);
	go_straight(motorB,10);
	inkOn(true);
	go_straight(motorA,10);
	inkOn(false);
	go_straight(motorB,10);
	inkOn(true);
	go_straight(motorA,-10);
	inkOn(false);
}

void spaceAfterF()
{
	go_straight(motorA,20);
}

void drawT()
{
	inkOn(true);
	go_straight(motorA,10);
	inkOn(false);
	go_straight(motorA,-5);
	inkOn(true);
	go_straight(motorB,-20);
	inkOn(false);
	go_straight(motorA,10);
}

void drawR()
{
	inkOn(true);
	go_straight(motorB,20);
	go_straight(motorA,10);
	go_straight(motorB,-10);
	go_straight(motorA,-10);
	drawDiag(false, 45, true, sqrt(2)*10);
	inkOn(false);
	go_straight(motorA,5);
}

void drawA()
{
	inkOn(true);
	go_straight(motorB,20);
	go_straight(motorA,10);
	go_straight(motorB,-20);
	inkOn(false);
	go_straight(motorB,10);
	inkOn(true);
	go_straight(motorA,-10);
	inkOn(false);
	go_straight(motorA,15);
	go_straight(motorB,-10);
}

void drawS()
{
	inkOn(true);
	go_straight(motorA,10);
	go_straight(motorB,10);
	go_straight(motorA,-10);
	go_straight(motorB,10);
	go_straight(motorA,10);
	inkOn(false);
	go_straight(motorA,5);
}

void drawH ()
{
	inkOn(true);
	go_straight(motorB,-20);
	inkOn(false);
	go_straight(motorA,10);
	inkOn(true);
	go_straight(motorB,20);
	inkOn(false);
	go_straight(motorB,-10);
	inkOn(true);
	go_straight(motorA,-10);
	inkOn(false);
}

void uOfTrash()
{
	drawU();
	spaceAfterU();
	drawO();
	drawF();
	spaceAfterF();
	drawT();
	drawR();
	drawA();
	drawS();
	drawH();
}

task main ()
{
	uOfTrash();
}
