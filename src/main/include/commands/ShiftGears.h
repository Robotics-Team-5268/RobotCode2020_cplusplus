#pragma once

#include "RobotContainer.h"

#include <frc/DoubleSolenoid.h>

class ShiftGears : public RobotContainer {
 public:
  ShiftGears(frc::DoubleSolenoid::Value aValue);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
 private:
  frc::DoubleSolenoid::Value mValue;
};
