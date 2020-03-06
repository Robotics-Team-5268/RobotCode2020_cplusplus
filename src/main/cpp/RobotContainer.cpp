#include "RobotContainer.h"

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
    : mAutonomousCommand( &mDrive, AutonomousChooser().AutonomousSelection() )
{
    mDriverJoystick.reset(new frc::Joystick(0));
    mMechanismsJoystick.reset(new frc::Joystick(1));
    for (int i=1; i<=10; i++)
    {
        mDriverBtns.push_back(new frc2::JoystickButton(mDriverJoystick.get(), i));
        mMechanismsBtns.push_back(new frc2::JoystickButton(mMechanismsJoystick.get(), i));
    }

    mDrive.SetDefaultCommand( DriveWithJoystick( &mDrive, mDriverJoystick ) );

	mDrive.calibrateGyro();

    // Keep at the end
    ConfigureButtonBindings();
}

frc2::Command* RobotContainer::GetAutonomousCommand()
{
    return &mAutonomousCommand;
}

void RobotContainer::ConfigureButtonBindings()
{
    mDriverBtns[4]->WhenPressed(new ShiftGears( &mPneumatics, frc::DoubleSolenoid::kReverse)); // LB, shift down
    mDriverBtns[5]->WhenPressed(new ShiftGears( &mPneumatics, frc::DoubleSolenoid::kForward)); // RB, shift up

    mMechanismsBtns[0]->WhileHeld( new Lift( &mWinches, true ) );
    //mMechanismsBtns[7]->WhileHeld( new Lift( &mWinches, false ) ); // Not currently used.  Will ratchet down after round

    mMechanismsBtns[1]->WhileHeld( new Telescope( &mWinches, true ) ); // B
    mMechanismsBtns[3]->WhileHeld( new Telescope( &mWinches, false ) ); // Y

    mMechanismsBtns[2]->WhenPressed( new SpinColor( &mColorWheel ) ); // X

    // RB
    mMechanismsBtns[4]->WhenPressed( new MoveFlipper( &mIntakeFlipper, true ) );
    mMechanismsBtns[4]->WhileHeld( new ShootBall( &mBallIntake ) );
    mMechanismsBtns[4]->WhenReleased( new MoveFlipper( &mIntakeFlipper, false ) );

    // LB
    mMechanismsBtns[5]->WhileHeld( new PickupBall( &mBallIntake ) );

    // mMechanismsBtns[2]->WhileHeld( new ReadColorSensor( &mColorWheel ) ); // Test command not currently used

    // R3
    mMechanismsBtns[6]->WhenPressed(new MoveStinger( &mPneumatics, frc::DoubleSolenoid::kForward));
    // mMechanismsBtns[3]->WhenPressed(new MoveStinger( &mPneumatics, frc::DoubleSolenoid::kReverse ) ); // Not currently retracting the stinger

    // The game requires 3-5 spins.  Start at 4 to maximimize error tolerance
    const int desiredRotations = 4;
    mMechanismsBtns[7]->WhenPressed( new SpinRotations( &mColorWheel, desiredRotations ) ); // RT - need to fix

    mMechanismsBtns[8]->WhenPressed( new MoveArm( &mLiftArm, true ) ); // L3
    mMechanismsBtns[9]->WhenPressed( new MoveArm( &mLiftArm, false ) ); // R3
}
