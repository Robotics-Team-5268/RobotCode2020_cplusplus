#pragma once

#include <frc/commands/Command.h>
#include <subsystems/ColorWheel.h>

class SpinRotations : public frc::Command {
 public:
  SpinRotations
    (
    ColorWheel* aColorWheel,
    int aNumRotations
    );
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
 private:
    ColorWheel* mColorWheel;
    int mNumRotations;
    ColorWheel::MatchedColor mLastMatchedColor;
    int mColorChangeCount;
};