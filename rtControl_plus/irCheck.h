int irState;
int dl = 500;  //차선인식 기준값

void ircheck()
{
  int ir1v = analogRead(ir1);
  int ir2v = analogRead(ir2);
  int ir3v = analogRead(ir3);
  int ir4v = analogRead(ir4);

       if(ir1v > dl && ir2v > dl && ir3v > dl && ir4v > dl) irState = 0;  //0000
  else if(ir1v > dl && ir2v > dl && ir3v > dl && ir4v < dl) irState = 1;  //0001
  else if(ir1v > dl && ir2v > dl && ir3v < dl && ir4v > dl) irState = 2;  //0010
  else if(ir1v > dl && ir2v > dl && ir3v < dl && ir4v < dl) irState = 3;  //0011
  else if(ir1v > dl && ir2v < dl && ir3v > dl && ir4v > dl) irState = 4;  //0100
  else if(ir1v > dl && ir2v < dl && ir3v > dl && ir4v < dl) irState = 5;  //0101
  else if(ir1v > dl && ir2v < dl && ir3v < dl && ir4v > dl) irState = 6;  //0110
  else if(ir1v > dl && ir2v < dl && ir3v < dl && ir4v < dl) irState = 7;  //0111
  else if(ir1v < dl && ir2v > dl && ir3v > dl && ir4v > dl) irState = 8;  //1000
  else if(ir1v < dl && ir2v > dl && ir3v > dl && ir4v < dl) irState = 9;  //1001
  else if(ir1v < dl && ir2v > dl && ir3v < dl && ir4v > dl) irState = 10; //1010
  else if(ir1v < dl && ir2v > dl && ir3v < dl && ir4v < dl) irState = 11; //1011
  else if(ir1v < dl && ir2v < dl && ir3v > dl && ir4v > dl) irState = 12; //1100
  else if(ir1v < dl && ir2v < dl && ir3v > dl && ir4v < dl) irState = 13; //1101
  else if(ir1v < dl && ir2v < dl && ir3v < dl && ir4v > dl) irState = 14; //1110
  else if(ir1v < dl && ir2v < dl && ir3v < dl && ir4v < dl) irState = 15; //1111
}