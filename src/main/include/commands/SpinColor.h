#pragma once

#include "RobotContainer.h"
#include <subsystems/ColorWheel.h>

class SpinColor : public RobotContainer {
 public:
  SpinColor();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
 private:
    ColorWheel::MatchedColor mFmsColor; //!< Field management system color
    bool mColorMatched;
};