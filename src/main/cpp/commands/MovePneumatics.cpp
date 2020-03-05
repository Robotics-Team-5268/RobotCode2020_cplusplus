#include "commands/MovePneumatics.h"

#include "RobotConfig.h"
#include "RobotContainer.h"

MovePneumatics::MovePneumatics(frc::DoubleSolenoid::Value v) {
    SetName( "MovePneumatics" );

    #if( PNEUMATICS_SUPPORT )
        AddRequirements(RobotContainer::pneumatics.get());
    #endif
    value = v;
}

void MovePneumatics::Initialize() {}

void MovePneumatics::Execute() {
    #if( PNEUMATICS_SUPPORT )
        if (value == frc::DoubleSolenoid::kForward) {
            RobotContainer::pneumatics->Forward();
        } else if (value == frc::DoubleSolenoid::kReverse){
            RobotContainer::pneumatics->Reverse();
        } else {
            RobotContainer::pneumatics->Off();
        }
    #endif
}

bool MovePneumatics::IsFinished() { 
    return true; 
}

void MovePneumatics::End(bool interrupted) {}
