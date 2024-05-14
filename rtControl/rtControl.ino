#include "rtPinmap.h"
#include "irCheck.h"
#include "motorControl.h"
#include "carCheck.h"

void setup()
{
  rtPinMode();

}

void loop()
{
  ircheck();

  switch(irState)
  {
    case 0:
      accel(0, 120, 0, 120);
      sg1.write(hCenter);
      break;
    case 1:
      accel(0, 120, 0, 120);
      sg1.write(hCenter+hMax);
      break;
    case 3:
      accel(0, 120, 0, 70);
      sg1.write(hCenter+hMax);
      break;
    case 7:
      accel(0, 120, 0, 0);
      sg1.write(hCenter+hMax);
      break;
    case 8:
      accel(0, 120, 0, 120);
      sg1.write(hCenter-hMax);
      break;
    case 12:
      accel(0, 70, 0, 120);
      sg1.write(hCenter-hMax);
      break;
    case 14:
      accel(0, 0, 0, 120);
      sg1.write(hCenter-hMax);
      break;
    case 15:
      accel(0, 0, 0, 0);
      sg1.write(hCenter);
      break;
    default:
      break;
  }
}
