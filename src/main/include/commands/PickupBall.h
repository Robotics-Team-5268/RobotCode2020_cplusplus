#pragma once

#include "CommandBase.h"

class PickupBall : public CommandBase {
 public:
  PickupBall();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
