#include "commands/Lift.h"

Lift::Lift( bool raise )
    : CommandBase("Lift")
    , mRaise( raise )    
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

}

void Lift::Interrupted()
{

}
