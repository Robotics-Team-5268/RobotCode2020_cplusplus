#pragma once

#include <memory>
#include <frc/commands/Command.h>
#include <frc/Joystick.h>
#include "subsystems/Drive.h"

class DriveWithJoystick : public frc::Command
{
public:
  DriveWithJoystick( Drive* aDrive, const std::shared_ptr<frc::Joystick>& aJoystick );
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;

private:
  Drive* mDrive;
  std::shared_ptr<frc::Joystick> mJoystick;
};
