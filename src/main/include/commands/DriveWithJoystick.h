#pragma once

#include "RobotContainer.h"

class DriveWithJoystick : public RobotContainer {
 public:
  DriveWithJoystick();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
