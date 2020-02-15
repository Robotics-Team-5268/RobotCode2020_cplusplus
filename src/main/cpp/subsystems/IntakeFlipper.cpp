#include "subsystems/IntakeFlipper.h"

IntakeFlipper::IntakeFlipper() : PIDSubsystem("IntakeFlipper", 7.0, 0.0, 8.0)
{
    // Value taken from REV-11-1271 datasheet
    const double pulsesPerRevolution = 8192.0;
    // Set the distance per pulse to work in degrees
    mFlipperEncoder.SetDistancePerPulse(360.0 / pulsesPerRevolution );
    SetAbsoluteTolerance(0.005);
    GetPIDController()->SetContinuous(false);
    GetPIDController()->SetOutputRange( 0.01, 0.15 );
}

IntakeFlipper::~IntakeFlipper()
{

}

void IntakeFlipper::InitDefaultCommand()
{

}

double IntakeFlipper::ReturnPIDInput()
{
    return mFlipperEncoder.Get();
}

void IntakeFlipper::UsePIDOutput(double aOutput)
{
    mFlipperSpeedController.PIDWrite(aOutput);
}
