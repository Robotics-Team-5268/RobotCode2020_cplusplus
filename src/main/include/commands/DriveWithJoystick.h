#pragma once

#include <frc/commands/Command.h>

class DriveWithJoystick : public frc::Command {
 public:
  DriveWithJoystick();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
};
