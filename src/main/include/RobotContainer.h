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

  BallIntake ballIntake;
  ColorWheel colorWheel;
  Drive drive;
  IntakeFlipper intakeFlipper;
  LiftArm liftArm;
  Pneumatics pneumatics;
  Winches winches;

  std::shared_ptr<frc::Joystick> driverJoystick;
  std::shared_ptr<frc::Joystick> mechanismsJoystick;
  std::vector<frc2::JoystickButton*> driverBtns;
  std::vector<frc2::JoystickButton*> mechanismsBtns;

  Autonomous mAutonomousCommand;
};
