#pragma once

#include <frc/commands/Command.h>
#include "subsystems/BallIntake.h"

class ShootBall : public frc::Command
{
public:
  ShootBall( BallIntake* aBallIntake );
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
private:
  BallIntake* mBallIntake;
};
