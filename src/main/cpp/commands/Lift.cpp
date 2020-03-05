#include "commands/Lift.h"

Lift::Lift( Winches* aWinches, bool aRaise )
    : mWinches( aWinches )
    , mRaise( aRaise )
{
    SetName( "Lift" );
    Requires( mWinches );
}

void Lift::Initialize() {}

void Lift::Execute() {

    const double percentOutput = mRaise ? 0.3 : -0.3;
    mWinches->lift( percentOutput );
}

bool Lift::IsFinished() { 
    return true; 
}

void Lift::End()
{
    mWinches->lift( 0.0 );
}
