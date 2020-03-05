#include "RobotContainer.h"

#include "AutonomousChooser.h"
#include <frc/DoubleSolenoid.h>
#include "frc/smartDashboard/SmartDashboard.h"
#include "Robot.h"
#include "commands/DriveWithJoystick.h"
#include "commands/ReadColorSensor.h"
#if( PNEUMATICS_SUPPORT )
    #include "commands/MovePneumatics.h"
#endif

RobotContainer::RobotContainer()
    : mAutonomousCommand( AutonomousChooser().AutonomousSelection() )
{
    mDriverJoystick.reset(new frc::Joystick(0));
    mDrive.SetDefaultCommand( DriveWithJoystick( &mDrive, mDriverJoystick ) );
    #if( PNEUMATICS_SUPPORT )
        mMechanismsJoystick.reset(new frc::Joystick(1));
    #endif
    for (int i=1; i<=10; i++)
    {
        mDriverButtons.push_back(new frc2::JoystickButton(mDriverJoystick.get(), i));
        #if( PNEUMATICS_SUPPORT )
            mMechanismsButtons.push_back(new frc2::JoystickButton(mMechanismsJoystick.get(), i));
        #endif
    }

    ConfigureButtonBindings();
}

frc2::Command* RobotContainer::GetAutonomousCommand()
{
    return &mAutonomousCommand;
}

void RobotContainer::ConfigureButtonBindings()
{
    mDriverButtons[2]->WhileHeld( new ReadColorSensor( &mColorWheel ) ); //This should be 'x' button on the XBox controller

    #if( PNEUMATICS_SUPPORT )
        mMechanismsButtons[2]->WhileHeld(new MovePneumatics( &mPneumatics, frc::DoubleSolenoid::kForward)); //This should be 'x' button on the XBox controller
        mMechanismsButtons[2]->WhenReleased(new MovePneumatics( &mPneumatics, frc::DoubleSolenoid::kOff)); //This should be 'x' button on the XBox controller
        mMechanismsButtons[3]->WhileHeld(new MovePneumatics( &mPneumatics, frc::DoubleSolenoid::kReverse)); //This should be 'y' button on the XBox controller
        mMechanismsButtons[3]->WhenReleased(new MovePneumatics( &mPneumatic, frc::DoubleSolenoid::kOff)); //This should be 'y' button on the XBox controller
    #endif
}