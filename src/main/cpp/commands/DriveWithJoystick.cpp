#include "commands/DriveWithJoystick.h"

DriveWithJoystick::DriveWithJoystick() : CommandBase("DriveWithJoystick") {
  Requires(drive.get());
}

void DriveWithJoystick::Initialize() {}

void DriveWithJoystick::Execute() {
  drive->setMotors(
    -CommandBase::oi->getDriverJoystick()->GetRawAxis(1) * 0.4,
	  -CommandBase::oi->getDriverJoystick()->GetRawAxis(5) * 0.4
  );
}

bool DriveWithJoystick::IsFinished() { return true; }

void DriveWithJoystick::End() {}

void DriveWithJoystick::Interrupted() {}
