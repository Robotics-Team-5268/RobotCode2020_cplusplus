#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/Encoder.h>
#include <ctre/Phoenix.h>
#include "RobotMap.h"

class LiftArm : public frc::Subsystem {
public:
    LiftArm();
    virtual ~LiftArm();

    int getEncoderValue();

    void setSpeed( double aPercentOutput );

private:
    WPI_TalonSRX mSpeedController{LIFT_ARM_SPEED_CONTROLLER};
    frc::Encoder mEncoder{ LIFT_ARM_ENCODER_CHANNEL_A, LIFT_ARM_ENCODER_CHANNEL_B };
};
