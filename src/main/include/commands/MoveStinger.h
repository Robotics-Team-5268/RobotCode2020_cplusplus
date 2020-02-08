#pragma once

#include "CommandBase.h"

#include <frc/DoubleSolenoid.h>

class MoveStinger : public CommandBase {
 public:
  MoveStinger(frc::DoubleSolenoid::Value v);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
 private:
  frc::DoubleSolenoid::Value value;
};
