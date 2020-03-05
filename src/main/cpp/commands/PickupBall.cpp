#include "commands/PickupBall.h"

#include "RobotContainer.h"

PickupBall::PickupBall()
{
    SetName("PickupBall");

    Requires( RobotContainer::ballIntake.get() );
}

void PickupBall::Initialize() {}

void PickupBall::Execute() {
    RobotContainer::ballIntake->setLowerSpeed( 0.7 );
    RobotContainer::ballIntake->setUpperSpeed( 0.3 );
}

bool PickupBall::IsFinished() { 
    return true; 
}

void PickupBall::End()
{
    RobotContainer::ballIntake->setLowerSpeed( 0.0 );
    RobotContainer::ballIntake->setUpperSpeed( 0.0 );
}
