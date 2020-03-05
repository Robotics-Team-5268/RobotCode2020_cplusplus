#include "commands/DriveWithJoystick.h"

DriveWithJoystick::DriveWithJoystick() : RobotContainer("DriveWithJoystick") {
  Requires(drive.get());
}

void DriveWithJoystick::Initialize() {}

void DriveWithJoystick::Execute() {
  drive->setMotors(
    -RobotContainer::oi->getDriverJoystick()->GetRawAxis(1) * 0.4,
	  -RobotContainer::oi->getDriverJoystick()->GetRawAxis(5) * 0.4
  );
}

bool DriveWithJoystick::IsFinished() { return true; }

void DriveWithJoystick::End() {}

void DriveWithJoystick::Interrupted() {}
