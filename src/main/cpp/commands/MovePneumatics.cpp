#include "commands/MovePneumatics.h"

#include "RobotConfig.h"

MovePneumatics::MovePneumatics
    (
    frc::DoubleSolenoid::Value v
    #if( PNEUMATICS_SUPPORT )
      , Pneumatics* aPneumantics
    #endif
    )
    : value( v )
    #if( PNEUMATICS_SUPPORT )
      , mPneumantics( aPneumantics )
    #endif

{
    SetName( "MovePneumatics" );

    #if( PNEUMATICS_SUPPORT )
        AddRequirements( mPneumantics );
    #endif
}

void MovePneumatics::Initialize() {}

void MovePneumatics::Execute() {
    #if( PNEUMATICS_SUPPORT )
        if (value == frc::DoubleSolenoid::kForward) {
            mPneumantics->Forward();
        } else if (value == frc::DoubleSolenoid::kReverse){
            mPneumantics->Reverse();
        } else {
            mPneumantics->Off();
        }
    #endif
}

bool MovePneumatics::IsFinished() { 
    return true; 
}

void MovePneumatics::End(bool interrupted) {}
