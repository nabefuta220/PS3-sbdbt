
#ifndef PS3_H
#define PS3_H
#include <mbed.h>

#define PI 3.141592654

/**
 * \~english handle PS3 for Mbed OS6
 * \~japanese Mbed OS6でPS3を使うクラス
 **/
class PS3 : public UnbufferedSerial {
public:
	/**
	 * @brief \~japanese ボタンに対する列挙体
	 *
	 * @details \~japanese PS3::sikaku のようにして使う
	 */
	enum Button_type {
		sikaku  = 16,  // 00010000
		sankaku = 36,  // 00100100
		batu    = 37,  // 00100101
		maru    = 38,  // 00100110
		ue      = 32,  // 00100000
		sita    = 33,  // 00100001
		migi    = 34,  // 00100010
		hidari  = 35,  // 00100011
		L1      = 17,  // 00010001
		L2      = 18,  // 00010010
		R1      = 19,  // 00010011
		R2      = 20   // 00010100
	};
	/**
	 * @brief \~english Constructor
	 *        \~japanese コンストラクタ
	 *
	 * @details \~english Create a UnbufferedSerial port, connected to the
	 *specified transmit and receive pins
	 *          \~japanese 指定したTXピンとTXピンでUnbufferedSerial
	 *ポートをつくる
	 *
	 *
	 * @param \~english TX Transmit pin
	 *        \~japanese TX TXピン
	 * @param \~english RX Receive pin
	 *        \~japanese TX TXピン
	 **/
	PS3(PinName TX, PinName RX);
	/**
	 * @brief \~english Read the contents of PS3's data into PS3_data
	 *        \~japanese PS3data にあるPS3から送られているデータを読み取る
	 **/
	void getdata();
	/**
	 * @brief \~english create attach
	 *        \~japanese 割込みを作成する
	 **/
	void myattach();
	/**
	 * @brief \~english add function after PS3::getdata
	 *        \~japanese PS3::getdataの後に割込む関数を追加する
	 * @param \~english Func Function to call afterPS3::getdata
	 *        \~japanese Func PS3::getdataの後に割込む関数
	 **/
	void addattach(void (*Func)());
	/**
	 * @brief \~english do nothing
	 *        \~japanese 何もしない関数
	 *
	 **/
	void nothingFunc();
	/**
	 * @brief \~english Cheak if button in pushed
	 *        \~japanese ボタンが押されているかを調べる
	 * @param \~english button which button cheak (e.g.
	 *PS3::maru,PS3::ur,PS3::sita,PS3::L1 )
	 *        \~japanese ボタンが押されているかを調べるボタン(例:
	 *PS3::maru,PS3::ur,PS3::sita,PS3::L1 )
	 * @return \~english True for button is pushed , False for button is not
	 *pushed
	 *      \~japanese
	 *指定したボタンが押されている場合True、指定したボタンが押されていないときFalse
	 **/
	bool getButtonState(Button_type button);
	/**
	 * @brief \~english Cheak if select button in pushed
	 *         \~japanese セレクトボタンが押されているかを調べる
	 * @return \~english True for select button is pushed , False for select
	 *button is not pushed
	 *        \~japanese
	 *	 セレクトボタンが押されている場合True、セレクトボタンが押されていないときFalse
	 **/
	bool getSELECTState();
	/**
	 * @brief \~english Cheak if start button in pushed
	 *        \~japanese スタートボタンが押されているかを調べる
	 * @return \~english True for start button is pushed , False for start
	 *button is not pushed
	 *       \~japanese
	 *スタートボタンが押されている場合True、スタートボタンが押されていないときFalse
	 **/
	bool getSTARTState();

	/**
	 * @brief \~english get right joystick's X axis
	 *        \~japanese 右ジョイコンスティックのX座標を取得する
	 * @return \~english value of right joystick's X axis (take between -64 and
	 *63)　
	 *         \~japanese 右ジョイコンスティックのX座標(-64以上63以下の数値)
	 **/
	int getRightJoystickXaxis();
	/**
	 * @brief \~english get right joystick's Y axis
	 *        \~japanese 右ジョイコンスティックのY座標を取得する
	 * @return \~english value of right joystick's Y axis (take between -63 and
	 *64)
	 *          \~japanese 右ジョイコンスティックのY座標(-63以上64以下の数値)
	 **/
	int getRightJoystickYaxis();
	/**
	 * @brief \~english get left joystick's X axis
	 *        \~japanese 左ジョイコンスティックのX座標を取得する
	 * @return \~english value of left joystick's X axis (take between -64 and
	 *63)
	 *        \~japanese 左ジョイコンスティックのX座標(-64以上63以下の数値)
	 **/
	int getLeftJoystickXaxis();
	/**
	 * @brief \~english get left joystick's Y axis
	 *        \~japanese 左ジョイコンスティックのY座標を取得する
	 * @return \~english value of left joystick's Y axis (take between -63 and
	 *64)
	 * \~japanese 左ジョイコンスティックのY座標(-63以上64以下の数値)
	 **/
	int getLeftJoystickYaxis();

	/**
	 * @brief \~english get right joystick's angle in degree
	 *      \~japanese 右ジョイコンスティックの角度(度数法で返す)
	 * @return \~english angle of right joystick in degree (take beteen -180.0
	 *and 180.0)
	 *  \~japanese 右ジョイコンスティックの角度(-180.0以上180.0以下の数値)
	 **/
	double getRightJoystickAngle();
	/**
	 * @brief \~english get left joystick's angle in degree
	 *        \~japanese 左ジョイコンスティックの角度(度数法で返す)
	 * @return \~english angle of left joystick in degree (take beteen -180.0
	 *and 180.0)
	 *     \~japanese 左ジョイコンスティックの角度(-180.0以上180.0以下の数値)
	 **/
	double getLeftJoystickAngle();
	/**
	 * @brief \~english print PS3Data in console
   *        \~japanese PS3Dataの値をconsoleに出力する
	 **/
	void printdata();

private:
	char PS3Data[8];
	void (*fpFunc)();
	bool addflag;
};

#endif