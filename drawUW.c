/*NOTE TO READER OR PROGRAMMER

motorA is the Y direction (the longer rack)
motorB is the X direction (the shorter rack)
motorC ink motor*/

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

void draw(bool north, int angle, bool east, float dist)
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

//This code writes UW


void drawU()
{
	motor[motorA]=motor[motorB]=motor[motorC]=0;
	inkOn(true);
	draw(false, 0, false, 7.5);
	draw(false, 45, true, 3.5);
	draw(true, 90, true, 5);
	draw(true, 45, true, 3.5);
	draw(true, 0, false, 7.5);
	inkOn(false);
	draw(true, 90, true, 2.5);
}

void drawW()
{
	inkOn(true);
	draw(false, 14, true, 10);
	draw(true, 27, true, 5.5);
	draw(false, 27, true, 5.5);
	draw(true, 14, true, 10);
	inkOn(false);
//Space between letters is 0.5cm however the O finishes at the bottom left corner and must travel 10 mm + 5mm
}

task main ()
{
	drawU();
	drawW();
}
