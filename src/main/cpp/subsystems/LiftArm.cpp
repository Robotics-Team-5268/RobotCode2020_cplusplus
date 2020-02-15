#include "subsystems/LiftArm.h"

LiftArm::LiftArm() : PIDSubsystem("LiftArm", 7.0, 0.0, 8.0)
{
    // Value taken from REV-11-1271 datasheet
    const double pulsesPerRevolution = 8192.0;
    // Set the distance per pulse to work in degrees
    mEncoder.SetDistancePerPulse(360.0 / pulsesPerRevolution );
    SetAbsoluteTolerance(0.005);
    GetPIDController()->SetContinuous(false);
    GetPIDController()->SetOutputRange( 0.01, 0.15 );
}

LiftArm::~LiftArm()
{

}

void LiftArm::InitDefaultCommand()
{

}

double LiftArm::ReturnPIDInput()
{
    return mEncoder.Get();
}

void LiftArm::UsePIDOutput(double aOutput)
{
    mSpeedController.PIDWrite(aOutput);
}
