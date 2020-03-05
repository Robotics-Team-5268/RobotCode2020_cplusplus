#pragma once

#include "RobotContainer.h"
#include <subsystems/ColorWheel.h>

class SpinColor : public frc::Command {
 public:
  SpinColor();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;

 private:
    ColorWheel::MatchedColor mFmsColor; //!< Field management system color
    bool mColorMatched;
};