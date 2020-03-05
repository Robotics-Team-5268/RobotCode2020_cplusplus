#include "commands/Telescope.h"

Telescope::Telescope( Winches* aWinches, bool aExtend )
    : mWinches( aWinches )
    , mExtend( aExtend )
{
    SetName("Telescope");
    Requires( aWinches );
}

void Telescope::Initialize() {}

void Telescope::Execute() {

    const double percentOutput = mExtend ? 0.3 : -0.3;
    mWinches->telescope( percentOutput );
}

bool Telescope::IsFinished() { 
    return true; 
}

void Telescope::End()
{
    mWinches->telescope( 0.0 );
}
