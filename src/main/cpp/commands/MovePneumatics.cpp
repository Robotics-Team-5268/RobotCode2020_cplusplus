#include "commands/MovePneumatics.h"

#include "RobotConfig.h"
#include "CommandBase.h"

MovePneumatics::MovePneumatics(frc::DoubleSolenoid::Value v) : CommandBase("MovePneumatics") {
    #if( PNEUMATICS_SUPPORT )
        Requires(CommandBase::pneumatics.get());
    #endif
    value = v;
}

void MovePneumatics::Initialize() {}

void MovePneumatics::Execute() {
    #if( PNEUMATICS_SUPPORT )
        if (value == frc::DoubleSolenoid::kForward) {
            CommandBase::pneumatics->Forward();
        } else if (value == frc::DoubleSolenoid::kReverse){
            CommandBase::pneumatics->Reverse();
        } else {
            CommandBase::pneumatics->Off();
        }
    #endif
}

bool MovePneumatics::IsFinished() { 
    return true; 
}

void MovePneumatics::End() {}

void MovePneumatics::Interrupted() {}
