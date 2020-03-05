#pragma once

#include "RobotContainer.h"

class PickupBall : public RobotContainer {
 public:
  PickupBall();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
