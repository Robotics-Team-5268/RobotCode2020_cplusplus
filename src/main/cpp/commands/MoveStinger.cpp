#include "commands/MoveStinger.h"

#include "RobotContainer.h"

MoveStinger::MoveStinger(frc::DoubleSolenoid::Value aValue)
{
    SetName( "MoveStinger" );
    Requires(RobotContainer::pneumatics.get());
    mValue = aValue;
}

void MoveStinger::Initialize()
{
    // We want this command to run for 200 ms
    SetTimeout( 0.2 );
}

void MoveStinger::Execute() {
    if (mValue == frc::DoubleSolenoid::kForward) {
        RobotContainer::pneumatics->StingerForward();
    } else if (mValue == frc::DoubleSolenoid::kReverse){
        RobotContainer::pneumatics->StingerReverse();
    } else {
        RobotContainer::pneumatics->StingerOff();
    }
}

bool MoveStinger::IsFinished() { 
    return true; 
}

void MoveStinger::End()
{
    RobotContainer::pneumatics->StingerOff();
}

void MoveStinger::Interrupted() {}
