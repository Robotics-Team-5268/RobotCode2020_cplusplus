#pragma once

#include <frc/commands/PIDSubsystem.h>
#include <frc/Encoder.h>
#include <ctre/Phoenix.h>
#include "RobotMap.h"

class LiftArm : public frc::PIDSubsystem {
public:
    static constexpr double cRaiseArm = 90.0;
    static constexpr double cLowerArm = 0.0;

    LiftArm();
    virtual ~LiftArm();

    // No default command, if PID is enabled, the current setpoint will be maintained.
    void InitDefaultCommand() override;

    double ReturnPIDInput() override;

    void UsePIDOutput(double output) override;

private:
    WPI_TalonSRX speedController{LIFT_ARM_SPEED_CONTROLLER};
    frc::Encoder encoder{ LIFT_ARM_ENCODER_CHANNEL_A, LIFT_ARM_ENCODER_CHANNEL_B };
};
