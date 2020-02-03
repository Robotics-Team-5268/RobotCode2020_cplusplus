#include "subsystems/BallIntake.h"

BallIntake::BallIntake() : Subsystem("BallIntake") {

}

BallIntake::~BallIntake()
{

}

void BallIntake::setSpeed( double aPercent )
{
    speedControlGroup.Set( aPercent );
}
