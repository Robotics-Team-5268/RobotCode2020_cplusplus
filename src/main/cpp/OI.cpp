#include "OI.h"

#include "RobotConfig.h"
#include <frc/WPILib.h>
#include <frc/DoubleSolenoid.h>
#include "frc/smartDashboard/SmartDashboard.h"
#include "Robot.h"
#include "commands/MoveFlipper.h"
#include "commands/PickupBall.h"
#include "commands/ReadColorSensor.h"
#include "commands/ShootBall.h"
#if( PNEUMATICS_SUPPORT )
    #include "commands/MovePneumatics.h"
#endif
#include "subsystems/BallIntake.h"

OI::OI() {
  driverJoystick.reset(new frc::Joystick(0));
  #if( PNEUMATICS_SUPPORT )
      mechanismsJoystick.reset(new frc::Joystick(1));
  #endif
  for (int i=1; i<=10; i++){
    driverBtns.push_back(new frc::JoystickButton(driverJoystick.get(), i));
    #if( PNEUMATICS_SUPPORT )
        mechanismsBtns.push_back(new frc::JoystickButton(mechanismsJoystick.get(), i));
    #endif
  }

  driverBtns[2]->WhileHeld( new ReadColorSensor() ); //This should be 'x' button on the XBox controller

  driverBtns[4]->WhileHeld( new PickupBall() );

  driverBtns[5]->WhenPressed( new MoveFlipper( BallIntake::cOpenFlipper ) );
  driverBtns[5]->WhileHeld( new ShootBall() );
  driverBtns[5]->WhenReleased( new MoveFlipper( BallIntake::cCloseFlipper ) );

  #if( PNEUMATICS_SUPPORT )
      mechanismsBtns[2]->WhileHeld(new MovePneumatics(frc::DoubleSolenoid::kForward)); //This should be 'x' button on the XBox controller
      mechanismsBtns[2]->WhenReleased(new MovePneumatics(frc::DoubleSolenoid::kOff)); //This should be 'x' button on the XBox controller
      mechanismsBtns[3]->WhileHeld(new MovePneumatics(frc::DoubleSolenoid::kReverse)); //This should be 'y' button on the XBox controller
      mechanismsBtns[3]->WhenReleased(new MovePneumatics(frc::DoubleSolenoid::kOff)); //This should be 'y' button on the XBox controller
  #endif
}

std::shared_ptr<frc::Joystick> OI::getDriverJoystick() {
	return driverJoystick;
}
