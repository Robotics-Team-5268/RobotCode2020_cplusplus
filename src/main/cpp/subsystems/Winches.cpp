#include "subsystems/Winches.h"

Winches::Winches() : Subsystem("Winches") {

}

Winches::~Winches()
{

}

void Winches::lift( double aPercent )
{
    pullupSpeedController1.Set( aPercent );    
}

void Winches::telescope( double aPercent )
{
    telescopeSpeedController.Set( aPercent );
}