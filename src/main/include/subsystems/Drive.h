#pragma once

#include <frc/AnalogGyro.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/SpeedControllerGroup.h>
#include <ctre/Phoenix.h>
#include <frc/Ultrasonic.h>

#include "RobotMap.h"

class Drive : public frc2::SubsystemBase {
 private:
	WPI_TalonFX mSpeedControllerFL{DRIVE_SPEED_CONTROLLER_FL_CHANNEL};
	WPI_TalonFX mSpeedControllerBL{DRIVE_SPEED_CONTROLLER_BL_CHANNEL};
	frc::SpeedControllerGroup mLeftSC{mSpeedControllerFL, mSpeedControllerBL};

	WPI_TalonFX mSpeedControllerFR{DRIVE_SPEED_CONTROLLER_FR_CHANNEL};
	WPI_TalonFX mSpeedControllerBR{DRIVE_SPEED_CONTROLLER_BR_CHANNEL};
	frc::SpeedControllerGroup mRightSC{mSpeedControllerFR, mSpeedControllerBR};

	frc::DifferentialDrive mDiffDrive{mLeftSC, mRightSC};
	float mOldLeftSpeed;
	float mOldRightSpeed;
	const float MAX_CHANGE = .05;
	const float MAX_SPEED = 3000;//used to be 3000
	float mVelocityToCommandSlope[4];
	float mVelocityToCommandIntercept[4];

	frc::AnalogGyro mGyro{GYRO_ANALOG_PORT};

    //std::ofstream fout;
 public:
	Drive();
	virtual void setMotors(float aLeftSpeed, float aRightSpeed);

	float getGyroAngle();
	float getGyroRate();
	void resetGyro();
	void calibrateGyro();

	void SetVelocity(float aLeft, float aRight);
};