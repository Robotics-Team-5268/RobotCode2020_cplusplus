#include "RobotContainer.h"

#include "AutonomousChooser.h"
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

std::unique_ptr<BallIntake> RobotContainer::ballIntake;
std::unique_ptr<ColorWheel> RobotContainer::colorWheel;
std::unique_ptr<Drive> RobotContainer::drive;
std::unique_ptr<IntakeFlipper> RobotContainer::intakeFlipper;
std::unique_ptr<LiftArm> RobotContainer::liftArm;
std::unique_ptr<Pneumatics> RobotContainer::pneumatics;
std::unique_ptr<Winches> RobotContainer::winches;

std::shared_ptr<frc::Joystick> RobotContainer::driverJoystick;

RobotContainer::RobotContainer()
    : mAutonomousCommand( AutonomousChooser().AutonomousSelection() )
{
    driverJoystick.reset(new frc::Joystick(0));
    mechanismsJoystick.reset(new frc::Joystick(1));
    for (int i=1; i<=10; i++)
    {
        driverBtns.push_back(new frc::JoystickButton(driverJoystick.get(), i));
        mechanismsBtns.push_back(new frc::JoystickButton(mechanismsJoystick.get(), i));
    }

    ballIntake.reset( new BallIntake() );
    colorWheel.reset( new ColorWheel() );
    drive.reset(new Drive());
    intakeFlipper.reset( new IntakeFlipper() );
    liftArm.reset( new LiftArm() );
    pneumatics.reset(new Pneumatics());
    winches.reset( new Winches() );

    // Keep at the end
    ConfigureButtonBindings();
}

frc::Command* RobotContainer::GetAutonomousCommand()
{
    return &mAutonomousCommand;
}

void RobotContainer::ConfigureButtonBindings()
{
    driverBtns[4]->WhenPressed(new ShiftGears(frc::DoubleSolenoid::kReverse)); // LB, shift down
    driverBtns[5]->WhenPressed(new ShiftGears(frc::DoubleSolenoid::kForward)); // RB, shift up

    mechanismsBtns[0]->WhileHeld( new Lift( true ) );
    //mechanismsBtns[7]->WhileHeld( new Lift( false ) ); // Not currently used.  Will ratchet down after round

    mechanismsBtns[1]->WhileHeld( new Telescope( true ) ); // B
    mechanismsBtns[3]->WhileHeld( new Telescope( false ) ); // Y

    mechanismsBtns[2]->WhenPressed( new SpinColor() ); // X

    // RB
    mechanismsBtns[4]->WhenPressed( new MoveFlipper( true ) );
    mechanismsBtns[4]->WhileHeld( new ShootBall() );
    mechanismsBtns[4]->WhenReleased( new MoveFlipper( false ) );

    // LB
    mechanismsBtns[5]->WhileHeld( new PickupBall() );

    // mechanismsBtns[2]->WhileHeld( new ReadColorSensor() ); // Test command not currently used

    // R3
    mechanismsBtns[6]->WhenPressed(new MoveStinger(frc::DoubleSolenoid::kForward));
    // mechanismsBtns[3]->WhenPressed(new MoveStinger(frc::DoubleSolenoid::kReverse)); // Not currently retracting the stinger

    // The game requires 3-5 spins.  Start at 4 to maximimize error tolerance
    const int desiredRotations = 4;
    mechanismsBtns[7]->WhenPressed( new SpinRotations( desiredRotations ) ); // RT - need to fix

    mechanismsBtns[8]->WhenPressed( new MoveArm( true ) ); // L3
    mechanismsBtns[9]->WhenPressed( new MoveArm( false ) ); // R3
}

std::shared_ptr<frc::Joystick> RobotContainer::getDriverJoystick() {
	return driverJoystick;
}