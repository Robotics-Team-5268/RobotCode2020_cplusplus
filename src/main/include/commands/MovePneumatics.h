#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <frc/DoubleSolenoid.h>

class MovePneumatics : public frc2::CommandHelper<frc2::CommandBase, MovePneumatics> {
 public:
  MovePneumatics(frc::DoubleSolenoid::Value v);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End(bool interrupted) override;
 private:
  frc::DoubleSolenoid::Value value;
};
