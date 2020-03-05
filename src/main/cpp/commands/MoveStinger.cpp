#include "commands/MoveStinger.h"

MoveStinger::MoveStinger( Pneumatics* aPneumatics, frc::DoubleSolenoid::Value aValue)
    : mPneumatics( aPneumatics )
    , mValue( aValue )
{
    SetName( "MoveStinger" );
    Requires( mPneumatics );
}

void MoveStinger::Initialize()
{
    // We want this command to run for 200 ms
    SetTimeout( 0.2 );
}

void MoveStinger::Execute() {
    if (mValue == frc::DoubleSolenoid::kForward) {
        mPneumatics->StingerForward();
    } else if (mValue == frc::DoubleSolenoid::kReverse){
        mPneumatics->StingerReverse();
    } else {
        mPneumatics->StingerOff();
    }
}

bool MoveStinger::IsFinished() { 
    return true; 
}

void MoveStinger::End()
{
    mPneumatics->StingerOff();
}
