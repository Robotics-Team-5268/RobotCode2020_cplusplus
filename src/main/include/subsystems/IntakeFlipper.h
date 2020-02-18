#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/Encoder.h>
#include <ctre/Phoenix.h>
#include "RobotMap.h"

class IntakeFlipper : public frc::Subsystem {
public:
    IntakeFlipper();
    virtual ~IntakeFlipper();

    int getEncoderValue();

    void setSpeed( double aPercentOutput );

private:
    WPI_TalonSRX mFlipperSpeedController{BALL_INTAKE_FLIPPER_SPEED_CONTROLLER};
    frc::Encoder mFlipperEncoder{ FLIPPER_ENCODER_CHANNEL_A, FLIPPER_ENCODER_CHANNEL_B };
};
