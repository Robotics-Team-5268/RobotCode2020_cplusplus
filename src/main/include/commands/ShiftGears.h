#pragma once

#include "CommandBase.h"

#include <frc/DoubleSolenoid.h>

class ShiftGears : public CommandBase {
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
