#pragma once

#include <frc/commands/Command.h>
#include "subsystems/ColorWheel.h"

class ReadColorSensor : public frc::Command
{
public:
  ReadColorSensor( ColorWheel* aColorWheel );
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;

private:
  ColorWheel* mColorWheel;
};