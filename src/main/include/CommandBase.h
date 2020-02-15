#pragma once

#include <memory>

#include <frc/commands/CommandGroup.h>
#include <string.h>

#include "subsystems/BallIntake.h"
#include "subsystems/ColorWheel.h"
#include "subsystems/Drive.h"
#include "subsystems/LiftArm.h"
#include "subsystems/IntakeFlipper.h"
#include "subsystems/Pneumatics.h"
#include "subsystems/Winches.h"
#include "OI.h"

class CommandBase : public frc::CommandGroup {
 public:
  CommandBase(const std::string &name);
  CommandBase();
  static void init();

  static std::unique_ptr<BallIntake> ballIntake;
  static std::unique_ptr<ColorWheel> colorWheel;
  static std::unique_ptr<Drive> drive;
  static std::unique_ptr<IntakeFlipper> intakeFlipper;
  static std::unique_ptr<LiftArm> liftArm;
  static std::unique_ptr<Pneumatics> pneumatics;
  static std::unique_ptr<Winches> winches;
  static std::unique_ptr<OI> oi;
};
