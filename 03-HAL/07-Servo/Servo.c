/*
 * Servo.c
 *
 * Created: 1/27/2022 1:18:10 AM
 *  Author: Mohamed Elhafy
 */ 

#include "Timers.h"

void Servo_vSetAngle(uint_8 pin, float_32 Angle)
{
	uint_16 onTime=0;
	
	switch(pin)
	{
		case 'A':
		case 'a':
			onTime=1000*(Angle/180)+1500;
			Timer1_vGenratFstPWM_OnOC1ApinWithOnTimeInUs(onTime,19999);
			break;
		
		case 'B':
		case 'b':
			onTime=1000*(Angle/180)+1500;
			Timer1_vGenratFastPWM_OnOC1BpinWithOnTimeInUs(onTime,19999);
			break;
	}

}