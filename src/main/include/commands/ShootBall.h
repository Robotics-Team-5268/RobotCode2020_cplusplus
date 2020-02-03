#pragma once

#include "CommandBase.h"

class ShootBall : public CommandBase {
 public:
  ShootBall();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
