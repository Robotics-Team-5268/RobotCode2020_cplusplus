#include "commands/PickupBall.h"

PickupBall::PickupBall()
{
    SetName("PickupBall");

    Requires( ballIntake.get() );
}

void PickupBall::Initialize() {}

void PickupBall::Execute() {
    ballIntake->setLowerSpeed( 0.7 );
    ballIntake->setUpperSpeed( 0.3 );
}

bool PickupBall::IsFinished() { 
    return true; 
}

void PickupBall::End()
{
    ballIntake->setLowerSpeed( 0.0 );
    ballIntake->setUpperSpeed( 0.0 );
}

void PickupBall::Interrupted()
{

}
