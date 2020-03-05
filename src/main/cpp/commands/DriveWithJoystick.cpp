#include "commands/DriveWithJoystick.h"

#include "RobotContainer.h"

DriveWithJoystick::DriveWithJoystick() {
  AddRequirements( RobotContainer::drive.get()) ;

  SetName( "DriveWithJoystick" );
}

void DriveWithJoystick::Initialize() {}

void DriveWithJoystick::Execute() {
  RobotContainer::drive->setMotors(
    -RobotContainer::oi->getDriverJoystick()->GetRawAxis(1) ,
	  -RobotContainer::oi->getDriverJoystick()->GetRawAxis(5)
    // 0.0,0.0
  );
}

bool DriveWithJoystick::IsFinished() { return true; }

void DriveWithJoystick::End(bool interrupted) {}
