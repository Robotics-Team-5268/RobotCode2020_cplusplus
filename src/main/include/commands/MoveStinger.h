#pragma once

#include <frc/commands/Command.h>
#include <frc/DoubleSolenoid.h>
#include "subsystems/Pneumatics.h"

class MoveStinger : public frc::Command {
 public:
  MoveStinger( Pneumatics* aPneumatics, frc::DoubleSolenoid::Value aValue);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
 private:
  Pneumatics* mPneumatics;
  frc::DoubleSolenoid::Value mValue;
};
