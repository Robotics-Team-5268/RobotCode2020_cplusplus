#pragma once

#include <frc/commands/Command.h>
#include <frc/DoubleSolenoid.h>
#include "subsystems/Pneumatics.h"

class ShiftGears : public frc::Command
{
public:
  ShiftGears( Pneumatics* aPneumatics, frc::DoubleSolenoid::Value aValue);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;

private:
  Pneumatics* mPneumatics;
  frc::DoubleSolenoid::Value mValue;
};
