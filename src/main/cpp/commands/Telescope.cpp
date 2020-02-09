#include "commands/Telescope.h"

Telescope::Telescope( bool aExtend )
    : CommandBase("Telescope")
    , mExtend( aExtend )    
{
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

}

void Telescope::Interrupted()
{

}
