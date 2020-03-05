#include "subsystems/BallIntake.h"

BallIntake::BallIntake()
{
    SetName( "BallIntake" );
    mLowerSpeedController.SetInverted( true );
}

BallIntake::~BallIntake()
{

}

void BallIntake::setLowerSpeed( double aPercent )
{
    mLowerSpeedController.Set( aPercent );
}

void BallIntake::setUpperSpeed( double aPercent )
{
    mUpperSpeedController.Set( aPercent );
}
