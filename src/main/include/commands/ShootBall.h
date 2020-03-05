#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/BallIntake.h"

class ShootBall : public frc2::CommandHelper<frc2::CommandBase, ShootBall>
{
public:
  ShootBall( BallIntake* aBallIntake );
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End(bool interrupted) override;
private:
  BallIntake* mBallIntake;
};
