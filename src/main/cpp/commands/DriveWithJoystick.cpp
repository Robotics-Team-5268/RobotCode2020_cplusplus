#include "commands/DriveWithJoystick.h"

DriveWithJoystick::DriveWithJoystick( Drive* aDrive, const std::shared_ptr<frc::Joystick>& aJoystick )
  : mDrive( aDrive )
  , mJoystick( aJoystick )
{
  AddRequirements( mDrive ) ;

  SetName( "DriveWithJoystick" );
}

void DriveWithJoystick::Initialize() {}

void DriveWithJoystick::Execute() {
  mDrive->setMotors(
    -mJoystick->GetRawAxis(1) ,
	  -mJoystick->GetRawAxis(5)
    );
}

bool DriveWithJoystick::IsFinished() { return true; }

void DriveWithJoystick::End(bool interrupted) {}
