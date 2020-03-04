#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/I2C.h>
#include <frc/Timer.h>
#include <frc/DigitalInput.h>
#include <frc/AnalogInput.h>
#include <string.h>
// this class controls the REV digit board that we use to choose our autonomous mode
//without having to redeploy every match.
class REVDigitBoard: public frc2::SubsystemBase {
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
	void clear();
	bool getButtonA();
	bool getButtonB();
	double getPot();
	void display(double batt);
	void display(std::string str);

private:
	void _display( byte charz[4]);

	frc::I2C i2c;
	frc::DigitalInput buttonA, buttonB;
	frc::AnalogInput pot;

	byte charreg[37][2];
	byte charmap[256];
};
