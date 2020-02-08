#include "commands/MoveStinger.h"

#include "RobotConfig.h"
#include "CommandBase.h"

MoveStinger::MoveStinger(frc::DoubleSolenoid::Value v) : CommandBase("MoveStinger") {
    #if( PNEUMATICS_SUPPORT )
        Requires(CommandBase::pneumatics.get());
    #endif
    value = v;
}

void MoveStinger::Initialize()
{
    // We want this command to run for 200 ms
    SetTimeout( 0.2 );
}

void MoveStinger::Execute() {
    #if( PNEUMATICS_SUPPORT )
        if (value == frc::DoubleSolenoid::kForward) {
            CommandBase::pneumatics->StingerForward();
        } else if (value == frc::DoubleSolenoid::kReverse){
            CommandBase::pneumatics->StingerReverse();
        } else {
            CommandBase::pneumatics->StingerOff();
        }
    #endif
}

bool MoveStinger::IsFinished() { 
    return true; 
}

void MoveStinger::End()
{
    #if( PNEUMATICS_SUPPORT )
        CommandBase::pneumatics->StingerOff();
    #endif
}

void MoveStinger::Interrupted() {}