#pragma once

#include <frc/commands/Command.h>

class ShootBall : public frc::Command {
 public:
  ShootBall();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
