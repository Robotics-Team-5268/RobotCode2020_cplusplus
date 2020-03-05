#pragma once

#include "RobotContainer.h"
#include <subsystems/ColorWheel.h>

class SpinRotations : public RobotContainer {
 public:
  SpinRotations
    (
    int aNumRotations
    );
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
 private:
    int mNumRotations;
    ColorWheel::MatchedColor mLastMatchedColor;
    int mColorChangeCount;
};