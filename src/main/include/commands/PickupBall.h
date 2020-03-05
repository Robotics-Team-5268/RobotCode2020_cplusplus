#pragma once

#include <frc/commands/Command.h>

class PickupBall : public frc::Command {
 public:
  PickupBall();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
