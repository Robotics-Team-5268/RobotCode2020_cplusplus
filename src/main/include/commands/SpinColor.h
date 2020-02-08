#pragma once

#include "CommandBase.h"
#include <subsystems/ColorWheel.h>

class SpinColor : public CommandBase {
 public:
  SpinColor();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
 private:
    ColorWheel::MatchedColor mDesiredColor;

};