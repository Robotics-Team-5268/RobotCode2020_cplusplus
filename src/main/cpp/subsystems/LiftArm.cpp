#include "subsystems/LiftArm.h"

LiftArm::LiftArm() : Subsystem("LiftArm")
{

}

LiftArm::~LiftArm()
{

}

int LiftArm::getEncoderValue()
{
    return mEncoder.Get();
}

void LiftArm::setSpeed( double aPercentOutput )
{
    mSpeedController.Set( aPercentOutput );
}