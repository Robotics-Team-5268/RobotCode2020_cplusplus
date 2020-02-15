#pragma once

#include <frc/commands/PIDSubsystem.h>
#include <frc/Encoder.h>
#include <ctre/Phoenix.h>
#include "RobotMap.h"

class IntakeFlipper : public frc::PIDSubsystem {
public:
    static constexpr double cOpenFlipper = 15.0; // Move 15 degrees for testing
    static constexpr double cCloseFlipper = 0.0;

    IntakeFlipper();
    virtual ~IntakeFlipper();

    // No default command, if PID is enabled, the current setpoint will be maintained.
    void InitDefaultCommand() override;

    double ReturnPIDInput() override;

    void UsePIDOutput(double aOutput) override;

private:
    WPI_TalonSRX mFlipperSpeedController{BALL_INTAKE_FLIPPER_SPEED_CONTROLLER};
    frc::Encoder mFlipperEncoder{ FLIPPER_ENCODER_CHANNEL_A, FLIPPER_ENCODER_CHANNEL_B };
};
