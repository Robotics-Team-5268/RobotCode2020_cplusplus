#pragma once

#include <memory>
#include <vector>

#include "commands/Autonomous.h"

#include <frc/Joystick.h>
#include <frc2/command/button/JoystickButton.h>

#include "subsystems/BallIntake.h"
#include "subsystems/ColorWheel.h"
#include "subsystems/Drive.h"
#include "subsystems/LiftArm.h"
#include "subsystems/IntakeFlipper.h"
#include "subsystems/Pneumatics.h"
#include "subsystems/Winches.h"

class RobotContainer
{
public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

private:
  void ConfigureButtonBindings();

  BallIntake mBallIntake;
  ColorWheel mColorWheel;
  Drive mDrive;
  IntakeFlipper mIntakeFlipper;
  LiftArm mLiftArm;
  Pneumatics mPneumatics;
  Winches mWinches;

  std::shared_ptr<frc::Joystick> mDriverJoystick;
  std::shared_ptr<frc::Joystick> mMechanismsJoystick;
  std::vector<frc2::JoystickButton*> mDriverBtns;
  std::vector<frc2::JoystickButton*> mMechanismsBtns;

  Autonomous mAutonomousCommand;
};
