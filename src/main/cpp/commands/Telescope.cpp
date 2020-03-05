#include "commands/Telescope.h"

#include "RobotContainer.h"

Telescope::Telescope( bool aExtend )
    : mExtend( aExtend )
{
    SetName("Telescope");
    Requires( RobotContainer::winches.get() );
}

void Telescope::Initialize() {}

void Telescope::Execute() {

    const double percentOutput = mExtend ? 0.3 : -0.3;
    RobotContainer::winches->telescope( percentOutput );
}

bool Telescope::IsFinished() { 
    return true; 
}

void Telescope::End()
{
    RobotContainer::winches->telescope( 0.0 );
}

void Telescope::Interrupted()
{

}
