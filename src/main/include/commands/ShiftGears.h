#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/DoubleSolenoid.h>
#include "subsystems/Pneumatics.h"

class ShiftGears : public frc2::CommandHelper<frc2::CommandBase, ShiftGears>
{
public:
  ShiftGears( Pneumatics* aPneumatics, frc::DoubleSolenoid::Value aValue);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End(bool interrupted) override;

private:
  Pneumatics* mPneumatics;
  frc::DoubleSolenoid::Value mValue;
};
