#include "rtPinmap.h"
#include "ledControl.h"
#include "irCheck.h"
#include "motorControl.h"
#include "carCheck.h"
#include "echoControl.h"
#include "btControl.h"
#include "cdsControl.h"

void setup()
{
  rtPinMode();
  
}

void loop()
{
  btRead();
  cdsCheck();
  if(btCheck == 1)
  {
    ircheck();
    echoDetect();
    echoControl();
    Serial.println(distance);
    if(check == 0)
    {
      switch(irState)
      {
        case 0:
          accel(0, 120, 0, 120);
          handle(hCenter);
          break;
        case 1:
          accel(0, 120, 0, 120);
          handle(hCenter+hMax);
          break;
        case 3:
          accel(0, 120, 0, 70);
          handle(hCenter+hMax);
          break;
        case 7:
          accel(0, 120, 0, 0);
          handle(hCenter+hMax);
          break;
        case 8:
          accel(0, 120, 0, 120);
          handle(hCenter-hMax);
          break;
        case 12:
          accel(0, 70, 0, 120);
          handle(hCenter-hMax);
          break;
        case 14:
          accel(0, 0, 0, 120);
          handle(hCenter-hMax);
          break;
        case 15:
          accel(0, 0, 0, 0);
          handle(hCenter);
          break;
        default:
          break;
      }
    }
  }
  else
  {
    passive();
  }
}
