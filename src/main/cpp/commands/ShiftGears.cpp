#include "commands/ShiftGears.h"

#include "RobotConfig.h"
#include "CommandBase.h"

ShiftGears::ShiftGears(frc::DoubleSolenoid::Value v) : CommandBase("ShiftGears") {
    #if( PNEUMATICS_SUPPORT )
        Requires(CommandBase::pneumatics.get());
    #endif
    value = v;
}

void ShiftGears::Initialize()
{
    // We want this command to run for 200 ms
    SetTimeout( 0.2 );
}

void ShiftGears::Execute() {
    #if( PNEUMATICS_SUPPORT )
        if (value == frc::DoubleSolenoid::kForward) {
            CommandBase::pneumatics->ShiftForward();
        } else if (value == frc::DoubleSolenoid::kReverse){
            CommandBase::pneumatics->ShiftReverse();
        } else {
            CommandBase::pneumatics->ShiftOff();
        }
    #endif
}

bool ShiftGears::IsFinished() { 
    return true; 
}

void ShiftGears::End()
{
    #if( PNEUMATICS_SUPPORT )
        CommandBase::pneumatics->ShiftOff();
    #endif
}

void ShiftGears::Interrupted() {}