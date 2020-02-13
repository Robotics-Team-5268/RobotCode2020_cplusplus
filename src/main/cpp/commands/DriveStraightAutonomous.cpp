#include "commands/DriveStraightAutonomous.h"

DriveStraightAutonomous::DriveStraightAutonomous() : CommandBase("DriveStraightDistance")
{
    Requires( drive.get() );
}

void DriveStraightAutonomous::End()
{
    drive->setMotors( 0.0, 0.0 );
}

void DriveStraightAutonomous::Initialize()
{
    // Run the command for 2 seconds
    SetTimeout( 2.0 );
}

void DriveStraightAutonomous::Execute()
{
    // drive->setMotors( 0.1, 0.1 );
}

bool DriveStraightAutonomous::IsFinished()
{
    return true;
}
