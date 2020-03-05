#include "commands/Telescope.h"

Telescope::Telescope( bool aExtend )
    : mExtend( aExtend )
{
    SetName("Telescope");
    Requires( winches.get() );
}

void Telescope::Initialize() {}

void Telescope::Execute() {

    const double percentOutput = mExtend ? 0.3 : -0.3;
    winches->telescope( percentOutput );
}

bool Telescope::IsFinished() { 
    return true; 
}

void Telescope::End()
{
    winches->telescope( 0.0 );
}

void Telescope::Interrupted()
{

}
