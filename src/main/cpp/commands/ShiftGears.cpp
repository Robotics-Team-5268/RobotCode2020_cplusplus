#include "commands/ShiftGears.h"

ShiftGears::ShiftGears( Pneumatics* aPneumatics, frc::DoubleSolenoid::Value aValue )
    : mPneumatics( aPneumatics )
{
    SetName("ShiftGears");
    AddRequirements( mPneumatics );
    mValue = aValue;
}

void ShiftGears::Initialize()
{
    // TODO: Figure out timeouts
    // We want this command to run for 200 ms
    //WithTimeout( 0.2 );
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

void ShiftGears::End(bool interrupted)
{
    mPneumatics->ShiftOff();
}
