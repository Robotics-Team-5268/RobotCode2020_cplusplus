#include "commands/ShootBall.h"

ShootBall::ShootBall( BallIntake* aBallIntake )
    : mBallIntake( aBallIntake )
{
    SetName("ShootBall");
    Requires( mBallIntake );
}

void ShootBall::Initialize() {}

void ShootBall::Execute() {
    mBallIntake->setUpperSpeed( 0.8 );
}

bool ShootBall::IsFinished() { 
    return true; 
}

void ShootBall::End()
{
    mBallIntake->setUpperSpeed( 0.0 );
}
