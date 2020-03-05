#pragma once

#include "RobotContainer.h"
#include <subsystems/ColorWheel.h>

class SpinRotations : public frc::Command {
 public:
  SpinRotations
    (
    int aNumRotations
    );
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
 private:
    int mNumRotations;
    ColorWheel::MatchedColor mLastMatchedColor;
    int mColorChangeCount;
};