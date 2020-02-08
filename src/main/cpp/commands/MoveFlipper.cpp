#include "commands/MoveFlipper.h"

#include "CommandBase.h"

MoveFlipper::MoveFlipper(double setPoint) : CommandBase("MoveFlipper") {
    Requires(CommandBase::ballIntake.get());
    mSetpoint = setPoint;
}

void MoveFlipper::Initialize()
{
  ballIntake->Enable();
  ballIntake->SetSetpoint( mSetpoint );
}

// Make this return true when this Command no longer needs to run execute()
bool MoveFlipper::IsFinished()
{
    return ballIntake->OnTarget();
}
