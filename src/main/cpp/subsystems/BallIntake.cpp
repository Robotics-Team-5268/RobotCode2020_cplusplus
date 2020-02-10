#include "subsystems/BallIntake.h"

BallIntake::BallIntake() : PIDSubsystem("BallIntake", 7.0, 0.0, 8.0)
{
    // Value taken from REV-11-1271 datasheet
    const double pulsesPerRevolution = 8192.0;
    // Set the distance per pulse to work in degrees
    mFlipperEncoder.SetDistancePerPulse(360.0 / pulsesPerRevolution );
    SetAbsoluteTolerance(0.005);
    GetPIDController()->SetContinuous(false);
}

BallIntake::~BallIntake()
{

}

void BallIntake::InitDefaultCommand()
{

}

double BallIntake::ReturnPIDInput()
{
    return mFlipperEncoder.Get();
}

void BallIntake::UsePIDOutput(double aOutput)
{
    mFlipperSpeedController.PIDWrite(aOutput);
}

void BallIntake::setLowerSpeed( double aPercent )
{
    mLowerSpeedController.Set( aPercent );
}

void BallIntake::setUpperSpeed( double aPercent )
{
    mUpperSpeedController.Set( aPercent );
}
