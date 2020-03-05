#include "commands/ShiftGears.h"

#include "RobotContainer.h"

ShiftGears::ShiftGears(frc::DoubleSolenoid::Value aValue)
{
    SetName("ShiftGears");
    Requires(RobotContainer::pneumatics.get());
    mValue = aValue;
}

void ShiftGears::Initialize()
{
    // We want this command to run for 200 ms
    SetTimeout( 0.2 );
}

void ShiftGears::Execute() {
    if (mValue == frc::DoubleSolenoid::kForward) {
        RobotContainer::pneumatics->ShiftForward();
    } else if (mValue == frc::DoubleSolenoid::kReverse){
        RobotContainer::pneumatics->ShiftReverse();
    } else {
        RobotContainer::pneumatics->ShiftOff();
    }
}

bool ShiftGears::IsFinished() { 
    return true; 
}

void ShiftGears::End()
{
    RobotContainer::pneumatics->ShiftOff();
}
