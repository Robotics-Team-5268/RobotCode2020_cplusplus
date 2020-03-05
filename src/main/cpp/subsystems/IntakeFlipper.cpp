#include "subsystems/IntakeFlipper.h"

IntakeFlipper::IntakeFlipper()
{
    SetName( "IntakeFlipper" );
    mFlipperSpeedController.SetInverted( true );
    mFlipperEncoder.SetReverseDirection( true );
}

IntakeFlipper::~IntakeFlipper()
{

}

int IntakeFlipper::getEncoderValue()
{
    return mFlipperEncoder.Get();
}

void IntakeFlipper::setSpeed( double aPercentOutput )
{
    mFlipperSpeedController.Set( aPercentOutput );
}
