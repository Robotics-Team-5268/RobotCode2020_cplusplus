#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/SpeedControllerGroup.h>
#include <ctre/Phoenix.h>
#include "RobotMap.h"

class BallIntake : public frc::Subsystem {
public:
    BallIntake();
    virtual ~BallIntake();

private:
    WPI_TalonSRX speedController1{BALL_INTAKE_SPEED_CONTROLLER_1};
    WPI_TalonSRX speedController2{BALL_INTAKE_SPEED_CONTROLLER_2};
    WPI_TalonSRX speedController3{BALL_INTAKE_SPEED_CONTROLLER_3};

    frc::SpeedControllerGroup sppedControlGroup{speedController1, speedController2, speedController3};

};
