#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class Autonomous : public frc2::CommandHelper<frc2::CommandBase, Autonomous> {
 public:
  Autonomous(int selection);
};
