#include "Arduino.h"
#include "Engine_ctrl.h"


void SetupMotor(void)
{
	pinMode(11, OUTPUT);//Left Engine PWM Control
	pinMode(10, OUTPUT);//Right Engine PWM Control
	pinMode(8, OUTPUT);//Left Engine State
	pinMode(9, OUTPUT);//Left Engine State
	pinMode(6, OUTPUT);//Right Engine State
	pinMode(7, OUTPUT);//Right Engine State	
}

void Forwards(int LeftM, int RightM)
{
	
	digitalWrite(9, HIGH);
	digitalWrite(8, LOW);
	digitalWrite(7, HIGH);
	digitalWrite(6, LOW);
	analogWrite(11, LeftM);
	analogWrite(10, RightM);
}

void Backwards(int LeftM, int RightM)
{
	digitalWrite(9, LOW);
	digitalWrite(8, HIGH);
	digitalWrite(7, LOW);
	digitalWrite(6, HIGH);
	analogWrite(11, LeftM);
	analogWrite(10, RightM);
}

void Left(int LAngle, int LTime)
{
	digitalWrite(9, LOW);
	digitalWrite(8, LOW);
	digitalWrite(7, HIGH);
	digitalWrite(6, LOW);
	analogWrite(11, LAngle);
	analogWrite(10, LAngle);
	delay(LTime);
}

void Right(int RAngle, int RTime)
{
	digitalWrite(9, HIGH);
	digitalWrite(8, LOW);
	digitalWrite(7, LOW);
	digitalWrite(6, LOW);
	analogWrite(11, RAngle);
	analogWrite(10, RAngle);	
	delay(RTime);
}

void Stoph(void)
{
	digitalWrite(9, LOW);
	digitalWrite(8, LOW);
	digitalWrite(7, LOW);
	digitalWrite(6, LOW);
	analogWrite(11, LOW);
	analogWrite(10, LOW);
}
