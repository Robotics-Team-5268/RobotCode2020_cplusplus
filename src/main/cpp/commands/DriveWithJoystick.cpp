#include "commands/DriveWithJoystick.h"

DriveWithJoystick::DriveWithJoystick( Drive* aDrive, const std::shared_ptr<frc::Joystick>& aJoystick )
  : mDrive( aDrive )
  , mJoystick( aJoystick )
{
  SetName( "DriveWithJoystick" );
  AddRequirements( mDrive );
}

void DriveWithJoystick::Initialize() {}

void DriveWithJoystick::Execute() {
  mDrive->setMotors(
    -mJoystick->GetRawAxis(1) * 0.4,
	  -mJoystick->GetRawAxis(5) * 0.4
  );
}

bool DriveWithJoystick::IsFinished() { return true; }

void DriveWithJoystick::End(bool interrupted) {}
