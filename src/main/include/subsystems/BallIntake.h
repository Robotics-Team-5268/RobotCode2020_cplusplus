#pragma once

#include <frc/commands/PIDSubsystem.h>
#include <frc/Encoder.h>
#include <ctre/Phoenix.h>
#include "RobotConfig.h"
#include "RobotMap.h"

class BallIntake : public frc::PIDSubsystem {
public:
    static constexpr double cOpenFlipper = 60.0;
    static constexpr double cCloseFlipper = 0.0;

    BallIntake();
    virtual ~BallIntake();

    // No default command, if PID is enabled, the current setpoint will be maintained.
    void InitDefaultCommand() override;

    double ReturnPIDInput() override;

    void UsePIDOutput(double output) override;

    void setLowerSpeed( double aPercent );
    void setUpperSpeed( double aPercent );

private:
    WPI_VictorSPX lowerSpeedController{BALL_INTAKE_LOWER_SPEED_CONTROLLER};
    WPI_TalonSRX upperSpeedController{BALL_INTAKE_UPPER_SPEED_CONTROLLER};

    WPI_TalonSRX flipperSpeedController{BALL_INTAKE_FLIPPER_SPEED_CONTROLLER};
    frc::Encoder flipperEncoder{ FLIPPER_ENCODER_CHANNEL_A, FLIPPER_ENCODER_CHANNEL_B };
};
