#include "commands/PickupBall.h"

PickupBall::PickupBall() : CommandBase("PickupBall") {
    Requires( CommandBase::ballIntake.get() );
}

void PickupBall::Initialize() {}

void PickupBall::Execute() {
    ballIntake->setSpeed( 0.2 );
}

bool PickupBall::IsFinished() { 
    return true; 
}

void PickupBall::End()
{
    ballIntake->setSpeed( 0.0 );
}

void PickupBall::Interrupted()
{

}
