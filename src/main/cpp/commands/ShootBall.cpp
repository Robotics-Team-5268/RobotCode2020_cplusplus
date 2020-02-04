#include "commands/ShootBall.h"

ShootBall::ShootBall() : CommandBase("ShootBall") {
    Requires( ballIntake.get() );
}

void ShootBall::Initialize() {}

void ShootBall::Execute() {
    ballIntake->setUpperSpeed( 0.8 );
}

bool ShootBall::IsFinished() { 
    return true; 
}

void ShootBall::End()
{
    ballIntake->setUpperSpeed( 0.0 );
}

void ShootBall::Interrupted()
{

}
