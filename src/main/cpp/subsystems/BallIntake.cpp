#include "subsystems/BallIntake.h"

BallIntake::BallIntake() : Subsystem("BallIntake") {

}

BallIntake::~BallIntake()
{

}

void BallIntake::setLowerSpeed( double aPercent )
{
    lowerSpeedController.Set( aPercent );
}

void BallIntake::setUpperSpeed( double aPercent )
{
    upperSpeedController.Set( aPercent );
}
