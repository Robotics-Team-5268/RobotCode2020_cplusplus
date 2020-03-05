#include "commands/DriveWithJoystick.h"

#include "RobotContainer.h"

DriveWithJoystick::DriveWithJoystick()
{
  SetName( "DriveWithJoystick" );
  Requires(RobotContainer::drive.get());
}

void DriveWithJoystick::Initialize() {}

void DriveWithJoystick::Execute() {
  RobotContainer::drive->setMotors(
    -RobotContainer::getDriverJoystick()->GetRawAxis(1) * 0.4,
	  -RobotContainer::getDriverJoystick()->GetRawAxis(5) * 0.4
  );
}

bool DriveWithJoystick::IsFinished() { return true; }

void DriveWithJoystick::End() {}

void DriveWithJoystick::Interrupted() {}
