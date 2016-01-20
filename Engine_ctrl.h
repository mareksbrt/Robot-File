/* Engine_ctrl.h */

#ifndef Engine_ctrl_h
#define Engine_ctrl_h

#include "Arduino.h"

void SetupMotor(void);
void Forwards(int LeftM, int RightM);
void Backwards(int LeftM, int RightM);
void Left(int LAngle, int LTime);
void Right(int RAngle, int RTime);
void Stoph(void);

#endif