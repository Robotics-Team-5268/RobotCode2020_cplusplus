#include "commands/Lift.h"

#include "RobotContainer.h"

Lift::Lift( bool aRaise )
    : mRaise( aRaise )
{
    SetName( "Lift" );
    Requires( RobotContainer::winches.get() );
}

void Lift::Initialize() {}

void Lift::Execute() {

    const double percentOutput = mRaise ? 0.3 : -0.3;
    RobotContainer::winches->lift( percentOutput );
}

bool Lift::IsFinished() { 
    return true; 
}

void Lift::End()
{
    RobotContainer::winches->lift( 0.0 );
}

void Lift::Interrupted()
{

}
