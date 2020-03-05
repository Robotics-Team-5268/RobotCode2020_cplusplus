#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/VictorSP.h>
#include <ctre/Phoenix.h>
#include "RobotMap.h"

class BallIntake : public frc2::SubsystemBase {
public:
    BallIntake();
    virtual ~BallIntake();

    void setLowerSpeed( double aPercent );
    void setUpperSpeed( double aPercent );
private:
    frc::VictorSP mLowerSpeedController{BALL_INTAKE_LOWER_SPEED_CONTROLLER};
    WPI_TalonSRX mUpperSpeedController{BALL_INTAKE_UPPER_SPEED_CONTROLLER};
};
