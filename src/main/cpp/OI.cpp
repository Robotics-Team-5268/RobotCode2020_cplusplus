#include "OI.h"

#include "RobotConfig.h"
#include <frc/WPILib.h>
#include <frc/DoubleSolenoid.h>
#include "frc/smartDashboard/SmartDashboard.h"
#include "Robot.h"
#include "commands/Lift.h"
#include "commands/MoveArm.h"
#include "commands/MoveFlipper.h"
#include "commands/MoveStinger.h"
#include "commands/PickupBall.h"
#include "commands/ReadColorSensor.h"
#include "commands/ShiftGears.h"
#include "commands/ShootBall.h"
#include "commands/Telescope.h"
#if( PNEUMATICS_SUPPORT )
    #include "commands/MovePneumatics.h"
#endif

#include "subsystems/BallIntake.h"
#include "subsystems/LiftArm.h"

OI::OI() {
  driverJoystick.reset(new frc::Joystick(0));
  mechanismsJoystick.reset(new frc::Joystick(1));
  for (int i=1; i<=10; i++){
    driverBtns.push_back(new frc::JoystickButton(driverJoystick.get(), i));
    mechanismsBtns.push_back(new frc::JoystickButton(mechanismsJoystick.get(), i));
  }

  driverBtns[2]->WhileHeld( new ReadColorSensor() ); //This should be 'x' button on the XBox controller

  driverBtns[4]->WhileHeld( new PickupBall() );

  driverBtns[5]->WhenPressed( new MoveFlipper( BallIntake::cOpenFlipper ) );
  driverBtns[5]->WhileHeld( new ShootBall() );
  driverBtns[5]->WhenReleased( new MoveFlipper( BallIntake::cCloseFlipper ) );

  driverBtns[6]->WhenPressed( new MoveArm( LiftArm::cRaiseArm ) );

  driverBtns[8]->WhenPressed(new ShiftGears(frc::DoubleSolenoid::kForward));
  driverBtns[9]->WhenPressed(new ShiftGears(frc::DoubleSolenoid::kReverse));


  mechanismsBtns[2]->WhenPressed(new MoveStinger(frc::DoubleSolenoid::kForward)); //This should be 'x' button on the XBox controller
  mechanismsBtns[3]->WhenPressed(new MoveStinger(frc::DoubleSolenoid::kReverse)); //This should be 'y' button on the XBox controller

  mechanismsBtns[4]->WhileHeld( new Telescope( true ) );
  mechanismsBtns[5]->WhileHeld( new Telescope( false ) );

  mechanismsBtns[6]->WhileHeld( new Lift( true ) );
  mechanismsBtns[7]->WhileHeld( new Lift( false ) );
}

std::shared_ptr<frc::Joystick> OI::getDriverJoystick() {
	return driverJoystick;
}
