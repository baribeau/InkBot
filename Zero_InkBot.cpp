void zeroBot()
{
	// reset bot to 0 in x
	motor[motorA] = -10;
	while (getSensorValue(S2) == 0)
	{}
	motor[motorA] = 0;
	
	// reset bot to 0 in y
	motor[motorB] = 10;
	while (getSensorValue(S3) == 0)
	{}
	motor[motorB] = 0;
}
	
	
