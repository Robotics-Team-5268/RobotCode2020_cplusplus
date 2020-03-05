#include "commands/DriveStraightAutonomous.h"

#include "RobotContainer.h"

DriveStraightAutonomous::DriveStraightAutonomous()
{
    SetName( "DriveStraightDistance" );
    Requires( RobotContainer::drive.get() );
}

void DriveStraightAutonomous::End()
{
    RobotContainer::drive->setMotors( 0.0, 0.0 );
}

void DriveStraightAutonomous::Initialize()
{
    // Run the command for 2 seconds
    SetTimeout( 2.0 );
}

void DriveStraightAutonomous::Execute()
{
    // TODO: Uncomment this once it can be tested
    // RobotContainer::drive->setMotors( 0.1, 0.1 );
}

bool DriveStraightAutonomous::IsFinished()
{
    return true;
}
