#include "commands/ShootBall.h"

ShootBall::ShootBall( BallIntake* aBallIntake )
    : mBallIntake( aBallIntake )
{
    SetName("ShootBall");
    AddRequirements( mBallIntake );
}

void ShootBall::Initialize() {}

void ShootBall::Execute() {
    mBallIntake->setUpperSpeed( 0.8 );
}

bool ShootBall::IsFinished() { 
    return true; 
}

void ShootBall::End(bool interrupted)
{
    mBallIntake->setUpperSpeed( 0.0 );
}
