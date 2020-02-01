#pragma once

#include <frc/AnalogGyro.h>
#include <frc/commands/Subsystem.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/Talon.h>
#include <frc/Ultrasonic.h>

#include "RobotConfig.h"
#include "RobotMap.h"

class Drive : public frc::Subsystem {
 private:
    frc::Talon speedControllerFL{DRIVE_SPEED_CONTROLLER_FL_CHANNEL};
	frc::Talon speedControllerBL{DRIVE_SPEED_CONTROLLER_BL_CHANNEL};
	frc::SpeedControllerGroup leftSC{speedControllerFL, speedControllerBL};

	frc::Talon speedControllerFR{DRIVE_SPEED_CONTROLLER_FR_CHANNEL};
	frc::Talon speedControllerBR{DRIVE_SPEED_CONTROLLER_BR_CHANNEL};
	frc::SpeedControllerGroup rightSC{speedControllerFR, speedControllerBR};

	frc::DifferentialDrive diffDrive{leftSC, rightSC};
	float oldLeftSpeed, oldRightSpeed;
	const float MAX_CHANGE = .05;
	const float MAX_SPEED = 3000;//used to be 3000
	float velocityToCommandSlope[4];
	float velocityToCommandIntercept[4];

    #if( GYRO_SUPPORT )
	    frc::AnalogGyro gyro{GYRO_ANALOG_PORT};
    #endif

    //std::ofstream fout;
 public:
	Drive();
	void InitDefaultCommand() override;
	virtual void setMotors(float leftSpeed, float rightSpeed);
	virtual void safetyOff() {diffDrive.SetSafetyEnabled(false);}
	virtual void takeInput();
	#if( GYRO_SUPPORT )
	    frc::AnalogGyro* getGyro();
	    float getGyroAngle();
	    float getGyroRate();
	    void resetGyro();
	    void calibrateGyro();
	#endif
	void SetVelocity(float left, float right);
};