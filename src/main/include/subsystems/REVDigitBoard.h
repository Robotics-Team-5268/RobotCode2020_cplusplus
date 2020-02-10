#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/I2C.h>
#include <frc/Timer.h>
#include <frc/DigitalInput.h>
#include <frc/AnalogInput.h>
#include <string.h>
// this class controls the REV digit board that we use to choose our autonomous mode
//without having to redeploy every match.
class REVDigitBoard: public frc::Subsystem {
	typedef unsigned char byte;

	/*
	 * DOCUMENTATION::
	 *
	 * REVDigitBoard() : constructor
	 * void display(String str) : displays the first four characters of the string (only alpha (converted to uppercase), numbers, and spaces)
	 * void display(double batt) : displays a decimal number (like battery voltage) in the form of 12.34 (ten-one-decimal-tenth-hundredth)
	 * void clear() : clears the display
	 * boolean getButtonA() : button A on the board
	 * boolean getButtonB() : button B on the board
	 * double getPot() : potentiometer value
	 */
public:
	REVDigitBoard();
	void InitDefaultCommand();
	void clear();
	bool getButtonA();
	bool getButtonB();
  double getPot();
	void display(double aBatteryVoltage);
	void display(const std::string& aString);

private:
	void _display( byte aCharz[4]);

	frc::I2C mI2c;
	frc::DigitalInput mButtonA;
	frc::DigitalInput mButtonB;
	frc::AnalogInput mPotentiometer;

	byte mCharreg[37][2];
	byte mCharmap[256];
};
