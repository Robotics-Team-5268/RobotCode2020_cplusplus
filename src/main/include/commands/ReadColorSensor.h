#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/ColorWheel.h"

class ReadColorSensor : public frc2::CommandHelper<frc2::CommandBase, ReadColorSensor>
{
public:
  ReadColorSensor( ColorWheel* aColorWheel );
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End(bool interrupted) override;

private:
  ColorWheel* mColorWheel;
};