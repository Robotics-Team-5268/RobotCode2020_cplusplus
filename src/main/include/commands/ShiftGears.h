#pragma once

#include <frc/commands/Command.h>

#include <frc/DoubleSolenoid.h>

class ShiftGears : public frc::Command {
 public:
  ShiftGears(frc::DoubleSolenoid::Value aValue);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
 private:
  frc::DoubleSolenoid::Value mValue;
};
