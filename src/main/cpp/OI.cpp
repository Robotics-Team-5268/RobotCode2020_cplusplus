#include "OI.h"

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
#include "commands/SpinColor.h"
#include "commands/SpinRotations.h"
#include "commands/Telescope.h"

#include "subsystems/IntakeFlipper.h"
#include "subsystems/LiftArm.h"

OI::OI() {
  driverJoystick.reset(new frc::Joystick(0));
  mechanismsJoystick.reset(new frc::Joystick(1));
  for (int i=1; i<=10; i++){
    driverBtns.push_back(new frc::JoystickButton(driverJoystick.get(), i));
    mechanismsBtns.push_back(new frc::JoystickButton(mechanismsJoystick.get(), i));
  }

  driverBtns[4]->WhenPressed(new ShiftGears(frc::DoubleSolenoid::kReverse)); // LB, shift down
  driverBtns[5]->WhenPressed(new ShiftGears(frc::DoubleSolenoid::kForward)); // RB, shift up

  mechanismsBtns[0]->WhileHeld( new Lift( true ) );
  //mechanismsBtns[7]->WhileHeld( new Lift( false ) ); // Not currently used.  Will ratchet down after round

  mechanismsBtns[1]->WhileHeld( new Telescope( true ) ); // B
  mechanismsBtns[3]->WhileHeld( new Telescope( false ) ); // Y

  mechanismsBtns[2]->WhenPressed( new MoveArm( LiftArm::cRaiseArm ) ); // X

  // RB
  mechanismsBtns[4]->WhenPressed( new MoveFlipper( IntakeFlipper::cOpenFlipper ) );
  mechanismsBtns[4]->WhileHeld( new ShootBall() );
  mechanismsBtns[4]->WhenReleased( new MoveFlipper( IntakeFlipper::cCloseFlipper ) );

  // LB
  mechanismsBtns[5]->WhileHeld( new PickupBall() );


  // mechanismsBtns[2]->WhileHeld( new ReadColorSensor() ); // Test command not currently used

  // R3
  mechanismsBtns[9]->WhenPressed(new MoveStinger(frc::DoubleSolenoid::kForward));
  // mechanismsBtns[3]->WhenPressed(new MoveStinger(frc::DoubleSolenoid::kReverse)); // Not currently retracting the stinger

  // The game requires 3-5 spins.  Start at 4 to maximimize error tolerance
  const int desiredRotations = 4;
  mechanismsBtns[7]->WhenPressed( new SpinRotations( desiredRotations ) ); // RT - need to fix
  mechanismsBtns[8]->WhenPressed( new SpinColor() ); // LT - need to fix
}

std::shared_ptr<frc::Joystick> OI::getDriverJoystick() {
	return driverJoystick;
}
