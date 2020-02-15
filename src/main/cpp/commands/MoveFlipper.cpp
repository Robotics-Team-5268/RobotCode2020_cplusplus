#include "commands/MoveFlipper.h"

#include "CommandBase.h"

MoveFlipper::MoveFlipper(double aSetPoint) : CommandBase("MoveFlipper") {
    Requires(CommandBase::intakeFlipper.get());
    mSetpoint = aSetPoint;
}

void MoveFlipper::Initialize()
{
  intakeFlipper->Enable();
  intakeFlipper->SetSetpoint( mSetpoint );
}

// Make this return true when this Command no longer needs to run execute()
bool MoveFlipper::IsFinished()
{
    return intakeFlipper->OnTarget();
}
