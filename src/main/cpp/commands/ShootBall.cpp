#include "commands/ShootBall.h"

ShootBall::ShootBall() : CommandBase("ShootBall") {
    Requires( CommandBase::ballIntake.get() );
}

void ShootBall::Initialize() {}

void ShootBall::Execute() {
    ballIntake->setSpeed( 0.5 );
}

bool ShootBall::IsFinished() { 
    return true; 
}

void ShootBall::End()
{
    ballIntake->setSpeed( 0.0 );
}

void ShootBall::Interrupted()
{

}
