
#include "PS3.h"
#include <mbed.h>
void PS3::getdata() {
  char read_data;
  if (UnbufferedSerial::readable()) {
  UnbufferedSerial::read(&read_data, 1);
  /*
    while (UnbufferedSerial::read(&read_data, 1),read_data != 0x80 ) {
    }
    */
    for (int i = 1; i < 8; i++) {
      UnbufferedSerial::read(&read_data, 1);
    
      PS3Data[i] = read_data;
    }
  }
  if (addflag)
    (*fpFunc)();
}
PS3::PS3(PinName TX, PinName RX) : UnbufferedSerial(TX, RX) {

  PS3Data[0] = 128; // 0x80
  PS3Data[1] = 0;
  PS3Data[2] = 0;
  PS3Data[3] = 64;
  PS3Data[4] = 64;
  PS3Data[5] = 64;
  PS3Data[6] = 64;
  PS3Data[7] = 0;
  addflag = 0;
  UnbufferedSerial::baud(115200);
 // UnbufferedSerial::format(8,None,1);

   
  UnbufferedSerial::attach(Callback<void()>(this, &PS3::getdata),RxIrq);
}

void PS3::myattach() {
   UnbufferedSerial::attach(Callback<void()>(this, &PS3::getdata),RxIrq);
}

void PS3::addattach(void (*Func)()) {
  fpFunc = Func;
  addflag = 1;
}

void PS3::nothingFunc() {}

bool PS3::getButtonState(Button_type button) {
  return (*(PS3Data + (button >> 4)) >> (button & 0x0f)) & 1;
}
bool PS3::getSELECTState() {
  return getButtonState(migi) & getButtonState(hidari);
}
bool PS3::getSTARTState() { return getButtonState(ue) & getButtonState(sita); }
int PS3::getRightJoystickXaxis() { return (int)PS3Data[5] - 64; }
int PS3::getRightJoystickYaxis() { return (int)PS3Data[6] * -1 + 64; }
int PS3::getLeftJoystickXaxis() { return (int)PS3Data[3] - 64; }
int PS3::getLeftJoystickYaxis() { return (int)PS3Data[4] * -1 + 64; }
double PS3::getRightJoystickAngle() {
  return atan2(double(PS3Data[6] * -1 + 64), double(PS3Data[5] - 64)) *
         double(180 / PI);
}
double PS3::getLeftJoystickAngle() {
  return atan2(double(PS3Data[4] * -1 + 64), double(PS3Data[3] - 64)) *
         double(180 / PI);
}
void PS3::printdata() {

  for (int i = 0; i < 8; i++) {
    printf("%4d", PS3Data[i]);
  }
  printf("\n");
}
