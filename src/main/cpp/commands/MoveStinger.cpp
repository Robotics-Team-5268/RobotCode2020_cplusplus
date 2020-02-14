#include "commands/MoveStinger.h"

#include "CommandBase.h"

MoveStinger::MoveStinger(frc::DoubleSolenoid::Value aValue) : CommandBase("MoveStinger") {
    Requires(CommandBase::pneumatics.get());
    mValue = aValue;
}

void MoveStinger::Initialize()
{
    // We want this command to run for 200 ms
    SetTimeout( 0.2 );
}

void MoveStinger::Execute() {
    if (mValue == frc::DoubleSolenoid::kForward) {
        CommandBase::pneumatics->StingerForward();
    } else if (mValue == frc::DoubleSolenoid::kReverse){
        CommandBase::pneumatics->StingerReverse();
    } else {
        CommandBase::pneumatics->StingerOff();
    }
}

bool MoveStinger::IsFinished() { 
    return true; 
}

void MoveStinger::End()
{
    CommandBase::pneumatics->StingerOff();
}

void MoveStinger::Interrupted() {}
