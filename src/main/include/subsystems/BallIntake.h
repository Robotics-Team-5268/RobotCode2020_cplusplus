#pragma once

#include <frc/commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include "RobotMap.h"

class BallIntake : public frc::Subsystem {
public:
    BallIntake();
    virtual ~BallIntake();

    void setLowerSpeed( double aPercent );
    void setUpperSpeed( double aPercent );

private:
    WPI_TalonSRX lowerSpeedController{BALL_INTAKE_SPEED_CONTROLLER_1};
    WPI_TalonSRX upperSpeedController{BALL_INTAKE_SPEED_CONTROLLER_2};

};
