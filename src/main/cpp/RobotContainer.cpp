#include "RobotContainer.h"

#include "RobotConfig.h"

#include "AutonomousChooser.h"
#include "commands/DriveWithJoystick.h"
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

RobotContainer::RobotContainer()
    : mAutonomousCommand( &drive, AutonomousChooser().AutonomousSelection() )
{
    driverJoystick.reset(new frc::Joystick(0));
    mechanismsJoystick.reset(new frc::Joystick(1));
    for (int i=1; i<=10; i++)
    {
        driverBtns.push_back(new frc2::JoystickButton(driverJoystick.get(), i));
        mechanismsBtns.push_back(new frc2::JoystickButton(mechanismsJoystick.get(), i));
    }

    drive.SetDefaultCommand( DriveWithJoystick( &drive, driverJoystick ) );

	#if( GYRO_SUPPORT )
		drive.calibrateGyro();
	#endif

    // Keep at the end
    ConfigureButtonBindings();
}

frc2::Command* RobotContainer::GetAutonomousCommand()
{
    return &mAutonomousCommand;
}

void RobotContainer::ConfigureButtonBindings()
{
    driverBtns[4]->WhenPressed(new ShiftGears( &pneumatics, frc::DoubleSolenoid::kReverse)); // LB, shift down
    driverBtns[5]->WhenPressed(new ShiftGears( &pneumatics, frc::DoubleSolenoid::kForward)); // RB, shift up

    mechanismsBtns[0]->WhileHeld( new Lift( &winches, true ) );
    //mechanismsBtns[7]->WhileHeld( new Lift( &winches, false ) ); // Not currently used.  Will ratchet down after round

    mechanismsBtns[1]->WhileHeld( new Telescope( &winches, true ) ); // B
    mechanismsBtns[3]->WhileHeld( new Telescope( &winches, false ) ); // Y

    mechanismsBtns[2]->WhenPressed( new SpinColor( &colorWheel ) ); // X

    // RB
    mechanismsBtns[4]->WhenPressed( new MoveFlipper( &intakeFlipper, true ) );
    mechanismsBtns[4]->WhileHeld( new ShootBall( &ballIntake ) );
    mechanismsBtns[4]->WhenReleased( new MoveFlipper( &intakeFlipper, false ) );

    // LB
    mechanismsBtns[5]->WhileHeld( new PickupBall( &ballIntake ) );

    // mechanismsBtns[2]->WhileHeld( new ReadColorSensor( &colorWheel ) ); // Test command not currently used

    // R3
    mechanismsBtns[6]->WhenPressed(new MoveStinger( &pneumatics, frc::DoubleSolenoid::kForward));
    // mechanismsBtns[3]->WhenPressed(new MoveStinger( &pneumatics, frc::DoubleSolenoid::kReverse ) ); // Not currently retracting the stinger

    // The game requires 3-5 spins.  Start at 4 to maximimize error tolerance
    const int desiredRotations = 4;
    mechanismsBtns[7]->WhenPressed( new SpinRotations( &colorWheel, desiredRotations ) ); // RT - need to fix

    mechanismsBtns[8]->WhenPressed( new MoveArm( &liftArm, true ) ); // L3
    mechanismsBtns[9]->WhenPressed( new MoveArm( &liftArm, false ) ); // R3
}
