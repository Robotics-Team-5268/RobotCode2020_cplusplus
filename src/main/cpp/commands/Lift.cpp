#include "commands/Lift.h"

Lift::Lift( bool aRaise )
    : RobotContainer("Lift")
    , mRaise( aRaise )    
{
    Requires( winches.get() );
}

void Lift::Initialize() {}

void Lift::Execute() {

    const double percentOutput = mRaise ? 0.3 : -0.3;
    winches->lift( percentOutput );
}

bool Lift::IsFinished() { 
    return true; 
}

void Lift::End()
{
    winches->lift( 0.0 );
}

void Lift::Interrupted()
{

}
