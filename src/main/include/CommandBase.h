#pragma once

#include <memory>

#include <frc/commands/CommandGroup.h>
#include <string.h>

#include "subsystems/Drive.h"
#include "subsystems/Encoders.h"
#include "subsystems/Pneumatics.h"
#include "OI.h"

class CommandBase : public frc::CommandGroup {
 public:
  CommandBase(const std::string &name);
  CommandBase();
  static void init();

  
  static std::unique_ptr<Drive> drive;
  static std::unique_ptr<Encoders> leftEncoder;
  static std::unique_ptr<Encoders> rightEncoder;
  static std::unique_ptr<Pneumatics> pneumatics;
  static std::unique_ptr<OI> oi;
};
