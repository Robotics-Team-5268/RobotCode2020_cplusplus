#include "commands/Telescope.h"

Telescope::Telescope( bool extend )
    : CommandBase("Telescope")
    , mExtend( extend )    
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
