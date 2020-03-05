#include <frc/I2C.h>
#include <frc/Timer.h>
#include <frc/DigitalInput.h>
#include <frc/AnalogInput.h>
#include "Subsystems/RevDigitBoard.h"
#include <string.h>
#include <cctype>

REVDigitBoard::REVDigitBoard() : frc::Subsystem("REVDigitBoard")
		, mI2c( frc::I2C::kMXP, 0x70 )
		, mButtonA( 19 )
		, mButtonB( 20 )
		, mPotentiometer( 3 )
	{
		byte osc;
	 	byte blink;
	 	byte bright;
	 	osc = (byte)0x21;
	 	blink = (byte)0x81;
	 	bright = (byte)0xEF;

		mI2c.WriteBulk(&osc, 1);
		frc::Wait(.01);
		mI2c.WriteBulk(&bright, 1);
	  	frc::Wait(.01);
		mI2c.WriteBulk(&blink, 1);
		frc::Wait(.01);

		mCharreg[0][0] = (byte)0b00111111; mCharreg[9][1] = (byte)0b00000000; //0
		mCharmap['0'] = 0;
		mCharreg[1][0] = (byte)0b00000110; mCharreg[0][1] = (byte)0b00000000; //1
		mCharmap['1'] = 1;
	 	mCharreg[2][0] = (byte)0b11011011; mCharreg[1][1] = (byte)0b00000000; //2
		mCharmap['2'] = 2;
	 	mCharreg[3][0] = (byte)0b11001111; mCharreg[2][1] = (byte)0b00000000; //3
		mCharmap['3'] = 3;
	 	mCharreg[4][0] = (byte)0b11100110; mCharreg[3][1] = (byte)0b00000000; //4
		mCharmap['4'] = 4;
	 	mCharreg[5][0] = (byte)0b11101101; mCharreg[4][1] = (byte)0b00000000; //5
		mCharmap['5'] = 5;
	 	mCharreg[6][0] = (byte)0b11111101; mCharreg[5][1] = (byte)0b00000000; //6
		mCharmap['6'] = 6;
	 	mCharreg[7][0] = (byte)0b00000111; mCharreg[6][1] = (byte)0b00000000; //7
		mCharmap['7'] = 7;
	 	mCharreg[8][0] = (byte)0b11111111; mCharreg[7][1] = (byte)0b00000000; //8
		mCharmap['8'] = 8;
	 	mCharreg[9][0] = (byte)0b11101111; mCharreg[8][1] = (byte)0b00000000; //9
		mCharmap['9'] = 9;

	 	mCharreg[10][0] = (byte)0b11110111; mCharreg[10][1] = (byte)0b00000000; //A
		mCharmap['A'] = 10;
	 	mCharreg[11][0] = (byte)0b10001111; mCharreg[11][1] = (byte)0b00010010; //B
		mCharmap['B'] = 11;
	 	mCharreg[12][0] = (byte)0b00111001; mCharreg[12][1] = (byte)0b00000000; //C
		mCharmap['C'] = 12;
	 	mCharreg[13][0] = (byte)0b00001111; mCharreg[13][1] = (byte)0b00010010; //D
		mCharmap['D'] = 13;
	 	mCharreg[14][0] = (byte)0b11111001; mCharreg[14][1] = (byte)0b00000000; //E
		mCharmap['E'] = 14;
	 	mCharreg[15][0] = (byte)0b11110001; mCharreg[15][1] = (byte)0b00000000; //F
		mCharmap['F'] = 15;
	 	mCharreg[16][0] = (byte)0b10111101; mCharreg[16][1] = (byte)0b00000000; //G
		mCharmap['G'] = 16;
	 	mCharreg[17][0] = (byte)0b11110110; mCharreg[17][1] = (byte)0b00000000; //H
		mCharmap['H'] = 17;
	 	mCharreg[18][0] = (byte)0b00001001; mCharreg[18][1] = (byte)0b00010010; //I
		mCharmap['I'] = 18;
	 	mCharreg[19][0] = (byte)0b00011110; mCharreg[19][1] = (byte)0b00000000; //J
		mCharmap['J'] = 19;
	 	mCharreg[20][0] = (byte)0b01110000; mCharreg[20][1] = (byte)0b00001100; //K
		mCharmap['K'] = 20;
	 	mCharreg[21][0] = (byte)0b00111000; mCharreg[21][1] = (byte)0b00000000; //L
		mCharmap['L'] = 21;
	 	mCharreg[22][0] = (byte)0b00110110; mCharreg[22][1] = (byte)0b00000101; //M
		mCharmap['M'] = 22;
	 	mCharreg[23][0] = (byte)0b00110110; mCharreg[23][1] = (byte)0b00001001; //N
		mCharmap['N'] = 23;
	 	mCharreg[24][0] = (byte)0b00111111; mCharreg[24][1] = (byte)0b00000000; //O
	 	mCharmap['O'] = 24;
	 	mCharreg[25][0] = (byte)0b11110011; mCharreg[25][1] = (byte)0b00000000; //P
	 	mCharmap['P'] = 25;
	 	mCharreg[26][0] = (byte)0b00111111; mCharreg[26][1] = (byte)0b00001000; //Q
	 	mCharmap['Q'] = 26;
	 	mCharreg[27][0] = (byte)0b11110011; mCharreg[27][1] = (byte)0b00001000; //R
	 	mCharmap['R'] = 27;
	 	mCharreg[28][0] = (byte)0b10001101; mCharreg[28][1] = (byte)0b00000001; //S
	 	mCharmap['S'] = 28;
	 	mCharreg[29][0] = (byte)0b00000001; mCharreg[29][1] = (byte)0b00010010; //T
	 	mCharmap['T'] = 29;
	 	mCharreg[30][0] = (byte)0b00111110; mCharreg[30][1] = (byte)0b00000000; //U
	 	mCharmap['U'] = 30;
	 	mCharreg[31][0] = (byte)0b00110000; mCharreg[31][1] = (byte)0b00100100; //V
	 	mCharmap['V'] = 31;
	 	mCharreg[32][0] = (byte)0b00110110; mCharreg[32][1] = (byte)0b00101000; //W
	 	mCharmap['W'] = 32;
	 	mCharreg[33][0] = (byte)0b00000000; mCharreg[33][1] = (byte)0b00101101; //X
	 	mCharmap['X'] = 33;
	 	mCharreg[34][0] = (byte)0b00000000; mCharreg[34][1] = (byte)0b00010101; //Y
	 	mCharmap['Y'] = 34;
	 	mCharreg[35][0] = (byte)0b00001001; mCharreg[35][1] = (byte)0b00100100; //Z
	 	mCharmap['Z'] = 35;
		mCharreg[36][0] = (byte)0b00000000; mCharreg[36][1] = (byte)0b00000000; //space
		mCharmap[' '] = 36;
	}

	void REVDigitBoard::display( const std::string& aString) { // only displays first 4 chars
		byte charz[4] = {36,36,36,36};

		for(size_t i = 0; i < 4 && i < aString.length(); i++) {
			charz[i] = mCharmap[std::toupper(aString[i])];
		}

		_display(charz);
	}

	void REVDigitBoard::display(double aBatteryVoltage) { // optimized for battery voltage, needs a double like 12.34
		byte charz[4] = {36,36,36,36};
		// idk how to decimal point
		int ten = (int)(aBatteryVoltage/10);
		int one = ((int)aBatteryVoltage)%10;
		int tenth = ((int)(aBatteryVoltage*10)%10);
		int hundredth = ((int)(aBatteryVoltage*100)%10);

		if (ten != 0) charz[0] = ten;
		charz[1] = one;
		charz[2] = tenth;
		charz[3] = hundredth;

		_display(charz);
	}

	 void REVDigitBoard::clear() {
		 byte charz[4] = {36,36,36,36};
		 _display(charz);
	 }

	 bool REVDigitBoard::getButtonA() {
		 return !mButtonA.Get();// Not symbol because digital input is true when open
	 }
	 bool REVDigitBoard::getButtonB() {
		 return !mButtonB.Get();// Not symbol because digital input is true when open
	 }
	 double REVDigitBoard::getPot() {
		 return mPotentiometer.GetVoltage();
	 }

////// not supposed to be publicly used..

	void REVDigitBoard::_display( byte aCharz[4]) {
		byte byte1[10];
		byte1[0] = (byte)(0b00001111);
		byte1[1] = 0; //(byte)(0b00001111);
 		byte1[2] = mCharreg[aCharz[3]][0];
 		byte1[3] = mCharreg[aCharz[3]][1];
 		byte1[4] = mCharreg[aCharz[2]][0];
 		byte1[5] = mCharreg[aCharz[2]][1];
 		byte1[6] = mCharreg[aCharz[1]][0];
 		byte1[7] = mCharreg[aCharz[1]][1];
 		byte1[8] = mCharreg[aCharz[0]][0];
 		byte1[9] = mCharreg[aCharz[0]][1];
 		//send the array to the board
 		mI2c.WriteBulk(byte1, sizeof( byte1 ));
 		frc::Wait(0.01);
	}


