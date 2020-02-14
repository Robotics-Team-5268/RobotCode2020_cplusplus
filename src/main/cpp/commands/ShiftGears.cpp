#include "commands/ShiftGears.h"

#include "CommandBase.h"

ShiftGears::ShiftGears(frc::DoubleSolenoid::Value aValue) : CommandBase("ShiftGears") {
    Requires(CommandBase::pneumatics.get());
    mValue = aValue;
}

void ShiftGears::Initialize()
{
    // We want this command to run for 200 ms
    SetTimeout( 0.2 );
}

void ShiftGears::Execute() {
    if (mValue == frc::DoubleSolenoid::kForward) {
        CommandBase::pneumatics->ShiftForward();
    } else if (mValue == frc::DoubleSolenoid::kReverse){
        CommandBase::pneumatics->ShiftReverse();
    } else {
        CommandBase::pneumatics->ShiftOff();
    }
}

bool ShiftGears::IsFinished() { 
    return true; 
}

void ShiftGears::End()
{
    CommandBase::pneumatics->ShiftOff();
}

void ShiftGears::Interrupted() {}
