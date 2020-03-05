#include "commands/ShiftGears.h"

ShiftGears::ShiftGears( Pneumatics* aPneumatics, frc::DoubleSolenoid::Value aValue )
    : mPneumatics( aPneumatics )
{
    SetName("ShiftGears");
    Requires( mPneumatics );
    mValue = aValue;
}

void ShiftGears::Initialize()
{
    // We want this command to run for 200 ms
    SetTimeout( 0.2 );
}

void ShiftGears::Execute() {
    if (mValue == frc::DoubleSolenoid::kForward) {
        mPneumatics->ShiftForward();
    } else if (mValue == frc::DoubleSolenoid::kReverse){
        mPneumatics->ShiftReverse();
    } else {
        mPneumatics->ShiftOff();
    }
}

bool ShiftGears::IsFinished() { 
    return true; 
}

void ShiftGears::End()
{
    mPneumatics->ShiftOff();
}
