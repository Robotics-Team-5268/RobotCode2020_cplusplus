#pragma once

#include <memory>
#include <vector>

#include "commands/Autonomous.h"

#include <frc/Joystick.h>
#include <frc/buttons/JoystickButton.h>

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

  static std::unique_ptr<BallIntake> ballIntake;
  static std::unique_ptr<ColorWheel> colorWheel;
  static std::unique_ptr<Drive> drive;
  static std::unique_ptr<IntakeFlipper> intakeFlipper;
  static std::unique_ptr<LiftArm> liftArm;
  static std::unique_ptr<Pneumatics> pneumatics;
  static std::unique_ptr<Winches> winches;

  static std::shared_ptr<frc::Joystick> getDriverJoystick();

  frc::Command* GetAutonomousCommand();

private:
  void ConfigureButtonBindings();

  static std::shared_ptr<frc::Joystick> driverJoystick;
  std::shared_ptr<frc::Joystick> mechanismsJoystick;
  std::vector<frc::JoystickButton*> driverBtns;
  std::vector<frc::JoystickButton*> mechanismsBtns;

  Autonomous mAutonomousCommand;
};
