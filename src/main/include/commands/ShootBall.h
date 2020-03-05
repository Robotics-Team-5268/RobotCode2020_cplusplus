#pragma once

#include "RobotContainer.h"

class ShootBall : public RobotContainer {
 public:
  ShootBall();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
