#pragma once

#include <memory>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/Joystick.h>
#include "subsystems/Drive.h"

class DriveWithJoystick : public frc2::CommandHelper<frc2::CommandBase, DriveWithJoystick>

{
public:
  DriveWithJoystick( Drive* aDrive, const std::shared_ptr<frc::Joystick>& aJoystick );
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End(bool interrupted) override;

private:
  Drive* mDrive;
  std::shared_ptr<frc::Joystick> mJoystick;
};
