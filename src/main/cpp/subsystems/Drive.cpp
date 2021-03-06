#include "subsystems/Drive.h"

#include <frc/smartDashBoard/SmartDashBoard.h>

#define SCFL_INVERTED false
#define SCBL_INVERTED false
#define SCFR_INVERTED false
#define SCBR_INVERTED false

Drive::Drive()
{
	SetName( "Drive" );
	mOldLeftSpeed = 0.0;
	mOldRightSpeed = 0.0;
	mVelocityToCommandIntercept[0] = -316.89;
	mVelocityToCommandIntercept[1] = -378.00;
	mVelocityToCommandIntercept[2] = -364.78;
	mVelocityToCommandIntercept[3] = -331.27;
	mVelocityToCommandSlope[0] = 1/3493.57;
	mVelocityToCommandSlope[1] = 1/3493.90;
	mVelocityToCommandSlope[2] = 1/3386.53;
	mVelocityToCommandSlope[3] = 1/3744.83;
	mSpeedControllerFL.SetInverted(SCFL_INVERTED);
	mSpeedControllerBL.SetInverted(SCBL_INVERTED);
	mSpeedControllerFR.SetInverted(SCFR_INVERTED);
	mSpeedControllerBR.SetInverted(SCBR_INVERTED);

	mDiffDrive.SetSafetyEnabled(false);
}

void Drive::setMotors(float aLeftSpeed, float aRightSpeed)
{
	mDiffDrive.TankDrive(aLeftSpeed, aRightSpeed, false);

	frc::SmartDashboard::PutNumber("Speed Controller FL", mSpeedControllerFL.Get());
	frc::SmartDashboard::PutNumber("Speed Controller FR", mSpeedControllerFR.Get());
	frc::SmartDashboard::PutNumber("Speed Controller BL", mSpeedControllerBL.Get());
	frc::SmartDashboard::PutNumber("Speed Controller BR", mSpeedControllerBR.Get());
}

float Drive::getGyroAngle()
{
	return mGyro.GetAngle();
}

float Drive::getGyroRate()
{
	return mGyro.GetRate();
}

void Drive::resetGyro()
{
	mGyro.Reset();
}

void Drive::calibrateGyro()
{
	mGyro.Calibrate();
}

void Drive::SetVelocity(float aLeft, float aRight)
{
	float leftSpeed = aLeft * MAX_SPEED;
	float rightSpeed = aRight * MAX_SPEED;
	if (leftSpeed < 0) {
		leftSpeed = mVelocityToCommandSlope[0]*(leftSpeed + mVelocityToCommandIntercept[0]);
	} else {
		leftSpeed = mVelocityToCommandSlope[2]*(leftSpeed + mVelocityToCommandIntercept[2]);
	}
	if (rightSpeed < 0) {
		rightSpeed = mVelocityToCommandSlope[1]*(rightSpeed + mVelocityToCommandIntercept[1]);
	} else {
		rightSpeed = mVelocityToCommandSlope[3]*(rightSpeed + mVelocityToCommandIntercept[3]);
	}
	setMotors(leftSpeed, rightSpeed);
}