#include "commands/MovePneumatics.h"

#include "RobotConfig.h"
#include "Commands.h"

MovePneumatics::MovePneumatics(frc::DoubleSolenoid::Value v) {
    SetName( "MovePneumatics" );

    #if( PNEUMATICS_SUPPORT )
        AddRequirements(Commands::pneumatics.get());
    #endif
    value = v;
}

void MovePneumatics::Initialize() {}

void MovePneumatics::Execute() {
    #if( PNEUMATICS_SUPPORT )
        if (value == frc::DoubleSolenoid::kForward) {
            Commands::pneumatics->Forward();
        } else if (value == frc::DoubleSolenoid::kReverse){
            Commands::pneumatics->Reverse();
        } else {
            Commands::pneumatics->Off();
        }
    #endif
}

bool MovePneumatics::IsFinished() { 
    return true; 
}

void MovePneumatics::End(bool interrupted) {}
