#include <Engine_ctrl.h>

int turnSpeed = 200; // Turn Speed
int fSpeed = 255;    // Forwards speed
int bSpeed = 250;
int longDelay = 80; // Delay for tight corners
int shortDelay = 15; // Delay for wide corners
int i = 0;

void setup()
{
  SetupMotor();
  Stoph();

  pinMode(A4, INPUT); // sensor 4
  pinMode(A3, INPUT); // sensor 3
  pinMode(A2, INPUT); // sensor 2
  pinMode(A1, INPUT); // sensor 1
  }
void loop()

{
    if(sensor(1) && sensor(4)) Forwards(fSpeed, fSpeed);
    if(sensor(2)|| sensor (3)) Forwards(fSpeed, fSpeed);                          
    if(sensor(4))  Left(turnSpeed,shortDelay);                                    
    if(sensor(1)) Right(turnSpeed,shortDelay);                                    
    if(sensor(3)&&sensor(2)&&sensor(4)&&!sensor(1)) Left(turnSpeed,longDelay);    
    if(sensor(3)&&sensor(2)&&sensor(1)&& !sensor(4))Right(turnSpeed,longDelay);  
    if(sensor(3)&&sensor(2)&&sensor(1)&& sensor(4))Forwards(fSpeed,fSpeed);       
    if(!sensor(3)&&!sensor(2)&&!sensor(1)&& !sensor(4))
    {
      i++;
      if( i % 2)
      {
        Backwards(0, 250);
      }
      else
      {
        Backwards(250, 0);
      }
      delay(100);
    }

}


bool sensor(byte nr)
{
  switch(nr)

  {
    case 1:
    {
      if(!digitalRead(A1)) return 1;
      else return 0;
      break;
    }
    case 2:
    {
      if(!digitalRead(A2)) return 1;
      else return 0;
      break;
    }
    case 3:
    {
      if(!digitalRead(A3)) return 1;
      else return 0;
      break;
    }
    case 4:
    {
      if(!digitalRead(A4)) return 1;
      else return 0;
      break;
    }
  }
}
