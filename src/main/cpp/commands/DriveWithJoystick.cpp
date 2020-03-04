#include "commands/DriveWithJoystick.h"

#include "Commands.h"

DriveWithJoystick::DriveWithJoystick() {
  AddRequirements( Commands::drive.get()) ;

  SetName( "DriveWithJoystick" );
}

void DriveWithJoystick::Initialize() {}

void DriveWithJoystick::Execute() {
  Commands::drive->setMotors(
    -Commands::oi->getDriverJoystick()->GetRawAxis(1) ,
	  -Commands::oi->getDriverJoystick()->GetRawAxis(5)
    // 0.0,0.0
  );
}

bool DriveWithJoystick::IsFinished() { return true; }

void DriveWithJoystick::End(bool interrupted) {}
