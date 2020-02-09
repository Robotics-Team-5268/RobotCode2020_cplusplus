#include "subsystems/Winches.h"

Winches::Winches() : Subsystem("Winches") {

}

Winches::~Winches()
{

}

void Winches::lift( double aPercent )
{
    pullupSpeedControllGroup.Set( aPercent );
}

void Winches::telescope( double aPercent )
{
    telescopeSpeedController.Set( aPercent );
}