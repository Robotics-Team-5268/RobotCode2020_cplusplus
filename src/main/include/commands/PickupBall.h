#pragma once

#include <frc/commands/Command.h>
#include "subsystems/BallIntake.h"

class PickupBall : public frc::Command
{
public:
  PickupBall( BallIntake* aBallIntake );
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;

private:
  BallIntake* mBallIntake;
};
