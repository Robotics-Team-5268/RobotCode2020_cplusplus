#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class DriveWithJoystick : public frc2::CommandHelper<frc2::CommandBase, DriveWithJoystick> {
 public:
  DriveWithJoystick();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End(bool interrupted) override;
};
