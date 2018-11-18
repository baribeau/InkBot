// pattern selection

while (getButtonPress(ButtonNone));

if (getButtonPress(ButtonLeft))
{
	while (getButtonPress(ButtonLeft));
	//insert code for first pattern
}

else if (getButtonPress(ButtonRight))
{
	while (getButtonPress(ButtonRight));
	//insert code for second pattern	
}

else if (getButtonPress(ButtonDown))
{
	while (getButtonPress(ButtonDown));
	//insert code for third pattern
}

void drawSquare()
{
	drawDiag(false, 90, true, 30);
	drawDiag(false, 0, true, 30);
	drawDiag(true, 90, false, 30);
	drawDiag(true, 0, false, 30);
}
	
	
