#include "commands/PickupBall.h"

PickupBall::PickupBall( BallIntake* aBallIntake )
    : mBallIntake( aBallIntake )
{
    SetName("PickupBall");

    AddRequirements( mBallIntake );
}

void PickupBall::Initialize() {}

void PickupBall::Execute() {
    mBallIntake->setLowerSpeed( 0.7 );
    mBallIntake->setUpperSpeed( 0.3 );
}

bool PickupBall::IsFinished() { 
    return true; 
}

void PickupBall::End(bool interrupted)
{
    mBallIntake->setLowerSpeed( 0.0 );
    mBallIntake->setUpperSpeed( 0.0 );
}
