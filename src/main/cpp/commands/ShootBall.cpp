#include "commands/ShootBall.h"

#include "RobotContainer.h"

ShootBall::ShootBall()
{
    SetName("ShootBall");
    Requires( RobotContainer::ballIntake.get() );
}

void ShootBall::Initialize() {}

void ShootBall::Execute() {
    RobotContainer::ballIntake->setUpperSpeed( 0.8 );
}

bool ShootBall::IsFinished() { 
    return true; 
}

void ShootBall::End()
{
    RobotContainer::ballIntake->setUpperSpeed( 0.0 );
}

void ShootBall::Interrupted()
{

}
