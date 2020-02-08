#include "commands/MoveArm.h"

#include "CommandBase.h"

MoveArm::MoveArm(double setPoint) : CommandBase("MoveArm") {
    Requires(CommandBase::liftArm.get());
    mSetpoint = setPoint;
}

void MoveArm::Initialize()
{
  liftArm->Enable();
  liftArm->SetSetpoint( mSetpoint );
}

// Make this return true when this Command no longer needs to run execute()
bool MoveArm::IsFinished()
{
    return liftArm->OnTarget();
}