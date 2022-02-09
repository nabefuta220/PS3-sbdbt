
#ifndef PS3_H
#define PS3_H
#include <mbed.h>

#define PI 3.141592654

/**
 * handle PS3 for Mbed OS6
 **/
class PS3 : public UnbufferedSerial {
public:
// bit,button
  enum Button_type {
    sikaku = 16,  // 00010000
    sankaku = 36, // 00100100
    batu = 37,    // 00100101
    maru = 38,    // 00100110
    ue = 32,      // 00100000
    sita = 33,    // 00100001
    migi = 34,    // 00100010
    hidari = 35,  // 00100011
    L1 = 17,      // 00010001
    L2 = 18,      // 00010010
    R1 = 19,      // 00010011
    R2 = 20       // 00010100
  };
  /**
   * Constructor
   * Create a UnbufferedSerial port, connected to the specified transmit and
   *  receive pins,
   * @param tx Transmit pin
   * @param rx Receive pin
   **/
  PS3(PinName TX, PinName RX);
  /**
   * Read the contents of PS3's data into PS3_data
   **/
  void getdata();
  /**
   * create attatch
   **/
  void myattach();
  /**
   * add function after PS3::getdata
   * @param Func Function to call afterPS3::getdata
   **/
  void addattach(void (*Func)());
  /**
   * do nothing
   **/
  void nothingFunc();
  /**
   * Cheak if button in pushed
   * @param button which button cheak (e.g. maru,ur,sita,L1 )
   * @return True for button is pushed , False for button is not pushed
   **/
  bool getButtonState(Button_type button);
  /**
   * Cheak if select button in pushed
   * @return True for select button is pushed , False for select button is not
   * pushed
   **/
  bool getSELECTState();
  /**
   * Cheak if start button in pushed
   * @return True for start button is pushed , False for start button is not
   * pushed
   **/
  bool getSTARTState();

  /**
   * get right joystick's X axis
   * @return value of right joystick's X axis (take between -64 and 63)
   **/
  int getRightJoystickXaxis();
  /**
   * get right joystick's Y axis
   * @return value of right joystick's Y axis (take between -63 and 64)
   **/
  int getRightJoystickYaxis();
  /**
   * get left joystick's X axis
   * @return value of left joystick's X axis (take between -64 and 63)
   **/
  int getLeftJoystickXaxis();
  /**
   * get left joystick's Y axis
   * @return value of left joystick's Y axis (take between -63 and 64)
   **/
  int getLeftJoystickYaxis();

  /**
   * get right joystick's angle in degree
   * @return angle of right joystick in degree (take beteen -180.0 and 180.0)
   **/
  double getRightJoystickAngle();
  /**
   * get left joystick's angle in degree
   * @return angle of left joystick in degree (take beteen -180.0 and 180.0)
   **/
  double getLeftJoystickAngle();
  /**
   * print PS3Data in console
   **/
  void printdata();

private:
  char PS3Data[8];
  void (*fpFunc)();
  bool addflag;
};

#endif