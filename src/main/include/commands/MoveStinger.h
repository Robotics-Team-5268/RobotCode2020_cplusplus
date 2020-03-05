#pragma once

#include <frc/commands/Command.h>

#include <frc/DoubleSolenoid.h>

class MoveStinger : public frc::Command {
 public:
  MoveStinger(frc::DoubleSolenoid::Value aValue);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
 private:
  frc::DoubleSolenoid::Value mValue;
};
