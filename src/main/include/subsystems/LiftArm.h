#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Encoder.h>
#include <ctre/Phoenix.h>
#include "RobotMap.h"

class LiftArm : public frc2::SubsystemBase {
public:
    LiftArm();
    virtual ~LiftArm();

    int getEncoderValue();

    void setSpeed( double aPercentOutput );

private:
    WPI_TalonSRX mSpeedController{LIFT_ARM_SPEED_CONTROLLER};
    frc::Encoder mEncoder{ LIFT_ARM_ENCODER_CHANNEL_A, LIFT_ARM_ENCODER_CHANNEL_B };
};
