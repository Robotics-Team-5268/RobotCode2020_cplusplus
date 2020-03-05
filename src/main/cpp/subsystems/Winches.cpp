#include "subsystems/Winches.h"

Winches::Winches()
{
    SetName( "Winches" );
}

Winches::~Winches()
{

}

void Winches::lift( double aPercent )
{
    mPullupSpeedControllGroup.Set( aPercent );
}

void Winches::telescope( double aPercent )
{
    mTelescopeSpeedController.Set( aPercent );
}